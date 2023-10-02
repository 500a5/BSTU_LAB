
#include "Record.h"

string Record::get_title() {return title;}
string Record::get_date() {return date;}
string Record::get_text() {return text;}

void Record::set_title(string title) {this->title=title;}
void Record::set_text(string text) {this->text;}


void Record::look_unlook_comment() {
    coment = !coment;
}

int Record::get_id(){ return id;}
int Record::get_author_id() { return author_id;}
string Record::get_name_autor() { return name_autor;}
bool Record::get_coment() { return  coment;}

std::ostream& operator<< (std::ostream &out, const Record &rec) {
    out <<"         "<< "<" << rec.title << ">" << endl;
    out << "     " << rec.date;
    out << "     " << rec.name_autor<<":"<<endl;
    out << "  " << rec.text << endl << endl;
    out << " Комментарии:" << endl;
    for (auto com: rec.comments) {
        out << com;
    }
    return out;
}

MList<Commentaire> *Record::getCommends(){
    return &comments;
}
int Record::get_unique_com_id(){
    return rand() ;
};
void Record::add_comment(int id_user, string name_user){
    string text;
    cout<<"Введите коммментарий"<<endl;
    cin >> text;

    Commentaire comment = Commentaire(id_user, name_user, text, get_unique_com_id());;
    comments.push_front(comment);
}

