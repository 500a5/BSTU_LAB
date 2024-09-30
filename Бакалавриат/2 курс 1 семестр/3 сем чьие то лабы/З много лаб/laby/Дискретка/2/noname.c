/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start, end;

    start = clock();

    // Код, время выполнения которого нужно измерить
    ////*  /
    int i,j=2,k;
    for (i=0;i<1000;i++)
      {
           j+=i; printf ("\nj=%d\n",j);
      }

    end = clock();

    printf("The above code block was executed in %.8f second(s)\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));

    return 0;
}
/*

#include <stdio.h>
#include <time.h>
#include <conio.h>

int main() {
    int i, r;

    srand();
    for (i = 0; i < 10; i++) {
        r = rand();
        printf("%d\n", r);
    }

    _getch();
    return 0;
}


#include <time.h>
#include <stdio.h>

int main(void)
{
  time_t start,end;
  volatile long unsigned t;

  start = time(NULL);
  for(t=0; t<500; t++)
    printf ("%d\n",t);
  end = time(NULL);
  printf("Цикл использовал %f секунд.\n", difftime(end, start));

  return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
#include <time.h>

//#define N 50

int main()
{
    setlocale(LC_ALL, "Rus");
    int i, N=150;
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


void time_count (int **a, int **c,int N)
{
    int k;
    k=1;
    sravn (a,c,N,k);
    k=N*N/4;
    sravn (a,c,N,k);
    k=N*N/2;
    sravn (a,c,N,k);
    k=N*N*2/3;
    sravn (a,c,N,k);
    k=N*N;
    sravn (a,c,N,k);
}
void sravn (int **a, int **c, int N, int k)
{

    double l,min1,max1,s,min2,max2;
    clock_t start, end,d1,d2;
    int i,x,y;
    printf ("k=%d\n",k);
    max1=0;
    max2=0;
    min1=min2=clock();
    for (i=1;i<=1000;i++)
    {

        form(a,N,k);
         for (x=1;x<N;x++)
            for (y=1;y<N;y++)
                c[x][y]=a[x][y];
  start=clock();
        tr_zam_st(a,c,N);
        end=clock();
        s=((double) end - start) / ((double) CLOCKS_PER_SEC);
        if (s>max1)
            max1=s;
        if (s<min1)
            min1=s;
        clear (c,N);

        start=clock();
        tr_zam_W(a,c,N);
        end=clock();
        s=((double) end - start) / ((double) CLOCKS_PER_SEC);
        if (s>max2)
            max2=s;
        if (s<min2)
            min2=s;
        clear (c,N);
        clear (a,N);
    }
     printf ("\nmin1 = %f\nmax1 = %f\nmin2 = %f\nmax2 = %f\n", min1,max1, min2,max2);
}

void tr_zam_st (int **a, int **c, int N)
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

void tr_zam_W (int **a, int **c, int n)
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

