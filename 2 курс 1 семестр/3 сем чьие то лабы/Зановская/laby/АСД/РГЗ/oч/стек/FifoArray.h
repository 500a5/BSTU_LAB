#ifndef STACK_ARRAY_H_INCLUDED
#define STACK_ARRAY_H_INCLUDED

/*������ �����*/
const short StackSize = 100;

/*�������� �������������� ��������*/
const short stackOk = 0;											// ��� ���������
const short stackFull = 1;										// ���� ����������
const short stackEmpty = 2;										// ���� ����

/*���������� ������*/
extern int StackError = 0;
/*������� ��� �����*/
typedef int BaseType;
/*���������� �����*/
typedef struct
{
    BaseType buf[StackSize];						// ����� �����
    short uk;	                             			// ���������
} Stack;

/*������� ������ �� ������*/
void StackInit (Stack *S);									// ������������� �����
void StackPut (Stack *S, BaseType E);			// ��������� � ����
void StackGet (Stack *S, BaseType *E);			// ���������� �� �����
int StackFull (Stack *S);								// ��������: ����� �� ����
int StackEmpty (Stack *S);								// ��������: ���� �� ����


#endif // STACK_ARRAY_H_INCLUDED
