#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "Derevo.h"
enum {ListOk = 0, ListEmpty = 1, ListNotMem = 2, ListEnd = 3};
short int ListError;

typedef Tree Basetype;


typedef struct Element *ptrel;

typedef struct Element{
  Basetype data;
  ptrel next;
}Element;


typedef struct{
  ptrel start;
  ptrel ptr;
  unsigned int n;
}List;

void InitList(List **L);

int EmptyList(List *L);

int EndList(List *L);

unsigned int Count(List *L);

void PutList(List *L,Basetype E);

void ReadList(List *L,Basetype *E);

void GetList(List *L,Basetype *E);

void BeginPtr(List *L);

void EndPtr(List *L);

void MovePtr(List *L);

void MoveTo(List *L,unsigned int n);

void DoneList(List *L);

void CopyList(List *L1,List *L2);


#endif // LIST_H_INCLUDED
