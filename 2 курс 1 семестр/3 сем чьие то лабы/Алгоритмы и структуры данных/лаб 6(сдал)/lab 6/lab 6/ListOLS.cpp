#include "ListOLS.h"
#include "malloc.h"

short ListError;

//очищение пам€ти элемента
void freeElem(element *el) {
	//free(el);
}

//конструктор
void ListInit(List *L) {
	L->first = NULL;
	L->current = NULL;
	ListError = List_OK;
}

//деструктор
void ListDone(List *L) {//
	element * del;// удал€емый элемент
	element * next; // следующий элемент

	//если список не пустой
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

//создание и инициализаци€ элемента списка
element *creatElem(BaseType E) {
	element * el = (element *)malloc(sizeof(element));
	//если не удалось выделить пам€ть указателю
	//возвращаем нулевой указатель
	if (el == NULL)
		return NULL;

	el->Data = E;
	el->Next = NULL;

	return el;
}

//добавление элемента в начало списка
void ListPutFirst(List *L, BaseType E) {
	element *el = creatElem(E);
	//если не удалось выделить пам€ть
	if (el == NULL) {
		//инициализируем переменную ошибки
		ListError = List_NotMem;
		return;
	}

	//если список пуст
	if (ListEmpty(L))
		L->first = el;
	else {
		el->Next = L->first;
		L->first = el;
	}

	ListError = List_OK;
}

//добавление элемента после рабочего указател€
void ListPut(List *L, BaseType E) {
	//создаем элемент списка
	element *el = creatElem(E);
	//если не удалось выделить пам€ть
	if (el == NULL) {
		//инициализируем переменную ошибки
		ListError = List_NotMem;
		return;
	}

	//если список пуст, то вставл€ем в начало 
	if (ListEmpty(L)) {
		L->first = el;
		L->current = el;
	}
	else if (L->current->Next == NULL) {// если рабочий указатель в конце списка
		L->current->Next = el;
		L->current = el;
	}
	else {// если рабочий указатель в середине (общий случай)
		el->Next = L->current->Next;
		L->current->Next = el;
	}

	ListError = List_OK;
}

//вз€тие элемента по рабочему указателю
BaseType ListRead(List *L) {
	//если список пустой, то инициализировать переменную ошибки
	if (ListEmpty(L)) {
		ListError = List_Empty;
		return NULL;
	}
	return L->current->Data;
}

//вз€тие(удаление) элемента по рабочему указателю
BaseType ListGet(List *L) {
	//если список пустой, то инициализировать переменную ошибки
	if (ListEmpty(L)) {
		ListError = List_Empty;
		return NULL;
	}
	//запоминаем данные текущего элемента
	BaseType data = L->current->Data;

	//”ƒјЋя≈ћ “≈ ”ў»… ЁЋ≈ћ≈Ќ“
	//1 ситуаци€ - текущий элемент первый в списке
	if (L->current == L->first) {
		L->first = L->current->Next;
		freeElem(L->current);
		L->current = L->first;
	}
	else { //общий случай
		element* previus = L->first; //указатель на предыдущий элемент
		while (previus->Next != L->current)
			previus = previus->Next;

		previus->Next = L->current->Next;
		freeElem(L->current);
		L->current = previus;
	}

	ListError = List_OK;
	return data;
}

// перенос рабочего указател€ на следующий элемент
void ListMoveNext(List *L) {
	L->current = L->current->Next;
}

//€вл€етьс€ ли список пустым
int ListEmpty(List *L) {
	return (L->first == NULL) ? 1 : 0;
}

//находитьс€ ли рабочий указатель в конце списка
int ListEnd(List *L) {
	return (L->current == NULL) ? 1 : 0;
}

//перенос указател€ в конец списка
void ListPtrEnd(List *L) {
	//если список пустой, то инициализировать переменную ошибки
	if (ListEmpty(L)) {
		ListError = List_Empty;
		return;
	}

	L->current = L->first;

	while (L->current->Next != NULL)
		L->current = L->current->Next;
}

//перенос указател€ в начала списка
void ListPtrBegin(List *L) {
	//если список пустой, то инициализировать переменную ошибки
	if (ListEmpty(L)) {
		ListError = List_Empty;
		return;
	}

	L->current = L->first;
}
