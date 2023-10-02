#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "diskr3_3.h"

int main()
{
    int a[N][N], b[N];
    printf("----1----\n");
    null_matr(a);
    null_mass(b);
    otn_get_4(a);
    output_matr(a);
    printf("Rez:\n");
    razzb(a,b);
    viv_class(b);
    printf("\n");
    printf("----2----\n");
    null_matr(a);
    null_mass(b);
    otn_get_5(a);
    output_matr(a);
    printf("Rez:\n");
    razzb(a,b);
    viv_class(b);
    return 0;
}

