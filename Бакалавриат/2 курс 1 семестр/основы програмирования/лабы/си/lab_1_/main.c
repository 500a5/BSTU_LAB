
#include <stdio.h>
#include <process.h>


void inp_out_string(char *s){
    printf( "введите строку: " );
    gets(s); // считываем из потока ввода строку
    printf( "вы ввели: %s \n", s );
}

void inp_out_char(char c){
    printf("введите символ: ");
    c = getchar();    // ввод символа
    printf("вы ввели: ");
    putchar(c);        // вывод символа
    printf("\n");
}

void inp_int(int a){
    printf("в 10-ричной системе счисления: %10d \n",a);
    printf("в 8-ричной системе счисления:  %10o \n",a);
    printf("в 16-ричной системе счисления:  %10X \n",a);
    printf("адрес %p \n",&a);
}

void inp_float(float a){
    printf("вы ввели: %5.4f \n",a);
    printf("кратчайшее представление: %g \n",a);
    printf("в 16-ричной системе счисления %a \n",a);
    printf("адрес %p \n",&a);
}

int main(void) {
    char String[100];
    inp_out_string(String);

    char c;
    inp_out_char(c);

    int a;
    printf("введите целое число : ");
    scanf("%d", &a);
    inp_int(a);

    float e;
    printf("введите дробное число: ");
    scanf("%f", &e);
    inp_float(e);
system("pause");
    return 0;
}
