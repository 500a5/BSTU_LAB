#ifndef SVOYSTVA_H_INCLUDED
#define SVOYSTVA_H_INCLUDED

int reflex(int **a, size_t n);
int anti_reflex(int **a, size_t n);
int symmetr(int **a, size_t n);
int anti_symmetr(int **a, size_t n);
int transit(int **a, size_t n);
int anti_transit(int **a, size_t n);
int full(int **a, size_t n);
int tolerant(int **a, size_t n);
int equival(int **a, size_t n);
int poryadok(int **a, size_t n);

#include "svoystva.c"
#endif // SVOYSTVA_H_INCLUDED
