#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
int W[N];
int S[N];

void GetMem (int***a, size_t n);
void FreeMem (int***a, size_t n);
void OutputMatr(int **a, size_t n, size_t m);
void MakeGraf (int **a, size_t n, size_t m);
void SimpleCikle(int **G, int i, int len, int v, int n);
int ChekPovtEl(int len, int a);
int IsGamiltonProv(int **G, int i, int len, int v, int n);
int isGamilton(int **G, int n, int i, int v);
void OutputMarch (int n);
int Eiler (int **G, int g, int i, int len, int n, int v);
int main()
{
    int **a, n, m;

    printf("n >> ");
    scanf("%d", &n);
    printf("m >> ");
    scanf("%d", &m);
    GetMem(&a, n);

    MakeGraf(a, n, m);

    /*char s[]="Matr2.txt";
    FILE *F = fopen(s, "r");
    int v, u;
    GetMem(&a, n);
    for (v=0; v<n; v++)
        for (u=0; u<n; u++)
            fscanf(F, "%d", &a[v][u]);
    fclose(F);*/
    OutputMatr(a, n, n);

    printf("%d\n", Eiler(a,0,0, m, n, 1));
    OutputMarch(m);
  //  SimpleCikle(a,1,n+1,1,n);
    FreeMem(&a, n);
    return 0;
}

void GetMem (int***a, size_t n)
{
    int i;
    (*a) = (int**)calloc(n, sizeof(int*));
    for(i=0; i<n; i++)
        (*a)[i]=(int*)calloc(n,sizeof(int));
}

void FreeMem (int***a, size_t n)
{
    int i;
    for(i=0; i<n; i++)
        free((*a)[i]);
    free((*a));
}

void MakeGraf (int **a, size_t n, size_t m)
{
    srand(clock());
    unsigned i, j, k=0;
    while (k<m)
     {
        do
        {
          i=rand()%n;
          j=rand()%n;
        }
        while (a[i][j]&&a[j][i]);
        if (i!=j)
        {
            a[i][j]=a[j][i]=1;
            k++;
        }
     }
}

void OutputMatr(int **a, size_t n, size_t m)
{
    int i, j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void SimpleCikle(int **G, int i, int len, int v, int n)
{
    int j,k;
    for (j =0; j<n;j++)
        if(G[v][j] && ChekPovtEl(i, j+1))
        {
                W[i]=j+1;
                if (i==len-1)
                {
                    if(W[i]==W[0] && i>=3)
                        OutputMarch(len);
                }
            else
                SimpleCikle(G, i+1, len, j, n);
        }
}

int IsGamiltonProv(int **G, int i, int len, int v, int n)
{
    int j=0, k, flag=0;
    while (j<n && !flag)
    {
        if(G[v][j] && ChekPovtEl(i, j+1))
        {
            W[i]=j+1;
            if (i==len-1)
            {
                if(W[i]==W[0] && i>=3)
                    flag=1;
            }
            else
                IsGamiltonProv(G, i+1, len, j, n);
        }
        j++;
    }
    return flag;
}
/*
int IsGamilton(int** G, int n)
{

    int i=0;
    while (i<n+1 && IsGamiltonProv(G, 0, n+1, i, n))
        i++;
    return i<n+1;
}
*/

int ChekPovtEl(int len, int a)
{
    int i;
    for (i=1;i<len;i++)
        if(W[i]==a)
            return 0;
    return 1;
}

void OutputMarch (int n)
{
    int i;
    printf("[ ");
    for (i=0; i<n; i++)
    {
        printf("%i ", W[i]);
        //if (i!=n-1)
          //  printf(",  ");
    }
    printf("]\n");
}

int Eiler (int **G, int g, int i, int len, int n, int v)
{
    int j,k;
    printf ("\n");
    for (j=0;j<n;j++)
    {
        if (G[v-1][j])
        {
            S[i++]=v;  printf("%d",v);
            for (k=0;k<n&&!G[v-1][k];k++);
            if (k==n)
            {
                W[g++]=S[i];
                printf("%d",S[i]);
            }
        }
            else
                Eiler (G,g,i,len,n,v+1);

    }
    for (j=g;j<n;j++)
        W[j]=S[n-j];

}

