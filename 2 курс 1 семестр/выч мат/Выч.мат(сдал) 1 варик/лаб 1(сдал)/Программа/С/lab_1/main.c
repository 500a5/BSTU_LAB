#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

void input(double a[N][M]);//ввод матрицы N*M
void output(double a[N][M]);//вывод матрицы N*M
void copy(double a[N][M], double rez[N][M]);//копирование матрицы a в матрицу rez(робит)
void multiplicationOnNumb(double a[N][M], double value);//Умножение матрицы a на число value, результат в a
void multiplication(double rez[N][M], double a[N][M], double b[N][M]);//Перемножение матриц a и b, результат в rez
void addition(double rez[N][M], double a[N][M], double b[N][M]);//Сложение матриц a и b, результат в rez
void subtraction(double rez[N][M], double a[N][M], double b[N][M]);//Вычитание матрицы b из a, результат в rez
void transposition(double rez[N][M], double a[N][M]);//транспонирование матрицы a, результат в rez
void multiplicationOnVector(double rez[N][M], double a[N][M], double vect[]);//умножение матрицы a на вектор vect, результат в rez(не робит)
void SLAE(double rez[N], double matr[N][M]);
void toTriangularMatrices(double rez[N][M], double matr[N][M]);
int determinant(double a[N][M]);
void getUnitMatrix(double rez[N][N], int n);

int main()
{
    double matr[N][M];
    input(matr);
    double rez[N][M];
    SLAE(rez, matr);
    for (int i = 0; i < M - 1; i++) {
        printf("%d ", rez[i]);
    }

    return 0;
}

void input(double a[N][M]){//ввод матрицы N*M(робит)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%lf", &a[i][j]);
}

void output(double a[N][M]){//вывод матрицы N*M(робит)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%2.2f ", a[i][j]);
        printf("\n");
    }
}

void copy(double a[N][M], double rez[N][M]){//копирование матрицы a в матрицу rez(робит)
    for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                rez[i][j] = a[i][j];
}

void multiplicationOnNumb(double a[N][M], double value){//Умножение матрицы a на число value, результат в a(робит)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            a[i][j] = a[i][j] * value;
}

void multiplication(double rez[N][M], double a[N][M], double b[N][M]){//Перемножение матриц a и b, результат в rez
    int sum;
    for (int i = 0; i < a.N; i++)
        for (int j = 0; j < M; j++) {
            sum = 0;
            for (int k = 0; k < N; k++)
                sum +=  a[i][k] * b[k][j];
            rez[i][j] = sum;
        }
}

void addition(double rez[N][M], double a[N][M], double b[N][M]){//Сложение матриц a и b, результат в rez
    for (int i = 0; i < a.getStr(); i++)
        for (int j = 0; j < a.getTab(); j++)
            rez[i][j] = a[i][j] + b[i][j];
}

void subtraction(double rez[N][M], double a[N][M], double b[N][M]){//Вычитание матрицы b из a, результат в rez
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                rez[N][M] = a[N][M] - b[N][M];
}

void transposition(double rez[N][M], double a[N][M]){//транспонирование матрицы a, результат в rez
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            rez[j][i] = a[i,j];
        }
    }
}

void multiplicationOnVector(double rez[N], double a[N][M], double vect[]){//умножение матрицы a на вектор vect, результат в rez(робит, но не уверен с копией матрицы)
    double matr[N][M];
    copy(a, matr);

    for (int i = 0; i < N; i++) {
        rez[i] = 0;
        for (int j = 0; j < M; j++)
            rez[i] += matr[i][j] * vect[j];
    }
}

void SLAE(double rez[N], double matr[N][M]){//решение системы линейных уравнений методом гауса
    double a[N][M];
    copy(matr, a);
    double m,t;
    int k,j,i;
    for (k = 1; k < N; k++) { //прямой ход
        for (j = k; j < M; j++) {
            m = a[j][k - 1] / a[k -1][k - 1];
            for (i = 0; i < N; i++) {
                t = a[j][i] - (m * a[k - 1][i]);
                a[j][i] = t;
            }
        }
    }
    for (i = N - 1; i >=  0; i--) {//обратный ход
        vect[i] = a[i][N] / a[i][i];
        for (j = N - 1; j > i ; j--)
            rez[i] = rez[i] - a[i][j] * rez[j] / a[i][i];
    }
}

void toTriangularMatrices(double rez[N][M], double matr[N][M]) {// приведение матрицы к тругольному виду методом гауса
    copy(matr,rez);
    double m,t;
    int k,j,i;
    for (k = 1; k < N; k++) {
        for (j = k; j < N; j++) {
            m = rez[j][k - 1] / rez[k - 1][k - 1];
            for (i = 0; i < M; i++) {
                t = rez[j][i] - (m * rez[k - 1][i]);
                rez[j][i] = t
            }
        }
    }
}

int determinant(double a[N][M]){//нахождение определителя матрицы любого порядка
    double res = 1;
    double matr[N][M];
    toTriangularMatrices(matr, a);
    for (int i = 0; i < a.getStr(); i++)
        res *= matr[i][i];
    return res;
}

void getUnitMatrix(double rez[N][N], int n){//создание единичной матрицы нужного порядка

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (i == j)
                rez[i][j] = 1;
            else
                rez[i][j] = 0;
    }
}

