#pragma once

#ifndef LISTOLS_H_
#define LISTOLS_H_

// константы ошибок
const short List_OK = 0;
const short List_Empty = 1;
const short List_NotMem = 2;
const short List_End = 3;

//переменная ошибок
extern short ListError;

//базовый тип
typedef void * BaseType;

// элемент списка
struct element{
	BaseType Data; // данные
	element* Next; // указатель на следующий элемент
};

// односвязный линейный список
typedef struct {
	//указатель на первый элемент списка
	element* first;
	//указатель на текущий элемент
	element* current;
} List;

//конструктор
void ListInit(List *L);

//деструктор
void ListDone(List *L);

//добавление элемента после рабочего указателя
void ListPut(List *L, BaseType E);

//добавление элемента в начало списка
void ListPutFirst(List *L, BaseType E);

//взятие и удаление элемента по рабочему указателю
BaseType ListGet(List *L);

//чтение элемента по рабочему указателю
BaseType ListRead(List *L);

// перенос рабочего указателя на следующий элемент
void ListMoveNext(List *L);

//являеться ли список пустым
int ListEmpty(List *L);

//находиться ли рабочий указатель в конце списка
int ListEnd(List *L);

//перенос указателя в конец списка
void ListPtrEnd(List *L);

//перенос указателя в начало списка
void ListPtrBegin(List *L);

#endif

