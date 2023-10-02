#ifndef DEREVO_H_INCLUDED
#define DEREVO_H_INCLUDED

enum {TreeOk, TreeNotMem, TreeUnder};
typedef char BaseType;
typedef struct El *elptr;
typedef struct El
{
	BaseType Data;
	elptr LSon;
	elptr RSon;
} El;
typedef elptr Tree;
void InitTree(Tree *T);
//�������� �����
void CreateRoot(Tree* T);
//���� ����� ���
int IsLSon(Tree T);
//���� ����� ���
int IsRSon(Tree T);
//������ ������ � ������
void WriteDataTree(Tree *T, BaseType E);
//������ �������� ������
void ReadDataTree(Tree T, BaseType* E);
//������� � ������ ����
void MoveToLSon(Tree T, Tree *TS);
//������� � ������� ����
void MoveTorSon(Tree T, Tree *TS);
//������ �����
int IsEmptyTree(Tree T);
void DelTree(Tree T);

#endif // DEREVO_H_INCLUDED
