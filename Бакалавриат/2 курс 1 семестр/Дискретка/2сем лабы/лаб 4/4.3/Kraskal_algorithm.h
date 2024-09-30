#ifndef INC_4_3_KRASKAL_ALGORITHM_H
#define INC_4_3_KRASKAL_ALGORITHM_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int **init_matrix(int n);

void display_matrix(int **a, int n);
int** kraskal_algorithm(int **graph, int n);//алгоритм Краскала
void display_array(int *a, int n);
void zeros_array(int *a, int n);

void free_matrix(int** matrix, int n);

#endif //INC_4_3_KRASKAL_ALGORITHM_H
