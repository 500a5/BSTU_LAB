
#include "OLS.h"

void InitList(List **L) {//инициализация списка+
	*L = (List*)malloc(sizeof(List));
	(*L)->N = 0;
	(*L)->Start = NULL;
	(*L)->ptr = NULL;
}

void PutList(List *L, BaseType E) {//включение элемента в список+
	element* pntr = (element*)malloc(sizeof(el));
	pntr->data = E;
	if (L->Start == NULL) {//Установка первого элемента в списке
		L->Start = pntr;
 		L->ptr = pntr;
		pntr->next = NULL;
	}
	else {
		pntr->next = L->ptr->next;
		L->ptr->next = pntr;
		L->ptr = pntr;
	}
	L->N += 1;
}
	
void GetList(List *L, BaseType *E) {//исключение элемента из списка
	element* pntr;
	if (L->N == 0)
		return;
	else
	if (L->N == 1) {
		free(L->Start);
		L->Start = NULL;
		L->ptr = NULL;
	}
	else {
		pntr = L->ptr;
		BeginPtr(L);
		while (L->ptr->next != pntr)
			MovePtr;
		L->ptr->next = pntr->next;
		free(pntr);
	}
	L->N -= 1;
}

void ReadList(List *L, BaseType *E) {//чтение элемента списка+
	*E = L->ptr->data;
}

int EmptyList(List *L) {//проверка: свободен ли список+
	if (L->Start == NULL)
		return 1;
	else
		return 0;
}

int EndList(List *L) {//проверка: является ли элемент последним+
	if (L->ptr->next == NULL)
		return 1;
	else
		return 0;
}

unsigned int Count(List *L) {//возвращает количество элементов в списке+
	return L->N;
}

void BeginPtr(List *L) {//устанановка в начало списка+
	L->ptr = L->Start;
}

void EndPtr(List *L) {//устанановка в конец списка+
	while (L->ptr->next != NULL)
		MovePtr(L);
}

void MovePtr(List *L) {//переход к следующему элементу+
	L->ptr = L->ptr->next;
}

void MoveTo(List *L, unsigned int n) {//переход к n-му элементу.
	L->ptr = L->Start;
	for (unsigned int i = 0; i < n; i++) 
		MovePtr(L);
}

void DoneList(List *L) {//удаление списка.
	element* pntr;
	BeginPtr(L);
	while (L->ptr->next != NULL) {
		pntr = L->ptr->next;
		free(L->ptr);
		L->ptr = pntr;
	}
	free(L->ptr);
	free(L);
}

void CopyList(List *L1, List *L2) {//копирование списка L1 в список L2.
	BeginPtr(L1);
	BeginPtr(L2);
	BaseType E;
	while (EndList(L1)) {
		ReadList(L1, &E);
		PutList(L2, E);
		MovePtr(L1);
	}
}