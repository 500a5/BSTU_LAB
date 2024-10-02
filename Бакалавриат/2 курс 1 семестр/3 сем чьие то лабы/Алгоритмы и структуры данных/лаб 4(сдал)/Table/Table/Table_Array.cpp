#include "Table_Array.h"
#include <stdio.h>

//Инициализация таблицы
void initTableArray(TableArray *T) {
	T->uk = 0;
	errorTableArray = tableOk;
}

//Включение элемента в таблицу
void putTAbleArray(TableArray *T, elementTableArray E) {
	if (isFullTAbleArray(T))//Если таблица переполнена
		return;
	int posElement;
	if ((posElement = searchKey(T, E.key)) != -1)//Обновление данных
		T->buf[posElement].date = E.date;
	else {//Иначе включение элемента по указателю
		T->buf[T->uk] = E;// Добавление данных
		T->uk++;// Сдвиг указателя
	}
}

//Исключение элемента из таблицы
void getTableArray(TableArray *T, elementTableArray *E, KeyBaseType key) {
	if (isEmptyTableArray(T))//Если таблина пуста
		return;
	int posElement;
	if ((posElement = searchKey(T, key)) != -1) {// Ecли такой ключ найден
		E->date = T->buf[posElement].date;// Запись данных в переменную
		E->key = T->buf[posElement].key;// Запись ключа в переменную
		if (posElement != T->uk - 1) // Если найденный элемент - не последний
			T->buf[posElement] = T->buf[T->uk - 1];// Запись на место найденного элемента последнего
		T->uk--;// Сдвиг указателя
	}
}

//Поиск элемента с данным ключом
int searchKey(TableArray *T, KeyBaseType key) {
	unsigned i;
	for (i = 0; i < T->uk && T->buf[i].key != key;) //Для всех элементов таблицы выполнить поиск по ключу
		i++;
	if (i == T->uk) {// Если ключ не был найден
		errorTableArray = tableNoKey;// Установка исключительной ситуации
		return -1;// Возврат -1
	}
	return i;// Иначе возврат позиции элемента с таким ключом
}
//Предикат: Пуста ли таблица
int isEmptyTableArray(TableArray *T) {
	if (T->uk == 0) {
		errorTableArray = tableEmpty;
		return 1;
	}
}
//Предикат: Переполнена ли таблица
int isFullTAbleArray(TableArray *T) {
	if (T->uk == SIZE_TABLE_ARRAY) {
		errorTableArray = tableFull;
		return 1;
	}
	return 0;
}