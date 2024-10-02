
#pragma once
#ifndef RGZ_RECORD_H
#define RGZ_RECORD_H


#include <time.h>
#include <iostream>
#include <string>
#include "Commentaire.h"
#include "listM.hpp"
#include <time.h>


using namespace std;

class Record{
    int id;
    int author_id;
    string title;
    string text;
    string date;
    string name_autor;
    bool coment = true;
    MList<Commentaire> comments;
    int get_unique_com_id();

public:
    Record(int rec_id, int author_id, string title, string text , string name_autor){
        this->id = rec_id;
        this->author_id = author_id;
        this->title = title;
        this->text = text;
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        this->date = asctime(timeinfo);
        this->name_autor=name_autor;
    }
    int get_id();
    int get_author_id();
    string get_name_autor();
    string get_title();
    string get_date();
    string get_text();
    bool  get_coment();
    MList<Commentaire>* getCommends();
    void set_title(string title);
    void set_text(string text);
    void look_unlook_comment();
    void add_comment(int id_user, string name);
    friend std::ostream& operator<< (std::ostream &out, const Record &rec);
};



#endif //RGZ_RECORD_H
