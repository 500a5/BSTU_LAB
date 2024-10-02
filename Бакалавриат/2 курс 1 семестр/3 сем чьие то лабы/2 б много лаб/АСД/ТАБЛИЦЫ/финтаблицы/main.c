#include<stdio.h>
#include<stdlib.h>
#include "poisk.h"
#include "tabbl.h"

void main()
{
    int n,key,k,i;
    int *a;
    printf("input n, key ");
    scanf("%i%i",&n,&key);
    printf("\n");
    srand(time(NULL));
    for(i=1;i<=9;i++)
        {
            a=(int *)malloc(n*sizeof(int));
            read_table(a,n);
            k=bin_poisk(a,n,key);
            printf("\n%i\n",k);
            printf("\n");
            free(a);
            n=n+50;
        }
}

