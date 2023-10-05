#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

/*Размер очереди*/
#define SIZE_QUEUE_ARRAY 3
/*Описание исключительных ситуаций*/
const int okQueueArray = 0;									// Все нормально
const int fullQueueArray = 1;								// Очередь переполнена
const int emptyQueueArray = 2;								// Очередь пуста

/*Переменная ошибок*/
extern int errorQueueArray;
/*Базовый тип очереди*/
typedef int queueArrayBaseType;
/*Дескриптор очереди*/
typedef struct {
queueArrayBaseType buf[SIZE_QUEUE_ARRAY];				// Буфер очереди
unsigned ukEnd;											// Указатель на хвост (по нему включают)
unsigned ukBegin;										// Указатель на голову (по нему исключают)
unsigned len;											// Количество элементов в очереди
} QueueArray;

/*Функции работы с очередью*/
void initQueueArray(QueueArray *F);								// Инициализация очереди
void putQueueArray(QueueArray *F, queueArrayBaseType E);		// Включение в очередь
void getQueueArray(QueueArray *F, queueArrayBaseType *E);		// Исключение из очереди
int isFullQueueArray(QueueArray *F);							// Предикат: полна ли очередь
int isEmptyQueueArray(QueueArray *F);							// Предикат: пуста ли очередь

#endif // FIFO_H_INCLUDED
