#include <stdio.h>
#include <stdlib.h>
#include "mod_matr.h"

void input_matr(float **a, size_t m, size_t n)
{
    int i, j;
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
        scanf("%f",&a[i][j]);
}

void output_matr(float **a, size_t m, size_t n)
{
    int i, j;
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%.2f  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

char summ (float **a, size_t n, size_t m, float **b, size_t k, size_t l, float **s)
{
    if ((m==k)&&(n==l))
    {
        int i, j;
        for (i=0; i<m; i++)
            for (j=0; j<n; j++) s[i][j]=a[i][j]+b[i][j];
        return 1;
    }
    else return 0;
}

char razn (float **a, size_t n, size_t m, float **b, size_t k, size_t l, float **s)
{
    if ((m==k)&&(n==l))
    {
        int i, j;
        for (i=0; i<m; i++)
            for (j=0; j<n; j++) s[i][j]=a[i][j]-b[i][j];
        return 1;
    }
    else return 0;
}

void um_al (float **a, size_t m, size_t n, float **s)
{
    int i, j;
    float al;
    printf("alpha = ");
    scanf ("%f", &al);
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            s[i][j] = al*a[i][j];
        }
    }
}

void umn_matr (float **a, float **b, float **s, size_t m)
{
    int i, j, k;
    for(i = 0; i < m; i++)
        for(j = 0; j < m; j++)
        {
            s[i][j] = 0;
            for(k = 0; k < m; k++) s[i][j] += a[i][k] * b[k][j];
    }
}

void trans (float **a, size_t m, size_t n, float **s)
{
    int i, j;
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            s[j][i]=a[i][j];
        }
    }
}








