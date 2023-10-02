#include <iostream>
#include <windows.h>
#include <thread>
#include <string>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <mutex>
#include <chrono>

using namespace std;


class StringModificator {
protected:
    string* s;
    unsigned int n;
    mutex* m;
    bool sunc;
    int timeout;
public:
    StringModificator() {};

    unsigned int random(int min = 0, int max = 0) {
        srand(unsigned(time(NULL)));
        if (max == 0)
            max = n;
        if (n == 0)
            max = 1;
        return (unsigned int)(min + rand() % (max));
    }

    virtual void modificateString() = 0;
    void operator()() { modificateString(); };
};


class RandomCharsDeleter : public StringModificator {
public:
    RandomCharsDeleter(string* ss, mutex* mut, bool isSunc = true, int timeOut = 1) {
        this->s = ss;
        this->n = (*s).length();
        this->m = mut;
        this->sunc = isSunc;
        this->timeout = timeOut;
    }
    void modificateString() override {
        while (1) {
            if (sunc)(*m).lock();
            this->n = (*s).length();
            unsigned rand = random();
            (*s).erase(rand, 1);
            if (sunc)(*m).unlock();
            this_thread::sleep_for(chrono::seconds(timeout));
        }
    }
};


class RandomCharsAppender : public StringModificator {
public:
    RandomCharsAppender(string* ss, mutex* mut, bool isSunc = true, int timeOut = 1) {
        this->s = ss;
        this->n = (*s).length();
        this->m = mut;
        this->sunc = isSunc;
        this->timeout = timeOut;
    }

    void modificateString() override {
        while (1) {
            if (sunc)(*m).lock();
            (*s).push_back((char)(random(33, 90)));
            if (sunc)(*m).unlock();
            this_thread::sleep_for(chrono::seconds(timeout));
        }
    }

};

class Output {
    string* s;
    mutex* m;
    bool sunc;
public:
    Output(string* ss, mutex* mut, bool sun = true) {
        s = ss;
        m = mut;
        sunc = sun;
    }
    void operator()() {
        while (1) {
            if (sunc) (*m).lock();
            cout << *s << endl;
            if (sunc) (*m).unlock();
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

DWORD WINAPI wrapperForDeleter(LPVOID d) {
    RandomCharsDeleter deleter = *(RandomCharsDeleter*)d;
    deleter();
    ExitThread(0);
}

DWORD WINAPI wrapperForAppender(LPVOID a) {
    RandomCharsAppender appender = *(RandomCharsAppender*)a;
    appender();
    ExitThread(0);
}

class ProgressBar {
    int* value;
    mutex* m;
    bool sunc;
    unsigned timeout;
    string* s;
public:
    ProgressBar(mutex* mut, int* counter, string* barS, bool sun = true, int timeOut = 1) {
        value = counter;
        m = mut;
        s = barS;
        sunc = sun;
        this->timeout = timeOut;
    }
    void inc() {
        (*value)++;
        (*s).push_back('|');
    }
    void operator()() {
        while ((*value) < 10) {
            if (sunc) (*m).lock();
            inc();
            if (sunc) (*m).unlock();
            this_thread::sleep_for(chrono::seconds(timeout));
        }
    }
    unsigned getVal() {
        return *value;
    }
    string getBar() {
        return *s;
    }
};

class DisplayProgressBar {
    ProgressBar* bar;
    mutex* m;
    bool sunc;
    int timeout;
public:
    DisplayProgressBar(ProgressBar* b, mutex* mut, bool sun = true, int timeOut = 1) {
        bar = b;
        m = mut;
        sunc = sun;
        this->timeout = timeOut;
    }
    void operator()() {
        while ((*bar).getVal() < 10) {
            if (sunc) (*m).lock();
            display();
            if (sunc) (*m).unlock();
            this_thread::sleep_for(chrono::seconds(timeout));
        }
    };
    void display() {
        cout << (*bar).getBar() << endl;
    }
};

int main() {
    mutex m;
    string barS = "";
    int counter = 0;
    ProgressBar bar(&m, &counter, &barS, false, 1);


    DisplayProgressBar displayBar(&bar, &m, false, 3);
    thread pb(bar);
    thread dpb(displayBar);
    pb.join();
    dpb.join();
    string s = "Buddy you’re a young man hard man. Shoutin’ in the street gonna take on the world some day";
    bool mode = true;
    RandomCharsDeleter deleter(&s, &m, false, 3);
    RandomCharsAppender appender(&s, &m, false, 1);
    Output output(&s, &m, false);
    if (mode) {
        thread delete_thread(deleter);
        thread append_thread(appender);
        delete_thread.detach();
        append_thread.detach();
    }
    else {
        HANDLE delete_thread = CreateThread(NULL, 0, wrapperForDeleter, &deleter, 0, NULL);
        HANDLE append_thread = CreateThread(NULL, 0, wrapperForAppender, &appender, 0, NULL);
    }
    thread output_thr(output);
    system("pause");
    output_thr.detach();
    return 0;
}
