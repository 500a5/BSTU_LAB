#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LFN.h"

float f(float x, float y, int f){
    if (f == 0)
        return (cos(x)+2*y-2);

    else if (f == 1)
        return (-sin(x));

    else
        return (2);

}

float g(float x, float y, int f){
    if (f == 0)
        return (x*x + y*y - 1);
    else if (f == 1)
        return (2*x);
    else
        return (2*y);

}

int main() {
    float x, y, e = 0.001;
    int n ;
    printf("��᫮ ���権 n = ");
    scanf("%d",&n);
    printf("X = ");
    scanf("%f", &x);
    printf("Y = ");
    scanf("%f", &y);
    int t = meth_newton(f, g, &x, &y, e, n);
    if(t==1) {
        printf("��襭�� ��⥬� � �������� �筮���� ����祭� �� �᫮ ���権, �� �ॢ���饥 n \n");
        printf("��襭�� �ࠢ����� � �������� ����⭮�� \nX = %f", x);
        printf("\nY = %f\n", y);
    }
    else
        printf("��襭�� ��⥬� � �������� �筮���� �� ����祭� �� �᫮ ���権, �� �ॢ���饥 n \n");
}