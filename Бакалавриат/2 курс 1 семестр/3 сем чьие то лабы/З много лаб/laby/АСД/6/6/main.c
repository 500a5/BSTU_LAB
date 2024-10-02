#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct
{
    char Name[10]; // им€ запроса
    unsigned Time; // врем€ обслуживани€
    char P; /* приоритет задачи: 0 Ч высший, 1 Ч средний, 2 Ч низший */
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
//»нициализаци€ стека
void StackInit(Stack *S)
{
    S->uk = 0;
    StackError = stackOk;
}
//¬ключение в стек
void StackPut(Stack *S, BaseType E)
{
    if (StackFull(S))
        return;
    S->buf[S->uk] = E;
    S->uk++;
}
//»сключение из стека
void StackGet(Stack *S, BaseType *E)
{
    if (StackEmpty(S))
        return;
    *E = S->buf[S->uk - 1];
    S->uk--;
}
//—тек полон
int StackFull(Stack *S)
{
    return (S->uk == StackSize);
}
//—тек пуст
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
    int uk1;		// ”казатель на хвост
    int uk2;		// ”казатель на голову
    int n;		//  оличество элементов в очереди
} Fifo;
int FifoError;
 //»нициализаци€ очереди
void FifoInit (Fifo *F)
{
    F->uk1 = 0;
    F->uk2 = 0;
    F->n = 0;
    FifoError = fifoOk;
}
//¬ключение в очередь
void FifoPut(Fifo *F, BaseType E)
{
    if (FifoFull(F))
        return;
    F->buf[F->uk2] = E;
    F->uk2 = (F->uk2 + 1) % FifoSize;
    F->n++;
}
//»сключение из очереди
void FifoGet (Fifo *F, BaseType *E)
{
    if (FifoEmpty(F))
        return;
    *E = F->buf[F->uk1];
    F->uk1 = (F->uk1 + 1) % FifoSize;
    F->n--;
}
//ќчередь полна
int FifoFull(Fifo *F) {
    return (F->n == FifoSize);
}
//ќчередь пуста
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
    int n=3, i=0;    printf("n >> "); //количество запросов
    scanf("%d", &n);
    TInquiry P1, P2, tmp;
    TInquiry *pa = (TInquiry*)calloc(n, sizeof(TInquiry)); //выделение пам€ти на массив
    generate(pa, n); //генераци€ массива запросов


    Fifo F1, F2, F3; 		//ќбъ€вление и инициализаци€ очередей
    FifoInit(&F1);
    FifoInit(&F2);
    FifoInit(&F3);

    Stack S;		//ќбъ€вление и инициализаци€ стеков
    StackInit(&S);


    FifoSort(pa, &F1, &F2, &F3, n); //распределили запросы по очеред€м

    while (StackEmpty(&S) ||!FifoEmpty(&F1) || !FifoEmpty(&F2) || !FifoEmpty(&F3) || P1.Time!=0 || P2.Time!=0)
    {
        if (!FifoEmpty(&F1)) //если нулева€ очередь не пуста
        {
            FifoGet(&F1,&tmp);
            if (P1.Time==0 && P2.Time == 0) //процессоры пусты
                P1=tmp;
            if (P1.Time!=0 && P2.Time==0) //пуст второй
                P2=tmp;
            if (P1.Time==0 && P2.Time!=0) //пуст первый, не пуст второй
                P1=tmp;
            if (P1.Time!=0 && P2.Time!=0 && tmp.P<P1.P)
            {
                StackPut(&S, P1); //поместили в стек то что было
                P1=tmp; //записали новый процесс
            }
            else if (P1.Time!=0 && P2.Time!=0 && tmp.P<P2.P)
            {
                StackPut(&S, P2); //поместили в стек то что было
                P2=tmp; //записали новый процесс
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
