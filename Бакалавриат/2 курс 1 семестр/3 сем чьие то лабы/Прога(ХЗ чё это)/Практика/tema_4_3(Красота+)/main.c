#include <stdio.h>
#include <stdlib.h>

#define m 10
//вычитаем среднее значение из всех элементов массива
int in_arr(int*);
int out_arr(int*);

int main()
{
    int a[m], i;

    int sr = in_arr(a) / m;//получение среднего значения

    for(i = 0; i < m; i++){
        a[i] = a[i] - sr;
    }

    out_arr(a);

    return 0;
}

int in_arr(int a[m]){//ввод массива a и возврат суммы чисел sr
    int i, sr = 0;
    for(i = 0; i < m; i++){
        scanf("%d", &a[i]);
        sr = sr + a[i];
    }
    return sr;
}

int out_arr(int a[m]){//вывод массива a
    int i;
    for(i = 0; i < m; i++)
        printf("%d ", a[i]);
}
