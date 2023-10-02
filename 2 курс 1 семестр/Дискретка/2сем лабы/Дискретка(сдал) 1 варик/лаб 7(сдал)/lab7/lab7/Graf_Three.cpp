#include "Graf_Three.h"


//�������� ��������
int** algKracksal(int** graf, int n, int centralTop) {
	int **tree = (int**)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		tree[i] = (int*)malloc(sizeof(int)*n);
		arrZero(tree[i], n);
	}
	
	//int centralTop = findCentralTop(graf, n);//����������� �������

	int *was = (int*)malloc(sizeof(int)*n);
	arrZero(was, n);
	recAlgKracksal(graf, tree, n, centralTop - 1, was);//�� ����������� ������� ��������� �������
	

	return tree;
}

//��������� ������ �� ������� central
void recAlgKracksal(int **graf, int **tree,  int n, int central, int *was) {
	int *pass = (int*)malloc(sizeof(int) * n);
	arrZero(pass, n);
	was[central] = 1;
	for (int i = 0; i < n; i++) 
		if (graf[central][i] && !was[i]) {
			tree[central][i] = 1;
			tree[i][central] = 1;
			was[i] = 1;
			pass[i] = 1;
		}

	for (int i = 0; i < n; i++)
		if (pass[i]) {
			pass[i] = 0;
			recAlgKracksal(graf, tree, n, i, was);
		}
	free(pass);
}

//��������� ������� a ������� n
void arrZero(int* a, int n) {
	for (int i = 0; i < n; i++) 
		a[i] = 0;
}

//INT_MAX ������� a ������� n
void arrMax(int* a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = INT_MAX;
}

//����� ����������� �������
int findCentralTop(int **graf, int n) {
	int *arrEccentricity;
	int min;

	arrEccentricity = eccentricity(graf, n);//��������������� ������ �����

	min = minIndex(arrEccentricity, n);
	free(arrEccentricity);
	return min + 1;
}

//��������������� ������ �����
int* eccentricity(int **graf, int n) {
	int max;
	int *arrEccentricity = (int*)malloc(sizeof(int)*n);
	arrZero(arrEccentricity, n);


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			max = distance(graf, n, i, j);
			if ((i != j) && (arrEccentricity[i] < max))//������, �� ������
				arrEccentricity[i] = max;
		}
	return arrEccentricity;
}

//����� ����������� ���� ����� ��������� v1 � v2
int distance(int **graf, int n, int v1, int v2) {
	int min = INT_MAX;
	int *was = (int*)malloc(sizeof(int) * n);
	arrZero(was, n);

	min = recDistance(graf, n, was, v1, v2, min, 0);

	free(was);
	return min;
}

//�������� ��� ������ ���������� ����� ���������
int recDistance(int **graf, int n, int *was, int v1, int v2, int min, int now) {
	if (v1 == v2) {
		return now;
	}
	else 
		for (int i = 0; i < n && now < min; i++)
			if (graf[v1][i] && !was[i]) {
				was[v1] = 1;
				min = recDistance(graf, n, was, i, v2, min, now+1);
				was[v1] = 0;
			}
	return min;
}

//������� ������� ����������� ��������
int minIndex(int *a, int n) {
	int min = INT_MAX;
	int rez;
	for (int i = 0; i < n; i++)
		if (min > a[i]) {
			min = a[i];
			rez = i;
		}
	return rez;
}

//������������ ������
void matrFree(int **a, int n) {
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

//����� ������� a ������� n
void arrOut(int *a, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}