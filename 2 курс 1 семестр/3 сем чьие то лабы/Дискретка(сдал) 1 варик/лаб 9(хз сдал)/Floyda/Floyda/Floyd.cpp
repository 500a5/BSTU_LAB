#include <stdio.h>
#include <stdlib.h>
#include "Floyd.h"


void print(element **M) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("{d = %d, t = %d}  ", M[i][j].d, M[i][j].t);
		}
		printf("\n");
	}
}

//копирование
element** eqTo(element(*M)[SIZE]) {
	element **W = (element **)malloc(SIZE * sizeof(element *));
	for (int row = 0; row < SIZE; row++) 
		W[row] = (element *)malloc(SIZE * sizeof(element));
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			W[i][j].d = M[i][j].d;
			W[i][j].t = M[i][j].t;
		}
	return W;
}

//M - модифицированная матрица весов
//n - число вершин в графе
element** floydAlgorithm(element(*M)[SIZE], int n) {
	element **W = (element **)malloc(SIZE * sizeof(element *));	//Формируемая матрица W - матрица кратчайших путей между вершинами
	for (int row = 0; row < SIZE; row++)
		W[row] = (element *)malloc(SIZE * sizeof(element));
	W = eqTo(M);//Присвоим матрице W присвоим M
	for (int z = 0; z < SIZE; z++)
		for (int x = 0; x < SIZE; x++)
			for (int y = 0; y < SIZE; y++) 
				if ((W[x][z].d + W[z][y].d < W[x][y].d)) {
					W[x][y].d = W[x][z].d + W[z][y].d;
					W[x][y].t = W[z][y].t;
				}
	return W;
}

