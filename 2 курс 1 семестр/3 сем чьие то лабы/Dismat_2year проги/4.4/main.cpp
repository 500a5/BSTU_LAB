#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>

int **get_mem_for_matrix(int n){
    int **a = (int**)calloc(n, sizeof(int*));
    for(int i = 0; i < n; i++)
        a[i] = (int*)calloc(n, sizeof(int));
    return a;
}

void free_mem_for_matrix(int **a, int n){
    for(size_t i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

void input_graph(int **graph, int n){
/*
0 1 9 0 0 0
0 0 7 2 0 0
0 0 0 0 1 0
0 0 4 0 8 2
0 0 0 0 0 5
0 0 0 0 4 0
*/
    for(size_t i = 0; i < n; i++)
        for(size_t j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
}

void output_graph(int **graph, int n){
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

void init_visited_and_distance(int *visited, int *distance, int start, int n){
    for(size_t i = 0; i < n; i++){
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[start] = 0;
}

// алгоритм Дейкстры определяет кратчайший путь между вершинами start
// и end оргафа graph и его длину d(end)
int algorithm_dijkstra(int **graph, int *route, int n, int start_vertex, int end_vertex){
    int visited[n], distance[n], index = 0;
    for(size_t i = 0; i < n; i++){
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[start_vertex] = 0;
    while(index != end_vertex){
        int min = INT_MAX;
        for(int j = 0; j < n; j++)
            if(!visited[j] && distance[j] <= min){
                min = distance[j];
                index = j;
            }
        visited[index] = 1;
        for(int j = 0; j < n; j++){
            if(!visited[j] && graph[index][j] && distance[index] != INT_MAX && distance[index] + graph[index][j] < distance[j]){
                distance[j] = distance[index] + graph[index][j];
                route[j] = index;
            }
        }
        if(index == end_vertex)
            break;
    }
    return(distance[end_vertex]);
}

void path_display(int *path, int n){
    int last_checked_vertex = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(path[j] == last_checked_vertex && path[j] != -2){
                last_checked_vertex = j;
                printf("%d ", last_checked_vertex + 1);
            }
}

int main(){
    int n = 6;
    int start, end, vertex_1, vertex_2, shortest_length;

    printf("Starting Vertex = ");
    scanf("%d", &start);
    start--;
    printf("\nEnding Vertex = ");
    scanf("%d", &end);
    end--;
    printf("\nThrough what are the Vertex is the route: ");
    scanf("%d %d", &vertex_1, &vertex_2);
    vertex_1--;
    vertex_2--;
    int **graph = get_mem_for_matrix(n);

    input_graph(graph, n);

    int *route = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        route[i] = -2;
    route[start] = -1;

    shortest_length = algorithm_dijkstra(graph, route, n, start, vertex_1);
    shortest_length += graph[vertex_1][vertex_2];
    shortest_length += algorithm_dijkstra(graph, route, n, vertex_2, end);
    printf("Length of the shortest route = %d\n", shortest_length);
    path_display(route, n);
    free_mem_for_matrix(graph, n);
    return 0;
}
