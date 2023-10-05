#ifndef _LIST_H_
#define _LIST_H_

const short ListOk=0;
const short ListNotMem=1;
const short ListEmpty=2;
static short ListError;
typedef int BaseType;
typedef struct element *ptrel;
typedef struct element
{
    BaseType data;
    ptrel next;
} element;
typedef struct
{
    ptrel Start;
    ptrel ptr;
} List;

//������������� ������
void InitList(List *L);
//������� � ������
void PutList(List *L, BaseType E);
//������ �� ������
void GetList(List *L, BaseType *E);

//������ �� ������
void ReadList(List *L, BaseType *E);

//�������� - ������ ����
int EmptyList(List *L);

//�������� - ����� ������
int EndList(List *L);

//����������� ��������� � ������
unsigned int Count(List *L);

//����������� �������� ��������� � ������ ������
void BeginPtr(List *L);


//����������� �������� ��������� �� ���� �������� �����
void MovePtr(List *L);

//����������� �������� ��������� �� ������� n
void MoveTo(List *L, unsigned int n);

//������� �����
void ClearList(List *L);

//����������� ������� ������ �� ������
void CopyList(List *L1, List *L2);

#endif
