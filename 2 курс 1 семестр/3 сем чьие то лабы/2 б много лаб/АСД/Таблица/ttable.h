#ifndef TTABLE_H_INCLUDED
#define TTABLE_H_INCLUDED


#define TableSize 1000
#include <stdio.h>
#include <stdlib.h>

const short TableOk = 0;
const short TableEmpty = 1;
const short TableFull = 2;
const short TableNotContent = 3;
const short TableAlreadyContent = 4;
static short TableError;

typedef int DataType;
typedef int KeyType;

typedef struct base
{
    DataType data;
    KeyType key;
} base;

typedef struct
{
    base Buf[TableSize];
    unsigned Top;
} Table;

//Инициализация таблицы
void InitTable(Table *T);

//Вставка в таблицу
void PutTable(Table *T, DataType E, KeyType K);

//Взятие из таблицы
void GetTable(Table *T, DataType *E, KeyType K);

//Чтение из таблицы
void ReadTable(Table *T, DataType *E, KeyType K);

//Предикат - таблица пусто
int EmptyTable(Table *T);

//Предикат - таблица заполнена
int FullTable(Table *T);

//void read_table(Table *t, int n);
//v///=oid write_table(Table *t, int n);


#endif
