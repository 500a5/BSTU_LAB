#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct t_date{
    int day, month, year, week;
} t_date;

void input(t_date *A);
void output(int w);
int testYear(int year);
int comparison(t_date A, t_date B);

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

    printf("Ответ: ");
    output(A.week + w);

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

int search_week(t_date *A, t_date *B){
    int a, b, S, w;
    int i, t;
    int year1, year2;

    t = comparison(*A, *B);

    if ( t > 0 ){
        year1 = A->year;
        year2 = B->year;
        a = day_year(&A);/* A определить номер дня в году */
        b = day_year(&B);/* B определить номер дня в году */

    }
    else {
        year1 = B->year;
        year2 = A->year;
        a = day_year(&B);/* A определить номер дня в году */
        b = day_year(&A);/* B определить номер дня в году */
    }


    S = b/* а или b в зависимости от года (наибольший) */;

    for (i = year2/*наибольший год*/; i > year1/*наименьший год*/; i--){

        S = S + testYear(i);

    }

    w = abs(S + testYear(i) - a/* a или b (наименьший) */) % 7;


    return w;
}

int day_year(t_date *A){
    int S = 0;//
    int i;//счётчик месяца
    for (i = 1; i < (A->month); i++){
        if ( i == (1||3||5||7||8||10||12) )
            S = S + 31;
        else
            if ( i == 2 )
                if ( ((A->year % 4) == 0) && ((A->year % 100) != 0) )
                    S = S + 29;
                else
                    S = S + 28;
            else S = S + 30;
    }
    S = S + (A->day);
    return S;
}

int testYear(int year){
    if (((year % 4) == 0) && ((year % 100) != 0))
        return 366;
    else
        return 365;
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
