#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "mod.h"

void main()
{
    setlocale(LC_ALL, "Rus");
    printf("�������� 1/x*x; [0,2, 1]\n");
   /* printf("����������� ��������������\n");
    printf("   ��������: %f #", CentrPry(fun_1, 0.2, 1, 8));
    printf(" ��������: %f \n", RungeCentrPry(fun_1, 0.2, 1, 8));
    printf("��������\n");
    printf("   ��������: %f #", Trap(fun_1, 0.2, 1, 8));
    printf(" ��������: %f \n", RungeTrap(fun_1, 0.2, 1, 8));
    printf("�������� (��������)\n");
    printf("   ��������: %f #", Simp(fun_1, 0.2, 1, 2));
    printf(" ��������: %f \n", RungeSimp(fun_1, 0.2, 1, 2));*/

    printf("�����)\n");
    printf("   ��������: %f #", Gauss(fun_1, 0.2, 1, 2));
  //  printf(" ��������: %f \n", RungeSimp(fun_1, 0.2, 1, 2));

   /* printf("\n");

    printf("�������� cos(2x); [0, pi/3]\n");
    printf("����������� ��������������\n");
    printf("   ��������: %f #", CentrPry(fun_2, 0, M_PI/3, 8));
    printf(" ��������: %f \n", RungeCentrPry(fun_2, 0, M_PI/3, 8));
    printf("��������\n");
    printf("   ��������: %f #", Trap(fun_2, 0, M_PI/3, 8));
    printf(" ��������: %f \n", RungeTrap(fun_2, 0, M_PI/3, 8));
    printf("�������� (��������)\n");
    printf("   ��������: %f #", Simp(fun_2, 0, M_PI/3, 4));
    printf(" ��������: %f \n", RungeSimp(fun_2, 0, M_PI/3, 4));
    printf("\n");

    printf("�������� 5^x; [0, 2]\n");
    printf("����������� ��������������\n");
    printf("   ��������: %f #", CentrPry(fun_3, 0, 2, 8));
    printf(" ��������: %f \n", RungeCentrPry(fun_3, 0, 2, 8));
    printf("��������\n");
    printf("   ��������: %f #", Trap(fun_3, 0, 2, 8));
    printf(" ��������: %f \n", RungeTrap(fun_3, 0, 2, 8));
    printf("�������� (��������)\n");
    printf("   ��������: %f #", Simp(fun_3, 0, 2, 4));
    printf(" ��������: %f \n", RungeSimp(fun_3, 0, 2, 4));*/
}
