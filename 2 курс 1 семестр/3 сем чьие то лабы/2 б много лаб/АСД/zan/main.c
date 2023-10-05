#include <stdio.h>
#include <stdlib.h>
#include"Derevo.h"
//симметричный проход слева-направо
void Simm_Front(Tree T)
{
	if (!IsEmptyTree(T))
	{
		Simm_Front(T->LSon);
		printf("%d ", T->Data);
		Simm_Front(T->RSon);
	}
}
//симметричный проход справа-налево
void Simm_Back(Tree T)
{
	if (!IsEmptyTree(T))
	{
		Simm_Back(T->RSon);
		printf("%d ", T->Data);
		Simm_Back(T->LSon);
	}
}

void BuildTree(Tree *T1, int k){
    int E, i;
    for (i=0;i<k;i++)
    {
        scanf("%d",&E);
        WriteDataTree(T1, E);
    }
}

int main()
{
    BaseType T;
    int k;
    printf ("k = ");
    scanf ("%d", &k);
    BuildTree(&T, k);
    printf("Tree tops in direct order:\n");
    Simm_Front(T);
    printf("%d\n",k);
    printf("Tree tops in reverse order:\n");
    Simm_Back(T);
    return 0;
}
