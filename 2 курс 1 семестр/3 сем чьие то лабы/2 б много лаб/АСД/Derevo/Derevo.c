#include<stdio.h>
#include<stdlib.h>
#include"Derevo.h"

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
void WriteDataTree(Tree T, BaseType E)
{
	if (T->Data == 0)
	{
		T->Data = E;
	}
	else
	{
		if (T->Data > E)
		{printf("123\n");
			if (!IsLSon(T))
				CreateRoot(&T->LSon);
			WriteDataTree(T->LSon, E);
		}
		else
		{
			if (!IsRSon(T))
				CreateRoot(&T->RSon);
			WriteDataTree(T->RSon, E);
		}
	}
}
//������ �������� ������
void ReadDataTree(Tree T, BaseType* E)
{
	if (T == NULL)
	{
		TreeError = TreeUnder;
	}
	else
	{
		*E = T->Data;
	}
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
	free(T);
}
//������������ ������ �����-�������
void Simm_Front(Tree T)
{
	if (!IsEmptyTree(T))
	{
		Simm_Front(T->LSon);
		printf("%c ", T->Data);
		Simm_Front(T->RSon);
	}
}
//������������ ������ ������-������
void Simm_Back(Tree T)
{
	if (!IsEmptyTree(T))
	{
		Simm_Back(T->RSon);
		printf("%c ", T->Data);
		Simm_Back(T->LSon);
	}
}



