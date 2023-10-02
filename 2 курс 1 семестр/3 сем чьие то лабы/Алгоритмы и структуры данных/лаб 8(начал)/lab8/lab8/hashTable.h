#pragma once

#if !defined(__TABLE8_H)
#define __TABLE8_H
const short TableOk = 0;
const short TableNotMem = 1;
const short TableUnder = 2;
typedef void* T_Key; // Определить тип ключа
typedef void* BaseType;

typedef struct {
	int flag; /* flag =-1 — элемент массива был занят
				flag = 0 — элемент массива свободен
				flag = 1 — элемент массива занят */
	BaseType Data;
} ElTable;

typedef int(*h_f)(BaseType E, int index, int n);

typedef struct {
	ElTable* Buf;
	unsigned n; // Количество элементов в таблице
	unsigned SizeBuf; // Количество элементов в массиве
	unsigned SizeEl; // Размер элемента таблицы
	h_f HashFunc;
} Table;

typedef int(*func)(void*, void*); // Сравнивает ключи элементов таблицы, адреса которых находятся в параметрах a и b. Возвращает –1, если ключ элемента по адресу a меньше ключа элемента по адресу b, 0 — если ключи равны и +1 — если ключ элемента по адресу a больше ключа элемента по адресу b */

extern int TableError; // 0..2

Table* TableInit(h_f HashFunc, unsigned SizeBuf, unsigned SizeEl);
int TableEmpty(Table *T); // Возвращает 1 , если таблица пуста, иначе — 0
int TablePut(Table *T, BaseType E); // Включение элемента в таблицу. Возвращает 1 , если элемент включен в таблицу, иначе — 0 (если в таблице уже есть элемент с заданным ключем или нехватает памяти) */
int TableGet(Table *T, BaseType E, func f); // Исключение элемен-та. Возвращает 1 , если элемент с ключем Key был в таблице, иначе — 0 */
int TableRead(Table *T, BaseType E, func f); // Чтение элемента. Возвращает 1 , если элемент с ключем Key есть в таблице, иначе — 0 */
void TableDone(Table *T); // Уничтожение таблицы

#endif