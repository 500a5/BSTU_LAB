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

/*–ешение задачи коши методом –унге- утты, где
f - функци€ (перва€ произовда€) , a(b)- нижн€€(верхн€€) граница x , eps - точность ,
 y0 - начальное условие задачи  оши , n-количество на сколько разбиваетс€ отрезок */
double cauchyRK(func_f f, Matr *yOut, double a, double b , double y0, double n);

/*–ешение задачи коши методом Ёйлера */
double cauchyEul(func_f f, Matr *yOut, double a, double b, double y0, double n);

/*–ешение задачи коши методом Ёйлера- оши*/
double cauchyEC(func_f f , Matr *yOut, double a, double b , double y0, double n);

/*–ешение задачи коши методом Ёйлера- оши модифицированный*/
double cauchyECM(func_f f, Matr *yOut, double a, double b, double y0, double n);

double cauchy(func_f f, int m, Matr *yOut, double a, double b, double y0, double n, double eps);

void printFL (Matr a);

#endif
