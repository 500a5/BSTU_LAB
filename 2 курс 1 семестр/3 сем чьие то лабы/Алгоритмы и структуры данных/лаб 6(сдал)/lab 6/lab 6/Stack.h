#pragma once

#if !defined(__STACK1_H)
#define __STACK1_H
#include "Structs.h"
int const StackSize = 1000;
int const StackOk = 0;
int const StackOver = 1;
int const StackUnder = 2;
extern int StackErrorr; // ���������� ������
typedef void * BaseType; // ���������� ��� �������� �����

typedef struct {
	BaseType Buf[StackSize];
	unsigned Uk; // ��������� �� �������, ���������� �������� �����
} Stack;

void InitStack(Stack **s); // ������������� �����
int EmptyStack(Stack *s); // ��������: ���� ����?
void PutStack(Stack *s, BaseType E); // ��������� ������� � ����
BaseType GetStack(Stack *s); // ������� ������� �� �����
BaseType ReadStack(Stack *s); // ��������� ������� �� ������� �����
void DoneStack(Stack *f); // ��������� �������
#endif  
