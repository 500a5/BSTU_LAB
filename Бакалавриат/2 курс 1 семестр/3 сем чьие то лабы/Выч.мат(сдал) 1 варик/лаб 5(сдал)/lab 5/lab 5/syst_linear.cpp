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
	printf("Введите требуемую точность решения E: ");
	scanf("%lf", &exp);
	printf("\nВведите максимальное колличество итераций для проверки: ");
	scanf("%d", &n);
	printf("\nВведите начальное приближение в виде х у: ");
	scanf("%lf %lf", &x, &y);

	if (system_two_lin_equat(&x, &y, exp, n)) {
		printf("\nРешение системы уравнений с точностью Е найдено : x = %lf   y = %lf\n\n", x, y);
	}
	else
		printf("\nРешение системы уравнений с точностью Е за данное количество итераций не найдено!");
	getchar();
	getchar();
	getchar();
	return 0;
}
