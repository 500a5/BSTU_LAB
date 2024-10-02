#ifndef ASD_2_STEK_H
#define ASD_2_STEK_H
// размер стека

const short stacksize = 100;
// если операция прошла успешно
const short stackOk = 0;
// если стек пустой
const short stackEmpty = 1 ;
// если стек переполнен
const short stackfull = 2;
//  отображение исключающих ситуаций
extern short stackError;

typedef int BaseType;

typedef struct {
   BaseType Buf[100];
    short n;
}stack;

typedef stack *stack1;
void  initStack(stack1* s);

void putStack(stack1* s, BaseType el);

void getStack(stack1* s, BaseType * el);

short emptyStack(stack1 s);

short fullStack(stack1 s);
#endif //ASD_2_STEK_H
