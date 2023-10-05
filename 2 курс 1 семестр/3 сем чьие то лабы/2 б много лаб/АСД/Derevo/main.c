#include <stdio.h>
#include <stdlib.h>
#include"Fifo.h"

int Simm_Front_P(Tree T,int n,int *k)
{
    int k1=0;
	if (!IsEmptyTree(T))
	{
		k1+=Simm_Front_P(T->LSon,n,k);
		k1+=Simm_Front_P(T->RSon,n,k);
		if (k1==n) (*k)++;
		return (1);
	}else {
	    return(0);
	}
}

void max_way(Tree T,int k,int *max)
{
	if (!IsEmptyTree(T))
	{
		max_way(T->LSon,k+1,max);
		max_way(T->RSon,k+1,max);
	}else {
	    if(k-1>*max) *max=k-1;
	}
}

void BuildTree(Tree *T1)
{
     Basetype T;
    BaseType c;
    Fifo *F;
    InitFifo(&F);
    scanf("%c",&c);
    if (c=='.')
        return;
    else
    {
        InitTree(T1);
        WriteDataTree(*T1,c);
        PutFifo(F,*T1);
    }
    while (!EmptyFifo(F)){
        GetFifo(F,&T);
        scanf("%c",&c);
        if (c!='.') {
            CreateRoot(&T->LSon);
            WriteDataTree(T->LSon,c);
            PutFifo(F,T->LSon);

        } else T->LSon=NULL;
        scanf("%c",&c);
        if (c!='.') {
            CreateRoot(&T->RSon);
            WriteDataTree(T->RSon,c);
            PutFifo(F,T->RSon);
        } else T->RSon=NULL;
    }
}

int main()
{
    Basetype T;
    BuildTree(&T);
     printf("Tree:\n");
    Simm_Front(T);
    printf("\n");
    int k=0;
    Simm_Front_P(T,0,&k);
     printf("Kol-vo vershin s N sinovey:\n");
    printf("%d\n",k);
    k=0;
    max_way(T,0,&k);
    printf("Max Way:\n");
    printf("%d\n",k);
	getchar();
	getchar();
    return 0;
}
