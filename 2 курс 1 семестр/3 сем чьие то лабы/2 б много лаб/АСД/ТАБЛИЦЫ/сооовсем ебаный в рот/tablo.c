#include<stdio.h>
#include<stdlib.h>
#include "tablo.h"

table vvod_up_tabl(size_t n)
{
    size_t i;
    table tab;
    for(i=0;i<n;i++)
    {
        tab.uk=i;
        tab.buf[tab.uk].key=i+1;
    }
    return tab;
}

table vvod_neup_table(size_t n)
{
    size_t i;
    table tab1;
    for(i=0;i<n;i++)
    {
        tab1.uk=i;
        tab1.buf[tab1.uk].key=1+rand()%n;
    }
    return tab1;
}

void initTable(table *T) // �������������
{
    T->uk=0;
    TableError=TableOk;
}

int isFullTAble(table *T) // ������� �����������/�� �����������
{
    if (T->uk==sizee)
        {
            TableError=TableFull;
            return 1;
        }
    return 0;
}

int isEmptyTable(table *T) // ������� �����/�� �����
{
    if (T->uk==0)
        {
            TableError=TableEmpty;
            return 1;
        }
    return 0;
}

int poisk(table *T, int key)
{
    int i, kol=0;
    for(i=0; i<T->uk; i++)
        if(T->buf[i].data==key)
            return T->buf[i].key;
    return -1;
}

void putTable(table *T, element e) // ��������� �������� � �������
{
    if (isFullTAble(T))
        return;
    int posElement;
    if ((posElement=poisk(T,e.key))!= -1)
        T->buf[posElement].data=e.data;
    else
        {
            T->buf[T->uk]=e; // ���������� ������
            T->uk++; // ����� ���������
        }
}

void getTable(table *T, element *e, int key) // ���������� �������� �� �������
{
    if (isEmptyTable(T))
        return;
    int posElement;
    if ((posElement=poisk(T,key))!=-1)
        {
            e->data=T->buf[posElement].data; // ������ ������ � ����������
            e->key=T->buf[posElement].key; // ������ ����� � ����������
            if (posElement!=T->uk-1) //���� ��������� ������� �� ���������
                T->buf[posElement] = T->buf[T->uk - 1]; //������ �� ����� ���������� ��������
            T->uk--; // ����� ��������� ����������
        }
}
