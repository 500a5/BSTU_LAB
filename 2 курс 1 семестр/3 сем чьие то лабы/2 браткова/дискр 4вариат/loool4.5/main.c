#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#include <locale.h>

typedef struct
{
    int t; //�������, �������������� ������� j �� ���������� ���� �� i �� j
    int d; //����� ����������� ���� �� i �� g (W[i,j].d)
} BaseType;

int** InitMem(int N);           //������������� ������
void FreeMem(int** G, int N);       // ������������� ������
void WriteGraph(int** G, int N);    //����� �����
int** ReadGraph(int *N);            //���������� �����
BaseType** ModMatr(int** G, int N); //�������� ������� �����
void WriteMatrWes(BaseType** G, int N); //������ ������� �����
void CopyMatr (BaseType** M, BaseType** W, int N); //����������� �������
BaseType **AlgFloyd (BaseType** M, int N);  //�������� ������
int CheckGraf (BaseType** W, int N);        //�������� ������ �����

int main()
{
    setlocale(LC_ALL, "Rus");
    int** G, N;
	BaseType **M, **W;
	G = ReadGraph(&N);      //���������� �����
	WriteGraph(G, N);       //����� �����
	M = ModMatr(G, N);      //�������� ������� �����
	W = AlgFloyd(M, N);     //���������� ��������� ������
	WriteMatrWes(W, N);     //����� ������� ����� ��������� ��������� ������
	switch (CheckGraf(W, N))
	{
	    case 0:
	        {
	            printf("����� ������ ��� �����������.\n");
	            break;
	        }
        case 1:
            {
                printf("������������ ��������� ����.\n");
	            break;
            }
        case 2:
            {
                printf("������ ��������� ����.\n");
	            break;
            }
	}
    return 0;
}

int** InitMem(int N)
{
    int i;
	int** G;
	G = (int**)malloc(N*sizeof(int*));
	for(i = 0; i < N; i++)
		G[i] = (int*)calloc(N, sizeof(int));
	return G;
}

void FreeMem(int** G, int N)
{
    int i;
	for(i = 0; i < N; i++)
		free(G[i]);
	free(G);
}

void WriteGraph(int** G, int N)
{
    int i, j;
	printf("������:\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			if(i!=j && G[i][j] == 0)
				printf("I\t"); //������������� = infinity
			else
				printf("%i\t", G[i][j]);  //����� �����
		printf("\n");
	}
	printf("\n");
}

int** ReadGraph(int *N)
{
	int** G, tmp, i, j;
	FILE *f;
	f = fopen("input1.txt","r"); //������ �� ����� � ������ input
	fscanf(f,"%i",&tmp);
	G = InitMem(tmp);
	for(i = 0; i < tmp; i++)
	{
		for(j = 0; j < tmp; j++)
			fscanf(f, "%i", &G[i][j]);
	}
	fclose(f);
	(*N)=tmp;
	return G;
}

BaseType** ModMatr(int** G, int N)
{
  /*int t; //�������, �������������� ������� j �� ���������� ���� �� i �� j
    int d; //����� ����������� ���� �� i �� g (W[i,j].d)*/
	BaseType** M;
	int i, j;
	M = (BaseType**)malloc(N*sizeof(BaseType*));
	for(i = 0; i < N; i++)
		M[i] = (BaseType*)malloc(N*sizeof(BaseType)); //��������� ������ �� ������������ �
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
		{
			if(G[i][j] == 0) //���� ��� �����
				M[i][j].d = MAX; //�� � .d �������� �������������
			else
				M[i][j].d = G[i][j]; //����� ������������ �����
			if(i==j) //���� ������� ���������, �� ����
			{
				M[i][j].t = 0;
				M[i][j].d = 0;
			}
			else //�����, ���� ������� �� ����� ����
			{
				if(G[i][j] != 0)//���� ������� �� ����� ����
					M[i][j].t = G[i][j]; //�������� ���
				else
					M[i][j].t = -1; //����� -1 (������ ���)
			}
		}
	return M;
}

void WriteMatrWes(BaseType** G, int N)
{
    int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++) //����� ������� �����, ���� �������������, �� ������ I, ����� ������ �����������
        {
            (G[i][j].d == MAX) ? printf("(I; ") : printf("(%d; ", G[i][j].d);
            (G[i][j].t == MAX) ? printf("I)") : printf("%d)", G[i][j].t);
            printf("\t");
        }
		printf("\n");
	}
	printf("\n");
}

void CopyMatr (BaseType** M, BaseType** W, int N)
{
    int i, j;
    for (i = 0; i < N; i++) //����������� � � W
        for (j = 0; j < N; j++)
            W[i][j] = M[i][j];
}

BaseType **AlgFloyd (BaseType** M, int N)
{
    BaseType** W;
    int z, x, y;
	W = (BaseType**)malloc(N*sizeof(BaseType*)); //��������� ������
	for(z = 0; z < N; z++)
		W[z] = (BaseType*)malloc(N*sizeof(BaseType));
    CopyMatr(M, W, N); //����������� ������� ����� � � ������� W
    for (z = 0; z < N; z++)
        for (x = 0; x < N; x++)
            for (y = 0; y < N; y++)
            {
                if (W[x][z].d + W[z][y].d < W[x][y].d)
                {
                    W[x][y].d = W[x][z].d + W[z][y].d;
                    W[x][y].t = W[z][y].t;
                }
            }
    return W;
}

int CheckGraf (BaseType** W, int N)
{
    int flag1 = (W[0][1].d != MAX) || (W[1][0].d != MAX); //������������
	int flag2 = (W[0][1].d != MAX) && (W[1][0].d != MAX); //�������������
	int i, j;
	if (flag2) //������� �������� ������� ��� ������ ���������� �����
    { //�.�. ������������� �������� ����� ��������� � ����� �������� ����� �� ����������
        for (i = 0; i < N; i++)
            for (j = i+1; j < N; j++)
                flag2 = (W[i][j].d != MAX) && (W[j][i].d != MAX);
        if (flag2)
            return 2;
    }
	if (flag1)
    {
        for (i = 0; i < N; i++)
            for (j = i+1; j < N; j++)
                flag1 = (W[i][j].d != MAX) || (W[j][i].d != MAX);
        if (flag1)
            return 1;
    }
    return 0;
}

