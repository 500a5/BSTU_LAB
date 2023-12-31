/*
Пусть есть N - станций метро и k - линии, которые их связывают.Расстояние между станциями известно.
Надо найти кратчайший путь между двумя станциями, где под крайчайшим путём понимать

1. Наименьшее количество пересадок
2. Наименьшее число станций по пути следования(при равенстве числа станций минимизировать число пересадок)
3. Наименьшее время в пути(скорость движения между каждой парой станций известна как в ту, так и в другую сторону; время на пересадку известно тоже)
*/

#define _CRT_SECURE_NO_WARNINGS //для разрешения использования старых функций

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "Graf.h"


int main() {//главная функция
	setlocale(LC_ALL, "Rus");
	int n;
	station *a;
	input(&a, &n);
	printf("Опция: \n\t1. Наименьшее количество пересадок\n\t2. Наименьшее число станций по пути следования(при равенстве числа станций минимизировать число пересадок)\n\t3. Наименьшее время в пути(скорость движения между каждой парой станций известна как в ту, так и в другую сторону; время на пересадку известно тоже)\n");
	int t;
	scanf("%d", &t);
	int *rez = (int*)malloc(sizeof(int) * 2 * n);
	switch (t) {
	case(1):
		dijkstra_1(a, n, rez);
		break;
	case(2):
		dijkstra_2(a, n, rez);
		break;
	case(3):
		dijkstra_3(a, n, rez);
	}
	output(a, n, rez);
	freeMem(a, rez, n);
	

	getchar();
	getchar();

	return 0;
}
