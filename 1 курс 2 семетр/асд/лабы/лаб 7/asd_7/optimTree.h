
#ifndef ASD_7_OPTIMTREE_H
#define ASD_7_OPTIMTREE_H
#include"tree.h"
#include"search.h"

//Ввод массива длинны n
int*inputArr(size_t n);

//Возвращает оптимальное дерево поиска по введенным частотам
tree_searchgetOptimTree();

//Выделяет память для матрицы n x n
int**matrLoc(size_t n);

//Освобождает память занятую матрицей matr n x n
voidmatrFree(int**matr, size_t n);

//Строит дерево по матрице R
tree_searchgetTree(int**R, int*a, size_t n, size_t i, size_t j);

#endif //ASD_7_OPTIMTREE_H
