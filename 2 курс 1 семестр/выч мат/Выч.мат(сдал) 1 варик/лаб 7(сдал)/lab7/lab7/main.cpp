#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "windows.h"

#include "grad_metod.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	double exp;
	double x1, x2;
	double znach;
	double alf, bet, gam;

	printf("������� ��������� �������� ������� E: ");
	scanf("%lf", &exp);

	printf("������� ��������� ����������� M0(x1_0,x2_0) � ����� ���������� ��������: ");
	scanf("%lf %lf", &x1, &x2);

	printf("\n������� ��������� ������ ��������� � ���������� ���� alf, bet, gam: ");
	scanf("%lf %lf %lf", &alf, &bet, &gam);

	printf("\n������� ������������ ����������� �������� ��� ��������: ");
	scanf("%d", &n);


	if (metod_grad_whith_drob(&x1, &x2, exp, n, alf, bet, gam)) {
		znach = f_x1x2(x1, x2);
		printf("\n���������� ������������� �������� ����� ���������� �������� � ������������ �������� ������� ������� ������� ��������� � ���������� ����: �� (%lf ; %lf) �� ��������� � ���: y(M�) = %lf\n\n", x1, x2, znach);
	}
	else
		printf("\n�� ������ ���������� �������� ������ ������� � ��������� E �� �������!");
	getchar();
	getchar();
	return 0;
}
