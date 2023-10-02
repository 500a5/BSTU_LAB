#include <stdio.h>
#include "StackArray.h"
/*���������� ������*/
int StackError;
/*������������� �����*/
void StackInit(Stack *S)
{
    S->uk = 0;
    StackError = StackOk;
}
/*��������� � ����*/
void StackPut(Stack *S, BaseType E)
{
/*���� ���� ����������*/
    if (StackFull(S))
    {
        return;
    }
    /*�����*/
    S->buf[S->uk] = E;				// ��������� ��������
    S->uk++;							 	// ����� ���������
}
/*���������� �� �����*/
void getStackArray(StackArray *S, stackArrayBaseType *E)
{
/*���� ���� ����*/
    if (isEmptyStackArray(S))
        return;

/*�����*/
    *E = S->buf[S->uk - 1];		// ���������� �������� � ����������
    S->uk--;							 	// ����� ���������
}
/*��������: ����� �� ����*/
int isFullStackArray(StackArray *S)
{
    if (S->uk == SIZE_STACK_ARRAY)
    {
        StackError = StackFull;
        return 1;
    }
    return 0;
}
/*��������: ���� �� ����*/
int isEmptyStackArray(StackArray *S)
{
    if (S->uk == 0)
    {
        StackError = StackEmpty;
        return 1;
    }
    return 0;
}
