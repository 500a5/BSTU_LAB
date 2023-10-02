#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
 typedef struct {
      int d;
      int t;
} el;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n=6,i,j;
    int** A=(int**)calloc (n, sizeof(int*));
    for (i=0;i<n;i++)
        A[i]=(int*)calloc(n,sizeof(int));
    el** M=(el**)calloc(n,sizeof (el*));
    for (i=0;i<n;i++)
        M[i]=(el*)calloc(n,sizeof(el));
    srand(clock());
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            A[i][j]=rand()%9;
    for (i=0;i<n;i++)
        A[i][i]=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf ("%d  ", A[i][j]);
        printf ("\n");
    }
    printf ("\n");
    CreateMatrW(A,M,n);
    Floid(M,n);
    Output(M,n);
    Des(M,n);
    for(i=0;i<n;i++)
        free(M[i]);
    free(M);
    for(i=0;i<n;i++)
        free(A[i]);
    free(A);
    return 0;
}

void CreateMatrW (int** A, el** M, int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (A[i][j]>0)
            {
                M[i][j].t=i+1;
                M[i][j].d=A[i][j];
            }
            else
                if (A[i][j]<=0&& i!=j)
                    M[i][j].t=-1;
        }
    }
}
void Output (el** A, int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf("%i  ",A[i][j].d);
        printf("\n");
    }
     printf("\n");
     for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf("%i  ",A[i][j].t);
        printf("\n");
    }
     printf("\n\n");
}
void Floid (el** W, int n)
{
    int z,x,y;
    for (z=0; z<n; z++)
        for (x=0; x<n; x++)
            for (y=0; y<n; y++)
            {
                    if ((W[x][y].d==0 && W[z][y].d>0 && W[x][z].d>0 && x!=y) || ((W[z][y].d>0 && W[x][z].d>0 && W[x][y].d>0)&&((W[x][z].d+W[z][y].d)<W[x][y].d)))
                    {
                       W[x][y].d=W[x][z].d+W[z][y].d;
                       W[x][y].t=W[z][y].t;
                    }
            }
}
void Des (el** M, int n)
{
    int i, j, f, t, x;
    printf ("\ni    j    i-j    j-i\n");
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            if (M[i][j].d<M[j][i].d)
            {
                printf ("\n%d    %d     %d      %d     ",i+1,j+1,M[i][j].d,M[j][i].d);
                printf ("%d-",i+1); t=i; f=j;
                while (M[t][f].t!=t+1 && M[t][f].t!=f+1)
                {
                    if (M[t][f].t!=t)
                    {
                        x=t;
                        t=M[t][f].t;
                        printf ("%d-", t+1);
                        f=t;
                    }
                    else break;

                }
                printf ("%d", j+1);

                printf ("      |      %d-",j+1);
                while (M[i][j].t!=i+1 && M[i][j].t!=j+1)
                {
                    if (M[i][j].t!=t)
                    {
                        t=M[i][j].t;
                        printf ("%d-", t);
                    }
                    else break;

                }
                printf ("%d\n", i+1);
            }
        }
}
