#pragma once

#if !defined(__STACK1_H)
#define __STACK1_H
#include "Structs.h"
int const StackSize = 1000;
int const StackOk = 0;
int const StackOver = 1;
int const StackUnder = 2;
extern int StackErrorr; // Переменная ошибок
typedef void * BaseType; // Определить тип элемента стека

typedef struct {
	BaseType Buf[StackSize];
	unsigned Uk; // Указывает на элемент, являющийся вершиной стека
} Stack;

void InitStack(Stack **s); // Инициализация стека
int EmptyStack(Stack *s); // Проверка: стек пуст?
void PutStack(Stack *s, BaseType E); // Поместить элемент в стек
BaseType GetStack(Stack *s); // Извлечь элемент из стека
BaseType ReadStack(Stack *s); // Прочитать элемент из вершины стека
void DoneStack(Stack *f); // Разрушить очередь
#endif  
