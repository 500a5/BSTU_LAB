#pragma once

#define Graf_H
#ifdef Graf_H
int * init_posl(int n);
int ** init_graf(int n);
int is_marshrut(int *pos, int **graf, int n);// явл€етс€ ли данна€ последовательность pos маршрутом дл€ графа graf
int is_cep(int *pos, int n);
int is_easy_cep(int *pos, int n, int m);
int is_easy_cikl(int *pos, int n, int m);
int is_cikl(int *pos, int n);
void marshruti(int *a, int **graf, int i, int l, int n);
void output_marsh(int *a, int l);
void output_marsh1(int *a);
int find_in_cep(int a, int **graf, int *log_v, int n);
void all_max_easy_cepi(int *a, int **graf, int *log_v, int i, int n);
#endif // Graf_H

