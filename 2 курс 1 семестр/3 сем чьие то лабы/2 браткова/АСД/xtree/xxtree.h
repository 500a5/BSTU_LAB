#ifndef XXTREE_H_INCLUDED
#define XXTREE_H_INCLUDED


const int	TreeOk =0;
const   int  TreeNotMem = 1;
const int 	TreeUnder = 2;
typedef	int BaseType;

typedef   struct Tree *ptrel;
typedef   struct Tree{
                            BaseType data;
                            ptrel LSon;
                            ptrel RSon;
                        }Tree;


short TreeError;

void InitTree(Tree *T);// ������������ � ��������  �������, ������� ��-��� ��������� ������ ������

//void CreateRoot(Tree *T); //�������� ����

void WriteDataTree(Tree *T, BaseType E); //������ ������

void ReadDataTree(Tree *T,BaseType *E);//������

int  IsLSon(Tree *T);//1  ���� ����� ���, 0  ���

int  IsRSon(Tree *T);//1  ���� ������ ���, 0  ���

void MoveToLSon(Tree *T, Tree *TS);// ������� � ������ ����, ��� T � ��-��� ������, ���������� ����� ������� �������,

//TS � ����� ������, ��-�������� ����� ���� ������ ���������(������ ����)

void MoveToRSon(Tree *T, Tree *TS);//������� � ������� ����

int  IsEmptyTree(Tree *T);//1 � ������ ������,0 � �� ������

void DelTree(Tree *T);//�������� �����

#endif // XXTREE_H_INCLUDED
