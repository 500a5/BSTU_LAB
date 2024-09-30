

#ifndef RGZ_COMMENT_H
#define RGZ_COMMENT_H
#include <string>
#include <time.h>
#include <stdio.h>

using namespace std;
class Commentaire {
    int author_id;
    string text;
    string date;
    string name_author;
    int id_com;
public:
    Commentaire(int id, string name, string text, int id_com){
        this->author_id = id;
        this->text = text;
        this->name_author=name;
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        this->date = asctime(timeinfo);
        this->id_com=id_com;
    };
    string get_name_autor();
    int get_author_id();
    string get_date();
    string get_text();

    friend std::ostream& operator<< (std::ostream &out, const Commentaire &comm);
};


#endif //RGZ_COMMENT_H
