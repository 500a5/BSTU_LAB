#include "Tree.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

//Calc

Tree BildTree();////Строит дерево арифметического выражения, заданного в ОПЗ
void WritePrefix(Tree path);//вывод ППЗ
int Calc(Tree T);

int main() {
	Tree T = BildTree();
	WritePrefix(T);
	printf("\n");
	printf("%d", Calc(T));
	getchar();
	return 0;
}

//Строит дерево арифметического выражения, заданного в ОПЗ
Tree BildTree() {
	Stack S;
	basetype E;
	Tree T;
	char* cha;
	Tree path = NULL;
	InitTree(&T);
	InitStack(&S);
	char c = getchar();
	while (c != '\n') {
		cha = (char*)malloc(sizeof(char));
		*cha = c;
		//path = (ptrel)malloc(sizeof(elementT));//выделить память корню
		CreateRoot(&path);//создаем корень
		WriteDataTree(&path, cha);//задаем значение корню
		if ((c == '+') || (c == '-') || (c == '*') || (c == 'd')) {
			path->RSon = (ptrel)GetStack(&S);
			path->LSon = (ptrel)GetStack(&S);
			PutStack(&S, path);
		}
		else 
			PutStack(&S, path);
		c = getchar();
	}

	return path;
}

//вывод ППЗ
void WritePrefix(Tree path) {
	if (path != NULL) {
		char c = *(char*)path->data;
		printf("%c", c);
		WritePrefix(path->LSon);
		WritePrefix(path->RSon);
	}
}

int Calc(Tree T) {

	if (*(char*)(T->data) == '0')
		return 0;
	if (*(char*)(T->data) == '1')
		return 1;
	if (*(char*)(T->data) == '2')
		return 2;
	if (*(char*)(T->data) == '3')
		return 3;
	if (*(char*)(T->data) == '4')
		return 4;
	if (*(char*)(T->data) == '5')
		return 5;
	if (*(char*)(T->data) == '6')
		return 6;
	if (*(char*)(T->data) == '7')
		return 7;
	if (*(char*)(T->data) == '8')
		return 8;
	if (*(char*)(T->data) == '9')
		return 9;
	if (*(char*)(T->data) == '+')
		return Calc(T->LSon) + Calc(T->RSon);
	if (*(char*)(T->data) == '-')
		return Calc(T->LSon) - Calc(T->RSon);
	if (*(char*)(T->data) == '*')
		return Calc(T->LSon) * Calc(T->RSon);
	if (*(char*)(T->data) == 'd')
		return Calc(T->LSon) / Calc(T->RSon);
}
