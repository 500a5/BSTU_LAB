
#include "Blog.h"





void Blog::print_info_user(User u) {
    cout<< u;
}

string Blog::cin_password(string s){
    while(!check_password(s)){
        cout<<"��஫� ���즥�� ���� ������  8 ������"<<endl;
        cout<<"������ ��஫�"<<endl;
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
    cout << "������ ����� ���짮��⥫� 祩 ���� �� ��� ��ᬮ����" << endl;
    cin >> name;
    for (auto user:users)
        if (user.get_name()==name) {
            cout << user;
            user.print_record_user();
            return;
        }
    cout<<" ���짮��⥫� �� ������"<<endl;
}

bool  Blog::check_password(string password) {
    return  (password.length() >= 8);
}


void Blog::print_all_record(){
    MList<Record> record_blog;
    if(users.size()==0){
        cout << "����ᥩ ���� ���"<<endl;
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
        cout << "��३� �� ᫥������ ��࠭��� - 1" << endl;
        cout << "��३� �� �।����� ��࠭��� -2 " << endl;
        cout << "��� �� ��ᬮ�� ��娢� ����ᥩ - 0" << endl;
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
    cout << "�������� ��஫�  ��஫� - 1" << endl;
    cout << "�������� ������ - 2" << endl;
    cout << "�������� ����� - 3" << endl;
    cout << "�������� ⥫�䮭 - 4" << endl;
    cout << "�������� ���� ஦����� - 5" << endl;
    cout << "�������� ���ଠ�� � ᥡ� - 6" << endl << endl;
    cin >> v;
    switch (v) {
        case 1:
            cout << "������ ��஫�"<<endl;
            cin >> s;
            s=cin_password(s);
            u.set_password(s);
            break;
        case 2:
            cout << "������ ᢮� ������"<<endl;
            cin>>s;
            u.set_interests(s);
            break;
        case 3:
            cout << "������ �����"<<endl;
            cin >> s;
            u.set_mail(s);
            break;
        case 4:
            cout << "������ ⥫�䮭"<<endl;
            cin >>s;
            u.set_phone(s);
            break;
        case 5:
            cout << "������ ���� ஦�����"<<endl;
            u.set_birthday(s);
            break;
        case 6:
            cout << "������ ���ଠ�� � ᥡ�"<<endl;
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
        cout << "��� ������� 㦥 �����"<<endl;
        cout<<"������ �������"<<endl;
        cin>>s;
    }
    return s;
}

void Blog::add_new_user(){
    string name,password,interests,mail,phone,birthday,info;
    cout << "������ �������"<<endl;
    cin>>name;
    name=cin_name(name);
    cout<<"������ ��஫�";
    cin>>password;
    cin_password(password);
    cout << "������ ᢮� ������"<<endl;
    cin>>interests;
    cout << "������ �����"<<endl;
    cin>>mail;
    cout << "������ ⥫�䮭"<<endl;
    cin>>phone;
    cout << "������ ���� ஦�����"<<endl;
    cin>>birthday;
    cout << "������ ���ଠ�� � ᥡ�"<<endl;
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
        cout << endl<<"����⢨� � �����ﬨ - 1"<<endl;
        cout << "��ᬮ���� ᢮� ���� - 2" << endl;
        cout << "��ᬮ���� ��娢 ����ᥩ - 3" << endl;
        cout << "��।���஢��� ����� � ᥡ� - 4" << endl;
        cout << "��ᬮ���� �㦮� ���� - 5 " << endl;
        cout << "������� ᢮� ���� - 6 " <<endl;
        cout << "��� �� ������ - 7" << endl << endl;
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
    cout << "������ ᢮� �����" << endl;
    cin >> login;
    cout << "������ ��஫�" << endl;
    cin >> password;
    int id = check_authorization(login, password);
    if (id != -1) {
        return id;
    } else {
        cout << "���짮��⥫� �� ������" << endl;
        cout << "���஡����� �� ࠧ - 1 " << endl;
        cout << "��ॣ����஢����� - 2 " << endl;
        cout << "����� - 3 " << endl;
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
    cout << "���� - 1" << endl;
    cout << "��ॣ����஢����� - 2 " << endl;
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
    cout << "������ �������"<<endl;
    cin>>name;
    name=cin_name(name);
    cout << "������ ��஫�"<<endl;
    cin >>password;
    password=cin_password(password);
    cout << "������ ᢮� ������"<<endl;
    cin>>interest;
    cout << "������ �����"<<endl;
    cin >> mail;
    cout << "������ ⥫�䮭"<<endl;
    cin>> phone;
    cout << "������ ���� ஦�����"<<endl;
    cin>>birhday;
    cout << "������ ���� ���ଠ�� � ᥡ�"<<endl;
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
        cout<<"�த������ ࠡ���?"<<endl;
        cout<<"�� - 1"<<endl;
        cout<<"��� - 0 "<<endl;
        cin>> v ;
    }
}


