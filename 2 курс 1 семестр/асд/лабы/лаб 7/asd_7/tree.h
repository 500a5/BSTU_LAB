
#ifndef ASD_7_TREE_H
#define ASD_7_TREE_H
#define SizeMem 100

#define TreeOk 0
#define TreeNotMem 1
#define TreeUnder 2

extern int TreeError;

typedef int BaseType;
typedef unsigned char PtrEl;
typedef struct element{
    BaseType Data;
    PtrEl LSon;
    PtrEl RSon;
}element;
typedef PtrEl *Tree;

element MemTree[SizeMem];

void InitTree(Tree *T);
void CreateRoot(Tree *T);
void WriteDataTree(Tree *T, BaseType E);
void ReadDataTree(Tree *T, BaseType *E);
int IsLSon(Tree *T);
int IsRSon(Tree *T);
void MoveToLSon(Tree *T, Tree *TS);
void MoveToRSon(Tree *T, Tree *TS);
int IsEmptyTree(Tree *T);
void DellTree(Tree *T);

void InitMem();
int EmptyMem();
int NewMem();
void DisposeMem(int n);

#endif //ASD_7_TREE_H
