#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct t_date{
    int day, month, year, week;
} t_date;

void input(t_date *);
int search_week(t_date *A, t_date *B);
void plus(t_date *A);
void minus(t_date *A);
int comparison(t_date A, t_date B);
void output(int w);

int main()
{
    setlocale(LC_ALL, "Rus");

    struct t_date A, B;


    printf("Известно: \n");
    input(&A);
    printf("1-Пн\n2-Вт\n3-Ср\n4-Чт\n5-Пт\n6-Сб\n7-Вс\nВаш выбор: ");
    scanf("%d", &A.week);
    printf("Ваш выбор: ");
    output(A.week);
    printf("----------------------------------------\n");


    printf("Определить: \n");
    input(&B);


    int w;
    w = search_week(&A, &B);

    printf("----------------------------------------\n");
    printf("Ответ: ");

    output(w);

    return 0;
}

void input(t_date *A){
    printf("Введите дату: \n");
    printf("----------------------------------------\n");
    printf("Число: ");
    scanf("%d", &(A->day));
    printf("Месяц: ");
    scanf("%d", &(A->month));
    printf("Год: ");
    scanf("%d", &(A->year));
}

int search_week(t_date *A, t_date *B){


    while ( ((A->year) != (B->year)) || ((A->month) != (B->month)) || ((A->day) != (B->day)) ){
        int t;
        t = comparison(*A, *B);

        if (t < 0)
            plus(A);
        else
            minus(A);
    }
    return A->week;
}

int comparison(t_date A, t_date B){

    if( A.year == B.year){
        if (A.month == B.month){
            if (A.day == B.day)
                return 0;
            else
                if(A.day > B.day)
                    return 1;
                else
                    return -1;
        }
        else if (A.month > B.month)
            return 1;
        else return -1;
    }
    else if (A.year > B.year)
                return 1;
    else return -1;

}

void plus(t_date *A){
    (A->week)++;
    if (A->week == 8)
        A->week = 1;
    (A->day)++;
    if ( A->day > 28 ){
        if( (A->month == 2) && ((A->year % 4) != 0) && (A->day == 29)){
            A->day = 1;
            A->month++;
            if ( A->month == 13 ){
                A->year++;
                A->month = 1;
            }
        }
        if ( (A->month == 2) && ((A->year % 4) == 0) && ((A->year % 100) != 0) && (A->day == 30) ){
            A->day = 1;
            (A->month)++;
            if ( A->month == 13 ){
                (A->year)++;
                A->month = 1;
            }
        }

        if ( (A->day == 31) && ( A->month == (4 || 6 || 9 || 11)) ){
            A->day = 1;
            A->month++;
            if ( A->month == 13 ){
                (A->year)++;
                A->month = 1;
            }
        }

        if (A->day == 32){
            A->day = 1;
            A->month++;
            if ( A->month == 13 ){
                A->year++;
                A->month = 1;
            }
        }

    }
}

void minus(t_date *A){
    A->day--;
    A->week--;

    if (A->day == 0){
        if (A->month == 2){
            if ( ((A->year % 4) == 0) && ((A->year % 100) != 0) ){
                A->day = 29;
            }
            else {
                A->day = 28;
            }
        }
        if ( A->month == (4 || 6 || 9 || 11) ){
            A->day = 30;
    } else {
            A->day = 31;
      }
    }
    A->month--;
    if (A->month = 0){
        A->year--;
        A->month = 12;
    }
}

void output(int w){
        switch( w ){
        case 1: printf("Понедельник\n");
                break;
        case 2: printf("Вторник\n");
                break;
        case 3: printf("Среда\n");
                break;
        case 4: printf("Четверг\n");
                break;
        case 5: printf("Пятница\n");
                break;
        case 6: printf("Суббота\n");
                break;
        case 7: printf("Воскресенье\n");
                break;
    }
}
