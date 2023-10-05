
#ifndef ASD_3_SORT_FIFO_H
#define ASD_3_SORT_FIFO_H
//Размер очереди
#define FIFO_SIZE 10

//Очередь в порядке
static const short FIFO_OK    = 0;

//Очередь переполнена
static const short FIFO_FULL  = 1;

//Очередь пуста
static const short FIFO_EMPTY = 2;

//Переменная ошибки
extern short FIFO_ERROR;

typedef int t_baseType;

typedef struct{

    int Buf[FIFO_SIZE];

    short Uk1;
    short Uk2;

    short n;

} FIFO;

//Операция инициализации
void InitFIFO(FIFO *q);


void PutFIFO(FIFO *q, t_baseType E);

void GetFIFO(FIFO *q, t_baseType *E);

//Возвращает 1 если очередь q пуста
//Иначе 0
short EmptyFIFO(FIFO *q);

//Возвращает 0 если очередь q полная
//Иначе 1
short FullFIFO(FIFO *q);

#endif //ASD_3_SORT_FIFO_H
