#include <stdio.h>
#include "Fifo.h"
#include "Stack.h"



int main() {
    Fifo* f1 = (Fifo*) malloc(sizeof(Fifo));
    Fifo* f2 = (Fifo*) malloc(sizeof(Fifo));
    Fifo* f3 = (Fifo*) malloc(sizeof(Fifo));

    Stack* s1 = (Stack*) malloc(sizeof(Stack));
    Stack* s2 = (Stack*) malloc(sizeof(Stack));

    InitFifo(f1);
    InitFifo(f2);
    InitFifo(f3);
    InitStack(s1);
    InitStack(s2);
    short p1 = 0, p2 = 0;

    int k1 = 0, k2 = 0;

    BaseType q, q1, q2;

    int k = 0, n = 1;

    int f = 0;

    printf("Введите запрос: ");
    scanf("%d %d %d", &(q.data), &(q.time), &(q.p));

    while (k < n)
    {
        if(!f)
        {
            if(q.p == 0)
            {
                PutFifo(f1, q);
            }
            else if(q.p == 1){
                PutFifo(f2, q);
            }
            else{
                PutFifo(f3, q);
            }

        }

        if ((!EmptyFifo(f1) && !p1) || (!EmptyFifo(f1) && !p2) )
        {
            if(!p1)
            {
                printf("f1 в q1\n");
                GetFifo(f1, &q1);
                k1 = 0;
                p1 = 1;
            }
            else{
                printf("f1 в q2\n");
                GetFifo(f1, &q2);
                k2 = 0;
                p2 = 1;
            }
        }

        if (EmptyFifo(f1) && ((!EmptyFifo(f2) && !p1) || (!EmptyFifo(f2) && !p2)))
        {
            if(!p1)
            {
                printf("f2 в q1\n");
                GetFifo(f2, &q1);
                k1 = 0;
                p1 = 1;
            }
            else{
                printf("f2 в q2\n");
                GetFifo(f2, &q2);
                k2 = 0;
                p2 = 1;
            }
        }

        if (EmptyFifo(f1) && EmptyFifo(f2) && ((!EmptyFifo(f3) && !p1) || (!EmptyFifo(f3) && !p2)))
        {
            if(!p2)
            {
                printf("f3 в q2\n");
                GetFifo(f3, &q2);
                k2 = 0;
                p2 = 1;
            }
            else{
                printf("f3 в q1\n");
                GetFifo(f3, &q1);
                k1 = 0;
                p1 = 1;
            }
        }

        if (!EmptyFifo(f1) && p1 && p2 && (q1.p != 0 || q2.p != 0))
        {
            printf("Работа со стеком для f1\n");
            if(q1.p != 0)
            {
                PutStack(s1, q1);
                GetFifo(f1, &q1);
                k2 = 0;
            }
            else{
                PutStack(s1, q2);
                GetFifo(f1, &q2);
                k2 = 0;
            }
        }
        else if(!EmptyFifo(f2) && p1 && p2 && (q1.p == 2 || q2.p == 2))
        {
            printf("Работа со стеком для f2\n");
            if(q1.p == 2)
            {
                PutStack(s2, q1);
                GetFifo(f2, &q1);
                k2 = 0;
            }
            else{
                PutStack(s2, q2);
                GetFifo(f2, &q2);
                k2 = 0;
            }
        }
        else if(!(EmptyStack(s1)|| !EmptyStack(s2))&& (!p1 || !p2))
        {
            printf("Достаем значение из стека\n");
            if(!p1)
            {
                GetStack(s1, &q1);
                k1 = 0;
                p1 = 1;
            }
            else{
                GetStack(s2, &q2);
                k2 = 0;
                p2 = 1;
            }

        }

        if (p1)
        {
            k1++;
            if (k1 >= q1.time)
            {
                printf("Обр. процессора p1:  %d \n", q1.data);
                k1 = 0;
                p1 = 0;
                k++;
            }
        }

        if (p2)
        {
            k2++;
            if (k2 >= q2.time)
            {
                printf("Обр. процессора p2:  %d \n", q2.data);
                k2 = 0;
                p2 = 0;
                k++;
            }
        }

        if(!f)
        {
            printf("Введите запрос: ");
            scanf("%d %d %d", &(q.data), &(q.time), &(q.p));
            n++;

        }
        if (!f && q.data == 0)
        {
            f = 1;
            n--;
        }
    }

    return 0;
}