#include <stdio.h>
#include <malloc.h>

#define MAX_RANGE 1000000

typedef struct modificate_matrix_cell{
    int d;
    int t;
} matrix_el;

typedef matrix_el** modified_matrix;

int **init_matrix(int n){
    int ** matrix = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)calloc(n, sizeof(int));
    return matrix;
}

void input_matrix(int **matrix, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
}

void output_matrix(int** matrix, int n){
    printf("==================\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int get_outwardly_graph_subordinate_number(modified_matrix W, int n, int vertex){
    int F0 = 0;
    for (int j = 0; j < n; j++)
        if(W[vertex][j].d != MAX_RANGE)
            F0 += W[vertex][j].d;
    return F0;
}

int get_internal_graph_subordinate_number(modified_matrix W, int n, int vertex){
    int Ft = 0;
    for (int j = 0; j < n; j++)
        if(W[j][vertex].d != MAX_RANGE)
            Ft += W[j][vertex].d;
    return Ft;
}

int* get_outwardly_graph_medians(modified_matrix W, int n){
    int *F0 = (int*)calloc(n, sizeof(int));
    for (int vertex = 0; vertex < n; vertex++)
        F0[vertex] = get_outwardly_graph_subordinate_number(W, n, vertex);
    return F0;
}

int* get_internal_graph_medians(modified_matrix W, int n){
    int *Ft = (int*)calloc(n, sizeof(int));
    for (int vertex = 0; vertex < n; vertex++)
        Ft[vertex] = get_internal_graph_subordinate_number(W, n, vertex);
    return Ft;
}

void get_outwardly_iternal_graph_median(modified_matrix W, int n){
    int *F0t = (int*)calloc(n, sizeof(int));
    int min = MAX_RANGE;

    for (int i = 0; i < n; i++) {
        int F0 = get_outwardly_graph_subordinate_number(W, n, i);
        int Ft = get_internal_graph_subordinate_number(W, n, i);

        F0t[i] = F0 + Ft;
        if(F0t[i] < min)
            min = F0t[i];
    }
    printf("outwardly_iternal_graph_median:\n");
    for (int i = 0; i < n; i++)
        if(F0t[i] == min)
            printf("Node(#%d) ", i+1);
    printf("\n MIN(Fot) = %d", min);
    printf("\n\n");
}

matrix_el **make_modificate_weights_matrix(int** graph, int n){
    matrix_el **M = (matrix_el**)calloc(n, sizeof(matrix_el*));
    for (int i = 0; i < n; i++){
        M[i] = (matrix_el*)calloc(n, sizeof(matrix_el));
        for (int j = 0; j < n; j++)
            if(graph[i][j])
                M[i][j].d = graph[i][j];
            else
                M[i][j].d = MAX_RANGE;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if(i == j)
                M[i][j].t = 0;
            else if (graph[i][j] != 0)
                M[i][j].t = i+1;
            else if(graph[i][j] == 0)
                M[i][j].t = -1;
        }
    return M;
}

modified_matrix floyds_algorithm(int **graph, int n){
    modified_matrix W = make_modificate_weights_matrix(graph, n);
    for (int z = 0; z < n; z++)
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                if((W[x][y].t != 0)&&(W[x][z].d + W[z][y].d < W[x][y].d)) {
                    W[x][y].d = W[x][z].d + W[z][y].d;
                    W[x][y].t = W[z][y].t;
                }

    printf("\n==================\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if(W[i][j].d != MAX_RANGE)
                printf("%d ", W[i][j].d);
            else
                printf("%d ", 0);
        printf("\n");
    }
    return W;
}


/*
0 0 2 0 0 0
2 0 0 0 0 2
0 0 0 2 2 0
0 2 0 0 0 0
2 0 2 0 0 1
0 2 0 2 1 0

0 1 0 0 0 0
0 0 2 0 0 3
0 0 0 0 4 0
0 0 6 0 0 0
0 0 0 4 0 5
2 0 0 0 0 0
 */

void output_path(modified_matrix W, int i, int j){
    int k;
    k = W[i][j].t;
    if(k == 0)
        return;
    output_path(W, i, k-1);
    printf("%d ", k);
}

int main() {
    int n = 6;
    int **graph = init_matrix(n);
    input_matrix(graph, n);
    output_matrix(graph, n);
    modified_matrix W = floyds_algorithm(graph, n);
    get_outwardly_iternal_graph_median(W, n);
    int* F0 = get_outwardly_graph_medians(W, n);
    int* Ft = get_internal_graph_medians(W, n);
    int min_F0 = MAX_RANGE;
    int min_Ft = MAX_RANGE;
    for (int vertex = 0; vertex < n; vertex++) {
        if(F0[vertex] < min_F0)
            min_F0 = F0[vertex];
        if(Ft[vertex] < min_Ft)
            min_Ft = Ft[vertex];
    }
    for (int vertex = 0; vertex < n; vertex++)
        if(F0[vertex] == min_F0 && Ft[vertex] == min_Ft)
            printf("Internal and external median - it's Vertex #%d\n", vertex+1);

    output_path(W, 0, 5);
    printf("%d ", 6);
    return 0;
}