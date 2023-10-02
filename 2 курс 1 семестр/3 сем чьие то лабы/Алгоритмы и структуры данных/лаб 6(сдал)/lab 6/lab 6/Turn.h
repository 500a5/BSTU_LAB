#pragma once

#ifndef FIFO_H_
#define FIFO_H_

#include "ListOLS.h"

const short FifoOk = List_OK;
const short FifoEmpty = List_Empty;
const short FifoOver = List_NotMem;

// ���������� ������
extern int FifoError;

typedef List Fifo;

//������������� �������
void InitFifo(Fifo *f);

//��������� ������� � ������� 
void PutFifo(Fifo *f, void *E);

//������� ������� �� ������� 
void *GetFifo(Fifo *f);

//��������� �������
void *ReadFifo(Fifo *f);

// ��������, ����� �� �������?
int  EmptyFifo(Fifo *f);

// ��������� �������
void DoneFifo(Fifo *f);

#endif
