#include "Kraskal_algorithm.h"


void display_matrix(int **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}


void input_matrix(int **a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d ", &a[i][j]);
    printf("\n");
}


int **init_matrix(int n){
    int **matrix = (int**)calloc(n, sizeof(int*));//создаем тестовую матрицу
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)calloc(n, sizeof(int));
    return matrix;
}


//алгоритм Краскала
int** kraskal_algorithm(int **graph, int n) {
    int *flower = (int*)malloc(sizeof(int)*n);
    int **forest = init_matrix(n);
    for (int j = 0; j < n; j++)
        flower[j] = j;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (graph[i][j] == 1 )
                if (flower[i] != flower[j]) {
                    forest[i][j] = 1;
                    forest[j][i] = 1;
                    for (int k = 0; k < n; k++)
                        if(flower[k] == flower[j])
                            flower[k] = flower[i];
                }
    printf("Flowers: ");
    display_array(flower, n);
    printf("Forest:\n");
    display_matrix(forest, n);
    free(flower);
    return forest;
}

//обнуление массива a размера n
void zeros_array(int *a, int n) {
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

//освобождение памяти
void free_matrix(int** matrix, int n){
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

//вывод массива a размера n
void display_array(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]+1);
    printf("\n");
}