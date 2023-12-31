#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 20
#define STACK_OVERFLOW  -100//выход за границы массива
#define STACK_UNDERFLOW -101

#define StakOk 0
#define StakEmpty 1
#define StakFull 2

typedef struct Stack_tag {
	int data[STACK_MAX_SIZE];
	size_t size;
} Stack_t;

void printStackValue(const int value);
void printStack(const Stack_t *stack, void(*printStackValue)(const int));
void StakInit(Stack_t *s);
void push(Stack_t *stack, const int value);
int pop(Stack_t *stack);
int isEmpty(Stack_t *s);
int isFull(Stack_t *s);

int StakError;

int main()
{


}

void printStackValue(const int value) {
	printf("%d", value);
}

void printStack(const Stack_t *stack, void(*printStackValue)(const int)) {
	int i;
	int len = stack->size - 1;
	printf("stack %d > ", stack->size);
	for (i = 0; i < len; i++) {
		printStackValue(stack->data[i]);
		printf(" | ");
	}
	if (stack->size != 0) {
		printStackValue(stack->data[i]);
	}
	printf("\n");
}

void StakInit(Stack_t *s) {
	s->size = 0;
	StakError = StakOk;
}

void push(Stack_t *stack, const int value) {//Кладём новый элемент на стек.
	if (isFull(stack)) {
		exit(STACK_OVERFLOW);
	}
	stack->data[stack->size] = value;
	stack->size++;
}

int pop(Stack_t *stack) {//возвращает элемент с вершины
	if (isEmpty(stack)) {
		exit(STACK_UNDERFLOW);
	}
	stack->size--;
	return stack->data[stack->size];
}

int isEmpty(Stack_t *s) {
	return (s->size == 0) ? 1 : 0;
}

int isFull(Stack_t *s) {
	return (s->size == STACK_MAX_SIZE) ? 1 : 0;
}
