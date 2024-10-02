

#ifndef RGZ_DATABASE_H
#define RGZ_DATABASE_H

#include "User.h"
#include "listM.hpp"

class Blog{
    bool check_password(string password);
    string cin_password(string s);
    string cin_name(string s);
    void show_line();
    int get_unique_id();
    void add_new_user();
    bool check_nickname(string name);
    int  check_authorization(string login, string password);
    int  authorization();
    int registrtion();
    void edit_user(User u);
    void look_user_blog();
    void del_user(User user);
    void print_all_record();
    User *login();
    void interface(User *user);
    void print_info_user(User u);
public:
    static Blog& getInstance() {
        static Blog  instance;
        return instance;
    }
    MList<User> users;
    Blog(){};
    void main_loop();

};


#endif //RGZ_DATABASE_H
