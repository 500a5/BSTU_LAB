#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void input_mass (int A[], size_t nn)
{
    int i;
    for (i=0; i<nn; i++)
        scanf("%d", &A[i]);
}

void output_mass(int A[], size_t nn)
{
    int i;
    for (i=0; i<nn; i++)
        printf("%d ", A[i]);
}

void vkl_sort(int A[],int nn)
//Сортировка включением
{
    int i, j, k;
    for (j=1; j<nn; j++)
        {
            k = A[j];
            i = j-1;
            while ((k<A[i]) && (i>=0))
                {
                    A[i+1] = A[i];
                    i -= 1;
                }
            A[i+1] = k;
        }
}

void vibor_sort(int A[],int nn)
//Сортировка выбором
{
    int i, j, x, k;
    for (i=0; i<nn-1; i++)
        {
            x = A[i];
            k = i;
            for (j=i+1; j<nn; j++)
                if (A[j] < x)
                {
                    k = j;
                    x = A[k];
                }
    A[k] = A[i];
    A[i] = x;
        }
}


void obmen_sort (int A[],int nn)
// Сортировка обменом
{
    int i, j, k, p;
    for (i=0; i<nn-1; i++)
        {
            p = 0;
            for (j=nn-1; j>i; j--)
                if (A[j]<A[j-1])
                {
                    k = A[j];
                    A[j] = A[j-1];
                    A[j-1] = k;
                    p = 1;
                }
      /* Если перестановок не было, то сортировка выполнена */
    if ( p == 0)
	break;
        }
}


