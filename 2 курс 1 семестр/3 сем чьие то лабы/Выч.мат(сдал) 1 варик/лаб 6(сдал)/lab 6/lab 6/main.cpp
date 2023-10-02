#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "windows.h"

#include "od_minimization.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double exp;
	double a, b;
	double znach;

	printf("������� ��������� �������� ������� E: ");
	scanf("%lf", &exp);

	printf("������� ����� ������� ���������� �������������� : ");
	scanf("%lf", &a);
	printf("������� ������ ������� ���������� �������������� : ");
	scanf("%lf", &b);

	printf("\n����������� �������� ������� �� ������ ������� � �������� ���������\n");
	znach = optimal_find(exp, a, b);
	printf("\n������� ������������ ������ : %lf\n", znach);
	znach = cat_in_half(exp, a, b);
	printf("\n������� ������������ ������ : %lf\n", znach);
	znach = metod_fibanachi(exp, a, b);
	printf("\n������� ������������ ������ : %lf\n", znach);


	getchar();
	getchar();
	getchar();
	return 0;
}

