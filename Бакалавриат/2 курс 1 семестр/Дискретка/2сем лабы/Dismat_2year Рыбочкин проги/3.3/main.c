#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

void fill_array_with_zeros(int *object, int n);             //отчистка
void output(int **matrix);                                  //вывод матрицы
void make_relation(int **relation);                         //Формирование
void make_equation_class(int **relation, int x, int *cl);   //алгоритм 3.13
void split_to_equation_classes(int **R, int *S);            //алгоритм 3.14
int is_empty(const int *a);
void make_partition(const int *a, int count, int *c);
void difference_relations(const int *a, const int *b, int *c);


void fill_array_with_zeros(int *object, int n) {
    for (int i = 0; i < n; i++)
        object[i] = 0;
}

void output(int **matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void make_relation(int **relation) {
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            if ((abs(x - y) % 3 == 0) || (x == y))
                relation[x][y] = 1;
}

void make_equation_class(int **relation, int x, int *cl) {  //алгоритм 3.13
    for (int y = 0; y < N; y++)
        if (relation[y][x])
            cl[y] = 1;
}


void split_to_equation_classes(int **R, int *S) {
    fill_array_with_zeros(S, N);
    int count = 1;
    for (int x = 0; x < N; x++)
        for (int col = 0; col < N; col++)
            if (R[x][col]){
                if (!S[col]) {
                    S[col] = count++;
                    break;
                } else {
                    S[x] = S[col];
                }
            }
}

int is_empty(const int *a) {
    for (int i = 0; i < N; i++)
        if (a[i] == 1)
            return i;
    return -1;
}

void make_partition(const int *a, int count, int *c) { //объединение отношений
    for (size_t i = 0; i <= N; i++)
        if(a[i])
            c[i] = count;
}

void difference_relations(const int *a, const int *b, int *c) { //разность отношений
    for (size_t i = 0; i <= N; i++)
        c[i] = (a[i] > b[i]);
}


int main(){
    int i, M[N], partition[N];
    for (i = 1; i < N; i++)
        M[i] = i;
    int **relation;
    relation = (int **)calloc(N, sizeof(int*));
    for (i = 0; i < N; i++)
        relation[i] = (int *)calloc(N, sizeof(int));

    make_relation(relation);
    printf("\nRelation R\n");
    output(relation);
    printf("\n\n");

    split_to_equation_classes(relation, partition);

    printf("\nPartition F \n");
    for (i = 0; i < N; ++i)
        printf("%d ", partition[i]);

    return 0;
}