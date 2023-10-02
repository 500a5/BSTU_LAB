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

    printf("��������: \n");
    input(&A);
    printf("1-��\n2-��\n3-��\n4-��\n5-��\n6-��\n7-��\n��� �����: ");
    scanf("%d", &A.week);
    printf("��� �����: ");
    output(A.week);
    printf("----------------------------------------\n");

    printf("����������: \n");
    input(&B);

    int w;

    w = search_week(&A, &B);

    printf("�����: ");
    output(A.week + w);

    return 0;
}

void input(t_date *A){
    printf("������� ����: \n");
    printf("----------------------------------------\n");
    printf("�����: ");
    scanf("%d", &(A->day));
    printf("�����: ");
    scanf("%d", &(A->month));
    printf("���: ");
    scanf("%d", &(A->year));
}

void output(int w){
        switch( w ){
        case 1: printf("�����������\n");
                break;
        case 2: printf("�������\n");
                break;
        case 3: printf("�����\n");
                break;
        case 4: printf("�������\n");
                break;
        case 5: printf("�������\n");
                break;
        case 6: printf("�������\n");
                break;
        case 7: printf("�����������\n");
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
        a = day_year(&A);/* A ���������� ����� ��� � ���� */
        b = day_year(&B);/* B ���������� ����� ��� � ���� */

    }
    else {
        year1 = B->year;
        year2 = A->year;
        a = day_year(&B);/* A ���������� ����� ��� � ���� */
        b = day_year(&A);/* B ���������� ����� ��� � ���� */
    }


    S = b/* � ��� b � ����������� �� ���� (����������) */;

    for (i = year2/*���������� ���*/; i > year1/*���������� ���*/; i--){

        S = S + testYear(i);

    }

    w = abs(S + testYear(i) - a/* a ��� b (����������) */) % 7;


    return w;
}

int day_year(t_date *A){
    int S = 0;//
    int i;//������� ������
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
