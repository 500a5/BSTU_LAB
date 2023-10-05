#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "mod_matr.h"
#include "gauss.h"
#define EPS 0.0000001

void str_swap (float **a, char x, char y)
{
    float *tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

int comp (float x, float y)
{
    if ((x-y)>0) return 1;
    else
    {
        if (fabsf(x-y)<EPS) return 0;
    }
}

char gauss_nt (float **a, size_t m, size_t n)
{
    int i=0, j=0, k=0, y=0;
    float max=0, mu=0;
    for (k=0; k<m; k++)
    {
        y = k;
        max = fabsf(a[k][k]);
        for (i=k+1; i<m; i++)
        {
            if (comp(a[i][k], max))
            {
                y = i;
                max = fabsf(a[i][k]);

            }
        }
        if (!comp(max, 0)) return 0;

        str_swap(a, y, k);

        for (i=k+1; i<m; i++)
        {
            mu = a[i][k]/a[k][k];
            for (j=0; j<n; j++) a[i][j] -= mu*a[k][j];
        }
    }
    return 1;
}

void gauss_vt (float **a, size_t m, size_t n)
{
    int i=0, j=0, k=0;
    float max=0, mu=0;

    for (k=m-1; k>=0; k--)
    {
         for (i=k-1; i>=0; i--)
         {
             mu = a[i][k]/a[k][k];
             for (j=0; j<n; j++) a[i][j] -= mu*a[k][j];
         }
    }
}


char gauss_slau (float **a, size_t m, size_t n)
{
    int ch = gauss_nt(a, m, n);
    if (!ch) return 0;

    float suma=0;
    int i=0, j=0, k=0;

    gauss_vt (a, m, n);

    for (k=m; k<n; k++)
    {
        for (i=m-1; i>=0; i--)
        {
            suma=0;
            for (j=m-1; j>i; j--) suma += a[i][j]*a[j][k];
            a[i][k] = (a[i][k]-suma)/a[i][i];
            printf("%.2f ", a[i][k]);
        }
        printf("\n");
    }
}

float gauss_det (float **a, size_t m, size_t n)
{
    if (!(gauss_nt(a, m, n))) return 0;
    float dett=1;
    int i=0;
    for (i=0; i<m; i++) dett *= a[i][i];
    return dett;
}

char gauss_obrat (float **a, size_t m, size_t n)
{
    if (!gauss_nt(a, m, n)) return 0;
    int i, j;
    float num;

    gauss_vt(a, m, n);
    for (i = 0; i < m; i++)
    {
        num = a[i][i];
        for (j = m ; j < n; j++) a[i][j] /= num;
        a[i][i] = 1;
    }
    for (i=0;i<m;i++)
    {
        for (j=m;j<n;j++)
        {
            printf("%.2f  ", a[i][j]);
        }
        printf("\n");
    }
    return 1;
}












