#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "diskr3_3.h"


void null_matr(int a[N][N])
{
    int i, j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            a[i][j]=0;
        }
}

void null_mass(int a[N])
{
    int j;
        for (j=0; j<N; j++)
            a[j]=0;
}

void otn_get_4 (int a[N][N])
{
    int i, j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if ((i==j)||((i+j)%2!=0))
                a[i][j]=1;
        }
}

void otn_get_5 (int a[N][N])
{
    int i, j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if ((i+j)%2==0)
                a[i][j]=1;
        }
}

void output_matr(int a[N][N])
{
    int i, j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}


void output_mass(int a[N])
{
    int j;
     for (j=0; j<N; j++)
        {
                printf("%d ", a[j]);
        }
}

int sraw_str (int a[N], int b[N])
{
   int i=0;
   for (i=0; i<N; i++)
   {
       if (a[i]!=b[i])
        return 0;
   }
   return 1;
}

void copi_matr (int a[N][N], int b[N][N])
{
    int i, j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            b[i][j]=a[i][j];
}

void get_klaseq (int a[N][N], int b[N], int x)
{
    int i;
    /*for (i=0; i<=N; i++)
        b[i]=0;*/
    null_mass(b);
    b[x-1]=1;
    for (i=0; i<=N; i++)
        if (a[i][x-1])
            b[i]=1;
}

void razzb (int m[N][N], int s[N])
{
    int b[N][N], i, j,k=1;
    for(i=0;i<N;i++)
        s[i]=0;

    for(i=0;i<N-1;i++)
    {
        if(s[i]==0)
        {
            s[i]=k;

            get_klaseq(m,b,i+1);
            for(j=i;j<N;j++)
                if(sraw_str(m[j],b)==1)
                    s[j]=k;
            k++;
        }
    }
    if(s[N-1]==0) s[N-1]=k;

}

void viv_class(int s[N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        if(s[i]==i+1)
        {
            printf("Klass %i : ",i+1);
            for(j=0;j<N;j++)
                if(s[j]==i+1)
                    printf("%i ",j+1);
            printf("\n");
        }
    }
}
