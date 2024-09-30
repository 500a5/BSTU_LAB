#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int** algKracksal(int** graf, int n, int centralTop);//алгоритм Краскала
void recAlgKracksal(int **graf, int **tree, int n, int central, int *was);//заполняем дерево от вершины central(рекурсия)
void arrZero(int* a, int n);//обнуление массива a размера n
void arrMax(int* a, int n);//INT_MAX массива a размера n
int findCentralTop(int **graf, int n);//поиск центральной вершины
int* eccentricity(int **graf, int n);//эксцентриситеты вершин графа
int distance(int **graf, int n, int v1, int v2);//поиск кратчайшего пути между вершинами v1 и v2
int recDistance(int **graf, int n, int *was, int v1, int v2, int min, int now);//рекурсия для поиска расстояния между вершинами
int minIndex(int *a, int n);//возврат индекса наименьшего значения
void matrFree(int **a, int n);//освобождение памяти
void arrOut(int *a, int n);//вывод массива a размера n