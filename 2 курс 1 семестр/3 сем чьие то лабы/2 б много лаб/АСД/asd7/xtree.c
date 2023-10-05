#include<stdio.h>
#include<stdlib.h>
#include "xtree.h"

short TreeError;

void InitTree(Tree *T)
{
	CreateRoot(T);
}
//�������� �����
void CreateRoot(Tree* T)
{
	(*T) = (elptr)malloc(sizeof(elptr));
	(*T)->LSon = NULL;
	(*T)->RSon = NULL;
	(*T)->Data = 0;
}
//���� ����� ���
int IsLSon(Tree T)
{
	return (T->LSon != NULL);
}
//���� ����� ���
int IsRSon(Tree T)
{
	return (T->RSon != NULL);
}
//������ ������ � ������
void WriteDataTree(Tree *T, BaseType E)
{
    if (IsEmptyTree(T))
    {
        T->Data = E;
        return;
    }
    if (E<T->Data)
    {
        CreateRoot(&T->LSon);
        WriteDataTree(T->LSon, E);
        return;
    }
    if (E>T->Data)
    {
        CreateRoot(&T->RSon);
        WriteDataTree(T->RSon, E);
        return;
    }
}
//������ �������� ������
void ReadDataTree(Tree T, BaseType* E)
{
	if (T == NULL)
	{
		TreeError = TreeUnder;
		return;
	}
	else
		*E = T->Data;
}
//������� � ������ ����
void MoveToLSon(Tree T, Tree *TS)
{
	if (IsLSon(T))
		*TS = T->LSon;
	else
		TreeError = TreeUnder;
}
//������� � ������� ����
void MoveTorSon(Tree T, Tree *TS)
{
	if (IsRSon(T))
		*TS = T->RSon;
	else
		TreeError = TreeUnder;
}
//������ �����
int IsEmptyTree(Tree T)
{
	return(T == NULL);
}
void DelTree(Tree T)
{
    Tree *tmp;
    if (IsRSon(T))
    {
        MoveTorSon(T,&tmp);
        DelTree(tmp);
    }
    if (IsLSon(T))
    {
        MoveToLSon(T,&tmp);
        DelTree(tmp);
    }
    free(tmp);
	free(T);
}

