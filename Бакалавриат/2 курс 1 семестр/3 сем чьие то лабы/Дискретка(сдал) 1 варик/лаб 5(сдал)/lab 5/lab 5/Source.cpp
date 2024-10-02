#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "Source.h"

#define N 15

// явл€етс€ ли данна€ последовательность pos маршрутом дл€ графа graf
int is_marshrut(int *pos, int **graf, int n) {
	int flag = 1, i = 0;
	while (flag && (i < (n - 1))) {
		if ((graf[pos[i] - 1][pos[i + 1] - 1]) == 0)
			flag = 0;
		i++;
	}
	return flag;
}

// явл€етс€ ли данна€ последовательность pos цепью дл€ графа graf
int is_cep(int *pos, int n) {
	int a[N] = { 0 };// Ћогическое множество дл€ ребер
	int i = 0;
	int flag = 1;
	while (flag && (i < (n - 1))) {
		if (a[pos[i]] == pos[i + 1]) {
			flag = 0;
		}
		a[pos[i]] = pos[i + 1];
		i++;
	}
	return flag;
}
// явл€етс€ ли данна€ последовательность pos простой цепью дл€ графа graf
int is_easy_cep(int *pos, int n, int m) {
	int i;
	int *a;
	int flag = 1;
	a = (int*)malloc((m + 1) * sizeof(int));
	for (i = 0; i < (m + 1); i++) {
		a[i] = 0;
	}
	i = 0;
	while (flag && i < (n - 1)) {
		if (a[pos[i]] == 1)
			flag = 0;
		a[pos[i]] = 1;
		i++;
	}
	return flag;
}
// явл€етс€ ли данна€ последовательность pos циклом дл€ графа graf
int is_cikl(int *pos, int n) {
	if (pos[0] == pos[n - 1]) {
		return 1;
	}
	return 0;
}
int is_easy_cikl(int *pos, int n, int m) {
	if (pos[0] == pos[n - 1]) {
		int i;
		int *a;
		int flag = 1;

		a = (int*)malloc((m) * sizeof(int));
		for (i = 1; i < m; i++) {
			a[i] = 0;
		}
		i = 0;
		while (flag && i < (n - 1)) {
			if (a[pos[i]] == 1)
				flag = 0;
			a[pos[i]] = 1;
			i++;
		}
		return flag;
	}
	return 0;
}
//»нициализаци€ графа а ввиде матрицы смежности n*n
int ** init_graf(int n) {
	int i, j;
	int **a;

	// ¬ыделение пам€ти под указатели на строки
	a = (int**)malloc(n * sizeof(int*));
	printf("\n¬ведите граф ввиде матрицы смежности %d: \n", n);
	// ¬вод элементов графа
	for (i = 0; i < n; i++) {
		// ¬ыделение пам€ти под хранение строк
		a[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	return a;
}
int * init_posl(int n) {
	int i;
	int *a;
	// ¬ыделение пам€ти
	a = (int*)malloc(n * sizeof(int));
	printf("\n¬ведите последовательность длинны %d: ", n);
	// ¬вод элементов последовательности
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	return a;
}

void output_marsh(int *a, int l) {
	int i;
	for (i = 0; i < (l + 1); i++)
		printf("%d ", (a[i]));
	printf("\n");
}

void marshruti(int **graf, int i, int l, int n) {
	int *a;
	int x;
	for (x = 1; x <= n; x++) {
		if ((graf[a[i - 1]][x] == 1) && (x != a[i - 1])) {
			a[i] = x;
			if (i == l)
				output_marsh(a, l);
			else
				marshruti(a, graf, i + 1, l, n);
		}
	}
	return;
}

void output_marsh1(int *a) {
	int i = 0;
	while (a[i] > 0) {
		printf("%d ", a[i]);
		i++;
	}

	printf("\n");
}

int find_in_cep(int a, int **graf, int *log_v, int n) {
	for (int i = 1; i <= n; i++) {
		if ((graf[a][i] == 1) && (i != a) && (log_v[i] == 0))
			return 1;
	}
	return 0;
}

void all_max_easy_cepi(int *a, int **graf, int *log_v, int i, int n) {
	int x;
	for (x = 1; x <= n; x++) {
		if ((graf[a[i - 1]][x] == 1) && (x != a[i - 1]) && (log_v[x] == 0)) {
			a[i] = x;
			if (!(find_in_cep(a[i], graf, log_v, n)))
				output_marsh1(a);
			else {
				log_v[x] = 1;
				all_max_easy_cepi(a, graf, log_v, i + 1, n);
				log_v[x] = 0;
			}
		}
	}
}