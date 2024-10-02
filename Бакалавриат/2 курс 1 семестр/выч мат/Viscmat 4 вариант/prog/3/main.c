#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "mod.h"

void main()
{
    setlocale(LC_ALL, "Rus");
    printf("Интеграл 1/x*x; [0,2, 1]\n");
   /* printf("Центральные прямоугольники\n");
    printf("   Значение: %f #", CentrPry(fun_1, 0.2, 1, 8));
    printf(" Точность: %f \n", RungeCentrPry(fun_1, 0.2, 1, 8));
    printf("Трапеции\n");
    printf("   Значение: %f #", Trap(fun_1, 0.2, 1, 8));
    printf(" Точность: %f \n", RungeTrap(fun_1, 0.2, 1, 8));
    printf("Параболы (Симпсона)\n");
    printf("   Значение: %f #", Simp(fun_1, 0.2, 1, 2));
    printf(" Точность: %f \n", RungeSimp(fun_1, 0.2, 1, 2));*/

    printf("Гаусс)\n");
    printf("   Значение: %f #", Gauss(fun_1, 0.2, 1, 2));
  //  printf(" Точность: %f \n", RungeSimp(fun_1, 0.2, 1, 2));

   /* printf("\n");

    printf("Интеграл cos(2x); [0, pi/3]\n");
    printf("Центральные прямоугольники\n");
    printf("   Значение: %f #", CentrPry(fun_2, 0, M_PI/3, 8));
    printf(" Точность: %f \n", RungeCentrPry(fun_2, 0, M_PI/3, 8));
    printf("Трапеции\n");
    printf("   Значение: %f #", Trap(fun_2, 0, M_PI/3, 8));
    printf(" Точность: %f \n", RungeTrap(fun_2, 0, M_PI/3, 8));
    printf("Параболы (Симпсона)\n");
    printf("   Значение: %f #", Simp(fun_2, 0, M_PI/3, 4));
    printf(" Точность: %f \n", RungeSimp(fun_2, 0, M_PI/3, 4));
    printf("\n");

    printf("Интеграл 5^x; [0, 2]\n");
    printf("Центральные прямоугольники\n");
    printf("   Значение: %f #", CentrPry(fun_3, 0, 2, 8));
    printf(" Точность: %f \n", RungeCentrPry(fun_3, 0, 2, 8));
    printf("Трапеции\n");
    printf("   Значение: %f #", Trap(fun_3, 0, 2, 8));
    printf(" Точность: %f \n", RungeTrap(fun_3, 0, 2, 8));
    printf("Параболы (Симпсона)\n");
    printf("   Значение: %f #", Simp(fun_3, 0, 2, 4));
    printf(" Точность: %f \n", RungeSimp(fun_3, 0, 2, 4));*/
}
