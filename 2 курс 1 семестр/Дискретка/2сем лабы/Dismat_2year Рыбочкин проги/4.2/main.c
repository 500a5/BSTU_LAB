#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void display_array(int *rez, int n);
void graph_random_fill(int **graph, int n, int m);
void zeros_graph(int **graph, int n);
void done_graph(int **graph, int n);
void display_graph(int **graph, int n);
int is_graph_connect(int **graph, int n);
int is_hamiltons_graph(int **graph, int n);
int find_hamiltons_graph(int **graph, int *a, int *log_v, int i, int n);
int is_adjacent_nodes(int **graph, int a, int b, int n);
int is_euler_graph(int **graph, int n, int m);

//обнуление массива a, размера n
void arrZero(int *a, int n) {
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

//генерация графа n вершин и m ребер
void graph_random_fill(int **graph, int n, int m) {
    srand((unsigned)time(NULL));
    int node_1, node_2;
    zeros_graph(graph, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("+");
}

//удаление всех ребер
void zeros_graph(int **graph, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
}

//вывод графа
void display_graph(int **graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    printf("\n");
}

//освобождение графа
void done_graph(int **graph, int n) {
    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
}

// Обход в глубину
void dfs(int** graph, int* visited, int v, int n){
    if(visited[v])
        return;
    visited[v] = 1;
    for(int i = 0; i < n; i++)
        if(graph[v][i])
            dfs(graph, visited, i, n);
}

// Является ли граф связным
int is_graph_connect(int ** graph, int n) {
    int *visited = (int*)malloc(sizeof(int)*n);
    arrZero(visited, n);
    dfs(graph, visited, 0, n);
    for(int i = 0; i < n; i++)
        if(!visited[i])
            return 0;
    return 1;
}

//Является ли граф Гамильтоновым
int is_hamiltons_graph(int **graph, int n) {
    int flag = 0;
    int *a, *log_v;
    a = (int*)malloc(sizeof(int) * (n + 1));
    arrZero(a, n+1);
    for (int i = 0; i < n+1; i++)
        a[i] = -1;
    log_v = (int*)malloc(sizeof(int) * n);
    arrZero(log_v, n);
    a[0] = 1;
    log_v[0] = 0;
    if (find_hamiltons_graph(graph, a, log_v, 1, n))
        flag = 1;
    free(a);
    free(log_v);
    return flag;
}

//поиск гамильтонова цикла
int find_hamiltons_graph(int **graph, int *a, int *path, int i, int n) {
    int v, flag = 0;
    for(v = 0; v < n && !flag; v++){
        if(graph[v][path[i - 1]]||graph[path[i - 1]][v]){
            if (i == n &&  v == a[0] ) {
                flag = 1;
                display_array(path, n); printf("%d\n", v);
                display_array(a, n+1);
            } else if (a[v] == -1){
                a[v] = 1 ; path[i] = v;
                flag = find_hamiltons_graph(graph, a, path, i+1, n) ;
            } else
                continue;
        }
    }
    return flag;
}

// Является ли данный граф Эйлеровым
int is_euler_graph(int **graph, int n, int m) {
    int count = 0;
    int flag = 1;
    int i = 0, j = 0;
    while ((i < n) && flag) {
        while ((j < m) && flag) {
            if (graph[i][j] == 1)
                count++;
            j++;
        }
        if (((count + 1) % 2) == 0)
            flag = 0;
        i++;
        j = 0;
    }
    return flag;
}

void display_array(int *rez, int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", rez[i]);
    printf("\n");
}

int* generator_10(int n, int m) {
    int *rez = (int*)malloc(sizeof(int) * 5);
    clock_t time = clock();
    rez[0] = n;
    rez[1] = m;
    rez[2] = 0;
    rez[3] = 0;
    rez[4] = 0;
    int** graph = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
        graph[i] = (int *)malloc(sizeof(int)*n);
    while ((clock() - time) / CLOCKS_PER_SEC < 2) {
        graph_random_fill(graph, n, m);
        if (is_graph_connect(graph, n)) {
            if (is_hamiltons_graph(graph, n))
                rez[2] += 1;
            if (is_euler_graph(graph, n, m))
                rez[3] += 1;
            rez[4] += 1;
        }
    }
    done_graph(graph, n);
    return rez;
}


int main() {
    for (int n = 4; n <= 5; n++) {
        for (int m = 4; m <= 4; ++m) {
            printf("Nodes: %d || edges: %d   ", n, m);
            display_array(generator_10(n, m), 5);
        }
        getchar();
    }
    return 0;
}