#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct
{
    char Name[10]; // ��� �������
    unsigned Time; // ����� ������������
    char P; /* ��������� ������: 0 � ������, 1 � �������, 2 � ������ */
}TInquiry;
typedef TInquiry BaseType;
const short StackSize = 100;
const short stackOk = 0;
const short stackFull = 1;
const short stackEmpty = 2;
//extern short StackError = 0;

typedef struct
{
    BaseType buf[100];
    short uk;
} Stack;

short StackError = 0;
//������������� �����
void StackInit(Stack *S)
{
    S->uk = 0;
    StackError = stackOk;
}
//��������� � ����
void StackPut(Stack *S, BaseType E)
{
    if (StackFull(S))
        return;
    S->buf[S->uk] = E;
    S->uk++;
}
//���������� �� �����
void StackGet(Stack *S, BaseType *E)
{
    if (StackEmpty(S))
        return;
    *E = S->buf[S->uk - 1];
    S->uk--;
}
//���� �����
int StackFull(Stack *S)
{
    return (S->uk == StackSize);
}
//���� ����
int StackEmpty(Stack *S)
{
    return (S->uk == 0);
}


const short FifoSize = 100;
const int fifoOk = 0;
const int fifoFull = 1;
const int fifoEmpty = 2;
//extern short FifoError;

typedef struct
{
    BaseType buf[100];
    int uk1;		// ��������� �� �����
    int uk2;		// ��������� �� ������
    int n;		// ���������� ��������� � �������
} Fifo;
int FifoError;
 //������������� �������
void FifoInit (Fifo *F)
{
    F->uk1 = 0;
    F->uk2 = 0;
    F->n = 0;
    FifoError = fifoOk;
}
//��������� � �������
void FifoPut(Fifo *F, BaseType E)
{
    if (FifoFull(F))
        return;
    F->buf[F->uk2] = E;
    F->uk2 = (F->uk2 + 1) % FifoSize;
    F->n++;
}
//���������� �� �������
void FifoGet (Fifo *F, BaseType *E)
{
    if (FifoEmpty(F))
        return;
    *E = F->buf[F->uk1];
    F->uk1 = (F->uk1 + 1) % FifoSize;
    F->n--;
}
//������� �����
int FifoFull(Fifo *F) {
    return (F->n == FifoSize);
}
//������� �����
int FifoEmpty(Fifo *F){
    return (F->n == 0);
}

void generate (TInquiry *pa, int n)
{
    int i=0;
    for (i=0;i<n;i++)
    {
        printf ("Name:  ");
        scanf ("%s",pa[i].Name);
        printf ("Time:  ");
        scanf ("%d",&pa[i].Time);
        printf ("Priority:  ");
        scanf ("%s",&pa[i].P);
        printf("\n");
    }
}

void FifoSort (TInquiry *pa, Fifo *F1,Fifo *F2,Fifo *F3, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (pa[i].P == 0)
            FifoPut(F1, pa[i]);
        if (pa[i].P == 1)
            FifoPut(F2, pa[i]);
        if (pa[i].P == 2)
            FifoPut(F3, pa[i]);
    }
}


