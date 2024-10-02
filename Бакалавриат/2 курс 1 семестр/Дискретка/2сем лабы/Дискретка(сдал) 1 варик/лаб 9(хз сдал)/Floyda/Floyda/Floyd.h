#pragma once

#define INF 100
#define SIZE 6

typedef struct el {
	//Длина дуги ij
	int d;
	//Дуга:'i'-есть, '-1'-(i=j), '-2'-нет
	int t;
}element;


void print(element **M);
element** eqTo(element(*M)[SIZE]);
element** floydAlgorithm(element(*M)[SIZE], int n);