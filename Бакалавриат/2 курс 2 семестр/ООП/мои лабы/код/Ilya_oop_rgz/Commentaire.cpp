

#include "Commentaire.h"
#include <iostream>


int Commentaire::get_author_id() {
    return author_id;
}
string Commentaire::get_date() {
    return date;
}
string Commentaire::get_text() {
    return text;
}

string Commentaire::get_name_autor() {
    return name_author;
}
std::ostream& operator<< (std::ostream &out, const Commentaire &comm) {
    out << "   "<<comm.name_author << ":"<<"\n"<< "   "<< comm.date << "     " << comm.text << endl;
    return out;
}