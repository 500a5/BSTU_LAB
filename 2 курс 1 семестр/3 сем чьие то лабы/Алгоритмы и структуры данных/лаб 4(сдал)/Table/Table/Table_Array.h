#pragma once

#ifndef _TABLE_ARRAY_
#define _TABLE_ARRAY_
#define SIZE_TABLE_ARRAY 10
//�������������� ��������
const int tableOk = 0;
const int tableEmpty = 1;
const int tableFull = 2;
const int tableNoKey = 3;

extern int errorTableArray;//���������� ������

/*�������� �����*/
typedef int BaseType; // ������� ��� ������ �������
typedef int KeyBaseType; // ������� ��� ����� �������
typedef struct {
	KeyBaseType key;//���� �����
	BaseType date;//���� ������
} elementTableArray;

typedef struct {
	elementTableArray buf[SIZE_TABLE_ARRAY];// ����� �������
	unsigned uk;//���������
} TableArray;

void initTableArray(TableArray *T);// ������������� ������
void putTAbleArray(TableArray *T, elementTableArray E);// ��������� �������� � �������
void getTableArray(TableArray *T, elementTableArray *E, KeyBaseType key);// ���������� �������� �� �������
int searchKey(TableArray *T, KeyBaseType key);// ����� �������� � ������ ������
int isEmptyTableArray(TableArray *T);// ��������: ����� �� �������
int isFullTAbleArray(TableArray *T);// ��������: ����������� �� �������

#endif