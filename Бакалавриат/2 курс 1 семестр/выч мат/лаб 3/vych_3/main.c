#include <stdio.h>
#include <math.h>
#include "calculation_of_integrals.h"

float fun1(float x)
{
    return (pow(x,4)+1);
}

float fun2(float x)
{
    return (cosf(2*x));
}
float fun3(float x)
{
    return (pow(5,x));
}
int main()
{


    float output, program;
    float calc = (float)96/10;
    int n;

    output = pryamougolnik(fun1, -1, 2, 8, 0.01);
    printf("По формуле центральных (средних) прямоугольников:  %f\n", output);

    output = trapeze(fun1, -1, 2, 8, 0.01);
    printf("По формуле трапеций:  %f\n", output);

    output = parabola(fun1, -1, 2, 8, 0.01);
    printf("По формуле парабол (Симпсона):  %f\n", output);

    printf("\nВвод n: ");
    scanf("%i", &n);
    program = gauss(fun1, -1, 2, n);

    printf("\nТочное значение  = %lf\n", calc);
    printf("Гаусом = %f\n", program);

    printf("Абс: %f\n", fabs(program - calc));
    printf("Отн: %f %% \n", fabs(program - calc) / calc * 100);
}

