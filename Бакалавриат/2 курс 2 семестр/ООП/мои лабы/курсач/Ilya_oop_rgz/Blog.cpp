
#include "Blog.h"





void Blog::print_info_user(User u) {
    cout<< u;
}

string Blog::cin_password(string s){
    while(!check_password(s)){
        cout<<"Пароль дольжеен быть длинне  8 знаков"<<endl;
        cout<<"Введите пароль"<<endl;
        cin>>s;
    }
    return s;
}
void Blog::del_user(User u){
    int index=0;
    for (auto user:users) {
        if(user.get_id()!=u.get_id()) index++;
        else break;
    }
    auto it = users.begin();
    advance(it,index);
    users.erase(it);
}

void Blog::look_user_blog(){
    string name;
    cout << "Введите именя пользователя чей блог вы хотите посмотреть" << endl;
    cin >> name;
    for (auto user:users)
        if (user.get_name()==name) {
            cout << user;
            user.print_record_user();
            return;
        }
    cout<<" Пользователь не найден"<<endl;
}

bool  Blog::check_password(string password) {
    return  (password.length() >= 8);
}


void Blog::print_all_record(){
    MList<Record> record_blog;
    if(users.size()==0){
        cout << "Записей пока нет"<<endl;
        return;
    }
    for (auto user:users) {
        MList<Record> ur=user.getRecords();
        for (int i=0; i<ur.size();i++) {
            record_blog.push_back(ur[i]);
        }
    }
    record_blog.sort([](Record &d1, Record &d2) { return d1.get_date() > d2.get_date(); });
    int n=0;
    int v=1;
    while (v) {
        for (int i = n; (i < n + 10) && (i < record_blog.size()); i++) {
            cout << record_blog[i];
        }
        show_line();
        cout<<(record_blog.size()<10);
        if(record_blog.size()<10) return;
        cout << "Перейти на следующую страницу - 1" << endl;
        cout << "Перейти на предыдущую страницу -2 " << endl;
        cout << "Выйти из просмотра архива записей - 0" << endl;
        cin >> v;
        switch (v) {
            case 1:
                n+=10;
                break;
            case 2:
                n-=10;
                break;
            default:
                return;
        }
    }
}


void Blog::edit_user(User u) {
    int v;
    string s;
    cout << "Изменить пароль  пароль - 1" << endl;
    cout << "Изменить интересы - 2" << endl;
    cout << "Изменить почту - 3" << endl;
    cout << "Изменить телефон - 4" << endl;
    cout << "Изменить день рождения - 5" << endl;
    cout << "Изменить информацию о себе - 6" << endl << endl;
    cin >> v;
    switch (v) {
        case 1:
            cout << "Введите пароль"<<endl;
            cin >> s;
            s=cin_password(s);
            u.set_password(s);
            break;
        case 2:
            cout << "Введите свои интересы"<<endl;
            cin>>s;
            u.set_interests(s);
            break;
        case 3:
            cout << "Введите почту"<<endl;
            cin >> s;
            u.set_mail(s);
            break;
        case 4:
            cout << "Введите телефон"<<endl;
            cin >>s;
            u.set_phone(s);
            break;
        case 5:
            cout << "Введите день рождения"<<endl;
            u.set_birthday(s);
            break;
        case 6:
            cout << "Введите информацию о себе"<<endl;
            cin >> s;
            u.set_info(s);
            break;
        default:
            edit_user(u);
            break;
    };

}
void Blog::show_line() {
    cout<<"====================================================================================================="<<endl;
}

bool  Blog::check_nickname(string name) {
    for (auto user:users)
        if(user.get_name()==name) return false;
    return true;
}


string Blog::cin_name(string s){
    while(!check_nickname(s)){
        cout << "Этот никнейм уже занят"<<endl;
        cout<<"Введите никнейм"<<endl;
        cin>>s;
    }
    return s;
}

