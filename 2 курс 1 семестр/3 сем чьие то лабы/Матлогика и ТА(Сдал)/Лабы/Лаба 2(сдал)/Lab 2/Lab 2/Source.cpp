#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "windows.h"
#define N 100
long unsigned d[N];
long unsigned c[N];
//��������� ������ �������
int *getMemoryArr(int size);
//�������� ������ �������
void freeMemoryArr(int *arr);
//��������� ������ �������
int **getMemoryMatr(int str, int tab);
//�������� ������ �������
void freeMemoryMatr(int **matr, int str);
//���� ��� ������������� � �������� ���������� ����
void input_dnf(int** a, int* b, int m, int n);
//����� ��� �� �����
void output_forml(int **a, int* b, int m, int n);
//����� ���������� ������� ���������� � ��� ������ ���
int** output_tab(int **a, int *b, int m, int n);
int output_sknf(int **tabl, int n, int* ABC, int *b);
void input(long unsigned c[], int k);
void output(long unsigned d[], int k, int* b, int** tabl, int n, int *ABC);
void recurs(size_t i, int k, int* b, int** tabl, int n, int* ABC);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i, k;
	int **tabl;
	printf("���������� ������ � ���: ");
	int m;
	scanf("%i", &m);
	printf("���������� ����������: ");
	int n;
	scanf("%i", &n);
	int *b = getMemoryArr(pow(2, n));
	//������� ������� ���
	//������ ������� - ���� ������ ���
	//������ ������� ���������� ������ � ����� ����������
	//�������� � ������ ������������� �������(1), ���������(-1) ��� ����������(0) ����������
	int **a = getMemoryMatr(m, n);

	//������ ���������� � ���� ��������
	int *ABC = getMemoryArr(n);

	//���� ���
	input_dnf(a, ABC, m, n);
	//����� ��� � ��������� �����
	output_forml(a, ABC, m, n);
	//���������� ������� ���������� � ����� � �� �����
	tabl = output_tab(a, ABC, m, n);
	k = output_sknf(tabl, n, ABC, b);
	input(c, k);
	recurs(0, k, b, tabl, n, ABC);

	freeMemoryArr(ABC);
	freeMemoryMatr(a, m);
	freeMemoryMatr(tabl, pow(2, m));
	getchar();
	getchar();
	getchar();
	return 0;
}
//���� ��� ������������� � �������� ���������� ����
void input_dnf(int** a, int* b, int m, int n) {
	int i, j;

	printf("���� ����������: ");
	for (i = 0; i < n; i++) {
		b[i] = 'A' + i;
		printf("%c ", b[i]);
	}
	printf("\n");
	printf("�����������:\n");
	printf("������� ���������� : 1\n");
	printf("��������� ����������: -1\n");
	printf("���������� ����������: 0 \n");

	for (i = 0; i < m; i++) {
		printf("C����� %d:\n", i + 1);
		for (j = 0; j < n; j++)
			scanf("%i", &a[i][j]);
	}
}
//����� ��� �� �����
void output_forml(int **a, int* b, int m, int n) {
	int i = 0, j = 0;

	for (i = 0; i < m; i++) {
		printf("(");
		j = 0;
		while ((a[i][j] == 0) && (j < n))
			j++;
		if (j < n) {
			if (a[i][j] == -1)
				printf("!%c", b[j]);
			else
				printf("%c", b[j]);
		}
		j++;
		for (; j < n; j++) {
			if (a[i][j] == -1)
				printf(" + !%c", b[j]);
			if (a[i][j] == 1)
				printf(" + %c", b[j]);

		}
		printf(")");
		if ((i + 1) < m)
			printf("*");
	}
	printf("\n");
}
//����� ���������� ������� ����������, � ��� ������ ���
int** output_tab(int **a, int *b, int m, int n) {
	int i, j, mask = 1, f, x, z, k;
	//����� ����������� ������� � ������� ����������
	for (i = 0; i < n; i++)
		printf("%c ", b[i]);
	printf("f\n");

	int all = pow(2, n);
	//������� ����������
	int **tabl = getMemoryMatr(all, n + 1);


	for (i = 0; i < all; i++) {
		//��������� ��������� ������� ����������� �� ���������� �������
		for (j = 0; j < n; j++) {
			tabl[i][j] = (mask & (i >> (n - 1 - j)));
			printf("%i ", tabl[i][j]);
		}
		f = 1;
		z = 0;
		//������������ ������� �� ����������� ��������� �������
		while ((z < m) && (f)) {
			x = 0;
			k = 0;
			while (k < n) {
				if (a[z][k] == 1)
					x |= tabl[i][k];
				if (a[z][k] == -1)
					x |= !tabl[i][k];
				k++;
			}
			f = f && x;
			z++;
		}
		tabl[i][n] = f;
		printf("%i\n", tabl[i][n]);
	}
	return tabl;
}
int output_sknf(int **tabl, int n, int* ABC, int *b) {
	int i, j, k = 1;
	int n1 = pow(2, n);
	for (i = 0; i < n1; i++)
		if (tabl[i][n] == 0) {
			b[k - 1] = i;
			printf("%i)", k);
			printf("(");
			for (j = 0; j < n - 1; j++) {
				if (tabl[i][j] == 1)
					printf("!%c+", ABC[j]);
				else
					printf("%c+", ABC[j]);
			}
			if (tabl[i][n - 1] == 1)
				printf("!%c", ABC[n - 1]);
			else
				printf("%c", ABC[n - 1]);

			printf(")\n");
			k++;
		}
	return k - 1;
}
void input(long unsigned c[], int k) {
	for (int i = 0; i < k; i++)
		c[i] = i + 1;
}
void output(long unsigned d[], int k, int* b, int** tabl, int n, int *ABC) {
	size_t i, j;
	for (i = 0; i < k; i++)
		if (d[i]) {
			printf("(");
			for (j = 0; j < n - 1; j++) {
				if (tabl[b[i]][j] == 1)
					printf("!%c+", ABC[j]);
				else
					printf("%c+", ABC[j]);
			}
			if (tabl[b[i]][n - 1] == 1)
				printf("!%c", ABC[n - 1]);
			else
				printf("%c", ABC[n - 1]);
			printf(")");
		}
}
void recurs(size_t i, int k, int* b, int** tabl, int n, int* ABC) {
	short unsigned x;
	for (x = 0; x <= 1; x++) {
		d[i] = x;
		if (i == k - 1) {
			output(d, k, b, tabl, n, ABC);
			printf("\n");
		}
		else
			recurs(i + 1, k, b, tabl, n, ABC);
	}
}
//��������� ������ �������
int *getMemoryArr(int size) {
	return (int *)malloc(size * sizeof(int));
}
//�������� ������ �������
void freeMemoryArr(int *arr) {
	free(arr);
}
//��������� ������ �������
int **getMemoryMatr(int str, int tab) {
	int **matr = (int **)malloc(str * sizeof(int *));
	for (int i = 0; i < str; i++)
		matr[i] = (int *)malloc(tab * sizeof(int));
	return matr;
}

//�������� ������ �������
void freeMemoryMatr(int **matr, int str) {
	for (int i = 0; i < str; i++)
		free(matr[i]);
	free(matr);
}
