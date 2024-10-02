#include "FIFO.h"
//Переменная для ошибок
short FIFO_ERROR;

//Операция инициализации
void InitFIFO(FIFO *q)
{

    q->Uk1 = 0;
    q->Uk2 = 0;
    q->n   = 0;
    FIFO_ERROR = FIFO_OK;

}



void PutFIFO(FIFO *q, t_baseType E)
{

    if(FullFIFO(q)){
        q->Buf[q->Uk1] = E;
        q->Uk1 = (q->Uk1 + 1) % FIFO_SIZE;
        ++q->n;
        FIFO_ERROR = FIFO_OK;
    }

}



void GetFIFO(FIFO *q, t_baseType *E)
{
    if(EmptyFIFO(q)){
        *E = q->Buf[q->Uk2];
        q->Uk2 = (q->Uk2 + 1) % FIFO_SIZE;
        --q->n;
        FIFO_ERROR = FIFO_OK;
    }
}


short EmptyFIFO(FIFO *q)
{
    if(q->n==0){
        FIFO_ERROR = FIFO_OK;
        return 0;
    } else {
        FIFO_ERROR = FIFO_EMPTY;
        return 1;
    }

}


short FullFIFO(FIFO *q)
{
    if(q->n== FIFO_SIZE){
        FIFO_ERROR = FIFO_FULL;
        return 0;
    } else {
        FIFO_ERROR = FIFO_OK;
        return 1;
    }

}
