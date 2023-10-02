#pragma once


#include <stdio.h>
#include <stdlib.h>

#ifndef __LIST1_H
#define __LIST1_H

const int ListOk = 0;
const int ListNotMem = 1;
const int ListUnder = 2;
const int ListEnd = 3;

typedef double BaseType;

struct el {
	BaseType data;
	struct el* next;
	struct el* back;
};


typedef struct el element;

typedef struct {
	element* Start;
	element* End;
	element* ptr;
	unsigned int N;
} List;

extern short ListError;

void InitList(List **L);
void PutList(List *L, BaseType E);
void GetList(List *L, BaseType *E);
void ReadList(List *L, BaseType *E);
int EmptyList(List *L);
int EndList(List *L);
unsigned int Count(List *L);
void BeginPtr(List *L);
void EndPtr(List *L);
void MovePtr(List *L);
void MoveTo(List *L, unsigned int n);
void DoneList(List *L);
void CopyList(List *L1, List *L2);

#endif
