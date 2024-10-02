#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void main()
{
    int n;
    printf("n >> ");
    scanf("%d", &n);
    int *a = (int*)calloc(n, sizeof(int));
    input_mass(a, n);
    printf("\n");

    vkl_sort(a, n);

    output_mass(a, n);
}
