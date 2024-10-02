#include <stdio.h>
#include "StackArray.h"
/*Переменная ошибок*/
int StackError;
/*Инициализация стека*/
void StackInit(Stack *S)
{
    S->uk = 0;
    StackError = StackOk;
}
/*Включение в стек*/
void StackPut(Stack *S, BaseType E)
{
/*Если стек переполнен*/
    if (StackFull(S))
    {
        return;
    }
    /*Иначе*/
    S->buf[S->uk] = E;				// Включение элемента
    S->uk++;							 	// Сдвиг указателя
}
/*Исключение из стека*/
void getStackArray(StackArray *S, stackArrayBaseType *E)
{
/*Если стек пуст*/
    if (isEmptyStackArray(S))
        return;

/*Иначе*/
    *E = S->buf[S->uk - 1];		// Считывание элемента в переменную
    S->uk--;							 	// Сдвиг указателя
}
/*Предикат: полон ли стек*/
int isFullStackArray(StackArray *S)
{
    if (S->uk == SIZE_STACK_ARRAY)
    {
        StackError = StackFull;
        return 1;
    }
    return 0;
}
/*Предикат: пуст ли стек*/
int isEmptyStackArray(StackArray *S)
{
    if (S->uk == 0)
    {
        StackError = StackEmpty;
        return 1;
    }
    return 0;
}
