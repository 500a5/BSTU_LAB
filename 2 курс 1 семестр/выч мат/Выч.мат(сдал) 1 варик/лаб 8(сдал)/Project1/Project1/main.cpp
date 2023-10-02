#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"

const short ErrNotSolution = 0;
const short Ok = 1;
short Err;

//погрешность 
double E;

//наша функция
double fun(double x);

//первая производная функции
double fun_1dx(double x);

//вторая производная функции
double fun_2dx(double x);

//комбинированный метод
double comb_method(double a, double b);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Введите погрешность: ");
	scanf("%lf", &E);


	double a, b;
	printf("Введите отрезок: ");
	scanf("%lf%lf", &a, &b);

	double sol = comb_method(a, b);

	if (Err == Ok)
		printf("Прибележённое решение: %lf\n", sol);

	getchar();
	getchar();

	return 0;
}

//наша функция
double fun(double x) {
	return pow(x, 3) - 6 * pow(x, 2) + 11 * x - 6;
}

//первая производная функции
double fun_1dx(double x) {
	return 3 * pow(x, 2) - 2 * x + 11;
}

//вторая производная функции
double fun_2dx(double x) {
	return 6 * x - 2;
}

//комбинированный метод
double comb_method(double a, double b) {
	if ((fun(a) * fun(b)) >= 0) {
		printf("Корня на отрезке не сущестует\n");
		Err = ErrNotSolution;
		return 0;
	}
	double x_K, x_X;
	if ((fun(a) * fun_2dx(a)) > 0) {
		x_X = b;
		x_K = a;
	}
	else {
		x_X = a;
		x_K = b;
	}
	do {
		x_K = x_K - (fun(x_K) / fun_1dx(x_K));
		x_X = x_X - (fun(x_X) * (x_K - x_X)) / (fun(x_K) - fun(x_X));
		printf("x_K = %lf\n", x_K);
		printf("x_X = %lf\n", x_X);
	} while (fabs(x_K - x_X) > E);
	Err = Ok;
	return (x_K + x_X) / 2;
}
