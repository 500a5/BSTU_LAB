#pragma once

#if !defined(__TABLE8_H)
#define __TABLE8_H
const short TableOk = 0;
const short TableNotMem = 1;
const short TableUnder = 2;
typedef void* T_Key; // ���������� ��� �����
typedef void* BaseType;

typedef struct {
	int flag; /* flag =-1 � ������� ������� ��� �����
				flag = 0 � ������� ������� ��������
				flag = 1 � ������� ������� ����� */
	BaseType Data;
} ElTable;

typedef int(*h_f)(BaseType E, int index, int n);

typedef struct {
	ElTable* Buf;
	unsigned n; // ���������� ��������� � �������
	unsigned SizeBuf; // ���������� ��������� � �������
	unsigned SizeEl; // ������ �������� �������
	h_f HashFunc;
} Table;

typedef int(*func)(void*, void*); // ���������� ����� ��������� �������, ������ ������� ��������� � ���������� a � b. ���������� �1, ���� ���� �������� �� ������ a ������ ����� �������� �� ������ b, 0 � ���� ����� ����� � +1 � ���� ���� �������� �� ������ a ������ ����� �������� �� ������ b */

extern int TableError; // 0..2

Table* TableInit(h_f HashFunc, unsigned SizeBuf, unsigned SizeEl);
int TableEmpty(Table *T); // ���������� 1 , ���� ������� �����, ����� � 0
int TablePut(Table *T, BaseType E); // ��������� �������� � �������. ���������� 1 , ���� ������� ������� � �������, ����� � 0 (���� � ������� ��� ���� ������� � �������� ������ ��� ��������� ������) */
int TableGet(Table *T, BaseType E, func f); // ���������� ������-��. ���������� 1 , ���� ������� � ������ Key ��� � �������, ����� � 0 */
int TableRead(Table *T, BaseType E, func f); // ������ ��������. ���������� 1 , ���� ������� � ������ Key ���� � �������, ����� � 0 */
void TableDone(Table *T); // ����������� �������

#endif