#include <stdio.h>
#include "min_f.h"

int main() {
    double exp;
    double a, b;
    double znach;

    printf("������ �ॡ���� �筮��� �襭�� E: ");
    scanf("%lf", &exp);

    printf("\n������ ����� �࠭��� �஬���⪠ 㭨�����쭮�� : ");
    scanf("%lf", &a);
    printf("\n������ ����� �࠭��� �஬���⪠ 㭨�����쭮�� : ");
    scanf("%lf", &b);

    printf("\n�������쭮� ���祭�� �㭪樨 �� ������ ��१�� � �������� �筮����\n");
    znach = optimal_find(exp, a, b);
    printf("\n��⮤�� ��⨬��쭮�� ���᪠ : %lf\n", znach);
    znach = cat_in_half(exp, a, b);
    printf("\n��⮤�� ��⨬��쭮�� ���᪠ : %lf\n", znach);
    znach = metod_fibanachi(exp, a, b);
    printf("\n��⮤�� ��⨬��쭮�� ���᪠ : %lf\n", znach);


    return 0;
}