
#ifndef INTERFACE_H
#define INTERFASE_H
#include <fstream>
#include <string>
#include <iostream>


const int N = 30;


struct info_film {
    //info_film() {};
    char* adress;
    std::string name;   
    FILE* f;
    int time;     
    int year;           
  

    //info_film();

    void set_name(std::string );
    void set_time(int);
    void set_year(int);

    void set_adress(char *);

    void print_name();
    void print_year();
    void print_time();
    void print_all();

    void play_film();   
    void off_film();    
    void creatå_film(); 
};


struct film_collection {
    film_collection();
    //  film_collection() {};
    void add_film (info_film);       
    void dell_film(std::string s);   
    int  search_film(std::string s);  
    void output();

    info_film film[N];
    int n;
};


struct sort_film {
   // sort_film() {};
    film_collection film;

    void name_sort();  
    void year_sort(); 
};



struct unity_film {
   // unity_film() {};
    void year_unity(info_film t[], int n);        
};


struct play {
   // play() {};
    film_collection film;
    int  run_film(std::string s);
    void run();
};

#endif