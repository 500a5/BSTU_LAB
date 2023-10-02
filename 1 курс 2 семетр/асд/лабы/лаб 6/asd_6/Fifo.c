
#include "Fifo.h"

void InitFifo(Fifo* f)
{
    InitList(f);
    FifoError = ListError;
}

void PutFifo(Fifo* f, BaseType e)
{
    EndListPtr(f);
    PutList(f, e);
    FifoError = ListError;
}

void GetFifo(Fifo* f, BaseType* e)
{
    BeginListPtr(f);
    GetList(f, e);
    FifoError = ListError;
}

short EmptyFifo(Fifo* f)
{
    return EmptyList(f);
}

void DoneFifo(Fifo* f)
{
    DoneList(f);
    FifoError = ListError;
}

