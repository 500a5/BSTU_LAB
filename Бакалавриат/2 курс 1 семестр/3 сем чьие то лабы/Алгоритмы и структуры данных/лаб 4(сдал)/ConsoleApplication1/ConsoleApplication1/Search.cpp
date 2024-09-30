#include "Search.h"

#include "windows.h"
#include <math.h>
#include <stdio.h>


int countComparison;

//линейный поиск
int lineSearch(int *a, int n, int key) {
	countComparison = 0;
	int i = 0;
	while ((countComparison += 2) && (i < n) && (a[i] != key))
		i++;
	return (i != n) ? i : -1;
}

//быстрый линейный поиск
int fastLineSearch(int *a, int n, int key) {
	countComparison = 0;
	int i = 0;
	a[n] = key;
	while ((countComparison += 1) && (a[i] != key))
		i++;
	return (i != n) ? i : -1;
}

//бинарный поиск
int binSearch(int *a, int n, int key) {
	countComparison = 0;
	int left = 0;
	int right = n;
	int search = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		countComparison++;
		if (key == a[mid]) {
			search = mid;
			break;
		}
		if (key < a[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return search;
}

//блочный поиск
int blockSearch(int *a, int n, int key) {
	int step = sqrt(n);
	int stblock = 0;
	countComparison = 0;
	
	while (stblock < n + step) {
		countComparison += 1;
		if (a[stblock] > key) {
			for (int i = step; i > 0; i--) {
				countComparison += 1;
				if ((stblock - i) < n && a[stblock - i] == key)
					return stblock - i;
			}
			return -1;
		}
		stblock += step;
	}
	return -1;
}

//возвращает наихудшее количество шагов данного поиска
int getBadStep(int *a, int n, int(*find)(int *, int, int)) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		find(a, n, a[i]);
		if (max < countComparison)
			max = countComparison;
	}
	return max;
}

//возвращает среднее количество шагов данного поиска
int getAverageStep(int *a, int n, int(*find)(int *, int, int)) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		find(a, n, a[i]);
		sum += countComparison;
	}
	return sum / n;
}

// заполнение массива 
void initArr(int *arr, int n, short t) {
	srand(50);
	for (int i = 0; i < n; i++) {
		switch (t) {
		case ORDERLY: arr[i] = i; break;
		case DISORDERED:
			arr[i] = rand() % 100 + 1;
			break;
		}
	}
}



// функция - Эксперимент - эффективности сортировок
void experiment(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// тестовые массивы
	int a[MAX_SIZE_ARR];

	//цикл отвечает за тип массива (упорядоченный/ неупорядоченный)
	for (short t = 0; t < 2; t++) {
		switch (t) {
		case ORDERLY:
			printf("--------------Упорядоченный массив--------------\n");
			break;
		case DISORDERED:
			printf("--------------Непорядоченный массив-------------\n");
			break;
		}
		//цикл отвечает за изменение длинный массива
		for (int size = 50; size <= 450; size += 50) {
			printf("--------------Размер массива - %d---------------\n", size);
			switch (t) {
			case DISORDERED:
				initArr(a, size, DISORDERED);

				printf("Линейный поиск\n");
				printf("   Наихудшее время: %d\n", getBadStep(a, size, &lineSearch));
				printf("   Среднее время время: %d\n", getAverageStep(a, size, &lineSearch));

				printf("Быстрый линейный поиск\n");
				printf("   Наихудшее время: %d\n", getBadStep(a, size, &fastLineSearch));
				printf("   Среднее время время: %d\n", getAverageStep(a, size, &fastLineSearch));

				break;
			case ORDERLY:
				initArr(a, size, ORDERLY);

				printf("Быстрый линейный поиск\n");
				printf("   Наихудшее время: %d\n", getBadStep(a, size, &fastLineSearch));
				printf("   Среднее время время: %d\n", getAverageStep(a, size, &fastLineSearch));

				printf("Бинарный поиск\n");
				printf("   Наихудшее время: %d\n", getBadStep(a, size, &binSearch));
				printf("   Среднее время время: %d\n", getAverageStep(a, size, &binSearch));

				printf("Блочный поиск\n");
				printf("   Наихудшее время: %d\n", getBadStep(a, size, &blockSearch));
				printf("   Среднее время время: %d\n", getAverageStep(a, size, &blockSearch));
				break;
			}

		}
	}
}
