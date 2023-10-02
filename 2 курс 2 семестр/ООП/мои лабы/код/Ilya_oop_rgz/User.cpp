
#include "User.h"

string User:: get_name() {return nickname;}
string User::get_password() {return password;}
string User::get_interests() {return interests;}
string User::get_mail() {return mail;}
string User::get_phone() {return phone;}
string User::get_birthday() {return birthday;}
string User::get_info() {return info;}
int User::get_id() {return id;}

void User::set_id(int id){ this->id=id;}
void User::set_name(string nickname){this->nickname = nickname;}
void User::set_password(string password){this->password = password;}
void User::set_mail(string mail){this->mail = mail;}
void User::set_interests(string interests){this->interests = interests;}
void User::set_phone(string phone){this->phone=phone;}
void User::set_info(string info) {this->info = info;}
void User::set_birthday(string birthday) {this->birthday = birthday;}

int User::get_unique_rec_id(){
    return rand() ;
};

void User::add_record(string title, string text) {
    Record record=Record(get_unique_rec_id(), get_id(), title, text,get_name());
    records.push_front(record);
};

void User::interface_create_record() {
    string title,text;
    cout <<"������ �������� �����" <<endl;
    cin >> title;
    cout << "������ ⥪�� �����"<<endl;
    cin >>text;
    add_record(title,text);
}

int User::search_record_id(string name_record){
    for (auto record:records) {
        if(record.get_title()==name_record){
            return record.get_id();
        }
    }
    return -1;
}

int User::search_record_i(string name_record) {
    int i=0;
    for (auto record:records) {
        if(record.get_title()!=name_record){
            i++;
        }
    }
    if(records.size()<i){ return -1;}
    return i;
}

void User::show_line() {
    cout<<"====================================================================================================="<<endl;
}

void User::edit_record(){
    string title,text;
    cout <<"������ �������� ����� ������ ��� ��������" <<endl;
    cin >> title;
    int i_record=search_record_i(title);
    if(i_record==-1){
        cout<<"������ �� �������"<<endl;
        return;
    }
    cout<<"������ ����� ��� �����"<<endl;
    cin>>title;
    records[i_record].set_title(title);
    cout << "������ ⥪�� �����"<<endl;
    cin >>text;
    records[i_record].set_text(text);
}

void User:: delete_record(){
    string title;
    cout<<"������� �������� ����� ������ ���� 㤠����"<<endl;
    cin>>title;
    int id_record=search_record_id(title);
    if(id_record==-1){
        cout<<"������ �� �������"<<endl;
        return;
    }
    int index=0;
    for (auto record:records) {
        if(record.get_id()!=id_record) index++;
        else break;
    }
    auto it = records.begin();
    advance(it,index);
    records.erase(it);
}

std::ostream& operator<< (std::ostream &out, const User &user) {
    out << "���: " << user.nickname << endl;
    out << "������: " << user.interests << endl;
    out << "����: " << user.mail << endl;
    out << "���e���:  " << user.interests << endl;
    out << "���� ஦�����: " << user.birthday<< endl;
    out << "���ଠ�� � ���짮��⥫�: " << user.info << endl;
    return out;
}
void User::interface_look_unlook_comment(){
    cout<< "������ ��� ����� � ���ன ��� �������� ��ࠬ��� �������஢����"<<endl;
    string title;
    cin>>title;
    int i_record=search_record_i(title);
    if(i_record==-1){
        cout<<"������ �� �������"<<endl;
        return;
    }
    records[i_record].look_unlook_comment();
}


void User::print_record_user() {
    for (auto record:records) {
        cout<<record<<endl;
    }
}

void User::interface_add_coment(User u){
    string title;
    cout << "������ �������� ����� � ���ன ��� ��⠢��� �������਩"<<endl;
    cin >> title;
    int i_record=search_record_i(title);
    if(i_record==-1){
        cout<<"������ �� �������"<<endl;
        return;
    }
    if(records[i_record].get_coment()){
        records[i_record].add_comment(get_id(),u.get_name());
    } else{
        cout <<"� �⮩ ����� ����� ��⠢��� �������਩"<<endl;
    }
}

void User::interface_del_comment() {
    string title, name, text;
    cout << "������ ��� ����� � ���ன ��� 㤠���� �������਩ " << endl;
    cin >> title;
    int q=0;
    int i_r = search_record_i(title);
    if(i_r==-1){
        cout<<"������ �� �������"<<endl;
        return;
    }
    MList<Commentaire> *commentss = records[i_r].getCommends();
    for (auto com:*commentss) {
        q++;
        cout<<"�������਩:"<< q<<endl<<com<<endl;
    }
    cout << "������ ����� �������ࠨ� ����� ��� 㤠���� " << endl;
    cin >> q;
        auto it = commentss->begin();
        advance(it, q-1);
        commentss->erase(it);
}

void User:: interface_record(User *user){
    int v;
    cout << endl<<"������� ����� ������ - 1" << endl;
    cout << "��।���஢��� ������ - 2" << endl;
    cout << "������� ������ - 3" << endl;
    cout << "������� �������਩ � ����� - 4" << endl;
    cout<<"������� �������਩ � ����� - 5" << endl;
    cout << "����������� ��⠢���� �������ਨ   �����-6 " << endl;
    cout<<"�������� ����� - 7"<<endl<<endl;
    cin>>v;
    switch (v){
        case 1:
            show_line();
            interface_create_record();
            break;
        case 2:
            show_line();
            edit_record();
            break;
        case 3:
            show_line();
            delete_record();
            break;
        case 4:
            show_line();
            interface_add_coment(*user);
            break;
        case 5:
            show_line();
            interface_del_comment();
            break;
        case 6:
            show_line();
            interface_look_unlook_comment();
            break;
        case 7:
            show_line();
            break;
        default:
            show_line();
            interface_record(user);
            break;
    }
}
MList<Record> User ::getRecords() {
    return  records;
}