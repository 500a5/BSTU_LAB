
#ifndef ASD_6_FIFO_H
#define ASD_6_FIFO_H

#include "List.h"

static const short FifoOk = 0; // ListOk
static const short FifoEmpty = 1; // ListEmpty
static const short FifoNotMem = 2; // ListNotMem

short FifoError;

typedef List Fifo;

void InitFifo(Fifo* f);
void PutFifo(Fifo* f, BaseType e);
void GetFifo(Fifo* f, BaseType* e);
short EmptyFifo(Fifo* f);
void DoneFifo(Fifo* f);

#endif //ASD_6_FIFO_H
