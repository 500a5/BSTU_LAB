
#include "Tree.h"
#include "malloc.h"
short TreeError = TreeOk;

// ������������� � ���������  �������, ������� ��-��� ��������� ������ ������
void InitTree(Tree *T) {
	*T = NULL;
	TreeError = TreeOk;
}

//�������� �����
void CreateRoot(Tree *T) {
	*T = (Tree)malloc(sizeof(elementT));
	
	if (*T == NULL) {//���� �� ������� �������� ������
		TreeError = TreeNotMem;
		return;
	}
	(*T)->data = NULL;
	(*T)->LSon = NULL;
	(*T)->RSon = NULL;
}

//������ ������
void WriteDataTree(Tree *T, basetype E) {
	(*T)->data = E;
}

//������
basetype ReadDataTree(Tree *T) {
	return (*T)->data;
}

//1 � ���� ����� ���, 0 � ��� 
int IsLSon(Tree *T) {
	return ((*T)->LSon != NULL) ? 1 : 0;
}

//1 � ���� ������ ���, 0 � ��� 
int IsRSon(Tree *T) {
	return ((*T)->RSon != NULL) ? 1 : 0;
}


// ������� � ������ ����, ��� T � ��-��� ������, ���������� ����� ������� �������, TS � ����� ������, ��-�������� ����� ����� ������ ���������(������ ����)
void MoveToLSon(Tree *T, Tree *TS) {
	if ((*T)->LSon == NULL) {
		TreeError = NullPoint;
		return;
	}
	*TS = (*T)->LSon;
}

//������� � ������� ����
void MoveToRSon(Tree *T, Tree *TS) {
	if ((*T)->RSon == NULL) {
		TreeError = NullPoint;
		return;
	}
	*TS = (*T)->RSon;
}

//1 � ������ ������,0 � �� ������
int IsEmptyTree(Tree *T) {
	return (*T == NULL) ? 1 : 0;
}

//�������� �����
void DelTree(Tree *T) {
	free(*T);
}