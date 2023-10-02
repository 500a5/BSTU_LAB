#include <stdio.h>
#include <stdlib.h>

void getmem(int ***a, int n)
{
    *a = calloc(n,sizeof(int*));
    for (int i = 0; i < n; i++)
        (*a)[i] = calloc(n,sizeof(int));
}

void matr_A(int **a, int n)
{
    for(int i  =1; i < 11; i++)
        for(int j = 1; j < 11; j++)
            if (((i % 2 == 0) && (j % 2 == 0) )|| (i==j))
                a[i-1][j-1] = 1;
}

int qwrqwr(int **a, int *r, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        if (r[i] == 0)
        {
            k++;
            for (int j = 0; j < n; j++)
                if (a[i][j])
                    r[j] = k;
        }
    return k;
}

int main()
{
    int **a, n = 10, *r = calloc(n*n,sizeof(int));
    getmem(&a,n);
    matr_A(a,n);
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%i ",a[i][j]);
        printf("\n");
    }
    int k = qwrqwr(a,r,n);
    printf("\n\n");
    int t = 1;

    for (int i = 0; t <= k; i++)
    {
        if (r[i] == t)
        {
            for (int j = 0; j < n; j++)
                if (a[i][j])
                    printf("%i ", j + 1);
            t++;
            printf("\n");
        }
    }
    return 0;
}
