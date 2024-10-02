#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//Считывает взвешанный орграф из файла input.txt
int** ReadGraph(int *N);

//Вывод взвешенного графа
void WriteGraph(int** G, int N);

//Алгоритм Дейкстра
void Dijkstra(int** G, int N, int start);

//Вывод кратчайшего пути от вершины start до вершины vertex
void WritePath(int* T, int Start, int Vertex);

//Очистка памяти для матрицы G
void FreeMem(int** G, int N);

#endif // DIJKSTRA_H_INCLUDED
