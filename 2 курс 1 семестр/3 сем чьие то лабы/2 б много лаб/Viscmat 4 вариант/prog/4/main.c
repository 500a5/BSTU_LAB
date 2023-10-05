#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "mod_4.h"

float fxy (float x, float y)
    {return (cos(x)+2*y-2);}
float gxy (float x, float y)
    {return (pow(x, 2)+pow(y, 2)-1);}
float df__dx (float x)
    {return -sin(x);}
float df__dy (float y)
    {return 2;}
float dg__dx (float x)
    {return 2*x;}
float dg__dy (float y)
    {return 2*y;}


void main()
{
    setlocale(LC_ALL, "Rus");
    printf(">> М[0]: ");
    float x0, y0;
    scanf("%f %f", &x0, &y0);
    printf(">> n: ");
    int n;
    scanf("%d", &n);
    printf(">> eps: ");
    float epsil;
    scanf("%f", &epsil);
    printf("\n");
    int b = booll(fxy, df__dx, df__dy, gxy, dg__dx, dg__dy, &x0, &y0, epsil, n);
    if (b)
        printf("M[0](%f, %f) является точкой пересечения", x0, y0);
    else
        printf("M[0](%f, %f) не является точкой пересечения", x0, y0);
}
