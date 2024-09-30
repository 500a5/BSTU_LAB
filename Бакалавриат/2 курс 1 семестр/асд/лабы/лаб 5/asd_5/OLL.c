
#include <stdlib.h>
#include "OLL.h"


short OLL_ERROR;

void InitOLList(OLList *L)
{

    //Память под фиктивный элемент
    L->Start = malloc(sizeof(elementOLL));
    if (L->Start == NULL){

        //Память не выделилась
        OLL_ERROR = OLL_NOT_MEM;
        return;

    }

    //Текущий указатель на начало
    L->ptr = L->Start;
    L->ptr->next = NULL;

    //Инициализация длины списка
    L->N = 0;

    OLL_ERROR = OLL_OK;

}

void PutOLList(OLList *L, BaseTypeOLL E)
{

    ELptr new;
    new = malloc(sizeof(elementOLL));

    //Проверка выделилась ли память под новый узел
    if (new == NULL){
        OLL_ERROR = OLL_NOT_MEM;
        return;
    }

    new->data = E;

    //Указатель на следующий элемент за местом вставки
    new->next = L->ptr->next;

    //Связка предыдущего узла с новым элементом
    (L->ptr)->next = new;
    ++(L->N);

    OLL_ERROR = OLL_OK;

}

void GetOLList(OLList *L, BaseTypeOLL *E)
{

    //Если пытаемся удалить из пустого массива
    if (EmptyOLList(L)){
        OLL_ERROR = OLL_EMPTY;
        return;
    }

    //Проверяем не стоит ли указатель в конце
    if(EndOLList(L)) {
        OLL_ERROR = OLL_END;
        return;
    }

    elementOLL *elDel = L->ptr->next;

    //При удалении необходимо соединить предыдущий элемент со следующим
    L->ptr->next = elDel->next;
    *E = elDel->data;

    //Очистим память, уменьшим размер списка
    free(elDel);
    --(L->N);

    OLL_ERROR = OLL_OK;

}
void ReadOLList(OLList *L,BaseTypeOLL *E)
{

    //Если пытаемся читать из пустого массива
    if (EmptyOLList(L)){
        OLL_ERROR = OLL_EMPTY;
        return;
    }

    //Если указатель стоит в конце
    if(EndOLList(L)) {
        OLL_ERROR = OLL_END;
        return;
    }

    *E = L->ptr->next->data;

    OLL_ERROR = OLL_OK;
}

int EmptyOLList(OLList *L)
{

    return L->N == 0;

}

int EndOLList(OLList *L)
{

    return L->ptr->next == NULL;

}

unsigned int Count(OLList *L)
{

    return L->N;

}


void BeginPtr(OLList *L)
{

    L->ptr = L->Start;

}

void EndPtr(OLList *L)
{

    while (!EndOLList(L)){

        L->ptr = L->ptr->next;

    }

}

void MovePtr(OLList *L)
{

    if(EndOLList(L)){
        OLL_ERROR = OLL_END;
        return;
    }

    L->ptr = L->ptr->next;

}
void MoveTo(OLList *L, unsigned int n)
{

    BeginPtr(L);
    int i = 0;

    while ((i<n) && !EndOLList(L)){
        MovePtr(L);
        ++i;
    }

}


void DoneOLList(OLList *L)
{

    BeginPtr(L);

    BaseTypeOLL E;

    //Пока список не пустой, удаляем элементы
    while (!EmptyOLList(L)){
        GetOLList(L, &E);
    }

    //освобождаем фиктивный элемент
    free(L->ptr);

}
void CopyOLList(OLList *L1,OLList *L2)
{

    //Удалим лист L2
    DoneOLList(L2);
    //Инициалиализируем список заново
    InitOLList(L2);
    //Передвинем указатель L1 в начало
    BeginPtr(L1);

    BaseTypeOLL E;

    //Пока не конец списка, будем добавлять элементы в L1
    while (!EndOLList(L1)){

        ReadOLList(L1, &E);
        PutOLList(L2, E);
        MovePtr(L1);
        MovePtr(L2);

    }

}
