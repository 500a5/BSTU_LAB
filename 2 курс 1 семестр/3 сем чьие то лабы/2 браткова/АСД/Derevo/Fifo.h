#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED
#include "LIST.h"

#define FIFOOk  ListOk;
#define FIFOEmpty  ListEmpty;
#define FIFONotMem  ListNotMem;

extern int FIFOError;

typedef List Fifo;

void InitFifo(Fifo **F);

void PutFifo(Fifo *F,Basetype E);

void GetFifo(Fifo *F,Basetype *E);

void ReadFifo(Fifo *F, Basetype *E);  // ��������� �������
int  EmptyFifo(Fifo *F); // ��������, ����� �� �������?

void DoneFifo(Fifo *F);

#endif // FIFO_H_INCLUDED
