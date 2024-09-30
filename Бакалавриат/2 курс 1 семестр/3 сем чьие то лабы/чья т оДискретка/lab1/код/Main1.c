#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "svoystva.h"

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
    int m,n,**a, **b, **c;
    m = 10; n = 10;
    getmem(&a,m,n);
    getmem(&b,m,n);
    getmem(&c,m,n);
    matr_A(a,m,n);
   /* matr_B(b,m,n);
    matr_C(c,m,n);*/
    printf("Matrica A\n");
    printf("reflex\t\t\t%i\n",reflex(a,n));
    printf("anti-reflex\t\t%i\n",anti_reflex(a,n));
    printf("symmentryc\t\t%i\n",symmetr(a,n));
    printf("anti-symmentric\t\t%i\n",anti_symmetr(a,n));
    printf("transit\t\t\t%i\n",transit(a,n));
    printf("anti-transit\t\t%i\n",anti_transit(a,n));
    printf("full\t\t\t%i\n",full(a,n));
    printf("tolerant\t\t%i\n",tolerant(a,n));
    printf("equival\t\t\t%i\n",equival(a,n));
    printf("poryadok\t\t%i\n",poryadok(a,n));
    printf("\n");

  /*  printf("Matrica B\n");
    printf("reflex\t\t\t%i\n",reflex(b,n));
    printf("anti-reflex\t\t%i\n",anti_reflex(b,n));
    printf("symmentryc\t\t%i\n",symmetr(b,n));
    printf("anti-symmentric\t\t%i\n",anti_symmetr(b,n));
    printf("transit\t\t\t%i\n",transit(b,n));
    printf("anti-transit\t\t%i\n",anti_transit(b,n));
    printf("full\t\t\t%i\n",full(b,n));
    printf("tolerant\t\t%i\n",tolerant(b,n));
    printf("equival\t\t\t%i\n",equival(b,n));
    printf("poryadok\t\t%i\n",poryadok(b,n));
    printf("\n");

    printf("Matrica C\n");
    printf("reflex\t\t\t%i\n",reflex(c,n));
    printf("anti-reflex\t\t%i\n",anti_reflex(c,n));
    printf("symmentryc\t\t%i\n",symmetr(c,n));
    printf("anti-symmentric\t\t%i\n",anti_symmetr(c,n));
    printf("transit\t\t\t%i\n",transit(c,n));
    printf("anti-transit\t\t%i\n",anti_transit(c,n));
    printf("full\t\t\t%i\n",full(c,n));
    printf("tolerant\t\t%i\n",tolerant(c,n));
    printf("equival\t\t\t%i\n",equival(c,n));
    printf("poryadok\t\t%i\n",poryadok(c,n));
    printf("\n");*/
    freemem(&a,m,n);
    /*freemem(&b,m,n);
    freemem(&c,m,n);*/
    printf("\n");
    return 0;
}
