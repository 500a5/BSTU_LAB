#pragma once

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef char TypeTask;


//задача
typedef struct TInquiry {
	char Name[10]; // Имя запроса
	unsigned Time; // Время обслуживания
	TypeTask T; // Тип задачи: 1 — Т1, 2 — Т2, 3 — Т3
};

//структура процессора
typedef struct CPU {
	int flag; // флаг - CPU занят или свободен
	TypeTask T; // тип задачи, которую может решать процессор
	TInquiry *task; // решаемая задача в данный момент
};


#endif
