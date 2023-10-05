#include <stdio.h>
#include <stdlib.h>
#define N 10
#include <locale.h>

void new_matr33 (int a[N][N]);
void null_matr (int a[N][N]);
void output_matr(int a[N][N]);
void output_mass(int a[N]);
void null_mass (int a[N]);
void make_eqkals (int a[N][N], int b[N], int x);
void ed_mass (int a[N]);
void copi_matr (int a[N][N], int b[N][N]);
int sraw_mn (int a[N], int b[N]);
int sraw_matr (int a[N][N], int b[N][N]);
void razb_mn (int m[N][N]);


int main()
{
    setlocale(LC_ALL, "Rus");
    int a[N][N], b[N];

    null_matr(a); //обнуление матрицы для построения отношения
    new_matr33(a); // формирование матрицы a
    output_matr(a); // дмонстрация

    razb_mn(a);
}

void new_matr33 (int a[N][N])
{
    int i=0, j=0;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if (i==j) a[i][j]=1;
        }

    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if ((i+j)%2!=0) a[i][j]=1;
        }
}

void null_matr (int a[N][N])
{
    int i=0, j=0;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            a[i][j]=0;
}

void output_matr(int a[N][N])
{
    int i, j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void output_mass(int a[N])
{
    int i;
    for(i=0; i<N; i++)
        printf("%d ", a[i]);
}

void null_mass (int a[N])
{
    int i;
    for (i=0; i<N; i++)
        a[i]=0;
}

void make_eqkals (int a[N][N], int b[N], int x)
{
    b[x]=1;
    int i;
    for (i=0; i<N; i++)
    {
        if (a[x][i])
            b[i]=1;
    }
}

void ed_mass (int a[N])
{
    int i;
    for (i=0; i<N; i++)
        a[i]=1;
}

void copi_matr (int a[N][N], int b[N][N])
{
    int i, j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            b[i][j]=a[i][j];
}

int sraw_mn (int a[N], int b[N])
{
    int i;
    for (i=0; i<N; i++)
        if (a[i]!=b[i])
            return 0;
    return 1;
}

int sraw_matr (int a[N][N], int b[N][N])
{
    int i, j;
    for (i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            if (a[i][j]!=b[i][j])
                return 0;
        }
    return 1;
}

void razb_mn (int m[N][N])
{
    int a[N][N], s[N][N], i=0, k=1, j, f;
    null_matr(a);
    copi_matr(m, a);
    null_matr(s);

    make_eqkals(a, s[0], 1);
    for (i=0; i<N; i++)
    {
        f=1;
        make_eqkals(a, s[k], i);
        j=0;
        while ((j<k)&&(f))
        {
            f=sraw_mn(s[k], s[j]);
            j++;
        }
        if (!f)
            k++;
    }

    output_mass(s);
}