void Blog::add_new_user(){
    string name,password,interests,mail,phone,birthday,info;
    cout << "Введите никнейм"<<endl;
    cin>>name;
    name=cin_name(name);
    cout<<"Введите пароль";
    cin>>password;
    cin_password(password);
    cout << "Введите свои интересы"<<endl;
    cin>>interests;
    cout << "Введите почту"<<endl;
    cin>>mail;
    cout << "Введите телефон"<<endl;
    cin>>phone;
    cout << "Введите день рождения"<<endl;
    cin>>birthday;
    cout << "Введите информацию о себе"<<endl;
    cin>>info;

    User user = User(get_unique_id(), name, password, interests, mail, phone, birthday, info);
    users.push_back(user);
};

int Blog::get_unique_id(){
    return users.size() ;
};


void Blog::interface(User *user) {
    int v;
    while (v!=7){
        cout << endl<<"Действия с записями - 1"<<endl;
        cout << "Посмотреть свой блог - 2" << endl;
        cout << "Посмотреть архив запесей - 3" << endl;
        cout << "Отредактировать данные о себе - 4" << endl;
        cout << "Посмотреть чужой блог - 5 " << endl;
        cout << "Удалить свой блог - 6 " <<endl;
        cout << "Выйти из аккаунта - 7" << endl << endl;
        cin >> v;
        switch (v){
            case 1:
                show_line();
                user->interface_record(user);
                break;
            case 2:
                show_line();
                print_info_user(*user);
                user->print_record_user();
                break;
            case 3:
                show_line();
                print_all_record();
                break;
            case 4:
                show_line();
                edit_user(*user);
                break;
            case 5:
                show_line();
                look_user_blog();
                break;
            case 6:
                show_line();
                del_user(*user);
                return;
                break;
            case 7:
                show_line();
                break;
            default:
                show_line();
                interface(user);
        }
    }
}
int Blog:: authorization() {
    string login;
    string password;
    cout << "Введите свой логин" << endl;
    cin >> login;
    cout << "Введите пароль" << endl;
    cin >> password;
    int id = check_authorization(login, password);
    if (id != -1) {
        return id;
    } else {
        cout << "Пользователь не найден" << endl;
        cout << "Попробовать еще раз - 1 " << endl;
        cout << "Зарегистрироваться - 2 " << endl;
        cout << "Назад - 3 " << endl;
        int v;
        cin >> v;
        switch (v) {
            case 1:
                return authorization();
            case 2:
                return registrtion();
            case 3:
                break;
            default:
                return authorization();
        };
    }
    return 0;
}

User* Blog:: login() {
    int v;
    int id;
    cout << "Войти - 1" << endl;
    cout << "Зарегистрироваться - 2 " << endl;
    cin >> v;
    switch (v)
    {
        case 1:
            show_line();
            id=authorization();
            break;
        case 2:
            show_line();
            id=registrtion();
            break;
        default:
            show_line();
            break;

    }
    return &users[id];
}

int  Blog::check_authorization(string login, string password){
    for (auto user:users)
        if (login == user.get_name() && password == user.get_password())
            return user.get_id();
    return -1;
}

int Blog::registrtion(){

    string name, password, interest, mail,phone, birhday,info;
    cout << "Введите никнейм"<<endl;
    cin>>name;
    name=cin_name(name);
    cout << "Введите пароль"<<endl;
    cin >>password;
    password=cin_password(password);
    cout << "Введите свои интересы"<<endl;
    cin>>interest;
    cout << "Введите почту"<<endl;
    cin >> mail;
    cout << "Введите телефон"<<endl;
    cin>> phone;
    cout << "Введите день рождения"<<endl;
    cin>>birhday;
    cout << "Введите день информацию о себе"<<endl;
    cin>>info;
    User user(get_unique_id(),name,password,interest,mail,phone,birhday,info);
    users.push_back(user);
    return user.get_id();
}



void Blog::main_loop(){
    int v=1;
    while (v){
        User *user=login();
        show_line();
        interface(user);
        cout<<"Продолжить работу?"<<endl;
        cout<<"ДА - 1"<<endl;
        cout<<"НЕТ - 0 "<<endl;
        cin>> v ;
    }
}


