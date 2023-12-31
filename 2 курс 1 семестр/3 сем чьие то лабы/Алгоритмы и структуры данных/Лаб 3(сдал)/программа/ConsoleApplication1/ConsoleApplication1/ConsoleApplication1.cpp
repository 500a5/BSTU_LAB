#pragma comment(linker, "/STACK:10000000000")

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9*1000

void superinput1(int a[N]);//ленивый ввод
void superinput2(int a[N]);//ленивый ввод
void superinput3(int a[N]);//ленивый ввод
void input(int a[N]);//ввод массива чисел
void output(int a[N]);//вывод массива чисел
void swap(int *a, int *b);//замена a и b
	void inclusion(int a[N]);//сортировка включением
	void selection(int a[N]);//сортировка выбором
	void exchange(int a[N]);//сортировка обменом
	void exchange1(int a[N]);//улучшенная сортировка обменом 1
	void exchange2(int a[N]);//улучшенная сортировка обменом 2
	void shell(int a[N]); //сортировка Шелла
	void squick(int a[N]); //сортировка Хоара
		void quick(int a[N], int L, int R, int *time); //быстрая сортировка
	void HeapSort(int A[N]);// пирамидальная функция сортировки
		void sift(int A[N], int L, int R, int *time);

int main() {
	int a[N];
	int c = 0;
	/*superinput3(a);
	//output(a);
	clock_t t = clock();
	selection(a);
	t = clock() - t;
	//output(a);
	printf("time = %d\n", t);
	superinput3(a);
	//output(a);
	t = clock();
	exchange(a);
	t = clock() - t;
	//output(a);
	printf("time = %d\n", t);
	superinput3(a);
	//output(a);
	t = clock();
	exchange1(a);
	t = clock() - t;
	//output(a);
	printf("time = %d\n", t);
	superinput2(a);
	//output(a);
	t = clock();
	exchange2(a);
	t = clock() - t;
	//output(a);
	printf("time = %d\n", t);
	superinput3(a);
	//output(a);
	t = clock();
	shell(a);
	t = clock() - t;
	//output(a);
	printf("time = %d\n", t);
	//superinput3(a);
	//output(a);
	//t = clock();
	//squick(a);
	//t = clock() - t;
	//output(a);
	//printf("time = %d\n", t);
	superinput3(a);
	//output(a);
	t = clock();
	HeapSort(a);
	t = clock() - t;
	//output(a);
	printf("time = %d\n", t);*/

	clock_t t;
	superinput3(a);
	t = clock();
	squick(a);
	t = clock() - t;
	output(a);
	printf("\ntime = %d\n", t);

	return 0;
}

void superinput1(int a[N]) { 
	int i;

	for (i = 0; i < N; i++)
		a[i] = i;
}

void superinput2(int a[N]) {
	int i;

	for (i = 0; i < N; i++) {
		a[i] = rand();
	}
}

void superinput3(int a[N]) {
	int i, j = N;

	for (i = 0; i < N; i++) {
		a[i] = j;
		j--;
	}
}

void input(int a[N]) { //ввод массива чисел+
	int i;

	printf("Input arr: ");
	for (i = 0; i < N; i++)
		scanf_s("%d", &a[i]);
	return;
}

void output(int a[N]) { //вывод массива чисел+
	int i;

	printf("Output arr: ");
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	return;
}

void swap(int *a, int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
	return;
}

void inclusion(int a[N]) {//сортировка включением+
	int i, k;
	int time = 0;

	for (i = 1; i < N; i++) {
		k = i;
		while (k != 0) {
			time++;
			if (a[k] < a[k - 1]) {
				swap(&a[k], &a[k - 1]);
			}
			else {
				break;
			}
			k--;
		}

	}
	printf("time = %d\n", time);
	return;
}

void selection(int a[N]){//сортировка выбором+
	int i, j;
	int time = 0;

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			time++;
			if (a[i] > a[j])
				swap(&a[i], &a[j]);
		}
	}
	printf("time = %d\n", time);
	return;
}

void exchange(int a[N]) { //сортировка обменом+
	int i, j;
	int time = 0;

	for (i = 0; i < N; i++) {
		for (j = N - 1; j != i; j--) {
			time++;
			if (a[j - 1] > a[j])
				swap(&a[j - 1], &a[j]);
		}
	}
	printf("time = %d\n", time);
	return;
}

void exchange1(int a[N]) { //улучшенная сортировка обменом 1
	int i = 0, j;
	int flag = 1;
	int time = 0;
	
	while (i < N && flag) {
		flag = 0;
		for (j = N - 1; j != i; j--) {
			if (a[j - 1] > a[j]) {
				swap(&a[j - 1], &a[j]);
				flag = 1;
			}
		}
		i++;
	}
	printf("time = %d\n", time);
	return;
}

void exchange2(int a[N]) { //сортировка обменом
	int i = 0, j;
	int flag = 1;
	int time = 0;

	while (i < N && flag) {
		flag = 0;
		for (j = N - 1; j != i; j--) {
			time++;
			if (a[j - 1] > a[j]) {
				swap(&a[j - 1], &a[j]);
				flag = j;
			}
		}
		i = j + 1;
	}
	printf("time = %d\n", time);
	return;
}

void shell(int a[N]) { //сортировка Шелла+
	int time = 0;
	int h[1000]; int count = 0;
	h[count] = 1;
	while (h[count] < N) {
		h[count + 1] = 3 * h[count] + 1;
		count++;
	}
	int j;
	//цикл, отвечающий за изменение шагов
	for (int k = count; k >= 0; k--) {
		//обычнвя сортировка вставкой
		for (int i = 0; i < N; i = i + h[k]) {
			j = i;
			while ((++time) && (j - h[k] >= 0) && (a[j] < a[j - h[k]])) {
				swap(&a[j], &a[j - 1]);
				j = j - h[k];
			}
		}
	}
	return;
}

void squick(int a[N]) { //сортировка Хоара
	int time = 0;
	quick(a, 0, N - 1, &time);
	printf("time = %d\n", time);
}

void quick(int a[N], int L, int R, int *time) { //быстрая сортировка
	int x = a[L], i = L, j = R; // в качестве разделителя выбираем первый элемент

	while (i <= j) {
		while (a[i] < x) {
			*time++;
			i++;
		}
		while (a[j] > x) {
			*time++;
			j--;
		}
		time++;
		if (i <= j) {
			swap(&a[i], &a[j]);
			i++;
			j--;
		}
	}
	if (L < j)
		quick(a, L, j, time);
	if (i < R)
		quick(a, i, R, time);
}


void HeapSort(int A[N]) {// пирамидальная функция сортировки
	int L, R, x;
	int time = 0;

	L = N / 2; R = N - 1;
	
	while (L > 0) { //  Построение пирамиды из исходного массива
		L = L - 1;
		sift(A, L, R, &time);
	}
	
	while (R > 0) { // Сортировка: пирамида => отсортированный массив
		x = A[0]; A[0] = A[R]; A[R] = x;
		R--;
		sift(A, L, R, &time);
	}
	printf("time = %d\n", time);
	return;
}
/* ============================================ */
void sift(int A[N], int L, int R, int *time) {
	int i, j, x, k;
	i = L;
	j = 2 * L + 1;
	x = A[L];
	time++;
	if ((j < R) && (A[j] < A[j + 1])) {
		j++;
	}
	while ((j <= R) && (x < A[j]))
	{
		k = A[i]; A[i] = A[j];  A[j] = k;
		i = j;
		j = 2 * j + 1;
		time++;
		if ((j < R) && (A[j] < A[j + 1])) 
			j++;
	}
}
