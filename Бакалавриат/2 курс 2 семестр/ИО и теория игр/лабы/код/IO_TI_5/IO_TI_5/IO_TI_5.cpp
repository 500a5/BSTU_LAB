#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <float.h>

void writeTable(int m, int n, double** T, int* Basic, int a, int b) {
	printf("б.п\tс.ч");
	for (int i = 0; i < n - 1; ++i)
		printf("     \tx%i", i + 1);
	printf("\n");

	for (int i = 0; i < m; ++i) {
		printf("x%i\t", Basic[i] + 1);
		for (int j = 0; j < n; ++j)
			if (i == a && j == b)
				printf("[%lf] ", T[i][j]);
			else
				printf("%lf ", T[i][j]);
		printf("\n");
	}

	printf("Z\t");
	for (int j = 0; j < n; ++j)
		printf("%lf ", T[m][j]);
	printf("\n");
}

double** makeTable(int m, int n, double* Z, double** System) {
	double** T;
	T = (double**)calloc((m + 1), sizeof(double*));
	for (int i = 0; i < m + 1; ++i)
		T[i] = (double*)calloc((n + m + 1), sizeof(double));

	for (int i = 0; i < m; ++i)
		T[i][0] = System[i][n];
	T[m][0] = 0;

	for (int i = 0; i < m; ++i)
		for (int j = 1; j < n + 1; ++j)
			T[i][j] = System[i][j - 1];

	for (int i = 1; i < n + 1; ++i)
		if (Z[i - 1])
			T[m][i] = -Z[i - 1];
		else
			T[m][i] = 0;

	int j = n + 1;
	for (int i = 0; i < m; ++i) {
		T[i][j] = 1.0;
		++j;
	}

	return T;
}

int* findBasic(int m, int n, double** System) {
	int* Basic;
	Basic = (int*)calloc(m, sizeof(int));
	int t = 0;

	for (int j = 1; j < n; ++j) {
		int k = 0;
		for (int i = 0; i < m; ++i)
			if (System[i][j])
				++k;

		for (int i = 0; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				int k = 0;
				if (System[i][j]) {
					for (int i = 0; i < m; ++i)
						if (System[i][j])
							++k;
				}
				if (k == 1 && t < m) {
					Basic[t] = j - 1;
					++t;
				}
			}
		}
	}

	if (t != m)
		printf("Недостаточно базисных переменных, приведите систему к базисному виду и повторите попытку.\n");
	else
		return Basic;
	return NULL;
}

int checkPositive(int m, double** T) {
	for (int i = 0; i < m; ++i)
		if (T[i][0] < 0)
			return 0;
	return 1;
}

void makeNewTable(int m, int n, double** T, int* Basic, char c, int method) {
	int count = 1;
	while (!checkPositive(m, T)) {
		double min = DBL_MAX;
		int mini;
		for (int i = 0; i < m; ++i)
			if (T[i][0] < min) {
				min = T[i][0];
				mini = i;
			}

		min = DBL_MAX;
		int minj = 99;
		for (int i = 1; i < n + 1; ++i) {
			if (T[mini][0] < 0 && T[mini][i] < 0 && T[mini][0] / T[mini][i] < min) {
				min = T[mini][0] / T[mini][i];
				minj = i;
			}
		}

		if (minj == 99) {
			if (method == 1)
				printf("\nCимплекс-таблица №%i:\n", count);
			else
				printf("\nОбобщенная cимплекс-таблица №%i:\n", count);
			writeTable(m, n + 1, T, Basic, 99, 99);
			printf("Задача является недопустимой и решения не имеет\n");
			return;
		}
		else {
			if (method == 1)
				printf("\nCимплекс-таблица №%i:\n", count);
			else
				printf("\nОбобщенная cимплекс-таблица №%i:\n", count);
			writeTable(m, n + 1, T, Basic, mini, minj);
			++count;

			Basic[mini] = minj - 1;

			double t = T[mini][minj];
			for (int i = 0; i < n + 1; ++i)
				T[mini][i] = T[mini][i] / t;

			double k;
			for (int i = mini - 1; i > -1; --i) {
				k = T[i][minj];
				for (int j = 0; j < n + 1; ++j)
					T[i][j] -= T[mini][j] * k;
			}

			for (int i = mini + 1; i < m + 1; ++i) {
				k = T[i][minj];
				for (int j = 0; j < n + 1; ++j)
					T[i][j] -= T[mini][j] * k;
			}
		}
	}

	if (method == 1)
		printf("\nCимплекс-таблица №%i:\n", count);
	else
		printf("\nОбобщенная cимплекс-таблица №%i:\n", count);
	writeTable(m, n + 1, T, Basic, 99, 99);

	printf("%cmax = %lf\n", c, T[m][0]);
	printf("Точка максимума = ( ");
	for (int i = 0; i < n; ++i) {
		int flag = 1;
		for (int j = 0; j < m; ++j)
			if (i == Basic[j] && i < n - m) {
				printf("%f ", T[j][0]);
				flag = 0;
			}
		if (flag && i < n - m)
			printf("0 ");
	}
	printf(")\n");

	if (c == 'Z' || c == 'z')
		printf("Fmin = %lf\n", T[m][0]);
	else if (c == 'F' || c == 'f')
		printf("Zmin = %lf\n", T[m][0]);

	printf("Точка минимума = ( ");
	for (int i = n - m + 1; i < n + 1; ++i)
		printf("%f ", T[m][i]);
	printf(")\n");
}

int main() {
	setlocale(LC_ALL, "Rus");
	int m, n;
	char c;

	printf("Введите количество неизвестных: ");
	scanf("%i", &n);

	double* Z;
	Z = (double*)calloc(n, sizeof(double));

	scanf("%c", &c);
	printf("Введите наименование целевой функции: ");
	scanf("%c", &c);

	printf("Введите коэффициенты при неизвестных в целевой функции:\n  ");
	for (int i = 0; i < n; ++i)
		printf("  x%i", i + 1);

	printf("\n%c = ", c);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &Z[i]);

	printf("Введите кол-во уравнений: ");
	scanf("%i", &m);

	double** System;
	System = (double**)calloc(m, sizeof(double*));
	for (int i = 0; i < m; ++i)
		System[i] = (double*)calloc((n + 1), sizeof(double));

	printf("Введите расширенную матрицу системы:\n");
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n + 1; ++j)
			scanf("%lf", &System[i][j]);

	int method;
	printf("Выберите метод решения задачи:\n1 - Двойственный симплекс-метод\n2 - Метод последовательного уточнения оценок\n");
	scanf("%i", &method);

	double** T = makeTable(m, n, Z, System);

	int* Basic = findBasic(m, n + m + 1, T);
	if (Basic == NULL) {
		return 0;
	}

	makeNewTable(m, n + m, T, Basic, c, method);

	return 0;
}
