#include "tree.h"

#include "optimTree.h"
int*inputArr(size_t n) {
    int *rez = calloc(n, sizeof(int));
    for (size_t i = 0; i < n; ++i)
        scanf("%d", rez + i);

    return rez;
}

//Возвращаетоптимальноедеревопоискаповведеннымчастотам
tree_searchgetOptimTree()
{

    printf("Input n: ");
    size_t n;
    scanf("%d", &n);

    printf("Input a: ");
    int*a = inputArr(n - 1);

    printf("Input key a: ");
    int*keyA = inputArr(n - 1);

    printf("Input b: ");
    int*b = inputArr(n);
    printf("Input keyb: ");
    int*keyB = inputArr(n);
    int**C = matrLoc(n);
    int**R = matrLoc(n);
    int**W = matrLoc(n);
//Инициализация h=0
    for (size_t i = 0; i< n; ++i) {
        C[i][i] = 0;
        W[i][i] = b[i];
        R[i][i] = keyB[i];
    }
    for (size_t h = 1; h < n; ++h) {
        for (size_t i = 0; i< n - h; ++i) {
            size_t j = i + h;
            W[i][j] = W[i][j - 1] + a[j - 1] + b[j];

            int min = C[i][j - 1] + C[j][j];
            size_t m = j;
            for (size_t k = i + 1; k <= j; ++k) {
                if (C[i][k - 1] + C[k][j] < min) {
                    min = C[i][k - 1] + C[k][j];
                    m = k;
                }
            }
            C[i][j] = W[i][j] + min;
            R[i][j] = keyA[m - 1];
        }
    }
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i< n; ++i) {
            printf("%d ", R[l][i]);
        }
        printf("\n");
    }
    Tree tree = getTree(R, keyA, n, 0, n - 1);
    matrFree(C, n);
    matrFree(W, n);
    matrFree(R, n);
    free(a);
    free(b);
    free(keyA);
    free(keyB);
    return tree;

}
//Выделяетпамятьдляматрицы n x n
int**matrLoc(size_t n)
{

    int**matr = calloc(n, sizeof(int*));
    for (size_t i = 0; i< n; ++i)
        matr[i] = calloc(n, sizeof(int));
    return matr;

}

//Освобождаетпамятьзанятуюматрицейmatr n x n
void matrFree(int**matr, size_t n)
{

    for (size_t i = 0; i< n; ++i)
        free(matr[i]);
    free(matr);

}

//Строитдеревопоматрице R
tree_searchgetTree(int**R, int*a, size_t n, size_t i, size_t j)
{

    Tree tree;
    initTree(&tree, R[i][j]);
    if(i != j){
        size_t rootIndex = unorderedLineSearch(a, n, R[i][j]);
        tree->L_Son = getTree(R, a, n, i, rootIndex);
        tree->R_Son = getTree(R, a, n, rootIndex + 1, j);
    }


    return tree;
}
