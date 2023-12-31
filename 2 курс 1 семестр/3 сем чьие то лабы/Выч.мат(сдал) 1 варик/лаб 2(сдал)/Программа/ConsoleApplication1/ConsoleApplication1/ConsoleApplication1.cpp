// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include <locale.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
//струкутра задачи
typedef struct {
	double x;
	int str;
	int tab;
	double **matr;
	int isRavn;
} MatrNuton;
//функция инициализации
void InitMatrNuton(MatrNuton *, int);
//функция очищения памяти структуры
void freeMatrNuton(MatrNuton *);
//1 - равномерная сетка, 0 - не равномерная
int isRavn(MatrNuton *);
//построения интерполяционного многочлена Ньютона для случая равномерной и неравномерной сетки
double findSolution(MatrNuton *);
int main() {
	setlocale(0, "Rus");
	MatrNuton st;
	InitMatrNuton(&st, 1);
	st.isRavn = isRavn(&st);
	double res = findSolution(&st);
	printf("%lf\n", res);
	freeMatrNuton(&st);
	getchar();
	return 0;
}
//функция инициализации
void InitMatrNuton(MatrNuton *st, int iForCons) {
	if (iForCons == 0) {
		printf("Введите X\n");
		scanf("%d", &st->x);
		printf("Введите количество пар X Y\n");
		scanf("%d", &st->str);
		st->tab = st->str + 1;
		//выделяем память матрице
		st->matr = (double **)malloc(st->str * sizeof(double *));
		for (int i = 0; i < st->str; i++)
			st->matr[i] = (double *)malloc(st->tab * sizeof(double));
		//ввод значений сетки с клавиатуры
		for (int i = 0; i < st->str; i++)
			for (int j = 0; j < 2; j++)
				scanf("%f", &st->matr[i][j]);
	}
	else {
		FILE *file = fopen("mydata.txt", "r");
		fscanf(file, "%lf%d", &st->x, &st->str);
		st->tab = st->str + 1;
		//выделяем память матрице
		st->matr = (double **)malloc(st->str * sizeof(double *));
		for (int i = 0; i < st->str; i++)
			st->matr[i] = (double *)malloc(st->tab * sizeof(double));
		//ввод значений сетки с клавиатуры
		for (int i = 0; i < st->str; i++)
			for (int j = 0; j < 2; j++)
				fscanf(file, "%lf", &st->matr[i][j]);
		fclose(file);
	}
}
//функция очищения памяти структуры
void freeMatrNuton(MatrNuton *st) {
	for (int i = 0; i < st->str; i++)
		free(st->matr[i]);
	free(st->matr);
}
//1 - равномерная сетка, 0 - не равномерная
int isRavn(MatrNuton *st) {
	int step = st->matr[1][0] - st->matr[0][0];
	for (int i = 1; i < st->str; i++)
		if ((st->matr[i][0] - st->matr[i - 1][0]) != step)
			return 0;
	return 1;
}
//построения интерполяционного многочлена Ньютона для случая равномерной и неравномерной сетки
double findSolution(MatrNuton *st) {
	int countStr = st->str - 1;
	for (int j = 2; j < st->tab; j++) {
		for (int i = 0; i < countStr; i++) {
			if (st->isRavn == 1)
				st->matr[i][j] = st->matr[i + 1][j - 1] - st->matr[i][j - 1];
			else
				st->matr[i][j] = (st->matr[i + 1][j - 1] - st->matr[i][j - 1])
				/ (st->matr[i + 1][0] - st->matr[i][0]);
			printf("(%d, %d) = %lf\n", i, j, st->matr[i][j]);
		}
		countStr--;
	}
	if (st->isRavn == 1) {
		//нахождение коэфециента t
		double t = (st->x - st->matr[0][0]) / (st->matr[1][0] - st->matr[0][0]);
		//значение многочлена Нтютона для равномерной сетки
		double d1 = st->matr[0][1] + st->matr[0][2] * t;
		double d2 = (st->matr[0][3] * t * (t - 1)) / 2;
		double d3 = (st->matr[0][4] * t * (t - 1) * (t - 2)) / 2;
		return d1 + d2 + d3;
	}
	else {
		//значение многочлена Нтютона для не равномерной сетки
		double d1 = st->matr[0][1] + st->matr[0][2] * (st->x - st->matr[0][0]);
		double d2 = st->matr[0][3] * (st->x - st->matr[0][0]) * (st->x - st -> matr[1][0]);
		return d1 + d2;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
