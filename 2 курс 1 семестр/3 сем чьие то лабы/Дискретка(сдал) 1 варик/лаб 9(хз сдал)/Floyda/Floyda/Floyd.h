#pragma once

#define INF 100
#define SIZE 6

typedef struct el {
	//����� ���� ij
	int d;
	//����:'i'-����, '-1'-(i=j), '-2'-���
	int t;
}element;


void print(element **M);
element** eqTo(element(*M)[SIZE]);
element** floydAlgorithm(element(*M)[SIZE], int n);