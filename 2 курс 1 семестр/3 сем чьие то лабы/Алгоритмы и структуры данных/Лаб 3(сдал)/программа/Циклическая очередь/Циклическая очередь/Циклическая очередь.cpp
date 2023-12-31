#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 20
#define OVERFLOW -1 //переполнение массива
#define Empty -2 //пустой массив

typedef struct {
	int arr[MAX_ARR];
	int first;
	int last;
	int size;
}turn;

void push(turn *a, int value);
int pop(turn *a);
void prinTurn(turn *a);
int isEmpty(turn *a);
int isFull(turn *a);

int main()
{
	turn a;
	a.first = 0;
	a.last = 0;
	a.size = 0;
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	prinTurn(&a);
}

void push(turn *a, int value) {
	a->size++;
	if (isFull(a))
		exit(OVERFLOW);
	a->last++;
	if (a->last == MAX_ARR)
		a->last = 0;
	a->arr[a->last - 1] = value;
}

int pop(turn *a) {
	if (isEmpty(a))
		exit(Empty);
	int s;
	s = a->arr[a->first];
	a->first++;
	if (a->first == 20)
		a->first = 0;
	return s;
}

void prinTurn(turn *a) {
	int i;
	for (i = 0; i < a->size; i++) {
		printf("%d ", pop(a));
	}
	return;
}

int isEmpty(turn *a) {
	return (a->size == 0) ? 1 : 0;
}

int isFull(turn *a) {
	return (a->size == MAX_ARR) ? 1 : 0;
}