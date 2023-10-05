#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "table_array.h"
#include "FIFO_prior_array.h"

//#include "Search.h"
const int N = 10;


int countComparison;

//линейный поиск
int lineSearch(int *a, int n, int key) {
    countComparison = 0;
    int i = 0;
    while ((countComparison += 2) && (i < n) && (a[i] != key))
        i++;
    return (i != n) ? i : -1;
}

//быстрый линейный поиск
int fastLineSearch(int *a, int n, int key) {
    countComparison = 0;
    int i = 0;
    a[n] = key;
    while ((countComparison += 1) && (a[i] != key))
        i++;
    return (i != n) ? i : -1;
}

//Быстрый линейный поиск для массива упорядоченного по возрастанию
int sortfastLineSearch(int *a, int n, int x)
{
    countComparison = 1;

    a[n] = x;
    int i = 0;
    while ((a[i] < x)) {
        i++;
        ++countComparison;
    }
    return (x < a[i]) || (i == n) ? -1 : i; //-1 в случае ненаходы

}

//бинарный поиск
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

//блочный поиск
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

// заполнение массива
void initArr(int *arr, int n, int t) {

    for (int i = 0; i < n; i++) {
        switch (t) {
            case 1:
                arr[i] = i;
                break;
            case 2:
                arr[i] = rand() % 100 + 1;
                break;
        }
    }
}
//возвращает наихудшее количество шагов данного поиска
int getBadStep(int *a, int n, int(*find)(int *, int, int)) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        find(a, n, a[i]);
        if (max < countComparison)
            max = countComparison;
    }
    return max;
}

//возвращает среднее количество шагов данного поиска
int getAverageStep(int *a, int n, int(*find)(int *, int, int)) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        find(a, n, a[i]);
        sum += countComparison;
    }
    return sum / n;
}


int main() {
    /**
    int a[N];
    initArr(a,N,1);
    for (int i = 0; i < N; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n Линейный поиск\n икомый элемент 4 index: %d\n",lineSearch(a,N,4));
     printf("Среднее число сранений: %d Наихудшее число сравнений: %d\n",getAverageStep(a,N,&lineSearch),getBadStep(a,N,&lineSearch));
    printf("Быстрый линейный поиск\n икомый элемент 4 index: %d\n",fastLineSearch(a,N,4));
    printf("Среднее число сранений: %d Наихудшее число сравнений: %d\n",getAverageStep(a,N,&fastLineSearch),getBadStep(a,N,&fastLineSearch));
    printf("Быстрый линейный поиск в упорядоченном\n икомый элемент 4 index: %d\n",sortfastLineSearch(a,N,4));
    printf("Среднее число сранений: %d Наихудшее число сравнений: %d\n",getAverageStep(a,N,&sortfastLineSearch),getBadStep(a,N,&sortfastLineSearch));
    printf("Бинарный поиск\n икомый элемент 4 index: %d\n",binSearch(a,N,4));
    printf("Среднее число сранений: %d Наихудшее число сравнений: %d\n",getAverageStep(a,N,&binSearch),getBadStep(a,N,&binSearch));
    printf("Блочный поиск\n икомый элемент 4 index: %d\n",blockSearch(a,N,4));
    printf("Среднее число сранений: %d Наихудшее число сравнений: %d\n",getAverageStep(a,N,&blockSearch),getBadStep(a,N,&blockSearch));
     **/
     /**
    tabl_array tabl;
    elementTabl el;
    short key;
    initTable(&tabl);
    printf("Input Key: ");
    scanf("%hd", &(el.key));
    printf("Input Data: ");
    scanf("%d", &(el.data));
    putTable(&tabl, el);

    printf("Input Key: ");
    scanf("%hd", &(key));
    getTable(&tabl, key, &el);
    printf("Your El: %d\n", el.data);
    printf("TABL EMPTY: %d\n", emptyTable(tabl));

    printf("TABL FULL: %d\n", fullTable(tabl));
    printf("TABL ERROR: %d\n", TABL_ERROR);
    return 0;
      */

    FIFOP fifo;
    int el;
    InitFIFOP(&fifo);
    printf("Input El: ");
    scanf("%d", &el);
    PutFIFOP(&fifo, el, el);
    printf("Input El: ");
    scanf("%d", &el);
    PutFIFOP(&fifo, el, el);
    GetFIFOP(&fifo, &el);
    printf("Your El: %d\n", el);
    printf("FIFO EMPTY: %d\n", EmptyFIFOP(&fifo));
    printf("FIFO FULL: %d\n", FullFIFOP(&fifo));
    printf("FIFO ERROR: %d\n", FIFO_P_ERROR);

}