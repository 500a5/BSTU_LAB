#pragma once

#ifndef _TABLE_ARRAY_
#define _TABLE_ARRAY_
#define SIZE_TABLE_ARRAY 10
//исключительные ситуации
const int tableOk = 0;
const int tableEmpty = 1;
const int tableFull = 2;
const int tableNoKey = 3;

extern int errorTableArray;//Переменная ошибок

/*Описание типов*/
typedef int BaseType; // Базовый тип данных таблицы
typedef int KeyBaseType; // Базовый тип ключа таблицы
typedef struct {
	KeyBaseType key;//Поле ключа
	BaseType date;//Поле данных
} elementTableArray;

typedef struct {
	elementTableArray buf[SIZE_TABLE_ARRAY];// Буфер таблицы
	unsigned uk;//Указатель
} TableArray;

void initTableArray(TableArray *T);// Инициализация таблиц
void putTAbleArray(TableArray *T, elementTableArray E);// Включение элемента в таблицу
void getTableArray(TableArray *T, elementTableArray *E, KeyBaseType key);// Исключение элемента из таблицы
int searchKey(TableArray *T, KeyBaseType key);// Поиск элемента с данным ключом
int isEmptyTableArray(TableArray *T);// Предикат: Пуста ли таблица
int isFullTAbleArray(TableArray *T);// Предикат: Переполнена ли таблица

#endif