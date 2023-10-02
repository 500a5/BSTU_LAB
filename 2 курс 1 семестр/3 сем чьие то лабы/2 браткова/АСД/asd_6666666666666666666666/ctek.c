#include <stdio.h>
#include <stdlib.h>
#include "ctek.h"

/*���������� ������*/
int errorStackArray;
/*������������� �����*/
void initStackArray(StackArray *S) {
S->uk = 0;
errorStackArray = okStackArray;
}
/*��������� � ����*/
void putStackArray(StackArray *S, stackArrayBaseType E) {
/*���� ���� ����������*/
if (isFullStackArray(S)) {
return;
}
/*�����*/
S->buf[S->uk] = E;				// ��������� ��������
S->uk++;							 	// ����� ���������
}
/*���������� �� �����*/
void getStackArray(StackArray *S, stackArrayBaseType *E) {
/*���� ���� ����*/
if (isEmptyStackArray(S)) {
return;
}
/*�����*/
*E = S->buf[S->uk - 1];		// ���������� �������� � ����������
S->uk--;							 	// ����� ���������
}
/*��������: ����� �� ����*/
int isFullStackArray(StackArray *S) {
if (S->uk == SIZE_STACK_ARRAY) {
errorStackArray = fullStackArray;
return 1;
}
return 0;
}
/*��������: ���� �� ����*/
int isEmptyStackArray(StackArray *S) {
if (S->uk == 0) {
errorStackArray = emptyStackArray;
return 1;
}
return 0;
}
