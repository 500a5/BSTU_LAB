#include "v_55.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

double fun(double x, double y) //функция варианта
{
    return 2*x*sin(x)+y/tan(x);
}

void getmem_matr(Matr *a, int m, int n) //выделение памяти
 {
     a->a=(double**)calloc(m,sizeof(double*));
     int i;
     for (i=0; i<m; i++)
        a->a[i]= (double *) calloc(n,sizeof(double));
     a->m = m;
     a->n = n;
 }

void printMatr(Matr A)
{
    int i ,j;
    printf("\n");
    for (i=0; i<A.m; i++)
    {
        for (j=0; j<A.n; j++)
            printf(" %lf",A.a[i][j]);
        printf("\n");
    }
 }

void freemem_matr(Matr *a) //освбождение памяти
{
    int i;
    for (i=0; i<a->m; i++)
        free(a->a[i]);
    free(a->a);
}


/*Решение задачи коши методом Рунге-Кутты, где
f - функция (первая произовдая) , a(b)- нижняя(верхняя) граница x , eps - точность ,
 y0 - начальное условие задачи Коши , n-количество на сколько разбивается отрезок */
double cauchyRK(func_f f, Matr *yOut, double a, double b , double y0, double n)
 {
     freemem_matr(yOut);
     getmem_matr(yOut, n+1, 2);
     double y=y0, x=a, k1, k2, k3, k4, h=(b-a)/n;
     yOut->a[0][1]=y0;
     yOut->a[0][0]=a;
     int i;
     for (i=0; i<n; i++)
     {
         k1 = f(x, y);
         k2 = f(x+h/2, y+h/2*k1);
         k3 = f(x+h/2, y+h/2*k2);
         k4 = f(x+h, y+h*k3);
         x+=h;
         y+=h/6*(k1+2*k2+2*k3+k4);
         yOut->a[i][0]=x;
         yOut->a[i][1]=y;
     }
  return y;
 }

double cauchyEul(func_f f, Matr *yOut, double a, double b, double y0, double n)
{
     freemem_matr(yOut);
     getmem_matr(yOut, n+1, 2);
     double y=y0, x=a, h=(b-a)/n;
     yOut->a[0][1]=y0;
     yOut->a[0][0]=a;
     int i;
     for (i=1; i<=n; i++)
     {
         y+=h*f(x, y);
         x+=h;
         yOut->a[i][0]=x;
         yOut->a[i][1]=y;
     }
 return y;
}

double cauchyEC(func_f f , Matr *yOut, double a, double b , double y0, double n)
{
     freemem_matr(yOut);
     getmem_matr(yOut, n+1, 2);
     double y=y0, x=a, h=(b-a)/n, fi;
     yOut->a[0][1]=y0;
     yOut->a[0][0]=a;
     int i;
     for (i=1; i<=n; i++)
     {
         fi=f(x, y);
         y+=h/2*(fi+f(x+h, y+h*fi));
         x+=h;
         yOut->a[i][0]=x;
         yOut->a[i][1]=y;
     }
 return y;
}

double cauchyECM(func_f f, Matr *yOut, double a, double b, double y0, double n)
{
     freemem_matr(yOut);
     getmem_matr(yOut, n+1, 2);
     double y=y0, x=a, h=(b-a)/n;
     yOut->a[0][1]=y0;
     yOut->a[0][0]=a;
     int i;
     for (i=1; i<=n; i++)
     {
         y+=h*f(x+h/2, y+h/2*f(x, y));
         x+=h;
         yOut->a[i][0]=x;
         yOut->a[i][1]=y;
     }
 return y;
}

double cauchy(func_f f, int m, Matr *yOut, double a, double b, double y0, double n, double eps)
{
    int p;
    double (*f1)(func_f f, Matr *yOut, double a, double b, double y0, double n ) ;
    switch (m)
    {
        case 1:
            p=1;
            f1 = cauchyEul;
        break;

        case 2:
            p=2;
            f1 = cauchyEC;
        break;

        case 3:
            p=2;
            f1 = cauchyECM;
        break;

        case 4:
            p=4;
            f1 = cauchyRK;
        break;
    }
     double yh = f1(f, yOut, a, b, y0, n);
     n = 2*n;
     double yh_2 = f1( f, yOut, a , b , y0 , n );
     double eps1 = fabs(yh - yh_2)/(pow(2,p)-1);
     while (eps1>eps)
     {
         yh = yh_2;
         n = 2*n;
         yh_2 = f1( f, yOut, a , b , y0 , n );
         eps1 = fabs(yh - yh_2)/(pow(2,p)-1);
     }
    return yh+(yh - yh_2)/(pow(2,p)-1);
}

void printFL (Matr a)
{
    FILE *S1;
    S1 = freopen("Rez1.txt", "w", stdout);
    printMatr(a);
    fclose(S1);
}
