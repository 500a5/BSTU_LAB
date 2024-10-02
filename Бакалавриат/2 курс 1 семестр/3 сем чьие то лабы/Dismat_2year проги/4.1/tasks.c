#include <stdio.h>
#include <malloc.h>
#include "graphs.c"
#include "graphs.h"


void num3() {
	int n, m;
	int *a; // массив последовательности
	int **graph; // Матрица графа

	printf("\nEnter length of sequence: ");
	scanf("%d", &n);

	a = init_sequence(n);

	printf("\nEnter range of graph's elements: ");
	scanf("%d", &m);
	graph = init_graph(m);

	if (is_way(a, graph, n)) {
		printf("\n This sequence - is a way!");
		if (is_chain(a, n, m)) {
			printf("\n This sequence - is a chain!");
			if (is_simple_chain(a, m))
				printf("\n This sequence - is a simple chain!");
			if (is_simple_cycle(a, n, m))
				printf("\n This sequence - is a simple cycle!");
		}
		else
			printf("\n This sequence not a chain!");

		if (is_cycle(a, n))
			printf("\n This sequence is a cycle!");
	} else
		printf("\n This sequence - is a way! Therefore nothing more\n");
}

void num4() {
	int n, l;
	int **graph;

	printf("\nEnter length of way: ");
	scanf("%d", &l);

	printf("\nEnter range of graph's elements: ");
	scanf("%d", &n);
    int a[l+1];
	graph = init_graph(n);

	printf("\nEnter the node for which we are looking for way: ");
	scanf("%d", &a[0]);

    routes(a, graph, 1, l, n);
}

void num5() {
	int i, j;
	int n, l;
	int **graph;
	printf("\nEnter length of way: ");
	scanf("%d", &l);
	printf("\nEnter range of graph's elements: ");
	scanf("%d", &n);
	graph = init_graph(n);

	int **r = get_count_all_ways_in_graph(graph, n, l);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("Between node %d and %d - %d ways.\n", i+1, j+1, r[i][j]);
		}
	}
}

void num6() {
	int l, n;
	int **graph;
	printf("\nEnter length of way: ");
	scanf("%d", &l);
	int a[l+1];

	printf("\nEnter range of graph's elements: ");
	scanf("%d", &n);
	graph = init_graph(n);

	printf("\nEnter 2 nodes, between which you need to find a way: ");
	scanf("%d %d", &a[0], &a[l]);

	get_rout_between_nodes(graph, n, a, a[l], l, 1);
}

void num7() {
	int n;// Мощность квадратной матрицы смежности графа
    int **graf; // Матрица графа
    printf("\nEnter range of graph's elements: ");
    scanf("%d", &n);
    graf = init_graph(n);
    int a[n+1];

	printf("\nEnter node, which you need to find all simple chair: ");
	scanf("%d", &a[0]);
	all_max_simple_chain(graf, n-1, a, 1);

}
