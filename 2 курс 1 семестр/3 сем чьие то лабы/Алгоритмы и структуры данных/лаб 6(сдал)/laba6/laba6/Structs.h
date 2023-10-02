#pragma once

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef char TypeTask;


//������
typedef struct TInquiry {
	char Name[10]; // ��� �������
	unsigned Time; // ����� ������������
	TypeTask T; // ��� ������: 1 � �1, 2 � �2, 3 � �3
};

//��������� ����������
typedef struct CPU {
	int flag; // ���� - CPU ����� ��� ��������
	TypeTask T; // ��� ������, ������� ����� ������ ���������
	TInquiry *task; // �������� ������ � ������ ������
};


#endif
