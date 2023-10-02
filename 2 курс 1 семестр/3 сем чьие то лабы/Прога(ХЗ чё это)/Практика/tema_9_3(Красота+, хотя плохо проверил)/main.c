#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//произведение матриц

void in_arr(int*, int, int);// Ввод элементов матрицы
void out_arr(int [], int, int);
void mult_arr(int*, int *, int *, int, int, int);

int main()
{
    setlocale(LC_ALL, "Rus");
    int row1, row2, col1, col2;

    //Ввод элементов первой матрицы
    printf("Введите количество строк первой матрицы: ");
    scanf("%d", &row1);
    printf("Введите количество столбцов первой матрицы: ");
    scanf("%d", &col1);
    printf("---------------------------------------\n");
    int a[row1*col1];
    in_arr(a ,row1, col1);
    // Ввод элементов второй матрицы
    printf("Введите количество строк второй матрицы: ");
    scanf("%d", &row2);
    printf("Введите количество столбцов второй матрицы: ");
    scanf("%d", &col2);
    printf("---------------------------------------\n");
    int b[row2][col2];
    in_arr(b, row2, col2);
    printf("---------------------------------------\n");
    // Вывод элементов второй матрицы
    out_arr(b, row2, col2);
    printf("---------------------------------------\n");

    if (col1 != row2){
        printf("Умножение невозможно!");
        return 0;
    }


    // Умножение матриц
    int c[row1*col2];

    mult_arr(c, a, b, row1, col1, col2);

    // Вывод матрицы произведения
    printf("Матрица произведения\n");
    printf("---------------------------------------\n");
    out_arr(c, row1, col2);
    printf("---------------------------------------\n");
    return 0;
}

void in_arr(int *a, int row, int col){//работает
    int i,j;
    printf("Введите элементы матрицы\n");
    for (i = 0; i < (row*col); i++)
            scanf("%d", &a[i]);
    printf("---------------------------------------\n");
}

void out_arr(int a[], int row, int col){//работает
    int i;
    for (i = 0; i < row*col; i++){
        printf("%d ", a[i]);
        if((i+1)%row == 0)
            printf("\n");
    }
}

void mult_arr(int *c ,int *a, int *b, int row1, int col1, int col2){
    int i,j,k;
    for (i = 0; i < row1; i++){
        for (j = 0; j < col2; j++){
            c[i*row1+j] = 0;
            for(k = 0; k < col1; k++)
                c[i*row1+j] += a[i*row1+k] * b[k*col2+j];
        }
    }
}
