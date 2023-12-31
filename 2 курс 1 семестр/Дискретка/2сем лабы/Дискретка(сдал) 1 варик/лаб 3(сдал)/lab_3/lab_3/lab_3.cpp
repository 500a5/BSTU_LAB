#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 10

void Empty(int *a, int n);//отчистка
void Output(int **a, int n);//вывод квадратного массива
void Formation(int **a, int n);//Формирование
void ClassEq(int **a, int x, int n, int *cl);//алгоритм 3.13
void Split(int **R, const int n, int *S);//алгоритм 3.14
int isEmpty(int *a, int n);
void ob_ot(int *a, int *b, int *c);
void razn_ot(int *a, int *b, int *c);
void postr(int *s, int **r);

int main()
{

	int n = 10;//множество 1..10
	setlocale(LC_ALL, "Rus");
	int i, M[N], S[N];
	for (i = 1; i < N; i++)
		M[i] = i;
	int **r;
	r = (int **)calloc(N, sizeof(int*));
	for (i = 0; i < N; i++)
		r[i] = (int *)calloc(N, sizeof(int));
	Formation(r, n);
	printf("\nОтношение R\n");
	Output(r, n);
	Split(r, n, S);
	i = 1;
	printf("\nРазбиение Ф \n");
	while (i < N)
		printf("%d ", S[i++]);
	Empty(*r, n*n);
	postr(S, r);
	printf("\n\n");
	Output(r, n);
	getchar();
	return 0;
}

void Empty(int *a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = 0;
	return;
}

void Output(int **a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void Formation(int **a, int n) {
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			if ((x % 2 == 0 && y % 2 == 0) || (x == y))
				a[x][y] = 1;
	return;
}

void ClassEq(int **a, int x, int n, int *cl) {//алгоритм 3.13
	int j = 0;
	for (int i = 0; i < n; i++)
		if (a[x][i])
			cl[j++] = i;
	return;
}

void Split(int **R, const int n, int *S) {//алгоритм 3.14
	int x;
	int cl[N];
	int A[] = {1,1,1,1,1,1,1,1,1,1};//множество M
	Empty(cl, N);
	Empty(S, n);
	while ((x =(isEmpty(A, n))) != -1) {
		A[x] = 0;
		ClassEq(R, x, n, cl);
		ob_ot(S, cl, S);
		razn_ot(A, cl, A);
	}
	return;
}

int isEmpty(int *a, int n) {
	for (int i = 0; i < n; i++)
		if (a[i] == 1)
			return i;
	return -1;
}

void ob_ot(int *a, int *b, int *c) { //объединение отношений
	int i, j;
	for (i = 1; i <= N; i++)
		c[i] = (a[i]) || (b[i]);
	return;
}

void razn_ot(int *a, int *b, int *c) { //разность отношений
	int i, j;
	for (i = 0; i <= N; i++)
		c[i] = (a[i] > b[i]);
	return;
}

void postr(int *s, int **r){
	int a[N], g = 0, x, y, i = 1, j = 1;
	while (j < N)
	{
		while (i < N)
		{
			if (s[i] == j)
			{
				g++;
				a[g] = i;
			}
			i++;
		}
		if (g == 1)
			r[a[g]][a[g]] = 1;
		if (g > 1)
			for (x = 1; x <= g; x++)
				for (y = 1; y <= g; y++)
					r[a[x]][a[y]] = 1;
		Empty(a, N);
		j++;
		i = 1;
		g = 1;
	}
}