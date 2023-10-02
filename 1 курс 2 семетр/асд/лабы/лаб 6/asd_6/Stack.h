#ifndef ASD_6_STACK_H
#define ASD_6_STACK_H

#include "List.h"

static const short StackOk = 0; // ListOk
static const short StackEmpty = 1; // ListEmpty
static const short StackNotMem = 2; // ListNotMem

short StackError;

typedef List Stack;

void InitStack(Stack* s);
void PutStack(Stack* s, BaseType e);
void GetStack(Stack* s, BaseType* e);
short EmptyStack(Stack* s);
void DoneStack(Stack* s);


#endif //ASD_6_STACK_H
