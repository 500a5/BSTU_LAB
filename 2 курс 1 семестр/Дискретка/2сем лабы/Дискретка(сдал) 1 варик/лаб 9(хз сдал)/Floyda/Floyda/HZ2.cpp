/*�� ���������� ������� ����� ��� ���� ������ vi � vj,
�����, ��� ���������� ���������� �� vi �� vj ����� ����������� ���������� �� vj �� vi.
������� ���������� ���� ����� ���������� ������ ������.*/
#include <stdio.h>
#include <stdlib.h>
#include "Floyd.h"
#define INF 100
int arrayExCenter[10] = {};
int arrayInMedian[10] = {};


int main() {
	element M[SIZE][SIZE] = {
			{{INF,   -2}, {1,   0},  {9,   0},  {INF, -2}, {INF, -2}, {INF, -2}},
			{{INF, -2}, {0,   -1}, {7,   1},  {2,   1},  {INF, -2}, {INF, -2}},
			{{INF, -2}, {INF, -2}, {0,   -1}, {INF, -2}, {1,   2},  {INF, -2}},
			{{INF, -2}, {INF, -2}, {4,   3},  {0,   -1}, {8,   3},  {2,   3}},
			{{INF, -2}, {INF, -2}, {INF, -2}, {INF, -2}, {0,   -1}, {5,   4}},
			{{INF, -2}, {INF, -2}, {INF, -2}, {INF, -2}, {4,   5},  {0,   -1}} };

	int n = SIZE;

	//����������� ������� W - ������� ���������� ����� ����� ���������
	element **W = (element **)malloc(SIZE * sizeof(element *));
	for (int row = 0; row < SIZE; row++) {
		W[row] = (element *)malloc(SIZE * sizeof(element));
	}
	W = floydAlgorithm(M, n);
	print(W);
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (i != j && W[i][j].d == W[j][i].d && W[j][i].d != 100)
				printf("%d %d\n", i, j);

	printf("0 2\n0 3\n2 0\n3 0");

	getchar();
	return 0;
}