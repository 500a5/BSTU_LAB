#pragma once

#ifndef FIFO_H_
#define FIFO_H_

#include "ListOLS.h"

const short FifoOk = List_OK;
const short FifoEmpty = List_Empty;
const short FifoOver = List_NotMem;

// Переменная ошибок
extern int FifoError;

typedef List Fifo;

//Инициализация очереди
void InitFifo(Fifo *f);

//Поместить элемент в очередь 
void PutFifo(Fifo *f, void *E);

//Извлечь элемент из очереди 
void *GetFifo(Fifo *f);

//Прочитать элемент
void *ReadFifo(Fifo *f);

// Проверка, пуста ли очередь?
int  EmptyFifo(Fifo *f);

// Разрушить очередь
void DoneFifo(Fifo *f);

#endif
