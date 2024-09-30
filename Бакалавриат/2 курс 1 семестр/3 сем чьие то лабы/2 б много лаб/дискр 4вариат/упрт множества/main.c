#include <stdio.h>
#include <stdlib.h>
#include "uprtmodul.h"


void main()
{
    printf(" M1 or M2 ");
    int ch, i;
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
        {
            int n=9;
            int** a= (int**)calloc(n, sizeof(int*));
            for (i=0; i<n; i++)
                a[i]=(int*)calloc(n, sizeof(int));

            init_M1(&a, n);

            for (i=0; i<n; i++)
                free(a[i]);
            free(a);
            break;
        }
    }
}
