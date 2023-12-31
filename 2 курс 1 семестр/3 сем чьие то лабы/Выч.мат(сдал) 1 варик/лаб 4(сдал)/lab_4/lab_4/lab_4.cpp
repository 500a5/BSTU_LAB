#define _CRT_SECURE_NO_WARNINGS

#include "windows.h"
#include "stdio.h"

#include "mod_solution_koshi.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double exp;// Точность решения
	double h; // Первоначальный шаг
	printf("Введите точность решения E: ");
	scanf("%lf", &exp);
	printf("Введите начальный шаг h: ");
	scanf("%lf", &h);
	printf("\ny(0): %lf", toch_znach(x_0));
	printf("\nТочное решение: %lf\n", toch_znach(x_n));
	printf("\nРешение задачи методом Эйлера: %lf \n", metod_eilera(h, exp));
	printf("\nРешение задачи методом Эйлера-Коши: %lf \n", metod_eilera_koshi(h, exp));
	printf("\nРешение задачи модифицированным методом Эйлера: %lf \n", metod_eilera_mod(h, exp));
	printf("\nРешение задачи методом Рунге Кутты: %lf \n", metod_runge_kutti(h, exp));
	int flag;
	printf("\nЗаписать результат работы программы в файл? 1 - да, 0 - нет: ");
	scanf("%d", &flag);
	if (flag) {
		FILE *f;
		if ((f = fopen("koshi.txt", "w")) != NULL) {
			fprintf(f, "\nМетод Эйлера: %lf \n", metod_eilera(h, exp));
			fprintf(f, "\nМетод Эйлера-Коши: %lf \n", metod_eilera_koshi(h, exp));
			fprintf(f, "\nМодиф. метод Эйлера: %lf \n", metod_eilera_mod(h, exp));
			fprintf(f, "\nМетод Рунге-Кутты: %lf \n", metod_runge_kutti(h, exp));
			printf("\nЗапись результатов в файл прошла успешно!\n");
		}
	}
	getchar();
	return 0;
}
