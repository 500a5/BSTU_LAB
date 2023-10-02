#pragma once

#define Graf_H
#ifdef Graf_H
int * init_sequence(int n);
int ** init_graph(int n);
int is_way(int *sequence, int **graph, int n);// явл€етс€ ли данна€ последовательность pos маршрутом дл€ графа graf
int is_chain(int *sequence, int n, int graph_n);
int is_simple_chain(int *sequence, int m);
int is_simple_cycle(int *pos, int n, int m);
int is_cycle(int *pos, int n);
void routes(int *a, int **graph, int i, int l, int n);
void output_root(int *a, int l);
void output_rout(int *a);
void get_count_for_graph(int **matr_with_counters, int **graph, int n, int *a, int L, int i);
int find_in_chain(int a, int **graph, int *log_v, int n);
void all_max_simple_chain(int **graph, int n, int *a, int i);
#endif

