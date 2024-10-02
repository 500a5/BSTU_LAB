#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#include "Source.h"


void num3() {
	int n, m;
	int *a; // массив последовательности
	int **graf; // Матрица графа

	printf("\nВведите длинну последовательности: ");
	scanf("%d", &n);

	a = init_posl(n);

	printf("\nВведите мощность множества элементов графа: ");
	scanf("%d", &m);
	graf = init_graf(m);

	if (is_marshrut(a, graf, n)) {
		printf("\n Данная последовательность для данного графа является маршрутом!");
		if (is_cep(a, n)) {
			printf("\n Данная последовательность для данного графа является цепью!");
			if (is_easy_cep(a, n, m))
				printf("\n Данная последовательность для данного графа является простой цепью!");
			if (is_easy_cikl(a, n, m))
				printf("\n Данная последовательность для данного графа является простым циклом!");
		}
		else {
			printf("\n Данная последовательность для данного графа не является цепью, а значит и пр. цепью и пр. циклом!");
		}

		if (is_cikl(a, n))
			printf("\n Данная последовательность для данного графа является циклом!");
	}
	else {
		printf("\n Данная последовательность для данного графа не является маршрутом! Следовательно и ничем больше.");
	}

}

void num4() {
	int n, l;
	int *a;
	int **graf;

	printf("\nВведите длинну маршрута: ");
	scanf("%d", &l);
	a = init_posl((l + 1));

	printf("\nВведите мощность множества элементов графа: ");
	scanf("%d", &n);
	graf = init_graf(n);

	printf("\nВведите вершину для которой необходимо найти маршруты: ");
	scanf("%d", &a[0]);

	marshruti(a, graf, 1, l, n);
}

void num5() {

	int i, j;
	int n, l;
	int *a;
	int **graf;
	int **r;
	printf("\nВведите длинну маршрута: ");
	scanf("%d", &l);
	a = init_posl((l + 1));

	printf("\nВведите мощность множества элементов графа: ");
	scanf("%d", &n);
	graf = init_graf(n);
	r = (int**)malloc((n + 1) * sizeof(int*));
	// Ввод элементов графа
	for (i = 1; i <= n; i++) {
		// Выделение памяти под хранение строк
		r[i] = (int*)malloc((n + 1) * sizeof(int));
		for (j = 1; j <= n; j++) {
			r[i][j] = 0;
		}
	}

	int v = 1;

	while (v <= n) {
		a[0] = v;
		marshruti(a, graf, 1, l, n);
		v++;
	}
	j = 1;
	for (i = (j + 1); i <= (n - 1); i++) {
		for (j = 1; j <= n; j++) {
			printf("Между вершинами %d и %d - %d маршрутов.\n", i, j, r[i][j]);
		}
	}
}

void num6() {
	int l, n;
	int *a;
	int **graf;
	printf("\nВведите длинну маршрута: ");
	scanf("%d", &l);
	a = init_posl((l + 1));

	printf("\nВведите мощность множества элементов графа: ");
	scanf("%d", &n);
	graf = init_graf(n);

	printf("\nВведите 2 вершины между которыми необходимо найти маршруты: ");
	scanf("%d %d", &a[0], &a[l]);

	marshruti(a, graf, 1, l, n);
}

void num7() {
	int *log_v;
	int *a; // массив маршрута
	int n;// Мощность квадратной матрицы смежности графа
	int **graf; // Матрица графа
	printf("\nВведите мощность множества элементов графа: ");
	scanf("%d", &n);
	graf = init_graf(n);

	int i;
	a = init_posl((n));
	for (i = 0; i < n; i++)
		a[i] = 0;

	printf("\nВведите вершину для которой необходимо найти все простые максимальные цепи: ");
	scanf("%d", &a[0]);

	log_v = init_posl((n + 1));
	for (i = 0; i <= n; i++)
		log_v[i] = 0;

	log_v[a[0]] = 1;

	all_max_easy_cepi(a, graf, log_v, i, n);

}