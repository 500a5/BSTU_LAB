#pragma once


#ifndef STRUCTS_H_
#define STRUCTS_H_
//������
typedef struct {
	char Name[10]; // ��� �������
	unsigned Time; // ����� ������������
	char P; // ��������� ������: 0 � ������, 1 � �������, 2 � ������
}TInquiry;

//��������� ����������
typedef struct {
	int flag; // ���� - CPU ����� ��� ��������
	TInquiry *task; // �������� ������ � ������ ������
}CPU;
#endif