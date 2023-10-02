#pragma once

#ifndef LISTOLS_H_
#define LISTOLS_H_

// ��������� ������
const short List_OK = 0;
const short List_Empty = 1;
const short List_NotMem = 2;
const short List_End = 3;

//���������� ������
extern short ListError;

//������� ���
typedef void * BaseType;

// ������� ������
struct element{
	BaseType Data; // ������
	element* Next; // ��������� �� ��������� �������
};

// ����������� �������� ������
typedef struct {
	//��������� �� ������ ������� ������
	element* first;
	//��������� �� ������� �������
	element* current;
} List;

//�����������
void ListInit(List *L);

//����������
void ListDone(List *L);

//���������� �������� ����� �������� ���������
void ListPut(List *L, BaseType E);

//���������� �������� � ������ ������
void ListPutFirst(List *L, BaseType E);

//������ � �������� �������� �� �������� ���������
BaseType ListGet(List *L);

//������ �������� �� �������� ���������
BaseType ListRead(List *L);

// ������� �������� ��������� �� ��������� �������
void ListMoveNext(List *L);

//��������� �� ������ ������
int ListEmpty(List *L);

//���������� �� ������� ��������� � ����� ������
int ListEnd(List *L);

//������� ��������� � ����� ������
void ListPtrEnd(List *L);

//������� ��������� � ������ ������
void ListPtrBegin(List *L);

#endif

