#include "Stack.h"

int StackError;

//Инициализация стека
void InitStack(Stack *s) {
	ListInit(s);
}

//Поместить элемент в стек
void PutStack(Stack *s, void *E) {
	ListPutFirst(s, E);
}

//Извлечь элемент из стека
void *GetStack(Stack *s) {
	//перенос рабочего указателя в начало списка
	ListPtrBegin(s);
 	return ListGet(s);
}

//Проверка: стек пуст?
int EmptyStack(Stack *s) {
	return ListEmpty(s);
}

//Прочитать элемент из вершины стека
void *ReadStack(Stack *s) {
	//перенос рабочего указателя в начало списка
	ListPtrBegin(s);
	return ListRead(s);
}

//Уничтожить стек
void DoneStack(Stack *s) {
	ListDone(s);
}