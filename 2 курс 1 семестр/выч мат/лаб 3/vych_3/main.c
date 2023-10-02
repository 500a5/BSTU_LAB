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
    printf("�� ��㫥 業�ࠫ��� (�।���) ��אַ㣮�쭨���:  %f\n", output);

    output = trapeze(fun1, -1, 2, 8, 0.01);
    printf("�� ��㫥 �࠯�権:  %f\n", output);

    output = parabola(fun1, -1, 2, 8, 0.01);
    printf("�� ��㫥 ��ࠡ�� (����ᮭ�):  %f\n", output);

    printf("\n���� n: ");
    scanf("%i", &n);
    program = gauss(fun1, -1, 2, n);

    printf("\n��筮� ���祭��  = %lf\n", calc);
    printf("���ᮬ = %f\n", program);

    printf("���: %f\n", fabs(program - calc));
    printf("��: %f %% \n", fabs(program - calc) / calc * 100);
}

