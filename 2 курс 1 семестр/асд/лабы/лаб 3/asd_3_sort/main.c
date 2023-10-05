#include <stdio.h>
#include "sort.h"
#include <time.h>
#include <stdlib.h>
#include "FIFO.h"
const long int N =  20*1000;

void output(int *a){
    for (int i = 0; i < N; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void input1(int *a){
    for (int i = 0; i < N; ++i) {
        a[i]=N-i;
    }
}
void input2( int *a){
    for (int i = 0; i < N; ++i) {
        a[i]=i;
    }
}
void input3(int *a){
    for (int i = 0; i < N; ++i) {
        a[i]=rand()%100;
    }
}
int main() {
    int a[N];

    input1(a);
    clock_t t = clock();
    HeapSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input2(a);
    t = clock();
    HeapSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input3(a);
    t = clock();
    HeapSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );


    input1(a);
    t = clock();
    Sis(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input2(a);
    t = clock();
    Sis(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );;

    input3(a);
    t = clock();
    Sis(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );


    input1(a);
    t = clock();
    StrSel(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input2(a);
    t = clock();
    StrSel(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input3(a);
    t = clock();
    StrSel(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );


    input1(a);
    t = clock();
    BblSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input2(a);
    t = clock();
    BblSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input3(a);
    t = clock();
    BblSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );


    input1(a);
    t = clock();
    ShellSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input2(a);
    t = clock();
    ShellSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input3(a);
    t = clock();
    ShellSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );


    input1(a);
    t = clock();
    HoarSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input2(a);
    t = clock();
    HoarSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    input3(a);
    t = clock();
    HoarSort(a,N);
    t=clock()-t;
    printf("%f\n", (double) t );

    /**
    FIFO a;
    int  FIFO_ERROR=0;
    t_baseType e=0;
    InitFIFO(&a);
    PutFIFO(&a,5);
    printf("‚ª«ξη¨«¨ %d\n",a.Buf[a.Uk1-1]);
    printf("Erorr:%d\n",FIFO_ERROR);
    PutFIFO(&a,3);
    printf("‚ª«ξη¨«¨ %d\n",a.Buf[a.Uk1-1]);
    printf("Erorr:%d\n",FIFO_ERROR);
    GetFIFO(&a,&e);
    printf("αª«ξη¨«¨ %d\n",e);
    printf("Erorr:%d\n",FIFO_ERROR);
    GetFIFO(&a,&e);
    printf("αª«ξη¨«¨%d\n",e);
    printf("Erorr:%d\n",FIFO_ERROR);
    return 0;
     **/
}