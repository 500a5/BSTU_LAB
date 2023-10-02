#include <stdio.h>
#include <stdlib.h>
#include "Fifo.h"

int FIFOError;


void InitFifo(Fifo **F){
  InitList(F);
  FIFOError=ListError;
}

void PutFifo(Fifo *F,Basetype E){
  EndPtr(F);
  PutList(F,E);
  FIFOError = ListError;
}

void GetFifo(Fifo *F,Basetype *E){
  BeginPtr(F);
  GetList(F,E);
  FIFOError = ListError;
}

void ReadFifo(Fifo *F, Basetype *E){
  BeginPtr(F);
  ReadList(F,E);
  FIFOError = ListError;
}

int  EmptyFifo(Fifo *F){
  FIFOError = ListError;
  return EmptyList(F);
}

void DoneFifo(Fifo *F){
  DoneList (F);
  free(F);
}
