#ifndef STACK_ARRAY_H_INCLUDED
#define STACK_ARRAY_H_INCLUDED

/*Размер стека*/
const short StackSize = 100;

/*Описание исключительных ситуаций*/
const short stackOk = 0;											// Все нормально
const short stackFull = 1;										// Стек переполнен
const short stackEmpty = 2;										// Стек пуст

/*Переменная ошибок*/
extern int StackError = 0;
/*Базовый тип стека*/
typedef int BaseType;
/*Дескриптор стека*/
typedef struct
{
    BaseType buf[StackSize];						// Буфер стека
    short uk;	                             			// Указатель
} Stack;

/*Функции работы со стеком*/
void StackInit (Stack *S);									// Инициализация стека
void StackPut (Stack *S, BaseType E);			// Включение в стек
void StackGet (Stack *S, BaseType *E);			// Исключение из стека
int StackFull (Stack *S);								// Предикат: полон ли стек
int StackEmpty (Stack *S);								// Предикат: пуст ли стек


#endif // STACK_ARRAY_H_INCLUDED
