#include <stdio.h>
#include <stdlib.h>
#include "uprtmodul.h"
#define X 9
#define Y 13


void output_matr(int **a, size_t n)
{
    int i, j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void init_M1 (int **a, size_t n)
{
    int i=0, gox[X], vey[X], ch=-1;
    for (i=0; i<=2; i++)
    {
        vey[i]=ch; vey[i+3]=ch; vey[i+6]=ch;
        gox[i]=ch; gox[i+3]=ch; gox[i+6]=ch;
        ch++;
    }
    int j;
    for(i=0; i<n; i++)
        for (j=0; i<n; j++)
        {
            if (gox[i]-gox[j] <= vey[i]-vey[j])
                a[i][j]=1;
        }
}









