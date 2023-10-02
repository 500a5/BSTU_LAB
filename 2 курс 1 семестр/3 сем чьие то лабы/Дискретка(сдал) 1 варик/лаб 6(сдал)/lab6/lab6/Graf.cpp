#include "Graf.h"

//��������� ����� n ������ � m �����
int** grafRandom(int n, int m) {
	int path1, path2;
	int** graf = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		graf[i] = (int *)malloc(sizeof(int)*n);
	grafZero(graf, n);

	while (m > 0) {//���� ���� ������������ �����
		path1 = rand()%n;
		path2 = rand()%n;
		if ((!graf[path1][path2]) && (path1 != path2)) {
			graf[path1][path2] = 1;
			graf[path2][path1] = 1;
			m-= 2;
		}
	}
	return graf;
}

//�������� ���� �����
void grafZero(int **graf, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graf[i][j] = 0;
}

//��������� ������� a, ������� n
void arrZero(int *a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

//����� �����
void grafOut(int** graf, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", graf[i][j]);
		printf("\n");
	}
}

//������������ �����
void grafFree(int ** graf, int n) {
	for (int i = 0; i < n; i++)
		free(graf[i]);
	free(graf);
}

// �������� �� ���� �������
int isGrafConnect(int ** graf, int n) {
	int flag = 1;
	int* a = (int*)malloc(sizeof(int)*n);//��������� ������ ��� ���������� ������� �������� ���������
	arrZero(a, n);//��������� ������� a, ������� n
	a[0] = 1;
	for (int i = 0; i < n; i++)//���������� ������� �������
		for (int j = 0; j < n; j++)
			if (graf[i][j])
				a[j] = 1;
	for (int i = 0; i < n && flag; i++)//��������� ����������
		if (!a[i]) 
			flag = 0;
	free(a);
	return flag;
}

//�������� �� ���� �������������
int isGrafGamilton(int** graf, int n) {
	int flag = 0;
	int *a, *log_v;
	if (isGrafConnect(graf, n)) {
		a = (int*)malloc(sizeof(int) * (n + 1));
		//arrZero(a, n+1);
		for (int i = 0; i < n+1; i++)
			a[i] = -1;
		log_v = (int*)malloc(sizeof(int) * n);
		arrZero(log_v, n);
		a[0] = 0;
		log_v[0] = 1;
		if (findGamCikl(graf, a, log_v, 0, n))
			flag = 1;
		free(a);
		free(log_v);
	}
	return flag;
}

//����� ������������ �����
int findGamCikl(int** graf, int* a, int* log_v ,int i, int n) {
	int x;
	for (x = 1; x <= n; x++) {
		if ((is�ontVer(graf ,a[i - 1], x, n)) && (x != a[i - 1]) && (log_v[x] == 0)) {
			a[i] = x;
			if ((a[i] == a[0]) && (i == n))
				return 1;
			else {
				log_v[x] = 1;
				if (findGamCikl(graf, a, log_v, (i + 1), n))
					return 1;
				log_v[x] = 0;
			}
		}
	}
	return 0;
}

//�������� ��������� ������ a � b, ����� ������ n � graf
int is�ontVer(int** graf ,int a, int b, int n) {
	for (int j = 0; j < n; j++)
		if (graf[a][j] && graf[b][j])
			return 1;
	return 0;

}

// �������� �� ������ ���� ���������
int isGrafEil(int ** graf, int n, int m) {
	int count = 0;
	int flag = 1;
	int i = 1, j = 1;
	if (isGrafConnect(graf, n)) {
		while ((i <= n) && flag) {
			while ((j <= m) && flag) {
				if (graf[i][j] == 1)
					count++;
				j++;
			}
			if (((count + 1) % 2) == 0)
				flag = 0;
			i++;
			j = 0;
		}
	}
	else
		flag = 0;
	return flag;
}

void out(int *rez, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", rez[i]);
}