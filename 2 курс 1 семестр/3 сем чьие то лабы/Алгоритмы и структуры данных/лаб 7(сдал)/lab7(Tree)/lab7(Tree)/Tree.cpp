
#include "Tree.h"
#include "malloc.h"
short TreeError = TreeOk;

// инициализаци€ Ч создаетс€  элемент, который бу-дет содержать корень дерева
void InitTree(Tree *T) {
	*T = NULL;
	TreeError = TreeOk;
}

//создание корн€
void CreateRoot(Tree *T) {
	*T = (Tree)malloc(sizeof(elementT));
	
	if (*T == NULL) {//если не удалось выделить пам€ть
		TreeError = TreeNotMem;
		return;
	}
	(*T)->data = NULL;
	(*T)->LSon = NULL;
	(*T)->RSon = NULL;
}

//запись данных
void WriteDataTree(Tree *T, basetype E) {
	(*T)->data = E;
}

//чтение
basetype ReadDataTree(Tree *T) {
	return (*T)->data;
}

//1 Ч есть левый сын, 0 Ч нет 
int IsLSon(Tree *T) {
	return ((*T)->LSon != NULL) ? 1 : 0;
}

//1 Ч есть правый сын, 0 Ч нет 
int IsRSon(Tree *T) {
	return ((*T)->RSon != NULL) ? 1 : 0;
}


// перейти к левому сыну, где T Ч ад-рес €чейки, содержащей адрес текущей вершины, TS Ч адрес €чейки, со-держащей адрес корн€ левого поддерева(левого сына)
void MoveToLSon(Tree *T, Tree *TS) {
	if ((*T)->LSon == NULL) {
		TreeError = NullPoint;
		return;
	}
	*TS = (*T)->LSon;
}

//перейти к правому сыну
void MoveToRSon(Tree *T, Tree *TS) {
	if ((*T)->RSon == NULL) {
		TreeError = NullPoint;
		return;
	}
	*TS = (*T)->RSon;
}

//1 Ч пустое дерево,0 Ч не пустое
int IsEmptyTree(Tree *T) {
	return (*T == NULL) ? 1 : 0;
}

//удаление листа
void DelTree(Tree *T) {
	free(*T);
}