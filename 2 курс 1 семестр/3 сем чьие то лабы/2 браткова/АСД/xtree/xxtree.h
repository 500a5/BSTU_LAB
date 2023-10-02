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

void InitTree(Tree *T);// инициализаци¤ Ч создаетс¤  элемент, который бу-дет содержать корень дерева

//void CreateRoot(Tree *T); //создание корн¤

void WriteDataTree(Tree *T, BaseType E); //запись данных

void ReadDataTree(Tree *T,BaseType *E);//чтение

int  IsLSon(Tree *T);//1  есть левый сын, 0  нет

int  IsRSon(Tree *T);//1  есть правый сын, 0  нет

void MoveToLSon(Tree *T, Tree *TS);// перейти к левому сыну, где T Ч ад-рес ¤чейки, содержащей адрес текущей вершины,

//TS Ч адрес ¤чейки, со-держащей адрес корн¤ левого поддерева(левого сына)

void MoveToRSon(Tree *T, Tree *TS);//перейти к правому сыну

int  IsEmptyTree(Tree *T);//1 Ч пустое дерево,0 Ч не пустое

void DelTree(Tree *T);//удаление листа

#endif // XXTREE_H_INCLUDED
