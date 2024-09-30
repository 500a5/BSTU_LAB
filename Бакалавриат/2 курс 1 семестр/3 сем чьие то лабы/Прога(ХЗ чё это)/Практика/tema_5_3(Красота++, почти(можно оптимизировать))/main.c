#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 3

void in_arr(int *);
int* sw_main(int*);
int* sw_sec(int *);
void swap(int*, int*);
void out_arr(int *);
int equal_arr(int *, int *);
void copy_arr(int*, int*);
int check_arr(int *a, int *b, int t);

int main()
{
    setlocale(LC_ALL, "Rus");

    /*Ввод матриц a, b*/
    int a[N][N], b[N][N];
    printf("----------------------------\n");
    in_arr(a);
    in_arr(b);
    check_arr(a, b, 0);
    printf("Массивы не могут быть похожи");
    return 0;
}

void in_arr(int *a){//Ввод матрицы n*n
    int i;
    for(i = 0; i < N*N; i++)
        scanf("%d", &a[i]);
    printf("----------------------------\n");
}

int* sw_main(int *a){//работает
    int i, j;
    for(i = 0; i < N; i++)
        for(j = i+1; j < N; j++)
            swap(&(a[i*N+j]), &(a[j*N + i]));
    return a;
}

int* sw_sec(int *a){//работает
    int row, col;
    for (row = 0; row < N-1; row++ )
        for (col = 0; col < N-row-1; col++ )
            swap(&(a[row*N+col]), &(a[(N-col-1)*N+N-row-1]));
    return a;
}

void swap(int *a, int *b){//работает
    int path = *a;
    *a = *b;
    *b = path;
}

void out_arr(int *a){//работает
    int i;
    for(i = 0; i < N*N; i++){
        printf("%d ", a[i]);
        if((i+1)%N == 0)
            printf("\n");
    }
}

int equal_arr(int *a, int *b){//работает
    int i,j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(a[i*N+j] != b[i*N+j])
                return 0;
    return 1;
}

int check_arr(int *a, int *b, int t){//
    if(equal_arr(a, b)){
        printf("Массивы могут быть похожи");
        _Exit(0);
    }
    if(t <= 4){
        int p1[N*N], p2[N*N], p3[N*N], p4[N*N];
        copy_arr(a, p1);
        copy_arr(a, p2);
        copy_arr(b, p3);
        copy_arr(b, p4);
        check_arr(b, sw_main(p1), t+1);
        check_arr(b, sw_sec(p2), t+1);
        check_arr(sw_main(p3), a, t+1);
        check_arr(sw_sec(p4), a, t+1);
    }
}

void copy_arr(int *a, int *b){
    int i;
    for(i = 0; i < N*N; i++)
        b[i] = a[i];
}
