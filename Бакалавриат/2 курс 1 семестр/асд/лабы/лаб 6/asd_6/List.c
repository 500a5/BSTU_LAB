
#include <stdlib.h>
#include "List.h"

void InitList(List* l)
{
    elptr pntr = (elptr) malloc(sizeof(struct element));

    if(pntr != NULL)
    {
        pntr->next = NULL;
    }
    else
    {
        ListError = ListNotMem;
        return;
    }

    l->start = pntr;
    l->ptr = pntr;
    ListError = ListOk;
}

void PutList(List* l, BaseType e)
{
    elptr pntr = (elptr)malloc(sizeof(struct element));

    if (pntr != NULL)
    {
        pntr->data = e;
        pntr->next = NULL;
    }
    else
    {
        ListError = ListNotMem;
        return;
    }

    pntr->next = l->ptr->next;
    l->ptr->next = pntr;
    ListError = ListOk;
}

void GetList(List* l, BaseType* e)
{
    if (l->start != l->ptr && l->ptr->next == NULL)
    {

        ListError = ListEnd;
    }
    else if (EmptyList(l))
    {
        ListError = ListEmpty;
    }
    else
    {
        elptr pntr = l->ptr->next;
        *e = pntr->data;
        l->ptr->next = pntr->next;
        free(pntr);
        ListError = ListOk;
    }
}

short EmptyList(List* l)
{
    return l->start->next == NULL;
}

void BeginListPtr(List* l)
{
    if (EmptyList(l))
        ListError = ListEmpty;
    else
    {
        l->ptr = l->start;
        ListError = ListOk;
    }
}

void EndListPtr(List* l)
{
    if (EmptyList(l))
        ListError = ListEmpty;
    else
    {
        BeginListPtr(l);

        while (l->ptr->next != NULL)
            MovePtr(l);
    }
}

void MovePtr(List* l)
{
    if (EmptyList(l))
        ListError = ListEmpty;
    else if (l->ptr->next == NULL)
        ListError = ListEnd;
    else
    {
        l->ptr = l->ptr->next;
        ListError = ListOk;
    }
}

void DoneList(List* l)
{
    BeginListPtr(l);

    while (!EmptyList(l))
    {
        BaseType null;

        GetList(l, &null);
    }

    free(l->start);
}


