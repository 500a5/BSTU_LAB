
#define _CRT_SECURE_NO_WARNINGS


#include "stdlib.h"
#include "stdio.h"
#include "pch.h"
#include <iostream>

/*
Пусть есть N-станций метро и k-линии, которые их связывают. Расстояние между станциями известно.
Надо найти кратчайший путь между двумя станциями, где под крайчайшим путём понимать

1. Наименьшее количество пересадок
2. Наименьшее число станций по пути следования (при равенстве числа станций минимизировать число пересадок)
3. Наименьшее время в пути (скорость движения между каждой парой станций известна как в ту, так и в другую сторону; время на пересадку известно тоже)
*/
#define N 256//количество станций и подстанций
#define K 13//количество линий
#define MAXSTRLN 40//максимальная длинна строки

void input(int a[N][N]);
void output(int a[N][N]);
void dijkstra_3(int a[N][N], int rez[N]);
void out_str(int *a);
void out_end(int rez[N]);
void* cr_mem_line();
void cl_mem_line(int *a);
int substation(int station, int arr_line[K][N + 1]);
int test_line(int start, int end, int arr_line[K][N + 1]);
void dijkstra_1(int a[N][N], int rez[N], int arr_line[K][N + 1]);

int main()
{
	setlocale(LC_ALL, "Rus");//подключили русские символы




	int a[N][N] = { 0 };//создаём массив станций
	input(a);//вводим массив станций
	int arr_line[K][N + 1];
	in_line(arr_line);
	int rez[N];
	dijkstra_1(a, rez, arr_line);

	out_end(rez);
}

void input(int a[N][N]) {//ввод массива станций и времени прохождения(проверено)
	int i, j, k;
	int time;
	printf("Создание связей между станциями:\n");
	for (k = 0; k < K; k++) {
		printf("Введите две станции(i j): ");
		scanf("%d", &i);
		i--;
		scanf("%d", &j);
		j--;
		if (a[i][j] > 0) {
			printf("Это значение вы уже вводили\n");
			k -= 1;
		}
		else {
			printf("Введите время проезда между заданными станциями станциями: time = ");
			scanf("%d", &time);
			while (time <= 0) {
				printf("Значение не может быть отрицательным или равным нулю, повторите попытку\n time =");
				scanf("%d", &time);
			}
			a[i][j] = time;
			a[j][i] = time;
		}
	}
}

void in_line(int a[K][N]) {//ввод линий(проверено)
	printf("Распределение станций и подстанций на линии:\n");
	int i, j;
	int path;
	for (i = 0; i < K; i++) {
		printf("Привязка %d_ой линии: \n", i + 1);
		printf("Введите номера станций (конец ввода 0): ");
		j = 0;
		scanf("%d", &path);
		while (path != 0) {
			if (path > 0 || path < N)
				a[i][j] = path - 1;
			scanf("%d", &path);
			j++;
		}
	}
}

