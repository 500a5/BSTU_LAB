
#include <stdio.h>
#include <stdlib.h>
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    int i, N=10+1, M[N];
    for (i=1;i<N;i++)
        M[i]=i;
    int **r;
    r=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        r[i]=(int *)calloc(N,sizeof(int));
    int **b;

    form_R(r, N); printf ("\nОтношение R\n"); output (r,N);

}
void decision (int **a, int **b, int **c, int **d, int N)
{
    int i;
    //выделение памяти для вспомогательных матриц
    int **e;
    e=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        e[i]=(int *)calloc(N,sizeof(int));
    int **g;
    g=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        g[i]=(int *)calloc(N,sizeof(int));
    compose (b,b,e,N);
    compose (a,e,d,N); //output (e,N);
    clear (e,N);
    add(c,e,N);
    subs(d,e,g,N); output (g,N);
    clear (e,N); clear (d, N);
    resort (c,e,N);
    unit(g,e,d,N);
}
int form_R (int **a, int N)
{
    int x,y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            if ((x%3==0 && y%3==0) || (x%5==0 && y%5==0) || (x==y))
                a[x][y]=1;
    return 0;
}


void output (int **a, int n)
{
    int x,y;
    for (x=1;x<n;x++)
    {
        for (y=1;y<n;y++)
            printf ("%d  ",a[x][y]);
        printf("\n");
    }
}

void clear (int **a, int n)
{
    int x,y;
    for (x=0;x<n;x++)
        for (y=0;y<n;y++)
            a[x][y]=0;
}

void cl_eq (int **R, int x, int *clX, int N, int y)
{
    int i,j=1;
    for (i=1;i<N;i++)
        if (R[x][i])
            clX[i]=y;
}

void razb (int m, int **r, int *s, int n)
{
    int a[n],i,fl=n,j=1;
    for (i=0;i<n;i++)
        a[i]=m[i];
    i=1;
    while (fl)
    {
        while (!a[i])
            i++;
        cl_eq(r,a[i],s,n,j);
        del (a,s,n);

    }
}

int del (int *a, int *s, int n)
{
    int i,j;
    for (i=1;i<n;i++)
        if (j=search(a,s[i],n))
            a[i]=0;
}

int search (int *a, int x, int n)
{
    int i;
    for (i=1;i<n;i++)
        if (a[i]==x)
            return i;
    return 0;
}
