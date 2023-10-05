#include "ttable.h"

//Инициализация таблицы
void InitTable(Table *T)
{
    T->Top=0;
    TableError=TableOk;
}

//Вставка в таблицу
void PutTable(Table *T, DataType E, KeyType K)
{
    base tmp;
    if (FullTable(T))
    {
        return;
    }
    ReadTable(T, &tmp.data, K);
    if ((TableError==TableNotContent) || (TableError == TableEmpty))
    {
        tmp.data=E;
        tmp.key=K;
        T->Buf[T->Top++]=tmp;
        TableError=TableOk;
    }  else TableError=TableAlreadyContent;
}
//Взятие из таблицы
void GetTable(Table *T, DataType *E, KeyType K)
{
    int i=0;
    if (EmptyTable(T))
    {
        return;
    }
    while (i<T->Top)
    {
        if (T->Buf[i].key==K)
        {
            int j;
            *E=T->Buf[i].data;
            for (j=i+1; j<T->Top; j++)
            {
                T->Buf[j-1]=T->Buf[j];
            }
            T->Top--;
            return;
        }
        i++;
    }
    TableError=TableNotContent;
}

//Чтение из таблицы
void ReadTable(Table *T, DataType *E, KeyType K)
{
    int i=0;
    if (EmptyTable(T))
    {
        return;
    }
    while (i<T->Top)
    {
        if (T->Buf[i].key==K)
        {
            *E=T->Buf[i].data;
            return;
        }
        i++;
    }
    TableError=TableNotContent;
}

//Предикат - таблица пусто
int EmptyTable(Table *T)
{
    if (T->Top==0)
    {
        TableError=TableEmpty;
        return 1;
    }
    return 0;
}

//Предикат - таблица заполнена
int FullTable(Table *T)
{
    if (T->Top==TableSize)
    {
        TableError=TableFull;
        return 1;
    }
    return 0;
}

