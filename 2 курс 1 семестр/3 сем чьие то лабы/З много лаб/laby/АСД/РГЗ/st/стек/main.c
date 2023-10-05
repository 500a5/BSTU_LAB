#ifndef _DECK_H_
#define _DECK_H_
#include "DList.h"

const int DeckOk = DListOk;
const int DeckNotMem = DListNotMem;
const int DeckEmpty = DListEmpty;
extern int DeckError;
typedef int BaseType;
typedef DList Deck;

void DeckInit(Deck *D);
void DeckDone(Deck *D);
int DeckEmpty(Deck *D);
void DeckPutE(Deck *D, BaseType E);
void DeckPutB(Deck *D, BaseType E);
void DeckGetE(Deck *D, BaseType *E);
void DeckGetB(Deck *D, BaseType *E);
#endif

Файл "Deck_List_Two.c"

#include "Deck.h"
//Инициализация дека
void DeckInit(Deck *D)
{
    DListInit(D);
    DListError = DeckOk;
}
//Удаление дека
void DeckDone(Deck *D)
{
    DListDone(D);
}
//дек пуст
int DeckEmpty(Deck *D)
{
    return DListEmpty(D);
}
//Включение в начало дека
void DeckPutB(Deck *D, BaseType E)
{
    DListBegin(D);
    DListPutPost(D, E);
}
//Включение в конец дека
void DeckPutE(Deck *D, BaseType E)
{
    DLsistEnd(D);
    DListPutPred(D, E);
}
//Исключение из начала дека
void DeckGetB(Deck *D, BaseType *E)
{
    DListBegin(D);
    DListGetPost(D, E);
}

//Исключение из конца дека
void DeckGetE(Deck *D, BaseType *E)
{
    DListE(D);
    DListGetPred(D, E);
}
