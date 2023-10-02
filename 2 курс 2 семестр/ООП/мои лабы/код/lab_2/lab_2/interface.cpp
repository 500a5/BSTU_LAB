#include "interface.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <locale.h>


using namespace std;

info_film::info_film() {
    name = "";
    time = 0;
    year = 0;
    
}

void info_film::set_name(std::string s)
{
    name = s;
}



void info_film::set_time(int n)
{
    time = n;
}

void info_film::set_year(int n)
{
    year = n;
}

void info_film::print_name()
{
    std::cout << "_________________________________________________________________________________________________" << endl;
    std::cout << "Название фильма: " << name << endl;
}



void info_film::print_time()
{
    std::cout << "Продолжительность фильма: " << time << " min"<< endl;
}

void info_film::print_year()
{
    std::cout << "Год выпуска: " << year << endl;
}


void info_film::print_all()
{
    print_name(); 
    cout << " ";
    print_year(); 
    cout << " ";
    print_time();
    cout << " ";
}

void info_film::set_adress(char* s)
{
    adress = s;
}

void info_film::play_film()
{
    cout << "======================= Фильм =======================" << endl;
   
}

void info_film::off_film()
{
    system("CLS");
}

int play::run_film(std::string name)
{
    int t = film.search_film(name);
    cout << t;
    if (t != -1)
        film.film[t].play_film();
    else
        cout << "Фильм не найден!" << endl;
    return t;
}

film_collection::film_collection()
{
    n = 3;
    char* s = (char*)"D:\\movies\\1.mp4";
    char* s1 = (char*)"D:\\movies\\2.mp4";
    char* s2 = (char*)"D:\\movies\\3.mp4";

    film[0].set_name("sherlock homs");
    film[0].set_adress(s);
    film[0].set_year(1975);
    film[0].set_time(320);
 

    film[1].set_name("titanic");
    film[1].set_adress(s1);
    film[1].set_year(1995);
    film[1].set_time(250);
   

    film[2].set_name("joker");
    film[2].set_adress(s2);
    film[2].set_year(2019);
    film[2].set_time(120);
}

void film_collection::add_film(info_film t)
{
    if (search_film(t.name) == -1)
    {
        film[n] = t;
        n++;
    }
    else
        std::cout << "фильм уже добавлен!" << endl;
}

void film_collection::dell_film(std::string s)
{
    int k = search_film(s);
    if (k != -1)
    {
        film[k] = film[n - 1];
        --n;
    }
    else
        std::cout << "фильм не найден!" << endl;
}

int film_collection::search_film(std::string s)
{
    int i = 0;
    while (i < n)
    {
        if (film[i].name == s)
        {
            return i;
        }
        i++;
    }
    return -1;
}

void info_film::creatе_film()
{
    std::string  s;
    //char* a;
    int n;
    float n1;
    cout << "Введите название   : ";
    cin >> s;
    set_name(s);
   
    cout << "Введите год выпуска: ";
    cin >> n;
    set_year(n);
    cout << "ВВедите продолжительность: ";
    cin >> n1;
    set_time(n1);
}

void sort_film::name_sort()
{
    for (int i = 0; i < film.n - 1; i++)
        for (int j = i + 1; j < film.n; j++)
        {
            if (film.film[i].name > film.film[j].name)
                std::swap(film.film[i], film.film[j]);
        }
}


void sort_film::year_sort()
{
    for (int i = 0; i < film.n - 1; i++)
        for (int j = i + 1; j < film.n; j++)
        {
            if (film.film[i].year > film.film[j].year)
                std::swap(film.film[i], film.film[j]);
        }
}

void unity_film::year_unity(info_film film[], int n)
{
    int f = 0, k = 1, i = 0, j = 1;

    std::cout << "-------------- 1 папка -------------- " << endl;
    while (i <= n - 1 && j <= n)
    {
        if (film[i].year == film[j].year)
        {
            if (!f) film[i].print_all();
            f = 1;
            film[j].print_all();
            j++;
            continue;
        }
        else
        {
            if (f)
            {
                k++;
                std::cout << "-------------- " << k << " папка -------------- " << endl;
            }
            f = 0;
            i = j;
            j = i + 1;
        }
    }

    i = 0; j = 1;
    while (i <= n - 1 && j <= n)
    {
        if (film[i].year == film[j].year)
        {
            i += 2;
            j += 2;
        }
        else
        {
            film[i].print_all();
            i++; j++;
        }
    }
}

void film_collection::output()
{
    for (int i = 0; i < n; i++)
    {
        film[i].print_all();
    }
}

void play::run()
{
    int n = 0, m, v, f = 0;
    std::string s, s1, y;
    sort_film c;
    while (n != 6)
    {
        if (!f) c.film.output();
        f = 0;
        cout << "Включить фильм                           - 1" << endl;
        cout << "Добавить фильм в фильмотеку              - 2" << endl;
        cout << "Удалить  фильм из фильмотеки             - 3" << endl;
        cout << "Отсортировать фильмотеку                 - 4" << endl;
        cout << "Объеденить фильмы по папкам              - 5" << endl;
        cout << "Выйти из домашней фильмотеки             - 6" << endl;
        cout << "Ваш выбор: ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Какой фильм включить? " << endl;
            cin >> s;
            cout << endl;
            int t = run_film(s);
            if (t != -1) {
                cout << endl;
               
                cout << "Выключить фильм?            - 1" << endl;
              
                    c.film.film[t].off_film(); break;
                
                }
            
            break;
        }
        case 2:
        {
            info_film t;
            t.creatе_film();
            c.film.add_film(t);
            break;
        }
        case 3:
        {
            cout << "Какой фильм удалить? " << endl;
            cin >> s1;
            c.film.dell_film(s1);
            break;
        }
        case 4:
        {
            cout << "Отсортировать по названию фильма     - 1 " << endl;
            cout << "Отсортировать по году создания       - 2 " << endl;
            cin >> m;
            switch (m)
            {
            case 1:
            {
                c.name_sort();
                break;
            }
            case 2:
            {
                c.year_sort();
                break;
                break;
            }
            
            }
            break;
        }


        case 5:
        {
            cout << "Объеденить фильмы в папку по году их создания  - 1" << endl;
            cin >> m;
           
                c.year_sort();
                unity_film u;
                u.year_unity(c.film.film, c.film.n);
                f = 1;
               
        }
        }
    }
}


