#include <stdio.h>
#include <stdlib.h>
#define size 100
//#include "table.h"
typedef struct {
        int key;
        int data;
                } element;

typedef struct {
        element buf[size];
        int uk;
                } table;


void read_table(table *t, int n)
{
    int i;
    element e;
    initTable(t);
    for (i=0;i<n;i++)
        {
            e.key=i;
            e.data=-20+rand()%50;
            putTable(t,e);

        }
}

void write_table(table *t, int n)
{
    int i;
    element e;
    for (i=0;i<n;i++)
        printf("%i ",t->buf[i].data);
}

int main()
{
    table t[5];
    read_table(t, 5);
    write_table(t, 5);
    return 0;
}
