#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void InitStack(Stack* s)
{
    InitList(s);
    StackError = ListError;
}

void PutStack(Stack* s, BaseType e)
{
    PutList(s, e);
    StackError = ListError;
}

void GetStack(Stack* s, BaseType* e)
{
    GetList(s, e);
    StackError = ListError;
}

short EmptyStack(Stack* s)
{
    return EmptyList(s);
}

void DoneStack(Stack* s)
{
    DoneList(s);
    StackError = ListError;
}
