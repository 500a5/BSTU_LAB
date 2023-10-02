#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float(*func_f)(float);
float fun(float x);
float proizv1(float x);
float proizv2(float x);
float Zhnach (func_f f, func_f p, func_f p2, float a, float b, float eps);

int main()
{
    float a, b, eps;
    printf("eps >> ");
    scanf("%f", &eps);
    printf("a >> ");
    scanf("%f", &a);
    printf("b >> ");
    scanf("%f", &b);
    printf("%.2f ", Zhnach(fun, proizv1, proizv2, a, b, eps));
    return 0;
}

float fun(float x) //������� ��������
{
    return x*x*x-9*x*x+27*x-27;
}

float proizv2(float x) //������ �����������
{
    return 6*x-18;
}

float proizv1(float x) //������ �����������
{
    return 3*x*x-18*x+27;
}

float Zhnach (func_f f, func_f p, func_f p2, float a, float b, float e)
{
/*���� �������� ������� � �� ������ �����������
����� ���� � ��� �� ���� � ����� � = a,
�� x0x = b,  x0k = �,  ����� x0x = �,  x0k = b.*/
{
    float x0k,x0x;
    FILE *F = fopen("Rez.txt", "w");
    fprintf(F, "eps = %.5f;  ", e);
    if ((f(a)*p2(a))>0) //���� ������ ����������� � �������� ������� � �����
    {// � ����� ��������� ����, �� x0x��� = b, �0� = �
        x0x=b;
        x0k=a;
        fprintf(F, "a = %.2f; ", x0k);
        fprintf(F, "b = %.2f \n\n", x0x);
    }
    else
    {//����� ��������
        x0x=a;
        x0k=b;
        fprintf(F, "  a = %.2f; ", x0x);
        fprintf(F, "  b = %.2f \n\n", x0k);
    }
    float x1k=x0k-f(x0k)/p(x0k); //�������� � ����� �1 ����
    float x1x=x0x-(f(x0x)*(x1k-x0x))/(f(x1k)-f(x0x)); //�������� � ����� �1 �����������
    float c=fabsf(x1k-x1x); //� ���� ��������� � �������� ��������


    while (c>e) //���� �������� �1� � �1� ������ �������
    {
        fprintf(F, "x0k = %.3f; ", x0k); //������ �������� � ����
        fprintf(F, "  x0x = %.3f \n", x0x);
        x1k=x0k-f(x0k)/p(x0k); //������������ ������ �������� �����������
        x1x=x0x-(f(x0x)*(x1k-x0x))/(f(x1k)-f(x0x));//����
        x0x=x1x; //���������������� �������� ��� ����������� ��������
        x0k=x1k;
        c=fabsf(x1k-x1x); //������� ������ � ��� ���������
    }
    fclose(F); //�������� �����
    return (x1k+x1x)/2; //���� �������� ����������, ���������� ����� �������� �� ���
}


}