int main()
{
    srand(time(NULL));
    int n=3, i=0;    printf("n >> "); //���������� ��������
    scanf("%d", &n);
    TInquiry P1, P2, tmp;
    TInquiry *pa = (TInquiry*)calloc(n, sizeof(TInquiry)); //��������� ������ �� ������
    generate(pa, n); //��������� ������� ��������


    Fifo F1, F2, F3; 		//���������� � ������������� ��������
    FifoInit(&F1);
    FifoInit(&F2);
    FifoInit(&F3);

    Stack S;		//���������� � ������������� ������
    StackInit(&S);


    FifoSort(pa, &F1, &F2, &F3, n); //������������ ������� �� ��������

    while (StackEmpty(&S) ||!FifoEmpty(&F1) || !FifoEmpty(&F2) || !FifoEmpty(&F3) || P1.Time!=0 || P2.Time!=0)
    {
        if (!FifoEmpty(&F1)) //���� ������� ������� �� �����
        {
            FifoGet(&F1,&tmp);
            if (P1.Time==0 && P2.Time == 0) //���������� �����
                P1=tmp;
            if (P1.Time!=0 && P2.Time==0) //���� ������
                P2=tmp;
            if (P1.Time==0 && P2.Time!=0) //���� ������, �� ���� ������
                P1=tmp;
            if (P1.Time!=0 && P2.Time!=0 && tmp.P<P1.P)
            {
                StackPut(&S, P1); //��������� � ���� �� ��� ����
                P1=tmp; //�������� ����� �������
            }
            else if (P1.Time!=0 && P2.Time!=0 && tmp.P<P2.P)
            {
                StackPut(&S, P2); //��������� � ���� �� ��� ����
                P2=tmp; //�������� ����� �������
            }
        }
        else
        {
            if (P1.Time!=0)
                P1.Time--;
            else
            {
                if(!StackEmpty(&S))
                    StackGet(&S, &P1);
                else
                    if (!FifoEmpty(&F1))
                        FifoGet(&F1, &P1);
            }
            if (P2.Time!=0)
                P2.Time--;
            else
            {
                if(!StackEmpty(&S))
                    StackGet(&S, &P2);
                else
                    if (!FifoEmpty(&F1))
                        FifoGet(&F1, &tmp);
            }
        }

        if (!FifoEmpty(&F2))
        {
            FifoGet(&F2,&tmp);
            if (P1.Time==0 && P2.Time == 0)
                P1=tmp;
            if (P1.Time!=0 && P2.Time==0)
                P2=tmp;
            if (P1.Time==0 && P2.Time!=0)
                P1=tmp;
            if (P1.Time!=0 && P2.Time!=0 && tmp.P<P1.P)
            {
                StackPut(&S, P1);
                P1=tmp;
            }
            else
                if (P1.Time!=0 && P2.Time!=0 && tmp.P<P2.P)
                {
                    StackPut(&S, P2);
                    P2=tmp;
                }
        }
        else
        {
            if (P1.Time!=0)
                P1.Time--;
            else
            {
                if(!StackEmpty(&S))
                    StackGet(&S, &P1);
                else
                    if (!FifoEmpty(&F2))
                        FifoGet(&F2, &tmp);
            }
            if (P2.Time!=0)
                P2.Time--;
            else
            {
                if(!StackEmpty(&S))
                    StackGet(&S, &P2);
                else
                    if (!FifoEmpty(&F2))
                        FifoGet(&F2, &tmp);
            }
        }
        if (!FifoEmpty(&F3))
        {
            FifoGet(&F3,&tmp);
            if (P1.Time==0 && P2.Time == 0)
                P2=tmp;
            if (P1.Time!=0 && P2.Time==0)
                P2=tmp;
            if (P1.Time==0 && P2.Time!=0)
                P1=tmp;
            if (P1.Time!=0 && P2.Time!=0 && tmp.P<P1.P)
            {
                StackPut(&S, P1);
                P1=tmp;
            }
            else
                if (P1.Time!=0 && P2.Time!=0 && tmp.P<P2.P)
                {
                    StackPut(&S, P2);
                    P2=tmp;
                }
        }
        else
        {
            if (P1.Time!=0)
                P1.Time--;
            else
            {
                if(!StackEmpty(&S))
                    StackGet(&S, &P1);
                else
                    if (!FifoEmpty(&F3))
                        FifoGet(&F3, &tmp);
            }
            if (P2.Time!=0)
                P2.Time--;
            else
            {
                if(!StackEmpty(&S))
                    StackGet(&S, &P2);
                else
                    if (!FifoEmpty(&F3))
                        FifoGet(&F3, &tmp);
            }
        }
    }
    return 0;
}
