#include <stdio.h>
#include "Table_List.h"

int TableListError;
//Инициализация таблицы
void TableInit(Table *T)
{
    ListInit(T);
}
//Включение элемента в таблицу
void TablePut(Table *T, element *E)
{
    if (TableFull(T))
        return;
    ptrel tmp = (ptrel)malloc(sizeof(element));

    tmp->data=E->data;
    tmp->key=E->key;
    tmp->next=L->ptr->next;
    L->ptr->next=tmp;
    L->ptr=L->ptr->next;
}
//Исключение элемента из таблицы
void TableGet(Table *T, element *E, KeyBaseType key)
{
    if (TableEmpty(T))
        return;
    ptrel tmp;
    tmp=L->ptr->next;
    L->ptr->next=tmp->next;
    E->data = tmp->data;
    E->key = tmp->key;
    free(tmp);
}
//Таблица пуста
int TableEmpty (Table *T)
{
    return ListEmpty(L);
}
