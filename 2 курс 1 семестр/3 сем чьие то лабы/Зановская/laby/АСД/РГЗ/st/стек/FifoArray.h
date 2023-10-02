#ifndef FIFOARRAY_H
#define FIFOARRAY_H
/*Размер очереди*/
const short FifoSize = 100;
/*Описание исключительных ситуаций*/
const int fifoOk = 0;									// Все нормально
const int fifoFull = 1;								// Очередь переполнена
const int fifoEmpty = 2;								// Очередь пуста

/*Переменная ошибок*/
extern short FifoError;
/*Базовый тип очереди*/
typedef int BaseType;

typedef struct
{
    BaseType buf[FifoSize];				// Буфер очереди
    int uk1;											// Указатель на хвост (по нему включают)
    int uk2;										// Указатель на голову (по нему исключают)
    int n;											// Количество элементов в очереди
} Fifo;


void FifoInit (Fifo *F);								// Инициализация очереди
void FifoPut (Fifo *F, BaseType E);		// Включение в очередь
void FifoGet (Fifo *F, BaseType *E);		// Исключение из очереди
int FifoEmpty (Fifo *F);							// Предикат: пуста ли очередь
int FifoFull (Fifo *F);							// Предикат: полна ли очередь

#endif
