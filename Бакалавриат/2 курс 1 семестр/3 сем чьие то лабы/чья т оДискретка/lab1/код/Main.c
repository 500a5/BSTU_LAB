#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

void getmem(int ***a, int m, int n)
{
    *a = calloc(m,sizeof(int*));
    for (int i = 0; i < m; i++)
        (*a)[i] = calloc(n,sizeof(int));
}

void freemem(int ***a, int m, int n)
{
    for (int i = 0; i < m; i++)
        free((*a)[i]);
    free(*a);
}
void matr_A(int **a, int m, int n)
{
    for (int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if ((i==j) | (i==0) | (j==0))

                a[i][j] = 1;
}

void matr_B(int **a, int m, int n)
{
    for (int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
            if (abs(i - j) <5)
                a[i-1][j-1] = 1;
}

void matr_C(int **a, int m, int n)
{
    for (int i = 1; i < 11; i++)
        for (int j = 1 ;j < 11; j++)
            a[i-1][j-1] = (j*j) % i == 0;
}

int main()
{
    int m,n,**a, **b, **c, **d, **d1, **d2, **d3, **d4;
    m = 10; n = 10;
    getmem(&a,m,n);
    getmem(&b,m,n);
    getmem(&c,m,n);
    getmem(&d,m,n);
    getmem(&d1,m,n);
    getmem(&d2,m,n);
    getmem(&d3,m,n);
    getmem(&d4,m,n);
    matr_A(a,m,n);
    printf("\n");


   Compos(a,a,d,n);


    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            printf("%i ",a[i][j]);
        printf("\n");
    }


printf("\n");
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            printf("%i ",d[i][j]);
        printf("\n");
    }

    freemem(&a,m,n);
    freemem(&b,m,n);
    freemem(&c,m,n);
    freemem(&d,m,n);
    freemem(&d1,m,n);
    freemem(&d2,m,n);
    freemem(&d3,m,n);
    freemem(&d4,m,n);
    printf("\n");
    return 0;
}
