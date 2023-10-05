#include <stdio.h>
#include <stdlib.h>
#include "ctek.h"

/*Переменная ошибок*/
int errorStackArray;
/*Инициализация стека*/
void initStackArray(StackArray *S) {
S->uk = 0;
errorStackArray = okStackArray;
}
/*Включение в стек*/
void putStackArray(StackArray *S, stackArrayBaseType E) {
/*Если стек переполнен*/
if (isFullStackArray(S)) {
return;
}
/*Иначе*/
S->buf[S->uk] = E;				// Включение элемента
S->uk++;							 	// Сдвиг указателя
}
/*Исключение из стека*/
void getStackArray(StackArray *S, stackArrayBaseType *E) {
/*Если стек пуст*/
if (isEmptyStackArray(S)) {
return;
}
/*Иначе*/
*E = S->buf[S->uk - 1];		// Считывание элемента в переменную
S->uk--;							 	// Сдвиг указателя
}
/*Предикат: полон ли стек*/
int isFullStackArray(StackArray *S) {
if (S->uk == SIZE_STACK_ARRAY) {
errorStackArray = fullStackArray;
return 1;
}
return 0;
}
/*Предикат: пуст ли стек*/
int isEmptyStackArray(StackArray *S) {
if (S->uk == 0) {
errorStackArray = emptyStackArray;
return 1;
}
return 0;
}
