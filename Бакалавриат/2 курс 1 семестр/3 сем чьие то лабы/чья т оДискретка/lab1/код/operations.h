#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

int Equal(int **a, int **b, size_t n);
int Includ(int **a, int **b, size_t n);
void Union(int **a, int **b, int **c, size_t n);
void Cross(int **a, int **b, int **c, size_t n);
void Dif(int **a, int **b, int **c, size_t n);
void Sym_dif(int **a, int **b, int **c, size_t n);
void Addit(int **a, int **b, size_t n);
void Obrash(int **a, int **c, size_t n);
void Compos(int **a, int **b, int **c, size_t n);

#include "Operations.c"
#endif
