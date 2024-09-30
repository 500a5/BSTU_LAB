
#ifndef ASD4_TABLE_ARRAY_H
#define ASD4_TABLE_ARRAY_H
#define TABL_SIZE 3

//Все в порядке
static const short TABL_OK      = 0;

//Таблица переполнена
static const short TABL_FULL    = 1;

//Таблица пуста
static const short TABL_EMPTY   = 2;

//Ключ не найден
static const short TABL_NOT_KEY = 3;

//Переменная для ошибок
extern short TABL_ERROR;

typedef struct
{

    short key;

    int   data;

}elementTabl;

typedef struct
{

    elementTabl buf[TABL_SIZE];

    short Uk;

}tabl_array;

//Инициализация таблицы
void initTable(tabl_array *tabl);

//Поместить элемент в таблицу
void putTable(tabl_array *tabl, elementTabl el);

//Взять элемент из таблицы
void getTable(tabl_array *tabl, short key, elementTabl *el);

//Таблица полная?
int fullTable(tabl_array t);

//Таблица пустая?
int emptyTable(tabl_array t);

#endif //ASD4_TABLE_ARRAY_H
