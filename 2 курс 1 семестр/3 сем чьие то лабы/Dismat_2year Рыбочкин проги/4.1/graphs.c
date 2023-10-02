#include <stdio.h>
#include <malloc.h>
#include "graphs.h"

// Является ли данная последовательность sequence маршрутом для графа graf
int is_way(int *sequence, int **graph, int n) {
	int flag = 1, i = 0;
	while (flag && (i < (n - 1))) {
		if ((graph[sequence[i] - 1][sequence[i + 1] - 1]) == 0)
			flag = 0;
		i++;
	}
	return flag;
}

// Является ли данная последовательность sequence цепью для графа graph
int is_chain(int *sequence, int n, int graph_n) {
    int tmp[graph_n][graph_n];
    for (size_t i = 0; i < graph_n; i++)
        for (size_t j = 0; j < graph_n; j++)
            tmp[i][j] = 0;
    for (size_t i = 0; i < n - 1; ++i)
            if(tmp[sequence[i] - 1][sequence[i+1] - 1] == 1)
                return 0;
            else
                tmp[sequence[i] - 1][sequence[i+1] - 1] = 1;
    return 1;
}
// Является ли данная последовательность sequence простой цепью для графа graph
int is_simple_chain(int *sequence, int m) {
    for (size_t i = 0; i < m - 1; ++i)
        for (size_t j = i + 1; j < m; ++j)
            if(sequence[i] == sequence[j])
                return 0;
    return 1;
}
// Является ли данная последовательность pos циклом для графа graph
int is_cycle(int *pos, int n) {
    return pos[0] == pos[n - 1];
}

int is_simple_cycle(int *pos, int n, int m) {
    int tmp = pos[m - 1];
    pos[m - 1] = 0;
    int flag = is_simple_chain(pos, m);
    pos[m - 1] = tmp;

    return flag && (pos[0] == pos[m - 1]);
}

//Инициализация графа а ввиде матрицы смежности n*n
int ** init_graph(int n) {
	int i, j;
	int **a;
	// Выделение памяти под указатели на строки
	a = (int**)malloc(n * sizeof(int*));
	printf("\nEnter graph in matrix %d: \n", n);
	// Ввод элементов графа
	for (i = 0; i < n; i++) {
		// Выделение памяти под хранение строк
		a[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	return a;
}
int * init_sequence(int n) {
	int i;
	int *a;
	// Выделение памяти
	a = (int*)malloc(n * sizeof(int));
	printf("\nEnter sequence with length = %d: ", n);
	// Ввод элементов последовательности
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	return a;
}

void output_root(int *a, int l) {
	int i;
	for (i = 0; i < (l + 1); i++)
		printf("%d ", (a[i]));
	printf("\n");
}

void routes(int *a, int **graph, int i, int l, int n) {
    for (int j = 0; j < n; ++j)
        if(graph[a[i - 1] - 1][j]){
            a[i] = j + 1;
            if(i >= l)
                output_root(a, i);
            else
                routes(a, graph, i + 1, l, n);
        }
}


//Записывает в r в элемент i j сколько маршрутов длинны L
//есть между вершинами i j в графе graph
//Состоящего из n вершин
int** get_count_all_ways_in_graph(int **graph, int n, int L){
    int a[L+1];
    int **r;
    r = (int**)malloc((n + 1) * sizeof(int*));
    // Ввод элементов графа
    for (int i = 0; i < n; i++) {
        // Выделение памяти под хранение строк
        r[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j < n; j++) {
            r[i][j] = 0;
        }
    }
    for (size_t i = 1; i <= n; ++i) {
        a[0] = i;
        get_count_for_graph(r, graph, n, a, L, 1);
    }
    return r;
}

//Записывает в matr_with_counters в элемент a[0] - 1  l - 1 сколько маршрутов длинны L
//есть между вершинами a[0] и W в графе matrAdjac
//Состоящего из N вершин
void get_count_for_graph(int **matr_with_counters, int **graph, int n, int *a, int L, int i){
    for (int j = 0; j < n; ++j)
        if(graph[a[i - 1] - 1][j]){
            a[i] = j + 1;
            if(i >= L)
                ++matr_with_counters[a[0] - 1][a[i] - 1];
            else
                get_count_for_graph(matr_with_counters, graph, n, a, L, i + 1);
    }
}

//Выводит Все маршруты длинны L
//между вершинами arrNod[0] и W
//графа graph состоящего из N вершин
void get_rout_between_nodes(int **graph, int n, int *a, int W, int L, int i){
    for (int j = 0; j < n; ++j)
        if(graph[a[i - 1] - 1][j]){
            a[i] = j + 1;
            if(i >= L) {
                if(a[i] == W)
                    output_root(a, i);
            } else
                get_rout_between_nodes(graph, n, a, W, L, i + 1);
        }
}

//Возвращает 1 если W нет в последовательности вершин a размера n
int check_not_in_sequence(int *a, int W, int n){
    for (size_t i = 0; i < n; ++i)
        if(a[i] == W)
            return 0;
    return 1;
}

//Выводит Все максимальные простые цепи выходящие из a[0]
//графа graph состоящего из N вершин
void all_max_simple_chain(int **graph, int n, int *a, int i) {
    int flag = 1;
    for (int j = 0; j < n; ++j)
        if (graph[a[i - 1] - 1][j] && check_not_in_sequence(a, j + 1, i)){
            flag = 0;
            a[i] = j + 1;
            all_max_simple_chain(graph, n, a, i + 1);
        }
    if(flag)
        output_root(a, i - 1);
}