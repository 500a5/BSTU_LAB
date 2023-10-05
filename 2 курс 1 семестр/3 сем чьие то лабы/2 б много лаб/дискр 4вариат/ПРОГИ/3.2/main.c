#include <stdio.h>
#include <stdlib.h>
#define N 10

#define OTN 1000
#include <locale.h>
#include <time.h>
#define EPS 0.0000001

int comp(int a[N][N], int b[N][N], int c[N][N])
//композиция
{
	int x = 0, y = 0, z, k = 0;
	for (; x<N; x++)
		for (y = 0; y<N; y++)
        {
			c[x][y] = 0;
			z = 0;
			while ((z<N) && !c[x][y])
			{
				c[x][y] = (c[x][y] || a[x][z]*b[z][y]);
				k++;
				z++;
			}
		}
	return(k);
}

void ob(int a[N][N], int b[N][N], int c[N][N])
//объединение
{
	int x = 0, y = 0;
	for (x=0; x<N; x++)
		for (y = 0; y<N; y++)
			c[x][y] = (a[x][y] || b[x][y]);

}

void generation (int a[N][N], unsigned count1, int n)
{
    srand(n);
    unsigned i,j,k;
    for (k=0; k<count1; ++k)
     {
        do
        {
          i=rand()%N;
          j=rand()%N;
        }
        while (a[i][j]);
        a[i][j]=1;
     }
}

void null_matr (int s[N][N])
//нулевая матрица
{
    int i=0, j=0;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            s[i][j]=0;
}

void output_matr(int a[N][N])
// вывод матрицы
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

void copy_ot (int a[N][N], int b[N][N])
//копия
{
    int i, j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            b[i][j]=a[i][j];
}

unsigned long tranzit_uol (int a[N][N], int c[N][N])
//алгоримт уоршалла
{
    unsigned long k = (N + 1)*(N + 1)*(N + 1);
    copy_ot(a, c);
    int x, y, z;
    for (z=0; z<N; z++)
        for (y=0; y<N; y++)
            for (x=0; x<N; x++)
            {
                c[x][y]=c[x][y]+c[x][z]*c[z][y];
                if (c[x][y] > 1)
                    c[x][y]=1;
            }
    return k;
}

unsigned long tranzit_step (int a[N][N], int c[N][N])
//объединение степеней
{
	int t1[N][N], t2[N][N], i;
	unsigned long k = 0;
	copy_ot(t1, a);
	copy_ot(c, a);
	for (i=2; i<=N; i++)
        {
            k += comp(t1, a, t2);
            ob(c, t2, c);
            copy_ot(t1, t2);
        }
	return k;
}

int sraw (float x, float y)
{
    if ((x-y)>0) return 1;
    else
    {
        if (fabsf(x-y)<EPS) return 0;
    }
}

void timer_1 (int a[N][N], int kolpar)
{
    int i=0, c[N][N];
    double min, max, tmp1, tmp2;
    null_matr(a);
    null_matr(c);
    generation(a, kolpar, i);
    clock_t time_start= clock();
    tranzit_uol(a, c);
    clock_t time_end = clock() - time_start;
    min = (double)time_end/CLOCKS_PER_SEC;
    max = (double)time_end/CLOCKS_PER_SEC;

    for (i=1; i<OTN; i++)
    {
        null_matr(a);
        null_matr(c);
        generation(a, kolpar, i);
        clock_t time_start= clock();
        tranzit_uol(a, c);
        clock_t time_end = clock() - time_start;
        tmp1 = (double)time_end/CLOCKS_PER_SEC;
       /* if (sraw(tmp1, min))
            min = tmp1;
        if (sraw(max, tmp1))
            max = tmp1;*/
        if (tmp1 > max)
            max = tmp1;
        if (tmp1 < min)
            min = tmp1;
    }
    printf("Уоршалл При N = %d, min = %f, max = %f\n", N, min, max);
}

void timer_2 (int a[N][N], int kolpar)
{
    int i=0, c[N][N];
    double min, max, tmp1, tmp2;
    null_matr(a);
    null_matr(c);
    generation(a, kolpar, i);
    clock_t time_start= clock();
    tranzit_uol(a, c);
    clock_t time_end = clock() - time_start;
    min = (double)time_end/CLOCKS_PER_SEC;
    max = (double)time_end/CLOCKS_PER_SEC;

    for (i=1; i<OTN; i++)
    {
        null_matr(a);
        null_matr(c);
        generation(a, kolpar, i);
        clock_t time_start= clock();
        tranzit_step(a, c);
        clock_t time_end = clock() - time_start;
        tmp1 = (double)time_end/CLOCKS_PER_SEC;
        if (tmp1 > max)
            max = tmp1;
        if (tmp1 < min)
            min = tmp1;
    }
    printf("Степень При N = %d, min = %f, max = %f\n", N, min, max);
}


int main()
{
    setlocale(LC_ALL, "Rus");
    int a[N][N], b[N][N];
    null_matr(a);
   // printf("Количество пар: ");
    int n = 1;
   // scanf("%d", &n);

    timer_2(a, n);
    null_matr(a);
   // timer_1(a, n);


    return 0;
}
