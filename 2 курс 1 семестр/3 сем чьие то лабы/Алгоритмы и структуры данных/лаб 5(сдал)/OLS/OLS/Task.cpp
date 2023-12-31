#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "OLS.h"
#include <math.h>
#include <locale.h>

#define EPS 0.0001

short ListError;

void inputPolynom(List *L, int n);
double sumPolynom(List *L, int x);
int equal(List *p, List *q, int x);



int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 3;
	List* L;
	InitList(&L);
	inputPolynom(L, n);
	printf("\n\n---------%lf", sumPolynom(L, 10));
	DoneList(L);
	return 0;
}

void inputPolynom(List *L ,int n) {
	double a;
	for (int i = 0; i < n; i++) {
		printf("Введите %d коэффициент: ", i+1);
		scanf("%lf", &a);
		if (a != 0) 
			PutList(L, a);
	}
	return;
}

double sumPolynom(List *L, int x) {
	double sum = 0;
	double *path;
	double data = x;
	BeginPtr(L);
	for (unsigned int i = 1; i <= L->N; i++) {
		ReadList(L, &data);
		MovePtr(L);
		sum = x*sum + data;
	}
	return sum;
}

int equal(List *p, List *q, int x) {
	double sum1, sum2;
	sum1 = sumPolynom(p, x);
	sum2 = sumPolynom(q, x);
	if ((sum1 - sum2) < EPS)
		return 1;
	else
		return 0;
}
