#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
int W[N];
int V[N];

void GetMem (int***a, size_t n);
void FreeMem (int***a, size_t n);
void OutputMatr(int **a, size_t n, size_t m);
void MakeGraf (int **a, size_t n, size_t m);
void SimpleCikle(int **G, int i, int len, int v, int n);
int ChekPovtEl(int len, int a);
int IsGamiltonProv(int **G, int i, int len, int v, int n, int *f);
int isGamilton(int **G, int n, int i, int v);
void WriteGamilton(int **G, int i, int len, int v, int n, int *f);
void OutputMarch (int n);
int Eiler (int **G, int g, int i, int len, int n, int v);
int main()
{
    int **G, **E, n, m;
    int V[100];
    printf("n >> ");
    scanf("%d", &n);
    printf("m >> ");
    scanf("%d", &m);
    GetMem(&G, n);
    GetMem(&E,n);
    MakeGraf(G, n, m);
    HenGraph(n,m);
    printf ("\n");
    //OutputMatr(G,n,n);
    printf ("\n");
    int    f=0,i=0;
//    WriteGamilton(G, i,n+1, 2, n, *f)
    FreeMem(&G, n);
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

void OutputMarch (int n)
{
    int i;
    for (i=0;i<=n;i++)
        printf ("%d   ",W[i]+1);
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
                    if(W[i]==W[0] && i>=3);
//                        OutputMarch(len);
                }
            else
                SimpleCikle(G, i+1, len, j, n);
        }
}

int IsGamilton(int **G, int i, int len, int v, int n, int *f)
{
    int j=0, k;
    while (j<n && (*f))
    {
        if(G[v][j] && ChekPovtEl(i, j+1))
        {
            W[i]=j+1;
            if (i==len-1)
            {
                if(W[i]==W[0] && i>=3)
                {
                    OutputMarch(i+1); printf ("\n..");
                    return (*f)=0;
                }
            }
            else
                f=IsGamiltonProv(G, i+1, len, j, n,&f);
        }
        j++;
    }
    //OutputMarch(i+1);
    return !(*f);
}


int IsGamiltonProv(int **G, int i, int len, int v, int n, int *f)
{
    int j=0, k;
    while (j<n && (*f))
    {
        if(G[v][j] && ChekPovtEl(i, j+1))
        {
            W[i]=j+1;
            if (i==len-1)
            {
                if(W[i]==W[0] && i>=3)
                {
                    OutputMarch(i+1);
                    return (*f)=0;
                }
            }
            else
                *f=IsGamiltonProv(G, i+1, len, j, n,&f);
        }
        j++;
    }
    //OutputMarch(i+1);
    return !(*f);
}

int ChekPovtEl(int len, int a)
{
    int i;
    for (i=1;i<len;i++)
        if(W[i]==a)
            return 0;
    return 1;
}

int IsEuler(int** G, int n)
{
    int x, k, y;
	for( x = 0; x < n; x++)
	{
		k = 0;
		for(y = 0; y < n; y++)
			if(G[x][y])
				k++;
		if((k % 2) == 1)
			return 0;
	}
	return 1;
}
void ClearMatr (int **a, int n)
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            a[i][j]=0;
}
void HenGraph (int n, int m)
{
    int **G, g=0,e=0,f=0;
    long int k=0;
    clock_t start, end, d=0;
    GetMem(&G,n);

    start=clock();
    while(d<10)
    {
        MakeGraf(G,n,m);
        k++;
        end=clock();
        g+=IsGamiltonProv(G, 0, n+1, 0, n,&f); f=1;
        e+=IsEuler(G,n);
        if (IsGamiltonProv(G, 0, n+1, 0, n,&f) && !IsEuler(G,n))
        {
             OutputMatr(G,n,n);
             SimpleCikle(G, 0, n+1, 0, n);

             return;
        }
        d=((double) end - start) / ((double) CLOCKS_PER_SEC);
        ClearMatr(G,n);
    }
    printf ("\ne = %d   g = %d  k = %d\n",e,g,k);
}
void WriteArr(int* A, int n)
{
    int i;
	for(i = 0; i < n; i++)
		printf("%i ", A[i]+1);
	printf("\n");
	//system("PAUSE");
}

void WriteGamilton(int **G, int i, int len, int v, int n, int *f)
{
    int j=0, k;
    while (j<n && (*f))
    {
        if(G[v][j] && ChekPovtEl(i, j+1))
        {
            W[i]=j+1;
            if (i==len-1)
            {
                if(W[i]==W[0] && i>=3)
                {
                    OutputMarch(i+1);
                    return (*f)=0;
                }
            }
            else
                IsGamiltonProv(G, i+1, len, j, n,&f);
        }
        j++;
    }
    //OutputMarch(i+1);
    return !(*f);
}

void WriteEuler(int** G, int* W, int** E, int i, int n, int m)
{
    int x;
	for( x = 0; x < n; x++)
	{
		if((G[W[i-1]][x] == 1) && (E[W[i-1]][x] == 0))
		{
			W[i] = x;
			E[W[i-1]][x] = 1;
			E[x][W[i-1]] = 1;
			if(i == m && W[0] == W[m])
                OutputMarch(m+1);
			else
				WriteEuler(G,W,E,i+1,n,m);
			E[W[i-1]][x] = 0;
			E[x][W[i-1]] = 0;
		}
	}
}
