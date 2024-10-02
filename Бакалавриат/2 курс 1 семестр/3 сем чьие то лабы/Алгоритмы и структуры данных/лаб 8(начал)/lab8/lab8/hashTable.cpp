#include "HashTable.h"
#include <stdlib.h>

Table* TableInit(h_f HashFunc, unsigned SizeBuf, unsigned SizeEl) {
	Table *T = (Table*)malloc(sizeof(Table));
	T->Buf = (ElTable*)malloc(sizeof(ElTable)*SizeBuf);
	for (int i = 0; i < SizeBuf; i++) {
		T->Buf[i].Data = NULL;
		T->Buf[i].flag = 0;
	}
	T->n = 0;
	T->SizeBuf = SizeBuf;
	T->SizeEl = SizeEl;
	T->HashFunc = HashFunc;
	TableError = TableOk;
	return T;
}

// Возвращает 1 , если таблица пуста, иначе — 0
int TableEmpty(Table *T) {
	if (T == NULL) {
		TableError = TableNotMem;
		exit(TableError);
	}
	return (T->n) ? 1 : 0;
}

// Включение элемента в таблицу. Возвращает 1 , если элемент включен в таблицу, иначе — 0 (если в таблице уже есть элемент с заданным ключем или нехватает памяти)
int TablePut(Table *T, BaseType E) {
	if (T == NULL) {
		TableError = TableNotMem;
		return 0;
	}
	if (T->n >= T->SizeBuf) {
		TableError = TableNotMem;
		return 0;
	}

	int index = T->HashFunc(E, -1, T->SizeBuf);//Вычисление адреса
	while (T->Buf[index].flag == 1) {
		index = T->HashFunc(E, index, T->SizeBuf);//Перевычисление адреса
	}
	T->Buf[index].Data = E;
	T->Buf[index].flag = 1;
	T->n += 1;
	return 1;
}

// Исключение элемен-та. Возвращает 1 , если элемент с ключем Key был в таблице, иначе — 0
int TableGet(Table *T, BaseType E, func f) {
	if (T == NULL) {
		TableError = TableNotMem;
		return 0;
	}
	int index = T->HashFunc(E, -1, T->SizeBuf);
	while (T->Buf[index].flag != 0) {
		if (!f(E, T->Buf[index].Data)) {
			T->Buf[index].Data = NULL;
			T->Buf[index].flag = -1;
			T->n -= 1;
			return 1;
		}
		index = T->HashFunc(E, index, T->SizeBuf);
	}
	return 0;
}

// Чтение элемента. Возвращает 1 , если элемент E есть в таблице, иначе — 0
int TableRead(Table *T, BaseType E, func f) {
	if (T == NULL) {
		TableError = TableNotMem;
		return 0;
	}
	int index = T->HashFunc(E, -1, T->SizeBuf);
	while (T->Buf[index].flag != 0) {
		if (f(E, T->Buf[index].Data))
			return 1;
		index = T->HashFunc(E, index, T->SizeBuf);
	}
	return 0;
}

// Уничтожение таблицы
void TableDone(Table *T) {
	for (unsigned i = 0; i < T->SizeBuf; i++)
		free(T->Buf[i].Data);
	free(T->Buf);
	free(T);
}
