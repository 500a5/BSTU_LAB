#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int size;
    char color[20];
} xyi;
xyi dima_shlen[5][4];
dima_shlen[2][3].size = 4;

��������� ������
int **a; int n = 3; int m = 5;
a = (int **) malloc(n*sizeof(int *));
int i;
for(i = 0; i < n; i++)
    a[i] = (int *) malloc(m* sizeof(int));

�������� ������
int **a; int n = 3; int m = 5;
int i;
for(i = 0; i < n; i++)
    free(a[i]);
free([a]);





void strCopy(char a[],char b[]); a[i] = 'y';

void (int **a,int m,int n); a[i][j]  = *(*(a+i) + j)
int *lol(char kek);

void strCopy(char *a,char *b); *(a+i) = 'x'
//��������� �� ������� strCopy
void (*pCopy)(char *,char *) = &strCopy;

//�������� ��������� �� �������
void lol(char a, char b, void (*pCopy)(char *,char *)){
    pCopy(a,b);
}

�����

FILE * lox = fopen("chlen.txt","r");
���������
r ������(���� ���  �����, �� fopen ����� NULL)
w ������
r+ ��� ������ � ������ (���� ���  �����, �� fopen ����� NULL)
w+ ��� ������ � ������

������� ��� ��������� ����, ���  � ��� �������
������  � �����  ������� ������������ �������� f
� ������ �������� FILE *
������: fprintf(FILE *,"���� ������ � ������������", ���� ����������);



�������� (���� ����� ��� �  � ���������)
FILE * lox = fopen("chlen.bin","rb");
rb
wb
r+b
w+b

fread(����� ����������, � ������ � ������, 1, ��������� �� ���� ����);
fwrite(���� �����);

fseek(���� ����, ������� �������� * sizeof(���, ������� ������� � ���� ����), SEEK_SET);

��� �����
fclose(��������� �� ����);
remove("���� ������ : ���������\\�������\\��.(��� ������ ����)");
rename("������ ����","����� ����");







