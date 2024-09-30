#pragma once


#ifndef STRUCTS_H_
#define STRUCTS_H_
//задача
typedef struct {
	char Name[10]; // »м€ запроса
	unsigned Time; // ¬рем€ обслуживани€
	char P; // ѕриоритет задачи: 0 Ч высший, 1 Ч средний, 2 Ч низший
}TInquiry;

//структура процессора
typedef struct {
	int flag; // флаг - CPU зан€т или свободен
	TInquiry *task; // решаема€ задача в данный момент
}CPU;
#endif