#include "stek.h"
short stackError;
// �����祭��: �����頥� stackFull, �᫨ �⥪ s ��९�����, ���� �����頥� stackOk

short fullStack(stack1 s){

    return (s->n == stacksize) ? stackfull : stackOk;

}

// �����祭��: �����頥� stackEmpty, �᫨ �⥪ s ����, ���� �����頥� stackOk

short emptyStack(stack1 s){

    return (!s->n) ? stackEmpty : stackOk;

}

// �����祭��: ���樠������� �⥪ s

void initStack(stack1* s){

    (*s)->n = 0;

    return;
}

// �����祭��: ����砥� ����� el � �⥪ s, �᫨ �⥪ �� ��९�����

void putStack(stack1* s, BaseType el){

    if (!(stackError = fullStack(*s))){

        (*s)->Buf[(*s)->n] = el;

        (*s)->n += 1;

    }
    return;
}

// �����祭��: �᪫�砥� ����� el �� �⥪� s, �᫨ �⥪ �� ����

void getStack(stack1* s, BaseType * el){

    if (!(stackError = emptyStack(*s))){

        *el = (*s)->Buf[(*s)->n];

        (*s)->n -= 1;

    }
    return;
}