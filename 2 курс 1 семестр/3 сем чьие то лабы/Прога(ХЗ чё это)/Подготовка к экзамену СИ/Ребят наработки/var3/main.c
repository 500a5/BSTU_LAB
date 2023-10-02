#include <stdio.h>
#include <stdlib.h>

#define STRLEN 30

#define SIZESTEK 50
char stek[SIZESTEK];
int pos = 0;

void put(char);//положить  в стек
char pop(void);//взять  из стека
char get(void);// получить значение на верхушке стека


int main()
{
    char c;//читаем из потока
    char prov;

    //заполняе стек
    while ((c = getchar()) != '\n'){
        if((c == '(') || (c == ')')  || (c == '[') || (c == ']')){
            if(pos == 0)
                put(c);
            else {
                prov = get();
                if( (prov == '(') && (c == ')'))
                    pop();
                else if( (prov == '[') && (c == ']'))
                    pop();
                else
                    put(c);
            }
        }
    }

    if(pos == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

//положить  в стек
void put(char c){
    stek[pos++]= c;
}

//взять  из стека
char pop(void){
    return stek[pos--];
}

//получить значение на верхушке стека
char get(void){
    return stek[pos-1];
}
