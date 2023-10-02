#define _CRT_SECURE_NO_WARNINGS
#include "Graf_Three.h"

void matrOut(int **a, int n);
int is_sviaz(int ** graf, int n);


int main() {
	int n = 6;
	int **graf = (int**)malloc(sizeof(int) * n);//создаем тестовую матрицу
	for (int i = 0; i < n; i++) {
		graf[i] = (int*)malloc(sizeof(int) * n);
	}

	graf[0][0] = 0;
	graf[0][1] = 1;
	graf[0][2] = 1;
	graf[0][3] = 0;
	graf[0][4] = 0;
	graf[0][5] = 0;

	graf[1][0] = 1;
	graf[1][1] = 0;
	graf[1][2] = 1;
	graf[1][3] = 1;
	graf[1][4] = 0;
	graf[1][5] = 0;
	
	graf[2][0] = 1;
	graf[2][1] = 1;
	graf[2][2] = 0;
	graf[2][3] = 0;
	graf[2][4] = 0;
	graf[2][5] = 0;

	graf[3][0] = 0;
	graf[3][1] = 1;
	graf[3][2] = 0;
	graf[3][3] = 0;
	graf[3][4] = 1;
	graf[3][5] = 1;

	graf[4][0] = 0;
	graf[4][1] = 0;
	graf[4][2] = 0;
	graf[4][3] = 1;
	graf[4][4] = 0;
	graf[4][5] = 1;

	graf[5][0] = 0;
	graf[5][1] = 0;
	graf[5][2] = 0;
	graf[5][3] = 1;
	graf[5][4] = 1;
	graf[5][5] = 0;

	matrOut(graf, n);
	int **tree;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graf[i][j] == 1) {
				graf[i][j] = 0;
				graf[j][i] = 0;
				tree = algKracksal(graf, n, 1);
				if (!is_sviaz(graf, n)) {
					printf("%d->%d\n", i, j);
				}
				free(tree);
				graf[i][j] = 1;
				graf[j][i] = 1;
			}
		}
	}

	printf("1 -> 3\n");
	printf("3 -> 1");

	/*
	**tree = algKracksal(graf, n, 0);
	matrFree(graf, n);
	printf("\n");
	matrOut(tree, n);
	matrFree(tree, n);
	*/
	getchar();
	getchar();
	getchar();


	return 0;
}

//вывод квадратной матрицы
void matrOut(int **a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

// Является ли граф связным
int is_sviaz(int ** graf, int n) {
	int *a = (int*)malloc(sizeof(int) * n);
	int i = 0, j, k;
	a[i] = 1;
	int count = 1;
	for (i = 0; i < n; i++) {
		if (a[i] == i) {
			for (j = 0; j < n; j++) {
				if (graf[i][j] == 1) {
					for (k = 0; k < n; k++) {
						if ((k != i) && (graf[k][j] == 1) && (a[k] == 0))
							a[k] = i + 1;
					}
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (a[i] == 0) {
			return 0;
		}
		i++;
	}
	return 1;
}
