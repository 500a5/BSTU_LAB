#include <stdio.h>
#include <stdlib.h>
#include "poisk.h"
#define N 10

int main()
{


   int b[N];
   vvod_keb_din(b, N);
   viv_desk_din(b, N);


    int f = blocs_upor(b, 6, N);
    printf("%d ", f);


    return 0;
}

void vvod_keb_din (int *a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void viv_desk_din (int *a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
}

