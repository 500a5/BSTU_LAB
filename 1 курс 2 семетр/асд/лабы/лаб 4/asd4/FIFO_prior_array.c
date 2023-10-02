
#include "FIFO_prior_array.h"


short FIFO_P_ERROR;

//Операция инициализации
void InitFIFOP(FIFOP *q)
{

    q->Uk1 = 0;
    q->Uk2 = 0;
    q->n   = 0;
    FIFO_P_ERROR = FIFO_P_OK;

}

//Если очередь не переполнена, то включает элемент E в очередь q
//с приоритетом priority
//Иначе QUEUE_P_ERROR = QUEUE_P_FULL
void PutFIFOP(FIFOP *q, t_baseTypeFIFOP E, priorityType priority)
{

    if(FullFIFOP(q))
        FIFO_P_ERROR = FIFO_P_FULL;
    else{

        q->Buf[q->Uk1].data     = E;
        q->Buf[q->Uk1].priority = priority;

        q->Uk1 = (q->Uk1 + 1) % FIFO_P_SIZE;

        ++q->n;
        FIFO_P_ERROR = FIFO_P_OK;

    }

}


//Если очередь не пуста, то перемещает элемент очереди
//с наибольшим приоритетом q по адресу E
//иначе QUEUE_P_ERROR = QUEUE_P_EMPTY
void GetFIFOP(FIFOP *q, t_baseTypeFIFOP *E)
{

    if(EmptyFIFOP(q))
        FIFO_P_ERROR = FIFO_P_EMPTY;
    else{

        int position     = q->Uk2;
        int positionMaxP = q->Uk2;

        while (position != q->Uk1){

            if(q->Buf[position].priority > q->Buf[positionMaxP].priority)
                positionMaxP = position;

            position = (position + 1) % FIFO_P_SIZE;

        }

        *E = q->Buf[positionMaxP].data;

        q->Buf[positionMaxP] = q->Buf[q->Uk2];

        q->Uk2 = (q->Uk2 + 1) % FIFO_P_SIZE;

        --q->n;
        FIFO_P_ERROR = FIFO_P_OK;

    }

}

//Возвращает 1 если очередь q пуста
//Иначе 0
short EmptyFIFOP(FIFOP *q)
{

    return q->n == 0;

}

//Возвращает 1 если очередь q полная
//Иначе 0
short FullFIFOP(FIFOP *q)
{

    return q->n == FIFO_P_SIZE;

}
