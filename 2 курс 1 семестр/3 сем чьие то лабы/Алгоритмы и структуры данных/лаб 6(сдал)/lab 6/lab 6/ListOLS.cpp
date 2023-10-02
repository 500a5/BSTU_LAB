#include "ListOLS.h"
#include "malloc.h"

short ListError;

//�������� ������ ��������
void freeElem(element *el) {
	//free(el);
}

//�����������
void ListInit(List *L) {
	L->first = NULL;
	L->current = NULL;
	ListError = List_OK;
}

//����������
void ListDone(List *L) {//
	element * del;// ��������� �������
	element * next; // ��������� �������

	//���� ������ �� ������
	if (L->first != NULL) {
		next = L->first;
		do {
			del = next;
			freeElem(del);
			next = next->Next;
		} while (next != NULL);
	}
	L->current = NULL;
	L->first = NULL;
}

//�������� � ������������� �������� ������
element *creatElem(BaseType E) {
	element * el = (element *)malloc(sizeof(element));
	//���� �� ������� �������� ������ ���������
	//���������� ������� ���������
	if (el == NULL)
		return NULL;

	el->Data = E;
	el->Next = NULL;

	return el;
}

//���������� �������� � ������ ������
void ListPutFirst(List *L, BaseType E) {
	element *el = creatElem(E);
	//���� �� ������� �������� ������
	if (el == NULL) {
		//�������������� ���������� ������
		ListError = List_NotMem;
		return;
	}

	//���� ������ ����
	if (ListEmpty(L))
		L->first = el;
	else {
		el->Next = L->first;
		L->first = el;
	}

	ListError = List_OK;
}

//���������� �������� ����� �������� ���������
void ListPut(List *L, BaseType E) {
	//������� ������� ������
	element *el = creatElem(E);
	//���� �� ������� �������� ������
	if (el == NULL) {
		//�������������� ���������� ������
		ListError = List_NotMem;
		return;
	}

	//���� ������ ����, �� ��������� � ������ 
	if (ListEmpty(L)) {
		L->first = el;
		L->current = el;
	}
	else if (L->current->Next == NULL) {// ���� ������� ��������� � ����� ������
		L->current->Next = el;
		L->current = el;
	}
	else {// ���� ������� ��������� � �������� (����� ������)
		el->Next = L->current->Next;
		L->current->Next = el;
	}

	ListError = List_OK;
}

//������ �������� �� �������� ���������
BaseType ListRead(List *L) {
	//���� ������ ������, �� ���������������� ���������� ������
	if (ListEmpty(L)) {
		ListError = List_Empty;
		return NULL;
	}
	return L->current->Data;
}

//������(��������) �������� �� �������� ���������
BaseType ListGet(List *L) {
	//���� ������ ������, �� ���������������� ���������� ������
	if (ListEmpty(L)) {
		ListError = List_Empty;
		return NULL;
	}
	//���������� ������ �������� ��������
	BaseType data = L->current->Data;

	//������� ������� �������
	//1 �������� - ������� ������� ������ � ������
	if (L->current == L->first) {
		L->first = L->current->Next;
		freeElem(L->current);
		L->current = L->first;
	}
	else { //����� ������
		element* previus = L->first; //��������� �� ���������� �������
		while (previus->Next != L->current)
			previus = previus->Next;

		previus->Next = L->current->Next;
		freeElem(L->current);
		L->current = previus;
	}

	ListError = List_OK;
	return data;
}

// ������� �������� ��������� �� ��������� �������
void ListMoveNext(List *L) {
	L->current = L->current->Next;
}

//��������� �� ������ ������
int ListEmpty(List *L) {
	return (L->first == NULL) ? 1 : 0;
}

//���������� �� ������� ��������� � ����� ������
int ListEnd(List *L) {
	return (L->current == NULL) ? 1 : 0;
}

//������� ��������� � ����� ������
void ListPtrEnd(List *L) {
	//���� ������ ������, �� ���������������� ���������� ������
	if (ListEmpty(L)) {
		ListError = List_Empty;
		return;
	}

	L->current = L->first;

	while (L->current->Next != NULL)
		L->current = L->current->Next;
}

//������� ��������� � ������ ������
void ListPtrBegin(List *L) {
	//���� ������ ������, �� ���������������� ���������� ������
	if (ListEmpty(L)) {
		ListError = List_Empty;
		return;
	}

	L->current = L->first;
}
