#include "HashTable.h"


#include <stdio.h>
#include <stdlib.h>

//Инициализация таблицы
Table* InitTable(unsigned SizeBuf, unsigned SizeEl){
//Выделим память под таблицу
    Table* T = (Table*)malloc(sizeof(Table));
//Память под указатель на массив
    T->Buf = (ElTable*)malloc(SizeBuf * sizeof(ElTable));

    for (int i=0; i<SizeBuf; i++){
//Все элементы массива свободны
        T->Buf[i].flag = 0;
    }
//Размер таблицы - 0
    T->n = 0;
    T->SizeBuf = SizeBuf;
    return T;
}

//Возвращает 1, если таблица пуста, иначе 0
int EmptyTable(Table *T){
    return (T->n == 0)?1:0;
}

int HashFun(Table *T, T_Key key, int i){
//Вычислим первую Хэш-функцию
    int e = key;
    int H1 = e % (T->SizeBuf);
//Вычислим вторую Хэш-функцию
    //Она не должна возвращать 0
    int H2 = 1 + ((int)e % (T->SizeBuf - 1));
    int H = (H1 + i*H2) % T->SizeBuf;
    return H;
}

/* Включение элемента в таблицу. Возвращает 1 , если элемент включен в таблицу,
 * иначе — 0 (если в таблице уже есть элемент с заданным ключем или не хватает памяти) */
int PutTable(Table *T, float *E, T_Key key){
//Если не хватает памяти
    if (T->n == T->SizeBuf){
        TableError = TableNotMem;
        return 0;
    }

//Пока не найдется свободная ячейка
    for (int i=0; i<T->SizeBuf; i++){
        int H = HashFun(T, key, i);
//Если ячейка не занята, осуществляем включение
        // Иначе, продолжаем поиск
        if (T->Buf[H].flag != 1){
            T->Buf[H].E = *E;
//Увеличиваем счетчик
            T->n++;
//Позиция становится занятой
            T->Buf[H].flag = 1;
            T->Buf[H].key = key;
            return 1;
        }
//Если такой элемент уже есть в таблице
        //Т.е ячейка по данному ключу занята
        if (T->Buf[H].flag == 1)
            return 0;
    }
}

//Возвращает 1 - если удаление успешно, иначе 0
int GetTable(Table *T, float *E, T_Key key) {
//Если пустая таблица
    if (EmptyTable(T)){
        return 0;
    }

    for (int i = 0; i < T->SizeBuf; i++) {
        int H = HashFun(T, key, i);
//Если такой элемент есть в таблице
        if (T->Buf[H].flag == 1){
            T->Buf[H].E = 0;
//Флаг устанавливаем в состояние "Элемент массива был занят"
            T->Buf[H].flag = -1;
//Уменьшаем счетчик
            T->n--;
            T->Buf[H].key = 0;
            return 1;
        }
    }
//Все места заняты
    return 0;
}


//Чтение элемента с ключом key: 1-если успешно, иначе 0
int ReadTable(Table *T, float *E, T_Key key){
//Если пустая таблица
    if (EmptyTable(T)) {
        return 0;
    }


    for (int i=0; i<T->SizeBuf; i++){
        int H = HashFun(T, key, i);
        if ((T->Buf[H].flag == 1)&&(T->Buf[H].key == key)){
            *E = T->Buf[H].E;
            return 1;
        }
    }

//Ключ не нашелся, неудачный поиск
    return 0;
}

//Изменение значения ключа key
int WriteTable(Table *T, float *E, T_Key key){
//Если пустая таблица
    if (EmptyTable(T)) {
        return 0;
    }
//Найдем позицию элемента через хэш функцию
    for (int i=0; i<T->SizeBuf; i++){
        int H = HashFun(T, key, i);
        if (T->Buf[H].flag == 1){
            T->Buf[H].E = *E;
            return 1;
        }
    }
//Изменить не удалось
    return 0;
}


//Удалить таблицу
void DoneTable(Table *T){
//Если таблица пуста, ее все равно необходимо удалить
    free(T->Buf);
    free(T);
}

void printTable(Table *T){
    for (int i=0; i<T->SizeBuf; i++){
        if (T->Buf[i].flag == 1){
            printf("Key: %c, Value: %2.1f\n", T->Buf[i].key, T->Buf[i].E);
        }
    }
}

