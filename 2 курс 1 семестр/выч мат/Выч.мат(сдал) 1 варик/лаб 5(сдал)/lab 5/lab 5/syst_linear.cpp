#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "windows.h"
#include <locale.h>

#include "mod_syst_linear.h"

int main() {
	int n;
	double exp;
	double x, y;
	setlocale(LC_ALL, "Rus");
	printf("������� ��������� �������� ������� E: ");
	scanf("%lf", &exp);
	printf("\n������� ������������ ����������� �������� ��� ��������: ");
	scanf("%d", &n);
	printf("\n������� ��������� ����������� � ���� � �: ");
	scanf("%lf %lf", &x, &y);

	if (system_two_lin_equat(&x, &y, exp, n)) {
		printf("\n������� ������� ��������� � ��������� � ������� : x = %lf   y = %lf\n\n", x, y);
	}
	else
		printf("\n������� ������� ��������� � ��������� � �� ������ ���������� �������� �� �������!");
	getchar();
	getchar();
	getchar();
	return 0;
}
