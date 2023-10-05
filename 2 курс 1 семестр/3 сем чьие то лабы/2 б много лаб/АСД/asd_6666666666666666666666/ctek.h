#ifndef CTEK_H_INCLUDED
#define CTEK_H_INCLUDED
#include "zap.h"

/*������ �����*/
#define SIZE_STACK_ARRAY 100
/*�������� �������������� ��������*/
const int okStackArray = 0;											// ��� ���������
const int fullStackArray = 1;										// ���� ����������
const int emptyStackArray = 2;										// ���� ����
/*********************************/
/*���������� ������*/
extern int errorStackArray;
/*������� ��� �����*/
typedef TInquiry stackArrayBaseType;
/*���������� �����*/
typedef struct {
stackArrayBaseType buf[SIZE_STACK_ARRAY];						// ����� �����
unsigned uk;													// ���������
} StackArray;
/******************/
/*������� ������ �� ������*/
void initStackArray(StackArray *S);									// ������������� �����
void putStackArray(StackArray *S, stackArrayBaseType E);			// ��������� � ����
void getStackArray(StackArray *S, stackArrayBaseType *E);			// ���������� �� �����
int isFullStackArray(StackArray *S);								// ��������: ����� �� ����
int isEmptyStackArray(StackArray *S);								// ��������: ���� �� ����
/**************************/

#endif // CTEK_H_INCLUDED
