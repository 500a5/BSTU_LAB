#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "malloc.h"

short is_anti_symmetrical(int **a){
    short result = 1;
    int N = 13;
    size_t j = 1, i = 0;
    while(i < N && result){
        while(j < N && result && i != j){
            if(result = (a[i][j] != a[j][i]) || (a[i][j] == 0 && a[j][i] == 0))
                j++;
        }
        if(result){
            i++;
            j = i+1;
        }
    }
    if(i < N || j < N)
        printf("not antisymmetrical, because exists a pair (%d, %d) && (%d, %d)\n", i, j, j, i);
    return result;
}

short is_transitive(int **a){
    short result = 1;
    int N = 13;
    size_t i = 0, j, z = 0;
    while(i < N && result){
        j = 1;
        while(j < N && result){
            z = 1;
            while(z < N && result) {
                if (a[i][z] && a[z][j])
                    result = a[i][j];
                if (result)
                    z++;
            }
            if(result)
                j++;
        }
        if(result)
            i++;
    }
    if(i < N || j < N)
        printf("not transitive, because (%d, %d) && (%d, %d), but not (%d, %d)\n", i, z, z, j, i, j);
    return result;
}

short is_ordering(int **a){
    return(is_anti_symmetrical(a) && is_transitive(a));
}


typedef struct{
    int x;
    int y;
} point;

point* create_set(size_t n){
    point* set_point = (point*)malloc(n * sizeof(point));
    return set_point;
}

int search_min(int** matr, point *set, size_t n){
    int max = 100;
    for (int a = 0; a < n; a++) {
        for (int x = 0; x < n; x++) {
            if((a != x) && matr[a][x] && (set[a].x <= set[x].x ))
                max = a;
        }
    }
    printf("max = [%d, %d]", set[max].x, set[max].y);
}

void free_set(point* point){
    free(point);
}

// инициализация множества точек
void input_set(point* a, int n){
    if (n == 9) {
        size_t i = 0;
        for (int x = -1; x < 2; x++)
            for (int y = -1; y < 2; y++) {
                a[i].x = x;
                a[i++].y = y;
            }
    } else if (n == 13) {
        a[0].x = -2; a[0].y = 0;
        a[1].x = -1; a[1].y = -1;
        a[2].x = -1; a[2].y = 0;
        a[3].x = -1; a[3].y = 1;
        a[4].x = 0;  a[4].y = -2;
        a[5].x = 0;  a[5].y = -1;
        a[6].x = 0;  a[6].y = 0;
        a[7].x = 0;  a[7].y = 1;
        a[8].x = 0;  a[8].y = 2;
        a[9].x = 1;  a[9].y = -1;
        a[10].x = 1; a[10].y = 0;
        a[11].x = 1; a[11].y = 1;
        a[12].x = 2; a[12].y = 0;
    }
}

void output_set(point* point, int n){
    printf("\n");
    for (size_t i = 0; i < n; i++) {
        printf("---POINT #%d---\n", i + 1);
        printf("x%d: %d\n", i + 1, point[i].x);
        printf("y%d: %d\n", i + 1, point[i].y);
    }
}

int** create_matr(size_t n){
    int** a = (int**)calloc(n, sizeof(int*));
    for (size_t i = 0; i < n; i++)
        a[i] = (int*)calloc(n, sizeof(int));
    return a;
}

void free_matr(int** a, size_t n){
    for (size_t i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

// создание матрицы отношения порядка для множества point
int** get_relation(point* point, int n){
    int** a = create_matr(n);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if ((point[i].x < point[j].x) && (point[i].y <= point[j].y))
                a[i][j] = 1;
    return a;
}

void output_relation(int** a, int n){
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void sum_cols(int** a, int* sum, int n){
    for (size_t j = 0; j < n; j++)
        for (size_t i = 0; i < n; i++)
            sum[j] += a[i][j];
}

void print_zero_indexes_and_replace(int** a, int* sum, int n){
    int index = -1;
    int *temp = (int*)malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
        if (!sum[i]) {
            printf("%d ", i + 1);
            sum[i] = -1;
            index++;
            temp[index] = i;
        }
    for (size_t j = 0; j < n; j++)
        if (sum[j])
            for (size_t k = 0; k <= index; k++)
                sum[j] -= a[temp[k]][j];
    printf("\n");
}

int exist_nonnegative_el(int* a, int n){
    for (size_t i = 0; i < n; i++)
        if (a[i] >= 0)
            return 1;
    return 0;
}

// создание матрицы отношения доминирования по матрице отношения порядка а
int** get_domination_relation(int** a, int n){
    int** domination_a = create_matr(n);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++) {
            if (a[i][j]) {
                int is_dom = 1;
                for (size_t k = 0; k < n; k++)
                    if ((j != k) && a[i][k])
                        if (a[k][j]) {
                            is_dom = 0;
                            break;
                        }
                domination_a[i][j] = is_dom;
            }
        }
    return domination_a;
}

// топологическая сортировка по матрице отношения доминирования
void topologic_sort(int** domination_a, int n){
    int* sum = (int*)calloc(n, sizeof(int));
    int step = 0;
    sum_cols(domination_a, sum, n);
    while (exist_nonnegative_el(sum, n)) {
        printf("elements level #%d: ", step);
        print_zero_indexes_and_replace(domination_a, sum, n);
        step++;
    }
    free(sum);
}

int main(){
    int size = 0;
    printf("input number of points: ");
    scanf("%d", &size);
    point* set = create_set(size);
    input_set(set, size);
    output_set(set, size);

    printf("\norder relation on set of points:\n");
    int** relation = get_relation(set, size);
    output_relation(relation, size);

    if(size == 13) {
        printf("is tran = %d\n", is_transitive(relation));
        printf("is not sym = %d\n", is_anti_symmetrical(relation));
        printf("is order = %d\n", is_ordering(relation));
    }

    printf("\ndomination relation, association with order relation:\n");
    int** dom_relation = get_domination_relation(relation, size);
    output_relation(dom_relation, size);

    printf("\ntopologic sort:\n");
    topologic_sort(dom_relation, size);
    search_min(relation, set, size);
    free_matr(dom_relation, size);
    free_matr(relation, size);
    free_set(set);
    return 0;
}
