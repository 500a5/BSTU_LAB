#include <stdio.h>
#include <stdlib.h>

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

void WriteArr(int* A, int N)
{
    int i;
	for(i = 0; i < N; i++)
		printf("%i ", A[i]+1);
	printf("\n");
}

int Kruskal(int** G, int N)
{
	int count = N, i, j, k;
	int* B = (int*)malloc(N*sizeof(int));
	for(i = 0; i < N; i++)
		B[i] = i; //������������ ��� �������
	for(i = 0; i < N; i++) //������� �������
	{
		for(j = 0; j < N; j++)
		{
			if(G[i][j] && B[i] != B[j]) //���� ���� ������� �
			{// ��� ������ �������� ���������������� �������
				for(k = 0; k < N; k++)
					if(B[j] == B[k]) // ������ �������� Bj �� �i
						B[k] = B[i];
				count--; //���������� ������� ������
			}
		}
	}
	if(count == 2) //��� ��������� ������
	//����� ��� k-���������� ��������� �����, ���������� �������
    //�� �������� ����� ��������� ��� �� ��� ������� ����������.
	{
		for(i = 0; i < N; i++)
			printf("%i ",B[i]); //����� ������� �������
		printf("---> ");
	}
	return count;
}

void GenComb(int** G, int** E, int* C, int N, int M, int k, int i, int b)
// G - ����, E - ������� ����, N - ������ ������� ���������, M - ���-�� ����, i - ����������� �������
// C -, k -, b -
{
    int x;
	for(x = b; x <= (M-k+i); x++)
	{
		C[i] = x;
		G[E[0][x]][E[1][x]] = 0;
		G[E[1][x]][E[0][x]] = 0;
		if(i == (k-1))
		{
			if(Kruskal(G, N) == 2)
				WriteArr(C, k);
		}
		else
			GenComb(G, E, C, N, M,k,i+1,x+1);
		G[E[0][x]][E[1][x]] = 1; //������� ����� � �������� � ���
		G[E[1][x]][E[0][x]] = 1; // ����������� ����� � ���������� ���������
	}
}

int** GenMatrReb(int** G, int N, int* M) //�������� ������� ����
{
	int** E, i, j; //� - ������� ����
	E = (int**)malloc(2*sizeof(int*)); //2 ������
	for(i = 0; i < 2; i++)
		E[i] = (int*)malloc((N*N-N)/2*sizeof(int)); //��� n = 5 ����� 10 N*N-N -�������� �����, ����� �� ��� �.�. ���������
	int count = 0; //���-�� �����
	for(i = 0; i < N; i++)
		for(j = i; j < N; j++)
			if(G[i][j]) //���� ��� ������� ����������
			{
				E[0][count] = i;
				E[1][count] = j;
				count++;
			}
	for(i = 0; i < 2; i++)
		E[i] = (int*)realloc(E[i],count*sizeof(int)); //�������� �� ���-�� �����
	(*M) = count; //���-�� ������
	return E;
}

int main()
{
	FILE *f;
	int** G;
	int** E;
	int N, M;
	int* C;
	int k;
	f = fopen("1.txt","r");
	fscanf(f,"%i",&N);
	G = InitMem(N);
	ReadGraph(f,G,N);
	WriteGraph(G,N,N);
	fclose(f);
	printf("Enter k: ");
	scanf("%i",&k); //���� ���-�� ��������� ��������� ����
	E = GenMatrReb(G, N, &M); //�������� ������� ����

	C = (int*)malloc(k*sizeof(int)); //
	GenComb(G,E,C,N,M,k,0,0);
	free(C);
	FreeMem(G,N);
	FreeMem(E,2);
	//system("PAUSE");
	return 0;
}
