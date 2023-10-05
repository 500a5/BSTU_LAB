#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

#define N 11

int main()
{
    setlocale(LC_ALL, "Rus");
    int i,  M[N],S[N];
    for (i=1;i<N;i++)
        M[i]=i;
    int **r;
    r=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        r[i]=(int *)calloc(N,sizeof(int));

    form_R(r); printf ("\nОтношение R\n"); output (r);
    razb (M,r,S);
    i=1;

    printf ("\nРазбиение Ф   \n");
    while (i<N)
        printf ("%d  ",S[i++]);
    clear(r);
    postr(S,r);
    output (r);
}
int form_R (int **a)
{
    int x,y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            if ((x%3==0 && y%3==0) || (x%5==0 && y%5==0) || (x==y))
                a[x][y]=1;
    return 0;
}


void output (int **a)
{
    int x,y;
    for (x=1;x<N;x++)
    {
        for (y=1;y<N;y++)
            printf ("%d  ",a[x][y]);
        printf("\n");
    }
}

void clear (int **a)
{
    int x,y;
    for (x=0;x<N;x++)
        for (y=0;y<N;y++)
            a[x][y]=0;
}
void clear_arr (int *a)
{
    int x;
    for (x=0;x<N;x++)
        a[x]=0;
}

void cl_eq (int **R, int x, int *clX, int y)
{
    int i,j=1;
    for (i=1;i<N;i++)
        if (R[x][i])
            clX[i]=y;
}

void razb (int *m, int **r, int *s)
{
    int a[N],i,c,fl=N,j=1;
    for (i=0;i<N;i++)
        a[i]=i;
    for (i=0;i<N;i++)
        s[i]=0;

    i=1;

    while (pust(a)&&fl)
    {
        while (!a[i]&&i<N)
            i++;
        cl_eq(r,a[i],s,j);
        fl-=del (a,s);
        j++;
    }
}

int del (int *a, int *s)
{
    int i,j=0;
    for (i=1;i<N;i++)
        if (s[i])
        {
            a[i]=a[i]&&(!s[i]);
            j++;
        }
    return j;
}

void postr (int *s, int **r)
{
    int a[N], g=0,x,y,i=1,j=1;
    while (j<N)
    {
        while (i<N)
        {
            if (s[i]==j)
            {
                g++;
                a[g]=i;
            }
            i++;
        }
        if (g==1)
            r[a[g]][a[g]]=1;
        if (g>1)
            for (x=1;x<=g;x++)
                for (y=1;y<=g;y++)
                    r[a[x]][a[y]]=1;
        clear_arr (a);
        j++;
        i=1;
        g=1;
    }
}

int pust (int *a)
{
    int i;
    for (i=1;i<N;i++)
        if(a[i])
            return (i<N);
}
