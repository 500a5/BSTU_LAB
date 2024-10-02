#include <stdio.h>
#include <stdlib.h>
#define MaxRoute 100

int** Locate (size_t m, size_t n)
{
    int ** A = (int**)calloc(m, sizeof(int*));
    size_t i;
    for (i=0; i<m; i++)
        A[i] = (int*)calloc(n, sizeof(int));
    return A;

}


void FreeMem(int** G, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        free(G[i]);
    free(G);
}

void InputG(int**G, size_t n)
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &G[i][j]);
}

void AlgDekstr1(size_t  S, size_t F, int**G, size_t n )
{
    int* T = (int*)calloc(n, sizeof(int));
    int* V = (int*)calloc(n, sizeof(int));
    int* D = (int*)calloc(n, sizeof(int));
    int i;
    for (i=0; i<n; i++)
    {
        T[i] = -1;
        D[i] = MaxRoute;
    }

    T[S] = 0;
    V[S] = 1;
    D[S] = 0;
    int min_c =0, min_v;
    while (S!=F && min_c!=MaxRoute)
    {
        min_c = MaxRoute;
        for(i=0; i<n; i++)
        {
            if(!V[i])
            {
                if( G[S][i])
                {
                   if (D[i]>G[S][i]+D[S])
                   {
                       D[i] = G[S][i]+D[S];
                       T[i] = S+1;
                   }

               }
                if (min_c>D[i])
                {
                    min_c = D[i];
                    min_v = i;
                }
            }
        }
        S = min_v;
        V[S] = 1;
    }

    for(i=0; i<n; i++)
        printf("%d ", V[i]);
    printf("\n");
        for(i=0; i<n; i++)
        printf("%d ", D[i]);
    printf("\n");
        for(i=0; i<n; i++)
        printf("%d ", T[i]);
    printf("\n");
}

void AlgDekstr(size_t  S, int**G, size_t n, int* T, int*D)
{
    int* V = (int*)calloc(n, sizeof(int));
//    int* D = (int*)calloc(n, sizeof(int));
    int i;
    for (i=0; i<n; i++)
    {
        T[i] = -1;
        D[i] = MaxRoute;
    }

    T[S] = 0;
    V[S] = 1;
    D[S] = 0;
    int min_c =0, min_v;
    while (min_c!=MaxRoute)
    {
        min_c = MaxRoute;
        for(i=0; i<n; i++)
        {
            if(!V[i])
            {
                if( G[S][i])
                {
                   if (D[i]>G[S][i]+D[S])
                   {
                       D[i] = G[S][i]+D[S];
                       T[i] = S+1;
                   }

               }
                if (min_c>D[i])
                {
                    min_c = D[i];
                    min_v = i;
                }
            }
        }
        S = min_v;
        V[S] = 1;
    }

    for(i=0; i<n; i++)
        printf("%d ", V[i]);
    printf("\n");
        for(i=0; i<n; i++)
        printf("%d ", D[i]);
    printf("\n");
        for(i=0; i<n; i++)
        printf("%d ", T[i]);
    printf("\n");
}

void OutputRoutes(int*T, size_t i, size_t S)
{
    if(i!=S)
        OutputRoutes(T, T[i]-1, S);
    printf("%d ", i+1);
}

void OutputRes(int* T, int*D, int*S, int* D2, size_t n)
{
    int i, j=0;
    int* V = (int*)calloc(n, sizeof(int));
    for(i=0; i<n; i++)
    {
        if(D[i]>D2[i])
        {
            printf("V = %d, D = %d, Route: ", i+1, D[i]);
            OutputRoutes(T, i, S);
            printf("\n");
        }

    }
}
int main()
{
    int** G = Locate(6, 6);
    InputG(G, 6);
    int S1 =  0, S2 = 1, n=6;
    int* T = (int*)calloc(n, sizeof(int));
    int* D = (int*)calloc(n, sizeof(int));
    int* T2 = (int*)calloc(n, sizeof(int));
    int* D2 = (int*)calloc(n, sizeof(int));
    AlgDekstr(S1, G, 6, T, D);
    AlgDekstr(S2, G, 6, T2, D2);
    OutputRes(T, D, S1, D2, 6);
    return 0;
}

/*0 1 9 0 0 0
0 0 7 2 0 0
0 0 0 0 1 0
0 0 4 0 8 2
0 0 0 0 0 5
0 0 0 0 4 0*/
