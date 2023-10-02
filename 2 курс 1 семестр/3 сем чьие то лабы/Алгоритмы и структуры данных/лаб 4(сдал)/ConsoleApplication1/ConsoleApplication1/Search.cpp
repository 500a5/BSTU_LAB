#include "Search.h"

#include "windows.h"
#include <math.h>
#include <stdio.h>


int countComparison;

//�������� �����
int lineSearch(int *a, int n, int key) {
	countComparison = 0;
	int i = 0;
	while ((countComparison += 2) && (i < n) && (a[i] != key))
		i++;
	return (i != n) ? i : -1;
}

//������� �������� �����
int fastLineSearch(int *a, int n, int key) {
	countComparison = 0;
	int i = 0;
	a[n] = key;
	while ((countComparison += 1) && (a[i] != key))
		i++;
	return (i != n) ? i : -1;
}

//�������� �����
int binSearch(int *a, int n, int key) {
	countComparison = 0;
	int left = 0;
	int right = n;
	int search = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		countComparison++;
		if (key == a[mid]) {
			search = mid;
			break;
		}
		if (key < a[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return search;
}

//������� �����
int blockSearch(int *a, int n, int key) {
	int step = sqrt(n);
	int stblock = 0;
	countComparison = 0;
	
	while (stblock < n + step) {
		countComparison += 1;
		if (a[stblock] > key) {
			for (int i = step; i > 0; i--) {
				countComparison += 1;
				if ((stblock - i) < n && a[stblock - i] == key)
					return stblock - i;
			}
			return -1;
		}
		stblock += step;
	}
	return -1;
}

//���������� ��������� ���������� ����� ������� ������
int getBadStep(int *a, int n, int(*find)(int *, int, int)) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		find(a, n, a[i]);
		if (max < countComparison)
			max = countComparison;
	}
	return max;
}

//���������� ������� ���������� ����� ������� ������
int getAverageStep(int *a, int n, int(*find)(int *, int, int)) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		find(a, n, a[i]);
		sum += countComparison;
	}
	return sum / n;
}

// ���������� ������� 
void initArr(int *arr, int n, short t) {
	srand(50);
	for (int i = 0; i < n; i++) {
		switch (t) {
		case ORDERLY: arr[i] = i; break;
		case DISORDERED:
			arr[i] = rand() % 100 + 1;
			break;
		}
	}
}



// ������� - ����������� - ������������� ����������
void experiment(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// �������� �������
	int a[MAX_SIZE_ARR];

	//���� �������� �� ��� ������� (�������������/ ���������������)
	for (short t = 0; t < 2; t++) {
		switch (t) {
		case ORDERLY:
			printf("--------------������������� ������--------------\n");
			break;
		case DISORDERED:
			printf("--------------�������������� ������-------------\n");
			break;
		}
		//���� �������� �� ��������� ������� �������
		for (int size = 50; size <= 450; size += 50) {
			printf("--------------������ ������� - %d---------------\n", size);
			switch (t) {
			case DISORDERED:
				initArr(a, size, DISORDERED);

				printf("�������� �����\n");
				printf("   ��������� �����: %d\n", getBadStep(a, size, &lineSearch));
				printf("   ������� ����� �����: %d\n", getAverageStep(a, size, &lineSearch));

				printf("������� �������� �����\n");
				printf("   ��������� �����: %d\n", getBadStep(a, size, &fastLineSearch));
				printf("   ������� ����� �����: %d\n", getAverageStep(a, size, &fastLineSearch));

				break;
			case ORDERLY:
				initArr(a, size, ORDERLY);

				printf("������� �������� �����\n");
				printf("   ��������� �����: %d\n", getBadStep(a, size, &fastLineSearch));
				printf("   ������� ����� �����: %d\n", getAverageStep(a, size, &fastLineSearch));

				printf("�������� �����\n");
				printf("   ��������� �����: %d\n", getBadStep(a, size, &binSearch));
				printf("   ������� ����� �����: %d\n", getAverageStep(a, size, &binSearch));

				printf("������� �����\n");
				printf("   ��������� �����: %d\n", getBadStep(a, size, &blockSearch));
				printf("   ������� ����� �����: %d\n", getAverageStep(a, size, &blockSearch));
				break;
			}

		}
	}
}
