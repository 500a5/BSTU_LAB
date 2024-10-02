
#ifndef LAB_2_OOP_INTERFACE_H
#define LAB_2_OOP_INTERFACE_H
#include <string>

const int N = 30;
struct  {
    std::string name;
    int ear;
    int time_min;
    std::string adrres;
}film[N];

void interface();
void Tmeny();
void print_name();
void open_film();
void new_film();
void del_film();
void adress_film();

#endif //LAB_2_OOP_INTERFACE_H
