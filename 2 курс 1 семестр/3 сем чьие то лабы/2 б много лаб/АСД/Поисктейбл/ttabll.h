#ifndef TTABLL_H_INCLUDED
#define TTABLL_H_INCLUDED


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

//������������� �������
void InitTable(Table *T);

//������� � �������
void PutTable(Table *T, DataType E, KeyType K);

//������ �� �������
void GetTable(Table *T, DataType *E, KeyType K);

//������ �� �������
void ReadTable(Table *T, DataType *E, KeyType K);

//�������� - ������� �����
int EmptyTable(Table *T);

//�������� - ������� ���������
int FullTable(Table *T);

Table up_table(size_t n);
Table noup_table(size_t n);
void output_table (Table t, unsigned n);



#endif
