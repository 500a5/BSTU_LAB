#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<math.h>

#include "tabble.h"

void initTable(table *T) // инициализация

{ T->uk=0;

TableError=TableOk;

}

int isFullTAble(table *T) // таблица переполнена/не переполнена

{ if (T->uk==size)

{ TableError=TableFull;

return 1;

}

return 0;

}

int isEmptyTable(table *T) // таблица пуста/не пуста

{ if (T->uk==0)

{ TableError=TableEmpty;

return 1;

}

return 0;

}

int poisk(table *T, int key)

{ int i,kol=0;

for(i=0;i<T->uk;i++)

if(T->buf[i].data==key)

return T->buf[i].key;

return -1;

}

void putTable(table *T, element e) // включение элемента в таблицу

{ if (isFullTAble(T))

return;

int posElement;

if ((posElement=poisk(T,e.key))!= -1)

T->buf[posElement].data=e.data;

else

{ T->buf[T->uk]=e; // Добавление данных

T->uk++; // Сдвиг указателя

}

}

void getTable(table *T, element *e, int key) // исключение элемента из таблицы

{ if (isEmptyTable(T))

return;

int posElement;

if ((posElement=poisk(T,key))!=-1)

{ e->data=T->buf[posElement].data; // Запись данных в переменную

e->key=T->buf[posElement].key; // Запись ключа в переменную

if (posElement!=T->uk-1) //если найденный элемент не последний

T->buf[posElement] = T->buf[T->uk - 1]; //запись на место найденного элемента

T->uk--; // Сдвиг указателя последнего

}

}

void read_table(table *t, int n)

{ int i;

element e;

initTable(t);

for (i=0;i<n;i++)

{ e.key=i;

e.data=-20+rand()%50;

putTable(t,e);

}

}

void write_table(table *t, int n)

{ int i;

element e;

for (i=0;i<n;i++)

printf("%i ",t->buf[i].data);

}
