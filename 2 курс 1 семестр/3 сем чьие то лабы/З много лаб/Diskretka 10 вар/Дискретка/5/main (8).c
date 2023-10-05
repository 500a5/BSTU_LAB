#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 10
int W[N];

void OutputMatr(int **a, size_t n, size_t m);
//����� �������
int** MakeIncMatr (int **a, size_t n, size_t *m);
//�������� ������� ������������
int IsMarsh (int **a, size_t n);
// ��� �������?
int IsChikle (int **a, size_t n);
//��� ����?
int IsSimpleChikle (int **a, size_t n);
//��� ������� ����?
int IsChepi (int **a, size_t n);
//��� ����?
int IsSimpleChepi (int **a, size_t n);
//��� ������� ����?
void MakeMarshouts (int **g, size_t n, size_t l, int i, int x);
// i - ����� � ���������
void OutputMarch (int* a, size_t n);
//����� ��������
int** MultMatr(int** a, int** b, size_t n, size_t m);
//��������� �������
int** KolMarsh (int **a, size_t n, size_t l);
//���������� ��������� ����� l
void OutputKolMarsh (int** a, size_t n);
//����� ���������� ��������� ����� l
void MakeMarshoutsXY (int **g, size_t n, size_t l, int i, int x, int y);

int main()
{
    setlocale(LC_ALL, "Rus");
    int n = 7; //������� ������ ���������
   // printf("input name of file: ");
    //char s[20];
    //gets(s);
    char s[]="Matr1.txt";
    FILE *F = fopen(s, "r");
    int v, u;

    int **sm = (int**)calloc(n, sizeof(int*));
    for(v=0; v<n; v++)
        sm[v]=(int*)calloc(n,sizeof(int));

    for (v=0; v<n; v++)
        for (u=0; u<n; u++)
            fscanf(F, "%d", &sm[v][u]);

    fclose(F);

    printf("������� ���������:\n");
    OutputMatr(sm, n, n);
    int m;
    int **inc = MakeIncMatr(sm, n, &m);
    int i;
    for (i=0;i<5;i++)
        printf ("\n%d\n\n",IsMarsh(sm,n));

    return 0;
}

