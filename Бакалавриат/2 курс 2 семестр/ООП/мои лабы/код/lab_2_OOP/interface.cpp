#include "interface.h"
#include <iostream>
int M=0;
void print_name() {
    /*
    scanf("%s", &film[M].name);
    printf("%s", film[M].name);
    */
}
void Tmeny() {
    printf("Открыть фильм - 1\n");
    printf("Добавить фильм - 2\n");
    printf("Удалить фильм - 3\n");
    printf("Показать расположение фильма - 4\n");
    printf("Выйти из фильмотеки - 5\n");
}

void open_film() {

}
void new_film() {

    M++;
    printf("Введите название фильма");
    scanf("%s", &film[M].name);
    printf("Введите год выпуска фильма");
    scanf("%d", &film[M].ear);
    printf("Введите продолжительность фильма в минутах");
    scanf("%d", &film[M].time_min);
    printf("ВВедите место хранение файла");
    scanf("%s", &film[M].adrres);
    return;
}
void del_film() {

}
void adress_film() {
}
void  interface() {
    int k;
    Tmeny();
    scanf("%d", &k);
    while (k!=5) {
        switch (k)
        {
            case 1:
                open_film();
                break;
            case 2:
                new_film();
                break;
            case 3:
                del_film();
                break;
            case 4:
                adress_film();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("ВВедена неверная команда");
                break;
        }

        scanf("%d", &k);
    }

}
