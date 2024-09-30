#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;
int popBack(Node **head);
const	ListOk = 0;
const  	ListNotMem = 1;
const  	ListUnder = 2;
const  	ListEnd  = 3;
typedef int BaseType;
typedef  struct element *ptrel;
typedef   struct element
{
    BaseType data;
    ptrel next;
};
typedef  struct List
{
    ptrel Start;
    ptrel ptr;
    int N;
} List;
short ListError;
void ReadList(List *L,BaseType *E);
void InitList(List *L)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp->data=NULL;
    tmp->next=NULL;
    L->ptr=tmp;
    L->Start=tmp;
    L->N=0;
}
void InputList(List *L)
{
    int i;
    BaseType E;
    L=(struct List*)malloc(sizeof (struct List));
    InitList(L);
    printf ("i = ");
    scanf ("%d",&i);
    L->Start = NULL;
    L->N=1;
    scanf ("%d",&E);
    i--;
    PutList(L,E);
    L->Start = L->ptr;
    while(i--!=0)
    {
        scanf ("%d",&E);
        PutList(L,E);
        L->N+=1;
    }
}

void PutList(List *L, BaseType E)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp->data = E;
    tmp->next = NULL;
    L->ptr = tmp;
    L->N+=1;
}
void GetList(List *L, BaseType *E)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    struct element *tmp1 = (struct element*) malloc(sizeof(struct element));
    tmp=L->Start;

    while (tmp->data != E) // просматриваем список начиная с корня
    {
        tmp1= tmp->next;
        tmp = tmp->next;
    }
    tmp1->next = tmp->next; // переставляем указатель
    L->N-=1;
}
void ReadList(List *L,BaseType *E)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp=L->Start;
    while (tmp->data != E)
        tmp = tmp->next;
}

int EmptyList(List *L)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp=L->ptr;
    if (tmp->next!=NULL)
        return 0;
    else return 1;
}
int EndList(List *L)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp=L->ptr;
    if (tmp->next!=NULL)
        return 0;
    else return 1;
}

int Count(List *L)
{
    int i=0;
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp=L->Start;
    while (tmp->next!=NULL)
    {
        i++;
        tmp=tmp->next;
    }
}

void BeginPtr(List *L)
{
    L->ptr=L->Start;
}
void EndPtr(List *L)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp=L->Start;
    while (tmp->next != NULL)
        tmp = tmp->next;
    L->ptr=tmp;
}

void MovePtr(List *L)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp=L->ptr;
    tmp=tmp->next;
    L->ptr=tmp;
}
void MoveTo(List *L, int n)
{
    int i=0;
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp=L->Start;
    while (i<n)
    {
        tmp = tmp->next;
        i++;
    }

    L->ptr=tmp;
}
void DoneList(List *L)
{
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp = L->ptr;
    while (tmp->next)
    {
        tmp = tmp->next;
        free(tmp);
    }
    free(L->Start);
}

void CopyList(List *L1,List *L2)
{
    L1->Start = L2->Start;
    L1->N = L2->N;
    struct element *tmp = (struct element*) malloc(sizeof(struct element));
    tmp=L1->Start;
    while (tmp->next!=NULL)
    {
        tmp=tmp->next;
        PutList(L2,tmp->data);
    }
}

