#include <stdio.h>
#include <stdlib.h>

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

//обнуление массива a размера n
void arrZero(int* a, int n) {
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

//заполняем дерево от вершины central
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
//возврат индекса наименьшего значения
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
//рекурсия для поиска расстояния между вершинами
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

//поиск кратчайшего пути между вершинами v1 и v2
int distance(int **graf, int n, int v1, int v2) {
    int min = INT_MAX;
    int *was = (int*)malloc(sizeof(int) * n);
    arrZero(was, n);

    min = recDistance(graf, n, was, v1, v2, min, 0);

    free(was);
    return min;
}


//эксцентриситеты вершин графа
int* eccentricity(int **graf, int n) {
    int max;
    int *arrEccentricity = (int*)malloc(sizeof(int)*n);
    arrZero(arrEccentricity, n);


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            max = distance(graf, n, i, j);
            if ((i != j) && (arrEccentricity[i] < max))//вопрос, не уверен
                arrEccentricity[i] = max;
        }
    return arrEccentricity;
}


//поиск центральной вершины
int findCentralTop(int **graf, int n) {
    int *arrEccentricity;
    int min;

    arrEccentricity = eccentricity(graf, n);//эксцентриситеты вершин графа

    min = minIndex(arrEccentricity, n);
    free(arrEccentricity);
    return min + 1;
}

//алгоритм Краскала
int** algKracksal(int** graf, int n) {
    int **tree = (int**)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        tree[i] = (int*)malloc(sizeof(int)*n);
        arrZero(tree[i], n);
    }

    int centralTop = findCentralTop(graf, n);//центральная вершина

    int *was = (int*)malloc(sizeof(int)*n);
    arrZero(was, n);
    recAlgKracksal(graf, tree, n, centralTop - 1, was);//от центральной вершины построить деревья


    return tree;
}




//INT_MAX массива a размера n
void arrMax(int* a, int n) {
    for (int i = 0; i < n; i++)
        a[i] = INT_MAX;
}









//освобождение памяти
void matrFree(int **a, int n) {
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

//вывод массива a размера n
void arrOut(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n = 5;
    int **graf = (int**)malloc(sizeof(int) * n);//создаем тестовую матрицу
    for (int i = 0; i < n; i++) {
        graf[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            if(i != j)
                graf[i][j] = 1;
            else
                graf[i][j] = 0;
    }

    graf[1][3] = 0;
    graf[3][1] = 0;
    graf[2][0] = 0;
    graf[0][2] = 0;

    matrOut(graf, n);
    int **tree;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graf[i][j] == 1) {
                graf[i][j] = 0;
                graf[j][i] = 0;
                tree = algKracksal(graf, n);
                if (is_sviaz(graf, n)) {
                    printf("%d->%d\n", i, j);
                }

                free(tree);
            }
        }
    }


    tree = algKracksal(graf, n);
    matrFree(graf, n);
    printf("\n");
    matrOut(tree, n);
    matrFree(tree, n);

    getchar();
    getchar();
    getchar();


    return 0;
}



