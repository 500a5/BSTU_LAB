#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "malloc.h"
#include "windows.h"

//������� ���������
typedef struct {
	int x;
	int y;
} Point;

//�������� - �������� �� ����
int compare(Point a, Point b) {
	return (a.x <= b.x) && (a.y <= b.y);
}

//�������� ��������� ����� ��������� �������
Point* create_set(int n) {
	Point* setpoint = (Point *)malloc(n * sizeof(Point));
	return setpoint;
}

//�������� ������ ���������
void delete_point(Point *point) {
	free(point);
}

//���� ��������� �����

void input_point(Point *a1, int key) {
	if (key == 9) {
		int x, y, i = 0;
		for (x = -1; x < 2; x++)
			for (y = -1; y < 2; y++) {
				a1[i].x = x;
				a1[i].y = y;
				i++;
			}
	}
	else if (key == 13) {
		a1[0].x = -2; a1[0].y = 0;
		a1[1].x = -1; a1[1].y = -1;
		a1[2].x = -1; a1[2].y = 0;
		a1[3].x = -1; a1[3].y = 1;
		a1[4].x = 0; a1[4].y = -2;
		a1[5].x = 0; a1[5].y = -1;
		a1[6].x = 0; a1[6].y = 0;
		a1[7].x = 0; a1[7].y = 1;
		a1[8].x = 0; a1[8].y = 2;
		a1[9].x = 1; a1[9].y = -1;
		a1[10].x = 1; a1[10].y = 0;
		a1[11].x = 1; a1[11].y = 1;
		a1[12].x = 2; a1[12].y = 0;
	}
}

//����� ��������� �����
void output_point(Point *point, int n) {
	printf("\n - - - O U T P U T T I N G P O I N T S - - -\n");
	for (int i = 0; i < n; i++) {
		int count = i + 1;
		printf("\n- - - Point #%d - - -\n", count);
		printf("x%d: %d\n", count, point[i].x);
		printf("y%d: %d\n", count, point[i].y);
	}
}

//��������� ������ �������(���������)
int **create_mattr(int n) {
	int **ptrmattr = (int **)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		ptrmattr[i] = (int *)calloc(n, sizeof(int));
	return ptrmattr;
}

//��������� ��������� �� ��������� �����
int** create_rel(Point *point, int n, int(*cmp) (Point, Point)) {
	int** relmattr = create_mattr(n);
	//������������ ���������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i != j) && cmp(point[i], point[j])) {
				relmattr[i][j] = 1;
			}
		}
	}
	return relmattr;
}

// �������� ������ �������
void delete_mattr(int **mattr, int n) {
	for (int i = 0; i < n; i++) {
		free(mattr[i]);
	}
	free(mattr);
}

// ����� �������
void output_mattr(int **mattr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			printf("%d ", mattr[i][j]);
		printf("\n");
	}
}

int **dom_set_redux(int **relmattr, int n) {
	int **domrel = create_mattr(n);
	//������ ���������� �������������,
	//���������������� � ���������� �������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (relmattr[i][j]) {
				int isdom = 1;
				for (int k = 0; k < n; k++)
					if ((j != k) && relmattr[i][k]) 
						if (relmattr[k][j]) {
							isdom = 0;
							break;
						}
				domrel[i][j] = isdom;
			}
	}
	return domrel;
}

//�������������� ������ W ��� �������������� ����������
void sum_cols(int **mattr, int *arr, int n) {
	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++)
			//������� ������ �� ������� � ���������� � ������
			arr[j] += mattr[i][j];
}

//����� ������� ��������� ��������� �
void print_zero_indexes_and_replace(int **mattr, int *arr, int n) {
	int *tmparr = (int *)malloc(n * sizeof(int));
	int index = 0;
	int i = 0;
	//����� ������� ���������
	for (i = 0; i < n; i++)
		if (!arr[i]) {
			printf("%d ", i + 1);
			arr[i] = -1;
			tmparr[index] = i;
			index++;
		}
	//�������� �������
	//��������� �� ������� W ����� 0 ���������
	tmparr[index] = -1;
	for (int j = 0; j < n; j++)
		if (arr[j])
			for (int k = 0; k < index; k++)
				arr[j] -= mattr[tmparr[k]][j];
	printf("\n");
}

// �������� ������� - �������� �� ���� ������ �������������� �������
int exist_positivezero(int *arr, int n) {
	for (int i = 0; i < n; i++)
		if (arr[i] >= 0)
			return 1;
	return 0;
}

void topologic_sort(int **dommattr, int n) {
	int *tmparr = (int *)calloc(n, sizeof(int));
	int step = 0;
	//�������������� ������ W ��� �������������� ����������
	sum_cols(dommattr, tmparr, n);
	while (exist_positivezero(tmparr, n)) {
		printf("�������� %d ������: ", step);
		print_zero_indexes_and_replace(dommattr, tmparr, n);
		step++;
	}
	free(tmparr);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setbuf(stdout, 0);
	int n = 0;
	printf("������� ���������� �����: ");
	scanf("%d", &n);
	Point *set = create_set(n);
	input_point(set, n);
	output_point(set, n);
	printf("\n��������� �� ��������� �����\n");
	int **relmattr = create_rel(set, n, compare);
	output_mattr(relmattr, n);
	printf("\n���������� �������������, ���������������� � ���������� �������\n");
	int **domrel = dom_set_redux(relmattr, n);
	output_mattr(domrel, n);
	printf("\n�������������� �����������\n");
	topologic_sort(domrel, n);
	delete_mattr(domrel, n);
	delete_mattr(relmattr, n);
	delete_point(set);
	getchar();
	getchar();
	getchar();
	return 0;
}