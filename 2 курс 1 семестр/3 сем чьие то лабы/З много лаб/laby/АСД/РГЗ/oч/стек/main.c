#include <stdio.h>
#include "FifoArray.h"
/*Переменная ошибок*/
int FifoError;
/*Инициализация очереди*/
void FifoInit (Fifo *F)
{
    F->uk1 = 0;
    F->uk2 = 0;
    F->n = 0;
    FifoError = fifoOk;
}
/*Включение в очередь*/
void FifoPut(Fifo *F, BaseType E)
{
/*Если очередь переполнена*/
    if (FifoFull(F))
        return;

/*Иначе*/
    F->buf[F->uk2] = E;									// Включение элемента
    F->uk2 = (F->uk2 + 1) % FifoSize;			// Сдвиг указателя
    F->n++;												// Увеличение количества элементов очереди
}
/*Исключение из очереди*/
void FifoGet (Fifo *F, BaseType *E)
{
/*Если очередь пуста*/
    if (FifoEmpty(F))
        return;
/*Иначе*/
    *E = F->buf[F->uk1];								// Запись элемента в переменную
    F->uk1 = (F->uk1 + 1) % FifoSize;		// Сдвиг указателя
    F->n--;												// Уменьшение длины
}
/*Предикат: полна ли очередь*/
int FifoFull(Fifo *F)
{
    return (F->n == FifoSize);
}
/*Предикат: пуста ли очередь*/
int FifoEmpty(Fifo *F)
{
    return (F->len == 0);
}
