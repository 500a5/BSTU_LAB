#include "Stack.h"

int StackError;

//������������� �����
void InitStack(Stack *s) {
	ListInit(s);
}

//��������� ������� � ����
void PutStack(Stack *s, void *E) {
	ListPutFirst(s, E);
}

//������� ������� �� �����
void *GetStack(Stack *s) {
	//������� �������� ��������� � ������ ������
	ListPtrBegin(s);
 	return ListGet(s);
}

//��������: ���� ����?
int EmptyStack(Stack *s) {
	return ListEmpty(s);
}

//��������� ������� �� ������� �����
void *ReadStack(Stack *s) {
	//������� �������� ��������� � ������ ������
	ListPtrBegin(s);
	return ListRead(s);
}

//���������� ����
void DoneStack(Stack *s) {
	ListDone(s);
}