#include <stdio.h>
#include <stdlib.h>
#include "poissk.h"
#include <math.h>
#include <locale.h>
#include <time.h>
#define N 51
int main()
{
    int n, x, k1=0, k2=0, k3=0;
    printf(" n >> ");
    scanf("%d", &n);
    int *a = (int*)calloc(n, sizeof(int));
    int b[N];

    vvod_rand_midl(a, n);
    printf("\n");
    //viv_desk_din(a, n);
    printf(" x >> ");
    scanf("%d", &x);

    //line_upor(a, x, n, &k2);
    line_neup(a, x, n, &k2);
    printf("Line %d ", k2);

   // binary_upor(a, x, n, &k3);
   speed_line_neup(a, x, n, &k3);
    printf("Speed %d ", k3);

   // blocs_upor(a, x, n, &k1);
  //  printf("Blok %d ", k1);



   // line_neup(a, x, n, &k2);
  //  printf("Line neup %d", k2);


    printf("\n");

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

void vvod_rand_max (int *a, size_t n)
{
    int i;
    for (i=1; i<n; i=i+2)
    {
        a[i]=n/(n-i)*i;
        a[i+1]=n+3-i;
    }
    printf("%d\n", a[n-1]);
}

void vvod_upor_max(int *a, size_t n)
{
     int i;
     for (i=0; i<n; i++)
        a[i]=i+2;
    printf("%d", a[n-1]);
}

void vvod_rand_midl (int *a, size_t n)
{
    int i;
    int midl = n/2;
    for (i=1; i<n; i=i+2)
    {
        a[i]=n/(n-i)*i;
        a[i+1]=n+3-i;
    }
    printf("%d\n", a[midl]);
}

void vvod_upor_midl(int *a, size_t n)
{
    int i;
    int midl = n/2;
    for (i=0; i<n; i++)
       a[i]=i+2;
    printf("%d\n", a[midl]);
}














