#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include <ctime>

#define MAXSIZE 255
using namespace std;
 class Body {
	
 protected:
	bool search_glas(char);
	void del_now(char[], int);

	
};

bool Body::search_glas(char c) 
 {
	int i = 0;
	 switch (c)
		 {
	 case 'a':
	 case 'e':
	 case 'o':
	 case 'u':
	 case 'i':
	 case 'y':
		 return true;
		
	 default:
		 return false;
		 };
	 }

 class Num_nowel : public Body { //подсчет числа гласных в тексте
	
 public:
	 void operator()(char text[], mutex & m)
		 {
		 int j = 0;
		
			 for (int i = 0; i < 100; i++)
			 {
			 int count = 0;
			 m.lock();
		
				 for (int j = 0; text[j] != '\0'; j++)
				 {
				 if (search_glas(text[j]))
					 count++;
				 }
			 m.unlock();
		 this_thread::sleep_for(chrono::seconds(1));
			 cout << "Число гласных равно: " << count << endl;
			 }
		 }
	
};

 void Body::del_now(char text[], int j) 
 {
	 int i;
	 for (i = j; text[i] != '\0'; i++)
		 text[i] = text[i + 1];
	 text[i] = '\0';
	 }

 class Del_add_vowel : public Body {
	
 public:
	 void operator()(char text[], mutex & m) {
		 for (int i = 0; i < 100; i++)
			 {
			 m.lock();
			 srand(unsigned(time(NULL)));
			 int j = 0;
			 if (strlen(text) != 0)
				 {
				 j = int(rand() % strlen(text));
				 if (search_glas(text[j]))
					 {
					 
						cout <<  j << endl;
					 del_now(text, j);
					 }
				 else
					{
					 
						 text[j] = 'a';
					 }
				 m.unlock();
				 this_thread::sleep_for(chrono::seconds(1));
				 }
			 else
				 {
				 cout << "Все символы закончились" << endl;
				 break;
				 }
			 }
		
	}
	
};

 void show(char text[], mutex & m) { 
	
		 for (int i = 0; i < 100; i++)
		 {
		 m.lock();
		 cout << text << endl;
		 m.unlock();
		 this_thread::sleep_for(chrono::seconds(1));
		 }
	
}

 int main()
 {
	 setlocale(LC_ALL, "rus");
	 mutex m;
	 Del_add_vowel del_add;
	 Num_nowel num;
	 char text[255] = "Everything is possible if you just believe";
	
		 cout << text << endl;
	
		 thread threadDel_add(del_add, text, ref(m));
	 thread threadNum_now(num, text, ref(m));
	 thread threadShow(show, text, ref(m));
	
		 threadNum_now.detach();
	 threadDel_add.detach();
	 threadShow.join();
	
		 cout << "\n\n";
	 return 0;
}

