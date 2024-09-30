#include "FIFO.h"

int FifoError;

//Инициализация очереди
void InitFifo(Fifo *f) {
	ListInit(f);
}

//Поместить элемент в очередь 
void PutFifo(Fifo *f, void *E) {
	//вставка элемента в начало
	ListPutFirst(f, E);
}

//Извлечь элемент из очереди 
void *GetFifo(Fifo *f) {
	//перенос рабочего указателя в конец
	ListPtrEnd(f);
	return ListGet(f);
}

//Прочитать элемент
void *ReadFifo(Fifo *f) {
	//перенос рабочего указателя в конец
	ListPtrEnd(f);
	return ListRead(f);
}

// Проверка, пуста ли очередь?
int  EmptyFifo(Fifo *f) {
	return ListEmpty(f);
}

// Разрушить очередь
void DoneFifo(Fifo *f) {
	ListDone(f);
}