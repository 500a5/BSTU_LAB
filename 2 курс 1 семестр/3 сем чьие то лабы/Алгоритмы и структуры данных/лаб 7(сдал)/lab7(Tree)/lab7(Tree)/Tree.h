#pragma once

#ifndef __TREE1_H
#define __TREE1_H
const short TreeOk = 0;
const short TreeNotMem = 1;
const short TreeUnder = 2;
const short NullPoint = 3;
typedef	void* basetype;
typedef struct elementT *ptrel;

typedef struct elementT {
	basetype data;
	ptrel LSon;
	ptrel RSon;
};

typedef ptrel Tree;
extern short TreeError;
void InitTree(Tree *T);// ������������� � ���������  �������, ������� ��-��� ��������� ������ ������
void CreateRoot(Tree *T); //�������� �����
void WriteDataTree(Tree *T, basetype E); //������ ������
basetype ReadDataTree(Tree *T);//������
int  IsLSon(Tree *T);//1 � ���� ����� ���, 0 � ��� 
int  IsRSon(Tree *T);//1 � ���� ������ ���, 0 � ��� 
void MoveToLSon(Tree *T, Tree *TS);// ������� � ������ ����, ��� T � ��-��� ������, ���������� ����� ������� �������, TS � ����� ������, ��-�������� ����� ����� ������ ���������(������ ����)
void MoveToRSon(Tree *T, Tree *TS);//������� � ������� ����
int  IsEmptyTree(Tree *T);//1 � ������ ������,0 � �� ������
void DelTree(Tree *T);//�������� �����
#endif