void output(int a[N][N]) {//вывод матрицы(не нужно)(проверено)
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int substation(int station, int arr_line[K][N + 1]) {//проверка пересечения линий(проверено)
	int count = 0;//счётчик числа линий на подстанции
	int i, j;//для циклов
	for (i = 0; i < K; i++) {
		j = 0;
		while (arr_line[i][j] >= 0) {
			if (arr_line[i][j] == station) {
				count++;
				i++;
				j = -1;
			}
			j++;
		}
		if (count >= 2) {
			return 1;
		}
	}
	return 0;
}

int test_line(int start, int end, int arr_line[K][N + 1]) {//возвращает номер линии(проверено), или -1 в случае ошибки или не существующего маршрута
	int i, j1, j2; //циклы
	if (start == end)
		return -1;
	for (i = 0; i < K; i++) {
		j1 = 0;
		while (arr_line[i][j1] >= 0) {
			if (arr_line[i][j1] == start) {
				j2 = 0;
				while (arr_line[i][j2] >= 0) {
					if (arr_line[i][j2] = end)
						return i;
					j2++;
				}
			}
			j1++;
		}
	}
	return -1;
}

int test_transfer(int i, int j, int k, int arr_line[K][N + 1]) {//Возвращает 1, если была пересадка, 0- если ее не было
	if (substation(j + 1, arr_line)) {
		int line1 = test_line(i, j, arr_line);
		int line2 = test_line(j, k, arr_line);
		if (line1 == line2 || i < 0)
			return 0;
		return 1;

	}
}

void dijkstra_1(int a[N][N], int rez[N], int arr_line[K][N + 1]) {//хз, придумай
	int line1, line2;
	int u;//сохранение станций
	unsigned short start;
	printf("Введите начальный пункт: start = ");
	scanf("%d", &start);
	start--;
	short was[N];//где мы были не инт-----------------------------------------------
	short pred[N];//из какой станции приехали
	int i, count;
	for (i = 0; i < N; i++) {//создание пустых массивов данных
		rez[i] = INT_MAX;
		was[i] = 0;
		pred[i] = -1;
	}
	rez[start] = 0;

	for (count = 0; count < N - 1; count++) {//создание количества переходов в пути
		int min = INT_MAX;
		for (i = 0; i < N; i++) {//Находит узел, в котором мы были
			if (!was[i] && (rez[i] <= min)) {
				min = rez[i];
				u = i;
			}
		}
		was[u] = 1;
		for (i = 0; i < N; i++) {
			if (!was[i] && a[u][i] && rez[u] != INT_MAX && rez[u] + 1 <= rez[i]) {
				if (test_transfer(pred[u], u, i, arr_line)) {
					rez[i] = rez[u] + 1;
					pred[i] = u;
				}
				else
				{
					pred[i] = u;
					rez[i] = rez[u];
				}
			}
		}
	}
}

void dijkstra_3(int a[N][N], int rez[N]) {//поиск лучшего маршрута, rez - результат(3 опция)
	unsigned short start;
	int u;
	printf("Введите начальный пункт: start = ");
	scanf("%d", &start);
	start--;
	short was[N];//где мы были не инт-----------------------------------------------
	int i, count;
	for (i = 0; i < N; i++) {//создание пустых массивов данных
		rez[i] = INT_MAX;
		was[i] = 0;
	}
	rez[start] = 0;
	for (count = 0; count < N - 1; count++) {//создание времени пути
		int min = INT_MAX;
		for (i = 0; i < N; i++) {//Находит узел, в котором мы были
			if (!was[i] && (rez[i] <= min)) {
				min = rez[i];
				u = i;
			}
		}
		was[u] = 1;
		for (i = 0; i < N; i++) {
			if (!was[i] && a[u][i] && rez[u] != INT_MAX && rez[u] + a[u][i] < rez[i])
				rez[i] = rez[u] + a[u][i];
		}
	}
}

void out_str(int *a) {//вывод строчного массива(проверено)
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", *(a + i));
}

void out_end(int rez[N]) {//конечный ответ(проверено)
	printf("Введите конечную станцию: end = ");
	int end;
	scanf("%d", &end);
	printf("Ответ: %d", rez[--end]);
}

void infromfile(int a[N][N], int *a) {//ввод из файла
	FILE f = fopen("Moscow.txt", "r");

	for (i = 0; i < N; i++) {
		a[i]
	}

}

void* get_mem_name(int N) {//выделение памяти для названия станций N- кол-во станций
	int i;
	int* a = malloc(sizeof(int*)*N);
	for (i = 0; i < N; i++)
		a[i] = malloc(sizeof(char)*MAXSTRLN);
	return a;
}

void free_mem_name(int N) {//освобождение памяти для названия станций N- кол-во станций
	int i;
	for (i = 0; i < N; i++)
		free(a[i]);
	free(a);
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
