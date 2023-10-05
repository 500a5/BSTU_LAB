#include <stdio.h>
#include <stdlib.h>

const short ListOk=0;
const short ListNotMem=1;
const short ListEmpty=2;
static short ListError;
typedef int BaseType;
typedef struct element *ptrel;
typedef struct element
{
    BaseType data;
    ptrel next;
} element;
typedef struct
{
    ptrel Start;
    ptrel ptr;
} List;


//������������� ������
void InitList(List *L)
{
    L->Start = (ptrel)malloc(sizeof(element));
    if (L->Start==NULL)
    {
        ListError=ListNotMem;
        return;
    }
    L->ptr=L->Start;
    L->ptr->next=NULL;
    ListError=ListOk;
}

//������� � ������
void PutList(List *L, BaseType E)
{
    ptrel tmp = (ptrel)malloc(sizeof(element));

    tmp->data=E;
    tmp->next=L->ptr->next;
    L->ptr->next=tmp;
    L->ptr=L->ptr->next;
}

//������ �� ������
void GetList(List *L, BaseType *E)
{
    ptrel tmp;
    if (EmptyList(L))
    {
        return;
    }
    tmp=L->ptr->next;
    L->ptr->next=tmp->next;
    *E = tmp->data;
    free(tmp);
}

//������ �� ������
void ReadList(List *L, BaseType *E)
{
    if (EmptyList(L))
    {
        return;
    }
    *E=L->ptr->data;
}

//�������� - ������ ����
int EmptyList(List *L)
{
    return (L->Start->next == NULL);
}

//�������� - ����� ������
int EndList(List *L)
{
    return (L->ptr->next == NULL);
}

//����������� ��������� � ������
unsigned int Count(List *L)
{
    unsigned int counter = 0;
    ptrel tmp = L->Start->next;
    while (tmp->next != NULL)
    {
        counter++;
        tmp=tmp->next;
    }
    return counter;
}

//����������� �������� ��������� � ������ ������
void BeginPtr(List *L)
{
    L->ptr=L->Start;
}

//����������� �������� ��������� �� ���� �������� �����
void MovePtr(List *L)
{
    L->ptr=L->ptr->next;
}

//����������� �������� ��������� �� ������� n
void MoveTo(List *L, unsigned int n)
{
    unsigned int counter=0;
    ptrel tmp = L->Start;
    while(counter++!=n)
    {
        tmp = tmp->next;
    }
    L->ptr=tmp;
}

//������� �����
void ClearList(List *L)
{
    ptrel tmp, tmpnext;
    tmp = L->Start;
    tmpnext=tmp->next;
    while (EmptyList(L))
    {
        tmp=tmpnext;
        tmpnext=tmpnext->next;
        free(tmp);
    }
    free(L->Start);
    ListError=ListEmpty;
}

//����������� ������� ������ �� ������
void CopyList(List *L1, List *L2)
{
    ptrel tmp = L1->Start;
    while (tmp->next!=NULL)
    {
        PutList(L2, tmp->next->data);
        tmp=tmp->next;
    }
}

void InputList(List *L)
{
    int i;
    BaseType E;

    InitList(L);
    printf ("i = ");
    scanf ("%d",&i);

    while(i--!=0)
    {
        scanf ("%d",&E);
        PutList(L,E);
//        L->N+=1;
    }
}
int check (List *L)
{
    int fl=1,t,f;
    BaseType E,x,T;
    BeginPtr(L);
    MovePtr(L);
    if (EmptyList(L))
        return 0;
//��� ���������
    ReadList(L,&x);
    if (EndList(L))
        return 1;
    //2 ��-�� - ����������
    MovePtr(L);
    ReadList(L,&T);

    f=T-x;
    while (fl&&!EndList(L))
    {
        MovePtr(L);
        ReadList(L,&E);

        fl=(f==E-T);
        T=E;
    }
    return fl;
}
void output (List *L)
{
    BeginPtr(L);
    MovePtr(L);
    while (L->ptr!=NULL)
    {
        printf ("%d  ", L->ptr->data);
        MovePtr(L);
    }
}

void main ()
{
    List *L;
    L=(struct List*)malloc(sizeof ( List));
    InputList (L);
    output(L);
    printf ("\n%d",check (L));
}


