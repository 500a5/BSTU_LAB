#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vi6.h"

float func_var(float x)
{    return (x+exp(1.5*x))*(x+1);   }


int main()
{
    float a = -1, b = -0.352;
    float eps, y;

    printf("eps >> ");
    scanf("%f", &eps);
    printf("\n");

    printf("Opt Poisk: \n");
    y = OptPoisk(func_var, a, b, eps);
    printf("min (f(x)) = %f", y);
    printf("\n");


    printf("Del Ort: \n");
    y = DelOtr(func_var, a, b, eps);
    printf("min (f(x)) = %f", y);
    printf("\n");

    printf("Met Fibonn: \n");
    y = MetFib(func_var, a, b, eps);
    printf("min (f(x)) = %f", y);
    printf("\n");

    return 0;
}
