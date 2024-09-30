
#ifndef ASD_8_HASHTABLE_H
#define ASD_8_HASHTABLE_H

static const TableOk = 0;
static const TableNotMem = 1;
static const TableUnder = 2;
typedef char T_Key; // Определить тип ключа
typedef struct ElTable
{
    int flag; /* flag =-1 — элемент массива был занят
                       flag = 0 — элемент массива свободен
                       flag = 1 — элемент массива занят */
    float E;
    T_Key key;
}ElTable;

typedef struct Table
{
    ElTable* Buf;
    unsigned n; // Количество элементов в таблице
    unsigned SizeBuf; // Количество элементов в массиве
    unsigned SizeEl;  // Размер элемента таблицы
}Table;


int TableError; // 0..2
Table* InitTable(unsigned SizeBuf, unsigned SizeEl);
int HashFun(Table *T, T_Key Key, int i);
int EmptyTable(Table *T); // Возвращает 1 , если таблица пуста, иначе — 0
int PutTable(Table *T, float *E, T_Key Key); /* Включение элемента в таблицу. Возвращает 1 , если элемент включен в таблицу, иначе — 0 (если в таблице уже есть элемент с заданным ключем или не хватает памяти) */
int GetTable(Table *T, float *E, T_Key Key);  /* Исключение элемен-та. Возвращает 1 , если элемент с ключем Key был в таблице, иначе — 0 */
int ReadTable(Table *T, float *E, T_Key key); /* Чтение элемента. Возвращает 1 , если элемент с ключем Key есть в таблице, иначе — 0 */
int WriteTable(Table *T, float *E, T_Key key);  /* Изменение элемен-та. Возвращает 1 , если элемент с ключем Key есть в таблице, иначе — 0 */
void DoneTable(Table *T); // Уничтожение таблицы
void printTable(Table *T);


#endif //ASD_8_HASHTABLE_H
