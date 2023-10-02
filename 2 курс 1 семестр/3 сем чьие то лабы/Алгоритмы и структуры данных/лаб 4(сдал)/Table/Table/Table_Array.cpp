#include "Table_Array.h"
#include <stdio.h>

//������������� �������
void initTableArray(TableArray *T) {
	T->uk = 0;
	errorTableArray = tableOk;
}

//��������� �������� � �������
void putTAbleArray(TableArray *T, elementTableArray E) {
	if (isFullTAbleArray(T))//���� ������� �����������
		return;
	int posElement;
	if ((posElement = searchKey(T, E.key)) != -1)//���������� ������
		T->buf[posElement].date = E.date;
	else {//����� ��������� �������� �� ���������
		T->buf[T->uk] = E;// ���������� ������
		T->uk++;// ����� ���������
	}
}

//���������� �������� �� �������
void getTableArray(TableArray *T, elementTableArray *E, KeyBaseType key) {
	if (isEmptyTableArray(T))//���� ������� �����
		return;
	int posElement;
	if ((posElement = searchKey(T, key)) != -1) {// Ec�� ����� ���� ������
		E->date = T->buf[posElement].date;// ������ ������ � ����������
		E->key = T->buf[posElement].key;// ������ ����� � ����������
		if (posElement != T->uk - 1) // ���� ��������� ������� - �� ���������
			T->buf[posElement] = T->buf[T->uk - 1];// ������ �� ����� ���������� �������� ����������
		T->uk--;// ����� ���������
	}
}

//����� �������� � ������ ������
int searchKey(TableArray *T, KeyBaseType key) {
	unsigned i;
	for (i = 0; i < T->uk && T->buf[i].key != key;) //��� ���� ��������� ������� ��������� ����� �� �����
		i++;
	if (i == T->uk) {// ���� ���� �� ��� ������
		errorTableArray = tableNoKey;// ��������� �������������� ��������
		return -1;// ������� -1
	}
	return i;// ����� ������� ������� �������� � ����� ������
}
//��������: ����� �� �������
int isEmptyTableArray(TableArray *T) {
	if (T->uk == 0) {
		errorTableArray = tableEmpty;
		return 1;
	}
}
//��������: ����������� �� �������
int isFullTAbleArray(TableArray *T) {
	if (T->uk == SIZE_TABLE_ARRAY) {
		errorTableArray = tableFull;
		return 1;
	}
	return 0;
}