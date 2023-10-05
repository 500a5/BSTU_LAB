#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mod_niut.h"

void main()
{
    setlocale(LC_ALL,"Rus");
    printf("В какой точке: ");
    float x;
    scanf("%f", &x);

    printf("Кол-во точек: ");
    int n, ch;
    scanf("%d", &n);

    tochka *a = (tochka*)calloc(n, sizeof(tochka));
    input(a, n);

    printf("Введено: \n");
    output(a, n);

    ch = checc(a, n);
   // printf("%d\n", ch);
    float *koef, rez, tmp1;
    int i;

    if (ch)
    {
        koef = end_razn(a, n, x);
        rez = a[0].y;
        for (i=1; i<n; i++)
        {
            tmp1 =(koef[i-1]* RECend_razn(a, i, 0)) / fact(i);
            rez +=tmp1;
        }
    }
    else
    {
        koef = del_razn(a, n, x);
        rez = a[0].y;
        for (i=1; i<n; i++)
        {
            tmp1 =(koef[i-1]* RECdel_razn(a, i, 0));
            rez +=tmp1;
        }
    }

    printf("Значение в точке x = %lf\n", rez);
    free(a);
}