int** MakeIncMatr(int **a, size_t n, size_t *m)
{
    int i, j, k=0, sum=0;
    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
           sum+=a[j][i]; //���������� �������� �������
    (*m) = sum;
    int **matr = (int**)calloc(n, sizeof(int*));
    for(i=0; i<n; i++)
        matr[i]=(int*)calloc(sum,sizeof(int));

    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
        {
           if(a[j][i])
           {
             matr[j][k]=1;
             matr[i][k]=1;
             k++;
           }
        }
    return matr;
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

int IsMarsh (int **a, size_t n)
{
    int i=0, l;
    printf("����� ��������: ");
    scanf("%i",&l);
    int *m=(int*)calloc(l, sizeof(int));
    for (i=0;i<l;i++)
        scanf("%i",&m[i]);
    //if(m[0]==m[l-1])
    //    return 0;
    i=0;
    while (i<l-1 && (a[m[i]-1][m[i+1]-1]!=0))
        i++;
    return i==l-1 ? 1 : 0;
}

int IsChikle (int **a, size_t n)
{
    int i, l;
    printf("����� ��������: ");
    scanf("%i", &l);
    int *m=(int*)calloc(l, sizeof(int));
    for (i=0;i<l;i++) //��� �������� ������� ������
        scanf("%i", &m[i]);
    if(m[0]!=m[l-1])
        return 0;
    int **tmp = (int**)calloc(n, sizeof(int*)); //������� ������� ��� ���������
    for(i=0; i<n; i++)
        tmp[i]=(int*)calloc(n,sizeof(int));
    int k=0, p=0;
    i=0;
    while (i<l-1 && (a[m[i]-1][m[i+1]-1]!=0))
    {
        k=m[i]-1; //�������� �������
        p=m[i+1]-1; //��� ������ � tmp
        if (tmp[k][p]==1 && tmp[p][k]==1)
            return 0;
        tmp[k][p]=1;
        tmp[p][k]=1;
        i++;
    }
    return i==l-1 ? 1 : 0;
}

int IsSimpleChikle (int **a, size_t n)
{
    int i=0, l, j, flag=1;
    printf("����� ��������: ");
    scanf("%i",&l);
    int *m=(int*)calloc(l, sizeof(int));
    for (i=0;i<l;i++)
        scanf("%i",&m[i]);

    if(m[0]!=m[l-1])
        return 0;
    i=0;
    while (i<l-1 && flag && (a[m[i]-1][m[i+1]-1]!=0))
    {
        j=i+1;
        while (j<l-1 && flag)
        {
            flag = m[i]!=m[j];printf ("\n%d   %d   ",m[i],m[j]);printf ("%d   %d   ",i,j);
            j++;
        }
        i++;
    }
    return flag;
}

int IsSimpleChepi (int **a, size_t n)
{
    int i=0, l, j, flag=1;
    printf("����� ��������: ");
    scanf("%i",&l);
    int *m=(int*)calloc(l, sizeof(int));
    for (i=0;i<l;i++)
        scanf("%i",&m[i]);
    i=0;
    while (i<l && flag && (a[m[i]-1][m[i+1]-1]!=0))
    {
        j=0;
        while (j<i-1 && flag)
        {
            flag = m[i]!=m[j];
            j++;
        }
        i++;
    }
    return flag;
}

int IsChepi (int **a, size_t n)//��� ����?
{
    int i, l;
    printf("����� ��������: ");
    scanf("%i", &l);
    int *m=(int*)calloc(l, sizeof(int));
    for (i=0;i<l;i++) //��� �������� ������� ������
        scanf("%i", &m[i]);

    int **tmp = (int**)calloc(n, sizeof(int*)); //������� ������� ��� ���������
    for(i=0; i<n; i++)
        tmp[i]=(int*)calloc(n,sizeof(int));

    int k=0, p=0;
    i=0;
    while (i<l-1 && (a[m[i]-1][m[i+1]-1]!=0))
    {
        k=m[i]-1; //�������� �������
        p=m[i+1]-1; //��� ������ � tmp
        if (tmp[k][p]==1 && tmp[p][k]==1)
            return 0;
        tmp[k][p]=1;
        tmp[p][k]=1;
        i++;
    }
    return i==l-1;
}

void OutputMarch (int* a, size_t n)
{
    int i;
    printf("[ ");
    for (i=0; i<n; i++)
    {
        printf("%i ", a[i]);
        //if (i!=n-1)
          //  printf(",  ");
    }
    printf("]\n");
}

void MakeMarshouts (int **g, size_t n, size_t l, int i, int x)
// g - ������� ��������� ����, n - ������, l -����� ����.
// ����������� ����� = i
{
    W[i-1] = x;
    int j;
    for (j=0; j<n; j++)
    {
       if (g[x-1][j])
        {
           if (i!=l)
                MakeMarshouts(g, n, l, i+1, j+1);
           else
           {
               W[i]=j+1;
               OutputMarch(W, l+1);
           }
        }
    }
}

int** MultMatr(int** a, int** b, size_t n, size_t m)
{
    int i, j, k;
    int **c=(int**)calloc(n, sizeof(int*));
    for(i=0; i<n; i++)
        c[i]=(int*)calloc(n, sizeof(int));
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
        {
            //c[i][j]=0;
            for (k=0; k<n; k++)
                c[i][j]+=(a[i][k]*b[k][j]);
        }
  return c;
}

int** KolMarsh (int **a, size_t n, size_t l)
{
    int i,j;
    int **k=(int **)malloc((n*sizeof(int*)));
    for(i=0;i<n;i++)
        {
            k[i]=(int*)malloc(n*sizeof(int));
            k[i]=a[i];
        }
    for(i=1; i<l; i++)
        k=MultMatr(k, a, n, n);
    return k;
}

void OutputKolMarsh (int** a, size_t n)
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=i; j<n; j++)
            printf("(%i ... %i) : %i\n", i+1, j+1, a[i][j]);
    }
}

void MakeMarshoutsXY (int **g, size_t n, size_t l, int i, int x, int y)
// g - ������� ��������� ����, n - ������, l -����� ����.
// ����������� ����� = i, x-1, y-last
{
    W[i-1] = x;
    int j;
    for (j=0; j<n; j++)
    {
        if (g[x-1][j])
            if (i==l-1)
            {
                if (g[y-1][j])
                {
                    W[i]=j+1;
                    W[l]=y;
                    OutputMarch(W, l+1);
                }
            }
            else
                MakeMarshoutsXY(g, n, l, i+1, j+1, y);
    }
}

/*int j;
    W[i-1]=x;
    for (j=0; j<n;j++)
    {
        if (A[x-1][j])
        {
           if (i==L-1)
           {
               if (A[j][v2-1])
               {
               W[i]=j+1;
               W[L]=v2;
               Output1Track(W,L+1);
               }
           }
           else
           GetTrack2 (i+1,j+1,v2,A,n);
        }
    }*/





