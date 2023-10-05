#include "xxtree.h"
#include <stdio.h>
#include <stdlib.h>

void InitTree(Tree *T)
{
    //T=NULL;
    //T = (Tree*)malloc(sizeof(Tree));
    T->data=0;
	T->LSon = NULL;
	T->RSon = NULL;
}

/*void CreateRoot(Tree *T)
{
    T->RSon=NULL;
    T->LSon=NULL;
    TreeError=TreeOk;
}*/

void WriteDataTree(Tree *T, BaseType E)
{
    printf("\n     %d \n", T->data);
    if (T->data==0)
    {
            T->data=E;
            return;

    }
    if(T->data<E)
    {
        if(!IsRSon(T))
        {
            WriteDataTree(&T->RSon,E);
            return;
        }
        else
        {
            T->LSon = (Tree*)malloc(sizeof(Tree));
            InitTree(&T->RSon);
            WriteDataTree(&T->RSon,E);
            return;
        }
    }
    if(T->data>E)
    {
        if(!IsLSon(T))
        {
            WriteDataTree(&T->LSon,E);
            return;
        }
        else
        {
            T->RSon = (Tree*)malloc(sizeof(Tree));
            InitTree(&T->LSon);
            WriteDataTree(&T->LSon,E);
            return;
        }
    }
}

void ReadDataTree(Tree *T,BaseType *E)
{
    E=T->data;
}

int  IsLSon(Tree *T)
{
    if (T->LSon==NULL)
    {
        TreeError=TreeUnder;
        return;
    }
    return T->LSon==NULL;
}

int  IsRSon(Tree *T)
{
    if (T->RSon==NULL)
    {
        TreeError=TreeUnder;
        return;
    }
    return T->RSon==NULL;
}

void MoveToLSon(Tree *T, Tree *TS)
{
    if (T->LSon==NULL)
    {
        TreeError=TreeUnder;
        return;
    }
    TS=T->LSon;

}

void MoveToRSon(Tree *T, Tree *TS)
{ if (T->RSon==NULL)
    {
        TreeError=TreeUnder;
        return;
    }
    TS=T->RSon;
}

int  IsEmptyTree(Tree *T)
{
    return T==NULL;
}

void DelTree(Tree *T)
{
        Tree TS;
        if (IsLSon(T))
        {
            MoveToLSon(T,&TS);
            DelTree(&TS);
        }
        if (IsRSon(T))
        {
            MoveToLSon(T,&TS);
            DelTree(&TS);
        }
        free(T);
}
