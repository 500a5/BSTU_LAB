#include <stdlib.h>
#include "hash_table.h"
void InitTable(Table* t, unsigned sizeBuf, hash h)
{
    t->h = h;
    t->sizeBuf = sizeBuf;
    t->n = 0;
    t->buf = (struct eltable**) malloc(sizeBuf * sizeof(struct eltable*));

    if (t->buf != NULL)
    {
        for(int i = 0; i < sizeBuf; i++)
            t->buf[i] = NULL;
        TableError = TableOk;
    }
    else
    {
        TableError = TableNotMem;
    }
}

int PutTable(Table* t, KeyType key, BaseType e)
{
    int k = t->h(key);

    struct eltable* el = (struct eltable*) malloc(sizeof(struct eltable));
    if (el == NULL)
    {
        TableError = TableNotMem;
        return 0;
    }
    el->key = key;
    el->e = e;

    el->next = t->buf[k];
    t->buf[k] = el;
    t->n++;

    TableError = TableOk;
    return 1;
}

int GetTable(Table* t, KeyType key, BaseType* e)
{
    if (EmptyTable(t))
    {
        TableError = TableEmpty;
        return 0;
    }

    int k = t->h(key);

    struct eltable* el = t->buf[k];
    if (el == NULL)
    {
        TableError = TableNotKey;
        return 0;
    }

    struct eltable* pr = NULL;
    while (el->next != NULL && el->key != key)
    {
        pr = el;
        el = el->next;
    }

    if (el->key == key)
    {
        *e = el->e;
        if(pr == NULL)
            t->buf[k] = NULL;
        else
            pr->next = el->next;
        free(el);
        t->n--;

        TableError = TableOk;
        return 1;
    }
    else
    {
        TableError = TableNotKey;
        return 0;
    }
}

int EmptyTable(Table* t)
{
    return t->n == 0;
}

void DoneTable(Table* t)
{
    if (EmptyTable(t))
    {
        TableError = TableOk;
        return;
    }

    int i = 0;
    while (i < t->sizeBuf)
    {
        struct eltable* el = t->buf[i];
        while (el != NULL)
        {
            t->buf[i] = el->next;
            free(el);
            el = t->buf[i];
            t->n--;
        }
        i++;
    }

    free(t->buf);

    TableError = TableOk;
}
