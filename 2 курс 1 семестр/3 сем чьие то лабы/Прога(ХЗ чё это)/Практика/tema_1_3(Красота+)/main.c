#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
//��������� ����� � �����, ����������, ����������
    setlocale(LC_ALL,"Rus");

    int i;
    float inch;
    printf("������� ������ (� ������) = ");
    scanf("%f", &inch);

    inch = inch * 2.54;//��������� ����� � ����������

    int m,s,mm;

    m = inch/100;//�����

    s = inch - m*100;//����������
    mm = modf(inch, &i) * 100;//����������

    printf("%d ������ %d ����������� %d �����������", m, s, mm);

    return 0;
}
