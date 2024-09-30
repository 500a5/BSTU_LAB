#include <stdio.h>
#include <stdlib.h>

#include "tree.c"


void BildRegTree(Tree *T);
void WriteSequence(Tree *T, int N);
int WriteNodes(Tree *T, int N);

int main()
{
    printf("Hello world!\n");
    return 0;
}


void BildRegTree(Tree *T)
{
    int a;
    scanf("%d", &a);
    while (a!=0)
    {
        WriteDataTree(&T,a);
        scanf("%d", &a);
    }
}

void WriteSequence(Tree *T, int N)
{
    if (N!=0)
    {

        Tree TS;
        MoveToLSon(T,&TS);
        WriteSequence(&TS,N-1);
        MoveToRSon(T,&TS);
        WriteSequence(&TS,N-1);
    }
}

int WriteNodes(Tree *T, int N)
{
    Tree TS;
    int M=0,K=0;
    if (IsLSon(T))
    {
        MoveToLSon(T,&TS);
        M+=WriteNodes(&TS,N);
        printf("LD-%d/n", M);
    }
    if (IsRSon(T))
    {
        MoveToRSon(T,&TS);
        K+=WriteNodes(&TS,N);
        printf("LD-%d/n", K);
    }
    return M+K;

}
