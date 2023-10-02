#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct
{
    int t; //���設�, �।������� ���設� j �� ���砩襬 ��� �� i �� j
    int d; //����� ���砩襣� ��� �� i �� g (W[i,j].d)
} BaseType;


int** InitMem(int N){	//���樠������ �����
    int i;	int** G;
    G = (int**)malloc(N*sizeof(int*));
    for(i = 0; i < N; i++)
        G[i] = (int*)calloc(N, sizeof(int));
    return G;
}

void FreeMem(int** G, int N)
{  	int i;	for(i = 0; i < N; i++)
        free(G[i]);	free(G);
}

void WriteGraph(int** G, int N)
{ //�뢮� ���
    int i, j;
    printf("����:\n");
    for(i = 0; i < N; i++)
    {	for(j = 0; j < N; j++)
            if(i!=j && G[i][j] == 0)
                printf("I\t");//��᪮��筮��� = infinity
            else	printf("%i\t", G[i][j]);  //�뢮� �᫠
        printf("\n");
    }
    printf("\n");
}

int** ReadGraph(int *N)
{//���뢠��� ���
    int** G, tmp, i, j;	FILE *f;
    f = fopen("input.txt","r"); //�⥭�� �� 䠩�� � ������ input
    fscanf(f,"%i",&tmp);
    G = InitMem(tmp);
    for(i = 0; i < tmp; i++){
        for(j = 0; j < tmp; j++)
            fscanf(f, "%i", &G[i][j]);
    }
    fclose(f);
    (*N)=tmp;
    return G;
}

BaseType** ModMatr(int** G, int N)//ᮧ����� ������ ��ᮢ
{
    /*int t; //���設�, �।������� ���設� j �� ���砩襬 ��� �� i �� j
      int d; //����� ���砩襣� ��� �� i �� g (W[i,j].d)*/
    BaseType** M;
    int i, j;
    M = (BaseType**)malloc(N*sizeof(BaseType*));
    for(i = 0; i < N; i++)
        M[i] = (BaseType*)malloc(N*sizeof(BaseType)); //�뤥����� ����� �� �����㢥ᮢ �
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            if(G[i][j] == 0) //�᫨ ��� ��⥩
                M[i][j].d = MAX; //� � .d ��᢮�� ��᪮��筮���
            else
                M[i][j].d = G[i][j]; //���� ���������� �����
            if(i==j) //�᫨ ������� ���������, � �㫨
            {
                M[i][j].t = 0;
                M[i][j].d = 0;
            }
            else //����, �᫨ ����� �� ࠢ�� ���
            {
                if(G[i][j] != 0)//�᫨ ����� �� ࠢ�� ���
                    M[i][j].t = G[i][j]; //��᢮�� ���
                else
                    M[i][j].t = -1; //���� -1 (⠪��� ���)
            }
        }
    return M;
}
void WriteMatrWes(BaseType** G, int N)
{//����� ������ ��ᮢ
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {//�뢮� ������ ��ᮢ, �᫨ ���, � ����� I, ���� ����� ᮤ�ন����
            (G[i][j].d == MAX) ? printf("(I; ") : printf("(%d; ", G[i][j].d);
            (G[i][j].t == MAX) ? printf("I)") : printf("%d)", G[i][j].t);
            printf("\t");
        }
        printf("\n");
    }
    printf("\n");
}

void CopyMatr (BaseType** M, BaseType** W, int N) //����஢���� � � W
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            W[i][j] = M[i][j];
}

BaseType **AlgFloyd (BaseType** M, int N)  // ������ 䫮���
{
    BaseType** W;
    int z, x, y;
    W = (BaseType**)malloc(N*sizeof(BaseType*)); //�뤥����� �����
    for(z = 0; z < N; z++)
        W[z] = (BaseType*)malloc(N*sizeof(BaseType));
    CopyMatr(M, W, N); //����ࢮ���� ������ ��ᮢ � � ������ W
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

int CheckGraf (BaseType** W, int N)  //�஢�ઠ ������
{
    int flag1 = (W[0][1].d != MAX) || (W[1][0].d != MAX); //᫠���吝�
    int flag2 = (W[0][1].d != MAX) && (W[1][0].d != MAX); //ᨫ쭮�吝�
    int i, j;
    if (flag2) //᭠砫� �஢�ਬ �᫮��� ��� ᨫ쭮 �易����� ���
    { //�.�. ᨫ쭮�吝� . ᫠�� �易��� � ⮣�� �஢�ઠ �㤥� �� ���४⭮�
        for (i = 0; i < N; i++)
            for (j = i+1; j < N; j++)
                flag2 = (W[i][j].d != MAX) && (W[j][i].d != MAX);
        if (flag2)            return 2;
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

int main()
{

    int** G, N;
    BaseType **M, **W;
    G = ReadGraph(&N);      //���뢠��� ���
    WriteGraph(G, N);       //�뢮� ���
    M = ModMatr(G, N);      //�������� ������ ��ᮢ
    W = AlgFloyd(M, N);     //�ਬ������ �����⬠ ������
    WriteMatrWes(W, N);     //�뢮� ������ ��᫥ �믮����� �����⬠ 䫮���
    switch (CheckGraf(W, N))
    {
        case 0:	{	printf("���� ᫠��� ��� ���������.\n"); 	break;	}
        case 1:      {	printf("������஭�� �易��� ���.\n");	break;	}
        case 2:    	{	printf("���쭮 �易��� ���.\n");		break;	}
    }
    return 0;
}



