
#include "table_array.h"
short TABL_ERROR;

//Инициализация таблицы
void initTable(tabl_array *tabl)
{

    tabl->Uk = 0;
    TABL_ERROR = TABL_OK;

}

//Поместить элемент в таблицу
void putTable(tabl_array *tabl, elementTabl el)
{

    if(fullTable(*tabl))
        TABL_ERROR = TABL_FULL;
    else{

        for (int i = 0; i < tabl->Uk; ++i)
            if(tabl->buf[i].key == el.key){

                tabl->buf[i].data = el.data;
                return;

            }

        tabl->buf[tabl->Uk] = el;
        ++tabl->Uk;
        TABL_ERROR = TABL_OK;

    }

}


//Взять элемент из таблицы
void getTable(tabl_array *tabl, short key, elementTabl *el)
{

    if(emptyTable(*tabl))
        TABL_ERROR = TABL_EMPTY;
    else{

        for (int i = 0; i < tabl->Uk; ++i) {

            if(tabl->buf[i].key == key){

                *el = tabl->buf[i];
                --tabl->Uk;
                tabl->buf[i] = tabl->buf[tabl->Uk];
                TABL_ERROR = TABL_OK;
                return;

            }

        }

        TABL_ERROR =TABL_NOT_KEY;

    }


}

//Таблица полная?
int fullTable(tabl_array t)
{

    return t.Uk == TABL_SIZE;

}

//Таблица пустая?
int emptyTable(tabl_array t)
{

    return t.Uk == 0;

}

