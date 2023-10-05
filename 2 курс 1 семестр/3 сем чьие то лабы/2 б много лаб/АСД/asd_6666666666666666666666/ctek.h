#ifndef CTEK_H_INCLUDED
#define CTEK_H_INCLUDED
#include "zap.h"

/*Размер стека*/
#define SIZE_STACK_ARRAY 100
/*Описание исключительных ситуаций*/
const int okStackArray = 0;											// Все нормально
const int fullStackArray = 1;										// Стек переполнен
const int emptyStackArray = 2;										// Стек пуст
/*********************************/
/*Переменная ошибок*/
extern int errorStackArray;
/*Базовый тип стека*/
typedef TInquiry stackArrayBaseType;
/*Дескриптор стека*/
typedef struct {
stackArrayBaseType buf[SIZE_STACK_ARRAY];						// Буфер стека
unsigned uk;													// Указатель
} StackArray;
/******************/
/*Функции работы со стеком*/
void initStackArray(StackArray *S);									// Инициализация стека
void putStackArray(StackArray *S, stackArrayBaseType E);			// Включение в стек
void getStackArray(StackArray *S, stackArrayBaseType *E);			// Исключение из стека
int isFullStackArray(StackArray *S);								// Предикат: полон ли стек
int isEmptyStackArray(StackArray *S);								// Предикат: пуст ли стек
/**************************/

#endif // CTEK_H_INCLUDED
