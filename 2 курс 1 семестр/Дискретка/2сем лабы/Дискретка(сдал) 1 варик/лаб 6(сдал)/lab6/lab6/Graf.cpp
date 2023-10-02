#include "Graf.h"

//генерация графа n вершин и m ребер
int** grafRandom(int n, int m) {
	int path1, path2;
	int** graf = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		graf[i] = (int *)malloc(sizeof(int)*n);
	grafZero(graf, n);

	while (m > 0) {//пока надо генерировать ребро
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

//удаление всех ребер
void grafZero(int **graf, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graf[i][j] = 0;
}

//обнуление массива a, размера n
void arrZero(int *a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

//вывод графа
void grafOut(int** graf, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", graf[i][j]);
		printf("\n");
	}
}

//освобождение графа
void grafFree(int ** graf, int n) {
	for (int i = 0; i < n; i++)
		free(graf[i]);
	free(graf);
}

// Является ли граф связным
int isGrafConnect(int ** graf, int n) {
	int flag = 1;
	int* a = (int*)malloc(sizeof(int)*n);//выделение памяти для временного массива проверки связности
	arrZero(a, n);//обнуление массива a, размера n
	a[0] = 1;
	for (int i = 0; i < n; i++)//заполнение массива связями
		for (int j = 0; j < n; j++)
			if (graf[i][j])
				a[j] = 1;
	for (int i = 0; i < n && flag; i++)//получение результата
		if (!a[i]) 
			flag = 0;
	free(a);
	return flag;
}

//Является ли граф Гамильтоновым
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

//поиск гамильтонова цикла
int findGamCikl(int** graf, int* a, int* log_v ,int i, int n) {
	int x;
	for (x = 1; x <= n; x++) {
		if ((isСontVer(graf ,a[i - 1], x, n)) && (x != a[i - 1]) && (log_v[x] == 0)) {
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

//Проверка смежности вершин a и b, всего вершин n в graf
int isСontVer(int** graf ,int a, int b, int n) {
	for (int j = 0; j < n; j++)
		if (graf[a][j] && graf[b][j])
			return 1;
	return 0;

}

// Является ли данный граф Эйлеровым
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