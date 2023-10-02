#include "Stack.h"
#include <malloc.h>
#include "windows.h"

int StackErrorr;

void InitStack(Stack **s) { // ������������� �����
	*s = (Stack*)malloc(sizeof(Stack));
	(*s)->Uk = -1;
	StackErrorr = StackOk;
}

int EmptyStack(Stack *s) { // ��������: ���� ����?
	return (s->Uk == -1) ? 1 : 0;
}

void PutStack(Stack *s, BaseType E) { // ��������� ������� � ���� */
	if (s->Uk == StackSize) {
		StackErrorr = StackOver;
		exit(StackErrorr);
	}
	s->Buf[s->Uk] = E;
	s->Uk++;
	StackErrorr = StackOk;
}

BaseType GetStack(Stack *s) { // ������� ������� �� ����� */
	if (s->Uk == StackSize) {
		StackErrorr = StackUnder;
		exit(StackErrorr);
	}
	s->Uk--;
	return s->Buf[s->Uk];
}

BaseType ReadStack(Stack *s) { // ��������� �������
	if (EmptyStack(s)) {
		StackErrorr = StackUnder;
		exit(StackUnder);
	}
	return s->Buf[s->Uk];
}

void DoneStack(Stack *s) { // ��������� �������
	free(s);
}