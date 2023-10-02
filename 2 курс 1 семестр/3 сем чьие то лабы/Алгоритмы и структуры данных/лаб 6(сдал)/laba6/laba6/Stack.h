#pragma once

#ifndef STACK_H_
#define STACK_H_

#include "ListOLS.h"

const short StackOk = List_OK;
const short StackUnder = List_Empty;
const short StackOver = List_NotMem;

// ���������� ������
extern int StackError; 

typedef List Stack;

//������������� �����
void InitStack(Stack *s);

//��������� ������� � ����
void PutStack(Stack *s, void *E);  

//������� ������� �� �����
void *GetStack(Stack *s);      

//��������� ������� �� ������� �����
void *ReadStack(Stack *s);

//��������: ���� ����?
int EmptyStack(Stack *s); 

//���������� ����
void DoneStack(Stack *s); 

#endif
