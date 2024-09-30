#ifndef XTREE_H_INCLUDED
#define XTREE_H_INCLUDED
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

//создание корня
void CreateRoot(Tree* T);

//Есть левый сын
int IsLSon(Tree T);

//Есть левый сын
int IsRSon(Tree T);

//запись данных в дерево
void WriteDataTree(Tree *T, BaseType E);

//Чтение элемента дерева
void ReadDataTree(Tree T, BaseType* E);

//Переход к левому сыну
void MoveToLSon(Tree T, Tree *TS);

//Переход к правому сыну
void MoveTorSon(Tree T, Tree *TS);

//Дерево пусто
int IsEmptyTree(Tree T);

void DelTree(Tree T);

//симметричный проход слева-направо
void Simm_Front(Tree T);

//симметричный проход справа-налево
void Simm_Back(Tree T);

#endif // XTREE_H_INCLUDED
