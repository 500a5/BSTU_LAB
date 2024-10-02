
#ifndef ASD4_FIFO_PRIOR_ARRAY_H
#define ASD4_FIFO_PRIOR_ARRAY_H

//Размер очереди
#define FIFO_P_SIZE  3

//Очередь в порядке
static const short FIFO_P_OK    = 0;

//Очередь переполнена
static const short FIFO_P_FULL  = 1;

//Очередь пуста
static const short FIFO_P_EMPTY = 2;

//Переменная ошибки
extern short FIFO_P_ERROR;

//Базовый тип
typedef int t_baseTypeFIFOP;

//Тип для приоритета
typedef int priorityType;

//Тип эелемнта очереди
typedef struct {

    t_baseTypeFIFOP data;

    priorityType     priority;

}elementFP;

typedef struct{

    elementFP Buf[FIFO_P_SIZE];

    short Uk1;
    short Uk2;

    short n;

} FIFOP;

//Операция инициализации
void InitFIFOP(FIFOP *q);

//Если очередь не переполнена, то включает элемент E в очередь q
//с приоритетом priority
//Иначе QUEUE_P_ERROR = QUEUE_P_FULL
void PutFIFOP(FIFOP *q, t_baseTypeFIFOP E, priorityType priority);

//Если очередь не пуста, то перемещает элемент очереди
//с наибольшим приоритетом q по адресу E
//иначе QUEUE_P_ERROR = QUEUE_P_EMPTY
void GetFIFOP(FIFOP *q, t_baseTypeFIFOP *E);

//Возвращает 1 если очередь q пуста
//Иначе 0
short EmptyFIFOP(FIFOP *q);

//Возвращает 1 если очередь q полная
//Иначе 0
short FullFIFOP(FIFOP *q);

#endif //ASD4_FIFO_PRIOR_ARRAY_H
