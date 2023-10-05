#include <stdio.h>
#include <stdlib.h>

#include "tree.c"


void BildRegTree(Tree *T); //построить дерево

void WriteSequence(Tree *T, int N); /*Выводит упорядоченную по возрастанию последовательность, со-ставленную из элементов дерева, меньших k.*/

int WriteNodes(Tree *T);

int main()
{
    Tree T;
    int N;
    InitTree(&T);
    BildRegTree(&T);
    N=WriteNodes(&T);
    //WriteSequence(&T, 5);
    printf("%d\n", N);
    return 0;
}


void BildRegTree(Tree *T)
{
    int a;
    scanf("%d", &a);
    while (a!=0)
    {
        WriteDataTree(T,a);
        scanf("%d", &a);
    }
}

void WriteSequence(Tree *T, int N)
{
    if (N!=0)
    {
        Tree TS;
        InitTree(&TS);
        MoveToLSon(T,&TS);
        WriteSequence(&TS,N-1);
        MoveToRSon(T,&TS);
        WriteSequence(&TS,N-1);
    }
    printf("%d \n", T->data);
}

int WriteNodes(Tree *T)
{
    Tree TS;
    int M=0,K=0;
    if (IsLSon(T))
    {
        MoveToLSon(T,&TS);
        M+=WriteNodes(&TS);
        printf("LD-%d\n", M);//кол-во левых корней
    }
    if (IsRSon(T))
    {
        MoveToRSon(T,&TS);
        K+=WriteNodes(&TS);
        printf("RD-%d\n", K); //кол-во правых корней
    }

    return M+K;
}
