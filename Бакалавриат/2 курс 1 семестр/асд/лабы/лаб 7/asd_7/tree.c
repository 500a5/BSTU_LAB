
#include "tree.h"


#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int TreeError;

void InitTree(Tree *T)
{
    InitMem();
    *T = NULL;
    TreeError = TreeOk;
}

void CreateRoot(Tree *T)
{
    if (!EmptyMem())
    {
        int k = NewMem();
        MemTree[k].LSon = 0;
        MemTree[k].RSon = 0;
        *T = k;
        TreeError = TreeOk;
    }
    else
        TreeError = TreeNotMem;
}

void WriteDataTree(Tree *T, BaseType E)
{
    int k = *T;
    MemTree[k].Data = E;
    TreeError = TreeOk;
}

void ReadDataTree(Tree *T, BaseType *E)
{
    int k = *T;
    *E = MemTree[k].Data;
    TreeError = TreeOk;
}

int IsLSon(Tree *T)
{
    int k = *T;
    TreeError = TreeOk;
    return (MemTree[k].LSon != 0);
}

int IsRSon(Tree *T)
{
    int k = *T;
    TreeError = TreeOk;
    return (MemTree[k].RSon != 0);
}

void MoveToLSon(Tree *T, Tree *TS)
{
    int k = *T;
    if (MemTree[k].LSon)
    {
        *TS = MemTree[k].LSon;
        TreeError = TreeOk;
    }
    else
        TreeError = TreeUnder;
}

void MoveToRSon(Tree *T, Tree *TS)
{
    int k = *T;
    if (IsRSon(T))
    {
        *TS = MemTree[k].RSon;
        TreeError = TreeOk;
    }
    else
        TreeError = TreeUnder;
}

int IsEmptyTree(Tree *T)
{
    return !(IsLSon(T) || IsRSon(T));
}

void DellTree(Tree *T)
{
    Tree *TS;
    if (IsRSon(*T))
    {
        MoveToRSon(*T, *TS);
        DellTree(*TS);
    }
    if (IsLSon(*T))
    {
        MoveToLSon(*T, *TS);
        DellTree(*TS);
    }
    int k = *T;
    DisposeMem(k);
}


void InitMem()
{
    for (int i = 0; i < SizeMem - 1; i++)
    {
        MemTree[0].Data = NULL;
        MemTree[0].LSon = NULL;
        MemTree[i].RSon = i + 1;
    }
}

int EmptyMem()
{
    return (MemTree[SizeMem - 1].Data != NULL);
}

int NewMem()
{
    unsigned char t = MemTree[0].RSon;
    MemTree[0].RSon = MemTree[t].RSon;
    return t;
}

void DisposeMem(int n)
{
    MemTree[n].Data = NULL;
    MemTree[n].LSon = NULL;
    MemTree[n].RSon = MemTree[0].RSon;
    MemTree[0].RSon = n;
}
