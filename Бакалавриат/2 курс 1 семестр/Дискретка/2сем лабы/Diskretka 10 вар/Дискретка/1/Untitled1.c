#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
#include <time.h>

//#define N 50

int main()
{
    setlocale(LC_ALL, "Rus");
    int i, N=150, n2=100,n3=150;
    int **a;
    a=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        a[i]=(int *)calloc(N,sizeof(int));
    int **c;
    c=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        c[i]=(int *)calloc(N,sizeof(int));

    time_count(a,c,N);

}
void form (int **a, int N, int k)
{
    int x,y,i=0;
    srand(124);

    while (i<k)
    {
        x=rand()%N;
        y=rand()%N;
        if (!a[x][y])
        {
            a[x][y]=1;
            i++;
        }
    }
}
void output (int **a, int n)
{
    int x,y;
    for (x=0;x<n;x++)
    {
        for (y=0;y<n;y++)
            printf ("%d  ",a[x][y]);
        printf("\n");
    }
}

void time_count (int **a, int **c,int N)
{
    double l,min1,max1=0,s,min2,max2=0;
    time_t start, end,d1,d2;
    int i,k,x,y;
    min1=min2=time(NULL);
    d1= time(NULL);
    k=1;

    for (i=1;i<=1000;i++)
    {
        form(a,N,k);
        for (x=1;x<N;x++)
            for (y=1;y<N;y++)
                c[x][y]=a[x][y];
        start=time(NULL);
        tr_zam_1(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));
        if (s>max1)
            max1=s;

        if (s<min1)
            min1=s;
        clear (c,N);
// printf ("\ns = %f\n",s);  printf ("\nmax1 = %f\n",max1);
printf ("\ni=%d",i);
        start=time (NULL);
        tr_zam_2(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));
        if (s>max2)
            max2=s;
        if (s<min2)
            min2=s;

        clear (c,N);
        clear (a,N);
    }
   printf ("\nmin1 = %f\nmax1 = %f\nmin2 = %f\nmax2 = %f\n", min1,max1, min2,max2);

    max1=0;
    max2=0;
    min1=min2=time(NULL);
    clear (c,N);
    clear (a,N);
    k=N*N/4;

    for (i=1;i<=1000;i++)
    {
        form(a,N,k);
         for (x=1;x<N;x++)
            for (y=1;y<N;y++)
                c[x][y]=a[x][y];
        start = time(NULL);
        tr_zam_1(a,c,N);
        for (x=1;x<N;x++)
            for (y=1;y<N;y++)
                c[x][y]=a[x][y];
        end=time(NULL);
        s=difftime(end, start);
        if (s>max1)
            max1=s;
        if (s<min1)
            min1=s;
        clear (c,N);

        start=time(NULL);
        tr_zam_2(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));
        if (s>max2)
            max2=s;
        if (s<min2)
            min2=s;
        clear (c,N);
        clear (a,N);
    }
    printf ("\nmin1 = %f\nmax1 = %f\nmin2 = %f\nmax2 = %f\n", min1,max1, min2,max2);

    clear (c,N);
    clear (a,N);
    max1=0;
    max2=0;
    min1=min2=time(NULL);

    k=N*N/2;
    for (i=1;i<=1000;i++)
    {
        form(a,N,k);
         for (x=1;x<N;x++)
            for (y=1;y<N;y++)
                c[x][y]=a[x][y];
        start=time(NULL);
        tr_zam_1(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));// printf ("\ns = %f\n",s);
        if (s>max1)
            max1=s;
        if (s<min1)
            min1=s;
        clear (c,N);

        start=time(NULL);
        tr_zam_2(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));
        if (s>max2)
            max2=s;
        if (s<min2)
            min2=s;
        clear (c,N);
        clear (a,N);
    }
    printf ("\nmin1 = %f\nmax1 = %f\nmin2 = %f\nmax2 = %f\n", min1,max1, min2,max2);
    clear (c,N);
    clear (a,N);
    max1=0;
    max2=0;
    min1=min2=time(NULL);
    k=N*N*2/3;
    for (i=1;i<=1000;i++)
    {
         start=time(NULL);
        form(a,N,k);
         for (x=1;x<N;x++)
            for (y=1;y<N;y++)
                c[x][y]=a[x][y];

        tr_zam_1(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));
        if (s>max1)
            max1=s;
        if (s<min1)
            min1=s;
        clear (c,N);

        start=time(NULL);
        tr_zam_2(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));
        if (s>max2)
            max2=s;
        if (s<min2)
            min2=s;
        clear (c,N);
        clear (a,N);
    }
     printf ("\nmin1 = %f\nmax1 = %f\nmin2 = %f\nmax2 = %f\n", min1,max1, min2,max2);
    clear (c,N);
    clear (a,N);
    max1=0;
    max2=0;
    min1=min2=time(NULL);
    k=N*N;
    for (i=1;i<=1000;i++)
    {
        form(a,N,k);
         for (x=1;x<N;x++)
            for (y=1;y<N;y++)
                c[x][y]=a[x][y];
        start=time(NULL);
        tr_zam_1(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));
        if (s>max1)
            max1=s;
        if (s<min1)
            min1=s;
        clear (c,N);
        start=time(NULL);
        tr_zam_2(a,c,N);
        end=time(NULL);
        s=(difftime(end, start));
        if (s>max2)
            max2=s;
        if (s<min1)
            min2=s;
        clear (c,N);
        clear (a,N);
    }
    printf ("\nmin1 = %f\nmax1 = %f\nmin2 = %f\nmax2 = %f\n", min1,max1, min2,max2);
}
void tr_zam_1 (int **a, int **c, int N)
{
    int i,j;
    int **b,**b1;
    b=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        b[i]=(int *)calloc(N,sizeof(int));
    b1=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        b1[i]=(int *)calloc(N,sizeof(int));
    for (i=1;i<N;i++)
        for (j=1;j<N;j++)
            b[i][j]=b1[i][j]=a[i][j];
    for (i=2;i<N;i++)
    {
        compose (b1,a,b,N);
        unit (c,b,c,N);
        for (i=1;i<N;i++)
            for (j=1;j<N;j++)
                b1[i][j]=b[i][j];
    }
}

void tr_zam_2 (int **a, int **c, int n)
{
    int x,y,z;

    for (x=1;x<n;x++)
        for (y=1;y<n;y++)
            for (z=1;z<n;z++)
                c[x][y]=c[x][y]||c[x][z]&&c[z][y];

}

void clear (int **a, int n)
{
    int x,y;
    for (x=0;x<n;x++)
        for (y=0;y<n;y++)
            a[x][y]=0;
}
//объединение
void unit (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=a[x][y] || b[x][y];
}
//композиция
void compose (int **a,int **b, int **res, int N)
{
    int x, y, z;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
        {
            res[x][y]=0;
            for(z=1;z<N;z++)
                res[x][y]=res[x][y] || a[x][z] && b[z][y];
        }
}
