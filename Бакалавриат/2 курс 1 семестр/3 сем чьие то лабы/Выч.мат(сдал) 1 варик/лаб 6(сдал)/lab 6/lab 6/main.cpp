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

	printf("Введите требуюмую точность решения E: ");
	scanf("%lf", &exp);

	printf("Введите левую границу промежутка унимодальности : ");
	scanf("%lf", &a);
	printf("Введите правую границу промежутка унимодальности : ");
	scanf("%lf", &b);

	printf("\nМинимальное значение функции на данном отрезке с заданной точностью\n");
	znach = optimal_find(exp, a, b);
	printf("\nМетодом оптимального поиска : %lf\n", znach);
	znach = cat_in_half(exp, a, b);
	printf("\nМетодом оптимального поиска : %lf\n", znach);
	znach = metod_fibanachi(exp, a, b);
	printf("\nМетодом оптимального поиска : %lf\n", znach);


	getchar();
	getchar();
	getchar();
	return 0;
}

