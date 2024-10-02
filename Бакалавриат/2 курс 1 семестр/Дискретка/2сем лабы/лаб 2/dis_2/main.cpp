#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstdlib>

int **generate_rand_matr(int **A, int n, int i)
{
    int x, y, j = 0;

    while (j != i)
    {
        x = rand() % n;
        y = rand() % n;
        if(A[x][y] == 0)
        {
            A[x][y] = 1;
            j++;
        }
    }

    return A;
}



void transitively(int **X, int **A, int n)
{
    int x, z, y;
    for(y = 0; y < n; y++)
        for(x = 0; x < n; x++)
            X[x][y] = A[x][y];

    for(z = 0; z < n; z++)
    {
        for(x = 0; x < n; x++)
        {
            for(y = 0; y < n; y++)
            {
                if((X[x][y] == 1) || ((X[x][z] == 1) && (X[z][y] == 1)))
                    X[x][y] = 1;
            }
        }
    }
}
void union_matr(int **C, int **A, int n)
{
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            if(C[x][y] == 0 && A[x][y] == 1)
                C[x][y] = 1;

}

int **composition_matr_A_B(int **A, int **B, int n)
{
    int **F = NULL;
    int i, j, z;

    F = (int**) malloc(n * sizeof(int*));

    for(i = 0; i < n; i++)
        F[i] = (int*) malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            F[i][j] = 0;


    for(i = 0; i < n; i++)
    {
        for(z = 0; z < n; z++)
        {
            if(A[i][z] == 1)
                for(j = 0; j < n; j++)
                {
                    if(B[z][j] == 1)
                        F[i][j] = 1;
                }
        }
    }

    return F;
}
int **getmem_matr(int **A, int n){
    A = (int**) malloc( n *  sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc(n * sizeof(int));
    }
    return(A);
}
void free_matr(int **A, int n){
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
}
void transitively_union(int **C, int **A, int n)
{
    int x, y, i = 0;

    int **B = NULL;
    B = (int**) malloc(n * sizeof(int*));
    for(y = 0; y < n; y++)
        B[y] = (int*) malloc(n * sizeof(int));


    for(x = 0; x < n; x++)
        for(y = 0; y < n; y++)
            C[x][y] = A[x][y];

    B = composition_matr_A_B(A, A, n);

    union_matr(C, B, n);

    for(i = 3; i < n; i++)
    {
        B = composition_matr_A_B(B, A, n);
        union_matr(C, B, n);
    }

    free_matr(B, n);
}

int main()
{

    srand(time(NULL));
    int **A = NULL;
    int **X = NULL;

    int n, i;

    printf("Введите мощность N: ");
    scanf("%d", &n);

    getmem_matr(X, n);
    A = getmem_matr(A, n);


    printf("Введите кол-во пар i: ");
    scanf("%d", &i);

    clock_t start;
    clock_t finish;
    double min;
    double max;
    double s;


    for(int y = 0; y<n; y++)
    {
        for(int r = 0; r<n; r++)
        {
            A[y][r] = 0;
            printf("%d ", A[y][r]);

        }

        printf("\n");
    }

    A = generate_rand_matr(A, n, i);
    for(int y = 0; y<n; y++)
    {
        for(int r = 0; r<n; r++)
            printf("%d ", A[y][r]);
        printf("\n");
    }

    start = clock();

    transitively(X, A, n);
    //transitively_union(X, A, n);

    finish = clock();

    s = finish - start;
    //s = double(finish - start) / CLOCKS_PER_SEC;
    min = s;
    max = s;

    for(int t = 1; t < 1000; t++)
    {
        A = generate_rand_matr(A, n, i);

        start = clock();

        transitively(X, A, n);
        //transitively_union(X, A, n);

        finish = clock();

        s = finish - start;
        //s = double(finish - start) / CLOCKS_PER_SEC;
        if(s > max)
            max = s;
        if(s < min)
            min = s;
    }

    printf("Min: %f\n", min);
    printf("Max: %f\n\n", max);

    free_matr(A, n);
    free_matr(X, n);

    return 0;
}