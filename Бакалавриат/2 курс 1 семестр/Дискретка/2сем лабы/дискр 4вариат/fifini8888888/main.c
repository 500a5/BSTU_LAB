#include <stdio.h>
#include <stdlib.h>
#define MaxRoute 1000

void AlgDekstr222(size_t S, size_t F, int**G, size_t n);

int** InitMem(int N)
{
	int** G, i;
	G = (int**)malloc(N*sizeof(int*));
	for(i = 0; i < N; i++)
		G[i] = (int*)malloc(N*sizeof(int));
	return G;
}

void FreeMem(int** G, int M)
{
    int i;
	for(i = 0; i < M; i++)
		free(G[i]);
	free(G);
}

void WriteGraph(int** G, int M, int N)
{
    int i, j;
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
			printf("%i ", G[i][j]);
		printf("\n");
	}
	printf("\n");
}

void ReadGraph(FILE *f, int** G, int N)
{
    int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			fscanf(f, "%i", &G[i][j]);
	}
	printf("\n");
}

void WritePath(int* T, int Start, int Vertex)
{
	if(Vertex!=Start)
		WritePath(T,Start,T[Vertex]);
	printf("%i ",Vertex+1);
}

void AlgDekstr1(size_t S, size_t F, int**G, size_t n)
{
    int* T = (int*)calloc(n, sizeof(int));
    int* V = (int*)calloc(n, sizeof(int));
    int* D = (int*)calloc(n, sizeof(int));
    int i, j;
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

   /* for(i = 0; i < n; i++)
		for(j = i+1; j < n; j++)
			if(D[i] == D[j] && D[i] != MaxRoute)
				return;

    for(i=0; i<n; i++)
    printf("%d ", V[i]);
    printf("\n");
    for(i=0; i<n; i++)
    printf("%d ", D[i]);
    printf("\n");
    for(i=0; i<n; i++)
    printf("%d ", T[i]);
    printf("\n");*/

    OutputRoutes(T, F, S);
}

void AlgDekstr(size_t  S, size_t F, int **G, size_t n, int* T, int* D)
{
    int* V = (int*)calloc(n, sizeof(int));
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
}

void OutputRoutes(int*T, size_t i, size_t S)
{
    if(i!=S)
        OutputRoutes(T, T[i]-1, S);
    printf("%d ", i);
}

int main()
{
    FILE *f;
	int** G;
	int N;
	int i, s1, s2, dl=0;
	f = fopen("1.txt","r");
	fscanf(f,"%i",&N);
	G = InitMem(N);
	ReadGraph(f,G,N);
	WriteGraph(G,N,N);
	fclose(f);

	//printf("v1 -> z\n");    scanf("%i%i",&v1,&z);

	s1 = 3;
	s2 = 6;
    AlgDekstr222(s1-1, s2-2, G, N);

    return 0;
}


void AlgDekstr222(size_t S, size_t F, int**G, size_t n)
{
    int* T = (int*)calloc(n, sizeof(int));
    int* V = (int*)calloc(n, sizeof(int));
    int* D = (int*)calloc(n, sizeof(int));
    int i, j;
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
    //OutputRoutes(T, F, S);
    WritePath(T, S, F);
}
