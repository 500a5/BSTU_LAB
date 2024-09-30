#pragma once

#ifndef STACK_H_
#define STACK_H_

#include "ListOLS.h"

const short StackOk = List_OK;
const short StackUnder = List_Empty;
const short StackOver = List_NotMem;

// Переменная ошибок
extern int StackError; 

typedef List Stack;

//Инициализация стека
void InitStack(Stack *s);

//Поместить элемент в стек
void PutStack(Stack *s, void *E);  

//Извлечь элемент из стека
void *GetStack(Stack *s);      

//Прочитать элемент из вершины стека
void *ReadStack(Stack *s);

//Проверка: стек пуст?
int EmptyStack(Stack *s); 

//Уничтожить стек
void DoneStack(Stack *s); 

#endif
