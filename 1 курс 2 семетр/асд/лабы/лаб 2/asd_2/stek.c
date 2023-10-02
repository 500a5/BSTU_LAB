#include "stek.h"
short stackError;
// Назначение: возвращает stackFull, если стек s переполнен, иначе возвращает stackOk

short fullStack(stack1 s){

    return (s->n == stacksize) ? stackfull : stackOk;

}

// Назначение: возвращает stackEmpty, если стек s пуст, иначе возвращает stackOk

short emptyStack(stack1 s){

    return (!s->n) ? stackEmpty : stackOk;

}

// Назначение: инициализирует стек s

void initStack(stack1* s){

    (*s)->n = 0;

    return;
}

// Назначение: включает элемент el в стек s, если стек не переполнен

void putStack(stack1* s, BaseType el){

    if (!(stackError = fullStack(*s))){

        (*s)->Buf[(*s)->n] = el;

        (*s)->n += 1;

    }
    return;
}

// Назначение: исключает элемент el из стека s, если стек не пуст

void getStack(stack1* s, BaseType * el){

    if (!(stackError = emptyStack(*s))){

        *el = (*s)->Buf[(*s)->n];

        (*s)->n -= 1;

    }
    return;
}