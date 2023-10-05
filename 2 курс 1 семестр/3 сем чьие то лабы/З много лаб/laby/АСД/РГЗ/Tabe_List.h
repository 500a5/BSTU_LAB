#ifndef _TABLE_LIST_H_
#define _TABLE_LIST_H_
#include "List.h"
const int tableOk = ListOk;
const int tableEmpty = ListEmpty;
extern int TableListError;
typedef int TableBaseType;
typedef int KeyBaseType;
typedef struct element *ptrel;
typedef struct
{
    TableBaseType data;
    KeyArrayBaseType key;
    ptrel next;
} element;
typedef struct
{
    ptrel Start;
    ptrel ptr;
} Table;

void TableListInit(Table *T);
void TableListPut(Table *T, element E);
void TableListGet(Table *T, element *E, KeyBaseType key);
int TableListEmpty(Table *T);

#endif
