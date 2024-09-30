
#pragma once

#ifndef RGZ_USER_H
#define RGZ_USER_H
#include <string>
#include "Record.h"
#include "listM.hpp"
#include <iostream>
#include "Record.h"
using namespace std;

class User
{
    int id;
    string nickname;
    string password;
    string interests;
    string mail;
    string phone;
    string birthday;
    string info;
    void show_line();
    void interface_add_coment(User u);
    void add_record(string title, string text);
    int get_unique_rec_id();
    friend std::ostream& operator<< (std::ostream &out, const User &user);
    void interface_create_record();
    void edit_record();
    int search_record_id(string name_record);
    void  delete_record();
    int search_record_i(string name_record);
public:
    User(int user_id, string nickname, string password, string interests, string mail, string phone, string birthday, string info){
        this->id = user_id;
        this->nickname = nickname;
        this->password = password;
        this->interests = interests;
        this->mail = mail;
        this->phone = phone;
        this->birthday = birthday;
        this->info = info;
    };
    MList<Record> records;
    MList<Record> getRecords();
    string get_name();
    string get_password();
    string get_interests();
    string get_mail();
    string get_phone();
    string get_birthday();
    string get_info();
    int get_id();

    void set_id(int id);
    void set_name(string nickname);
    void set_password(string password);
    void set_interests(string interests);
    void set_mail(string mail);
    void set_phone(string phone);
    void set_birthday(string birthday);
    void set_info(string info);
    void print_record_user();
    void  interface_record(User *user);
    void interface_look_unlook_comment();
    void interface_del_comment();
};


#endif //RGZ_USER_H
