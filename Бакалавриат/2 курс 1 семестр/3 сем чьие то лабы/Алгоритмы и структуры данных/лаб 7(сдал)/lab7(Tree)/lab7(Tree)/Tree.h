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
void InitTree(Tree *T);// инициализаци€ Ч создаетс€  элемент, который бу-дет содержать корень дерева
void CreateRoot(Tree *T); //создание корн€
void WriteDataTree(Tree *T, basetype E); //запись данных
basetype ReadDataTree(Tree *T);//чтение
int  IsLSon(Tree *T);//1 Ч есть левый сын, 0 Ч нет 
int  IsRSon(Tree *T);//1 Ч есть правый сын, 0 Ч нет 
void MoveToLSon(Tree *T, Tree *TS);// перейти к левому сыну, где T Ч ад-рес €чейки, содержащей адрес текущей вершины, TS Ч адрес €чейки, со-держащей адрес корн€ левого поддерева(левого сына)
void MoveToRSon(Tree *T, Tree *TS);//перейти к правому сыну
int  IsEmptyTree(Tree *T);//1 Ч пустое дерево,0 Ч не пустое
void DelTree(Tree *T);//удаление листа
#endif

