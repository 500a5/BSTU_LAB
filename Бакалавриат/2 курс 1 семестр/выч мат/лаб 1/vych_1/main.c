#include <stdio.h>
#include <process.h>
#include "p6.h"
#include "p7.h"

float **read_free_term(float **B, int i, int *g)
{
    int h = 1;
    int  y;
    int z = 0;
    B = (float**) malloc(i * sizeof(float*));
    for(y = 0; y < i; y++)
        B[y] = (float*) malloc(1 * sizeof(float));
    while(h != 0)
    {
        for(y = 0; y < i; y++)
            B[y] = (float*) realloc(B[y], (z+1) * sizeof(float));

        printf("\nВВедите свободные члены : ");
        for(y = 0; y < i; y++)
            scanf("%f", &B[y][z]);
        z++;

        printf("НУжно ввести еще свободные члены ? 1 - Да, 0 - Нет ");
        scanf("%d", &h);
    }

    for(y = 0; y < i; y++){
        for(int u = 0; u < z; u++)
            printf("%f ", B[y][u]);
        printf("\n");
    }
    *(g) = z;

    return B;
}
//ввод матрицы размером i

float **read_matr(float **set, int i)
{
    int y;
    float x;

    printf("\nRead matr:\n");
    set = (float**) malloc(i * sizeof(float*));
    for(y = 0; y < i; y++)
        set[y] = (float*) malloc(i * sizeof(float));

    for( y = 0; y < i; y++)
        for(int t = 0; t < i; t++)
        {
            scanf("%f", &x);
            set[y][t] = x;
        }
    return set;
}

//вывод матрицы

void write_matr(float **set,  int i)
{
    printf("\nWrite matr:\n");
    for(int y = 0; y != i; y++)
    {
        for(int t = 0; t != i; t++)
            printf("%f ", set[y][t]);
        printf("\n");
    }
}


int main(){
    int y, i, g;
    float r = 1;
    float **A = NULL;
    float **B = NULL;
    float **X = NULL;
    B = (float**) malloc(3 * sizeof(float*));
    for(y = 0; y < 3; y++)
        B[y] = (float*) malloc(1 * sizeof(float));
    A = (float**) malloc(3 * sizeof(float*));
    for(y = 0; y < 3; y++)
        A[y] = (float*) malloc(1 * sizeof(float));
    X = (float**) malloc(3 * sizeof(float*));
    for(y = 0; y < 3; y++)
        X[y] = (float*) malloc(1 * sizeof(float));
input(A,3,3);
input(B,3,3);
mult_A_B(A,3,3,B,X);
output(X,3,3);

    for (y = 0; y != i; y++)
        free(A[y]);
    free(A);

    for (y = 0; y != g; y++)
        free(B[y]);
    free(B);

    free(X);
printf("%d",&i);
    return 0;
}
