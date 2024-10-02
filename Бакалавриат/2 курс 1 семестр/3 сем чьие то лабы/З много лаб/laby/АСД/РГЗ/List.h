#ifndef _LIST_H_
#define _LIST_H_

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
void InitList(List *L);
//Вставка в список
void PutList(List *L, BaseType E);
//Взятие из списка
void GetList(List *L, BaseType *E);

//Чтение из списка
void ReadList(List *L, BaseType *E);

//Предикат - список пуст
int EmptyList(List *L);

//Предикат - конец списка
int EndList(List *L);

//Колличество элементов в списке
unsigned int Count(List *L);

//Перемещение текущего указателя в начало списка
void BeginPtr(List *L);


//Перемещение текущего указателя на один эелемент вперёд
void MovePtr(List *L);

//Перемещение текущего указателя на позицию n
void MoveTo(List *L, unsigned int n);

//Очистка спика
void ClearList(List *L);

//Копирование первого списка во второй
void CopyList(List *L1, List *L2);

#endif
