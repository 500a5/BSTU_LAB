#include "malloc.h"
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/// заполнение отношения случайными упорядоченными парами
void make_form(int **a, int N, int k) {
    int x, y, i = 0;
    if (k == N*N){
        for (i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = 1;
    }
    while (i < k){
        x = rand() % N;
        y = rand() % N;
        if (!a[x][y]){
            a[x][y] = 1;
            i++;
        }
    }
}


void warshel_algorithm_for_transitive_closure(int **a, int **c, int n) {
    for (int x = 1; x < n; x++)
        for (int y = 1; y < n; y++)
            c[x][y] = a[x][y];
    int x, y, z;
    for (z = 1; z < n; z++)
        for (x = 1; x < n; x++)
            for (y = 1; y < n; y++)
                c[x][y] = c[x][y] || c[x][z] && c[z][y];
}

/// очистка матрицы
void clear(int **a, int n) {
    int x, y;
    for (x = 0; x < n; x++)
        for (y = 0; y < n; y++)
            a[x][y] = 0;
}


int podmn_of_relation(int **a, int **b, int N){ //отношение а - подмножество b
    for(int i = 1; i < N; i++)
        for(int j = 1; j < N; j++)
            if (a[i][j] > b[i][j])
                return 0;
    return 1;
}

void comp_of_relation(int **a, int **b, int **c, int N){ //композиция отношений
    int i,j,k;
    for(i = 1; i < N; i++)
        for(j = 1; j < N; j++){
            c[i][j] = 0;
            for(k = 1; k < N; k++)
                c[i][j] = c[i][j] || (a[i][k] && b[k][j]);
        }
}

/// объединение
void unit(int **a, int **b, int **res, int N) {
    int x, y;
    for (x = 1; x < N; x++)
        for (y = 1; y < N; y++)
            res[x][y] = a[x][y] || b[x][y];
}

void copy(int **a, int **b, int N){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            b[i, j] = a[i, j];
}

void transitive_closure(int **a, int **c_tran, int N) {
    int i, j;
    int **power_a, **start_a;

    /// Сtran = a
    for (i = 1; i < N; i++)
        for (j = 1; j < N; j++)
            c_tran[i][j] = a[i][j];

    power_a = (int **)calloc(N, sizeof(int*));
    for (i = 0; i < N; i++)
        power_a[i] = (int *)calloc(N, sizeof(int));

    start_a = (int **)calloc(N, sizeof(int*));
    for (i = 0; i < N; i++)
        start_a[i] = (int *)calloc(N, sizeof(int));

    ///  power_a := Ctran^2
    comp_of_relation(a, a, power_a, N);
    copy(a, start_a, N);
    /// c_tran = C_tran + a^i
    for (i = 2; i < N; i++) {
        if(i % 2 == 0) {
            comp_of_relation(a, start_a, power_a, N);
            unit(c_tran, power_a, c_tran, N);
        } else{
            comp_of_relation(power_a, start_a, a, N);
            unit(c_tran, a, c_tran, N);
        }
    }

    for (i = 0; i < N; i++)
        free(power_a[i]);
    free(power_a);
}

void compare_of_methods(int **input_relation, int **res_relation, int N, int k) {
    double min1, max1, s, min2, max2;
    clock_t start, end;
    int i;
    printf("\nk=%d\n", k);
    max1 = 0;
    max2 = 0;
    min1 = min2 = clock();
    for (i = 1; i <= 50; i++){
        make_form(input_relation, N, k);

        start = clock();
        transitive_closure(input_relation, res_relation, N);
        end = clock();
        s = ((double)end - start) / ((double)CLOCKS_PER_SEC);
        if (s > max1)
            max1 = s;
        if (s < min1)
            min1 = s;
        clear(res_relation, N);

        start = clock();
        warshel_algorithm_for_transitive_closure(input_relation, res_relation, N);
        end = clock();
        s = ((double)end - start) / ((double)CLOCKS_PER_SEC);
        if (s > max2)
            max2 = s;
        if (s < min2)
            min2 = s;
        clear(res_relation, N);
        clear(input_relation, N);
    }
    printf("transitive_closure:\n");
    printf("min = %f\nmax = %f\n",  min1, max1);

    printf("Worshal transitive closure:\n");
    printf("min = %f\nmax = %f\n", min2, max2);
}

void time_count(int **relation_1, int **relation_2, int N) {
    int k;
    k = 1;
    compare_of_methods(relation_1, relation_2, N, k);
    k = N * N / 4;
    compare_of_methods(relation_1, relation_2, N, k);
    k = N * N / 2;
    compare_of_methods(relation_1, relation_2, N, k);
    k = N * N * 2 / 3;
    compare_of_methods(relation_1, relation_2, N, k);
    k = N * N;
    compare_of_methods(relation_1, relation_2, N, k);
}


int main() {
    int i, N = 150;
    int **relation_1;
    relation_1 = (int **)calloc(N, sizeof(int*));
    for (i = 0; i < N; i++)
        relation_1[i] = (int *)calloc(N, sizeof(int));
    int **relation_2;
    relation_2 = (int **)calloc(N, sizeof(int*));
    for (i = 0; i < N; i++)
        relation_2[i] = (int *)calloc(N, sizeof(int));
    time_count(relation_1, relation_2, N);
    getchar();
    return 0;
}