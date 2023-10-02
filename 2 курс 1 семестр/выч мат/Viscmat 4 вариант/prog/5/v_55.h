#ifndef V_55_H_INCLUDED
#define V_55_H_INCLUDED

#include <stdlib.h>
#include <math.h>
typedef struct
{
    double **a;
    int m, n;
} Matr;

typedef double(*func_f)(double, double);
double fun(double x, double y);


void getmem_matr(Matr *a, int m, int n);
void freemem_matr(Matr *a);

/*������� ������ ���� ������� �����-�����, ���
f - ������� (������ ����������) , a(b)- ������(�������) ������� x , eps - �������� ,
 y0 - ��������� ������� ������ ���� , n-���������� �� ������� ����������� ������� */
double cauchyRK(func_f f, Matr *yOut, double a, double b , double y0, double n);

/*������� ������ ���� ������� ������ */
double cauchyEul(func_f f, Matr *yOut, double a, double b, double y0, double n);

/*������� ������ ���� ������� ������-����*/
double cauchyEC(func_f f , Matr *yOut, double a, double b , double y0, double n);

/*������� ������ ���� ������� ������-���� ����������������*/
double cauchyECM(func_f f, Matr *yOut, double a, double b, double y0, double n);

double cauchy(func_f f, int m, Matr *yOut, double a, double b, double y0, double n, double eps);

void printFL (Matr a);

#endif
