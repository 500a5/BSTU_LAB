#include "dijkstra.h"
#define INT_MAX 1000

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

void WriteGraph(int** G, int N)
{
	printf("The orgraph:\n");
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			if(i!=j && G[i][j] == 0)
				printf("oo\t");
			else
				printf("%i\t", G[i][j]);
		printf("\n");
	}
}

void Dijkstra(int** G, int N, int start)
{
	int min, index;
	int* D;
	int* V;
	int* T;
	V = (int*)malloc(N*sizeof(int));
	D = (int*)malloc(N*sizeof(int));
	T = (int*)malloc(N*sizeof(int));
	for(int i = 0; i < N; i++)
	{
		V[i] = 0;
		D[i] = INT_MAX;
		T[i] = -1;
	}
	T[start] = 0;
	D[start] = 0;
	for(int count = 0; count < N-1; count++)
	{
		min = INT_MAX;
		for(int i = 0; i < N; i++)
			if((V[i] == 0) && (D[i] <= min))
			{
				min = D[i];
				index = i;
			}
		V[index] = 1;
		for(int i = 0; i < N; i++)
			if((V[i] == 0) && (G[index][i] != 0) && (D[index] != INT_MAX) && ((D[index] + G[index][i]) < D[i]))
			{
				D[i] = D[index] + G[index][i];
				T[i] = index;
			}

	}
	/*printf("Vertex:\n");
	for(int i = 0; i < N; i++)
		if(D[i] != INT_MAX)
		{
			printf("%i -> %i = %i\n", start+1, i+1, D[i]);
			WritePath(T,start,i);
			printf("\n");
		}
		else
		{
			printf("%i -> %i = oo\n", start+1, i+1);
		}*/
	printf("Vertex with the same shortest paths:\n");
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
			if(D[i] == D[j] && D[i] != INT_MAX)
			{
				printf("%i -> %i = %i\n", start+1, i+1, D[i]);
				printf("Path:\n");
				WritePath(T,start,i);
				printf("\n");
				printf("%i -> %i = %i\n", start+1, j+1, D[j]);
				WritePath(T,start,j);
				printf("\n");
				return;
			}
	printf("Not founded\n");
}

void WritePath(int* T, int Start, int Vertex)
{
	if(Vertex!=Start)
		WritePath(T,Start,T[Vertex]);
	printf("%i ",Vertex+1);
}

void FreeMem(int** G, int N)
{
	for(int i = 0; i < N; i++)
		free(G[i]);
	free(G);
}
