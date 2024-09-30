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

	printf("Введите требуюмую точность решения E: ");
	scanf("%lf", &exp);

	printf("Введите начальное приближение M0(x1_0,x2_0) к точке локального минимума: ");
	scanf("%lf %lf", &x1, &x2);

	printf("\nВведите параметры метода градиента с дроблением шага alf, bet, gam: ");
	scanf("%lf %lf %lf", &alf, &bet, &gam);

	printf("\nВведите максимальное колличество итераций для проверки: ");
	scanf("%d", &n);


	if (metod_grad_whith_drob(&x1, &x2, exp, n, alf, bet, gam)) {
		znach = f_x1x2(x1, x2);
		printf("\nВычисление приближенного значения точки локального минимума и минимального значения целевой функции методом градиента с дроблением шага: Мт (%lf ; %lf) со значением в ней: y(Mт) = %lf\n\n", x1, x2, znach);
	}
	else
		printf("\nЗа данное количество операций задача решение с точностью E не найдено!");
	getchar();
	getchar();
	return 0;
}
