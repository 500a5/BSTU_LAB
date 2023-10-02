#include <stdio.h>
#include <process.h>
//#include "zagalovok_arr_no_sort.h"  //библиотека для хранения и обработки множества как
                                    //не отсортированного массива натуральных чисел
#include "zagalovok_arr_sort.h"   //библиотека для хранения и обработки множества как
                                    //сортированного массива натуральных чисел
//#include "zagalovok_bool_arr.h"   //библиотека для хранения и обработки множества как массива
                                    //с баззовым типом boolean
int main() {
    int na,nb,nc,nd,nm1,nm2;
    int a[100], b[100], c[100], d[100], m1[100], m2[100];
    printf("Униврсум множеств, доступных для ввода: {1,2,3,4,5,6,7,8,9,10} \n");
    printf("Количество элементов множества >0 И <=10 \n");

    printf("Введите количество элементов A:  ");
    scanf("%d",&na);
    printf("Введите множество A:  ");
    input(a,&na);

    printf("Введите количество элементов B:  ");
    scanf("%d",&nb);
    printf("Введите множество B:  ");
    input(b,&nb);

    printf("Введите количество элементов C:  ");
    scanf("%d",&nc);
    printf("Введите множество C:  ");
    input(c,&nc);
/**
 *
 *
 */
    nd=A_sm_minus_B(b,c,nb,nc,d);
    nm1=A_minus_B(a,d,na,nd,m1);
    nd=A_or_B(b,c,nb,nc,d);
    nm2=A_minus_B(d,a,nd,na,m2);
    nd=A_or_B(m1,m2,nm1,nm2,d);
    printf("Результат:");
    output(d,nd);

    system("pause");
    return 0;
}