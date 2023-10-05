#include <stdio.h>
#include <stdlib.h>
#include "List.h"
const short ListOk=0;
const short ListNotMem=1;
const short ListEmpty=2;
static short ListError;
typedef int BaseType;
typedef struct element *ptrel;
typedef struct element
{
    BaseType data;
    ptrel next;
} element;
typedef struct
{
    ptrel Start;
    ptrel ptr;
} List;


//Инициализация списка
void InitList(List *L)
{
    L->Start = (ptrel)malloc(sizeof(element));
    if (L->Start==NULL)
    {
        ListError=ListNotMem;
        return;
    }
    L->ptr=L->Start;
    L->ptr->next=NULL;
    ListError=ListOk;
}

//Вставка в список
void PutList(List *L, BaseType E)
{
    ptrel tmp = (ptrel)malloc(sizeof(element));

    tmp->data=E;
    tmp->next=L->ptr->next;
    L->ptr->next=tmp;
    L->ptr=L->ptr->next;
}

//Взятие из списка
void GetList(List *L, BaseType *E)
{
    ptrel tmp;
    if (EmptyList(L))
    {
        return;
    }
    tmp=L->ptr->next;
    L->ptr->next=tmp->next;
    *E = tmp->data;
    free(tmp);
}

//Чтение из списка
void ReadList(List *L, BaseType *E)
{
    if (EmptyList(L))
    {
        return;
    }
    *E=L->ptr->data;
}

//Предикат - список пуст
int EmptyList(List *L)
{
    if (L->Start->next == NULL)
    {
        ListError = ListEmpty;
        return 1;
    }
    return 0;
}

//Предикат - конец списка
int EndList(List *L)
{
    if (L->ptr->next == NULL)
        return 1;
    return 0;
}

//Колличество элементов в списке
unsigned int Count(List *L)
{
    unsigned int counter = 0;
    ptrel tmp = L->Start->next;
    while (tmp->next != NULL)
    {
        counter++;
        tmp=tmp->next;
    }
    return counter;
}

//Перемещение текущего указателя в начало списка
void BeginPtr(List *L)
{
    L->ptr=L->Start;
}

//Перемещение текущего указателя на один эелемент вперёд
void MovePtr(List *L)
{
    L->ptr=L->ptr->next;
}

//Перемещение текущего указателя на позицию n
void MoveTo(List *L, unsigned int n)
{
    unsigned int counter=0;
    ptrel tmp = L->Start;
    while(counter++!=n)
    {
        tmp = tmp->next;
    }
    L->ptr=tmp;
}

//Очистка спика
void ClearList(List *L)
{
    ptrel tmp, tmpnext;
    tmp = L->Start;
    tmpnext=tmp->next;
    while (EmptyList(L))
    {
        tmp=tmpnext;
        tmpnext=tmpnext->next;
        free(tmp);
    }
    free(L->Start);
    ListError=ListEmpty;
}

//Копирование первого списка во второй
void CopyList(List *L1, List *L2)
{
    ptrel tmp = L1->Start;
    while (tmp->next!=NULL)
    {
        PutList(L2, tmp->next->data);
        tmp=tmp->next;
    }
}


