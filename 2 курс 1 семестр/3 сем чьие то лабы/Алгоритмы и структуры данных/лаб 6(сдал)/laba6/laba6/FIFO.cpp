#include "FIFO.h"

int FifoError;

//������������� �������
void InitFifo(Fifo *f) {
	ListInit(f);
}

//��������� ������� � ������� 
void PutFifo(Fifo *f, void *E) {
	//������� �������� � ������
	ListPutFirst(f, E);
}

//������� ������� �� ������� 
void *GetFifo(Fifo *f) {
	//������� �������� ��������� � �����
	ListPtrEnd(f);
	return ListGet(f);
}

//��������� �������
void *ReadFifo(Fifo *f) {
	//������� �������� ��������� � �����
	ListPtrEnd(f);
	return ListRead(f);
}

// ��������, ����� �� �������?
int  EmptyFifo(Fifo *f) {
	return ListEmpty(f);
}

// ��������� �������
void DoneFifo(Fifo *f) {
	ListDone(f);
}