#include <stdio.h>
#include <stdlib.h>
#include "v_55.h"

int main()
{
    Matr a;
    int m, n;
    printf("Input n >> ");
    scanf("%d",&n);
    double eps, an = 1.5707963, bn = 2.5707963, yo = 0;
    getmem_matr(&a, n+1, 2); //סעמכבצמג גסודהא 2
    printf("Input eps >> ");
    scanf("%lf",&eps);
    printf("1 - Eiler \n");
    printf("2 - Eiler-Koshi \n");
    printf("3 - Modific Eiler-Koshi \n");
    printf("4 - Runge-Kutta \n");
    printf("Input method >> ");
    scanf("%d",&m);
   // printf("Input n >> ");
   // scanf("%d",&n);
    printf("y = %lf\n", cauchy(fun, m, &a, an, bn, yo, n, eps));
    printFL(a);
    return 0;
}
