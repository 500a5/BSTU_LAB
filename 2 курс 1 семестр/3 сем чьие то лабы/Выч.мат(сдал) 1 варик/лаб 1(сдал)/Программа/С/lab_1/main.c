#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

void input(double a[N][M]);//���� ������� N*M
void output(double a[N][M]);//����� ������� N*M
void copy(double a[N][M], double rez[N][M]);//����������� ������� a � ������� rez(�����)
void multiplicationOnNumb(double a[N][M], double value);//��������� ������� a �� ����� value, ��������� � a
void multiplication(double rez[N][M], double a[N][M], double b[N][M]);//������������ ������ a � b, ��������� � rez
void addition(double rez[N][M], double a[N][M], double b[N][M]);//�������� ������ a � b, ��������� � rez
void subtraction(double rez[N][M], double a[N][M], double b[N][M]);//��������� ������� b �� a, ��������� � rez
void transposition(double rez[N][M], double a[N][M]);//���������������� ������� a, ��������� � rez
void multiplicationOnVector(double rez[N][M], double a[N][M], double vect[]);//��������� ������� a �� ������ vect, ��������� � rez(�� �����)
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

void input(double a[N][M]){//���� ������� N*M(�����)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%lf", &a[i][j]);
}

void output(double a[N][M]){//����� ������� N*M(�����)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%2.2f ", a[i][j]);
        printf("\n");
    }
}

void copy(double a[N][M], double rez[N][M]){//����������� ������� a � ������� rez(�����)
    for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                rez[i][j] = a[i][j];
}

void multiplicationOnNumb(double a[N][M], double value){//��������� ������� a �� ����� value, ��������� � a(�����)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            a[i][j] = a[i][j] * value;
}

void multiplication(double rez[N][M], double a[N][M], double b[N][M]){//������������ ������ a � b, ��������� � rez
    int sum;
    for (int i = 0; i < a.N; i++)
        for (int j = 0; j < M; j++) {
            sum = 0;
            for (int k = 0; k < N; k++)
                sum +=  a[i][k] * b[k][j];
            rez[i][j] = sum;
        }
}

void addition(double rez[N][M], double a[N][M], double b[N][M]){//�������� ������ a � b, ��������� � rez
    for (int i = 0; i < a.getStr(); i++)
        for (int j = 0; j < a.getTab(); j++)
            rez[i][j] = a[i][j] + b[i][j];
}

void subtraction(double rez[N][M], double a[N][M], double b[N][M]){//��������� ������� b �� a, ��������� � rez
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                rez[N][M] = a[N][M] - b[N][M];
}

void transposition(double rez[N][M], double a[N][M]){//���������������� ������� a, ��������� � rez
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            rez[j][i] = a[i,j];
        }
    }
}

void multiplicationOnVector(double rez[N], double a[N][M], double vect[]){//��������� ������� a �� ������ vect, ��������� � rez(�����, �� �� ������ � ������ �������)
    double matr[N][M];
    copy(a, matr);

    for (int i = 0; i < N; i++) {
        rez[i] = 0;
        for (int j = 0; j < M; j++)
            rez[i] += matr[i][j] * vect[j];
    }
}

void SLAE(double rez[N], double matr[N][M]){//������� ������� �������� ��������� ������� �����
    double a[N][M];
    copy(matr, a);
    double m,t;
    int k,j,i;
    for (k = 1; k < N; k++) { //������ ���
        for (j = k; j < M; j++) {
            m = a[j][k - 1] / a[k -1][k - 1];
            for (i = 0; i < N; i++) {
                t = a[j][i] - (m * a[k - 1][i]);
                a[j][i] = t;
            }
        }
    }
    for (i = N - 1; i >=  0; i--) {//�������� ���
        vect[i] = a[i][N] / a[i][i];
        for (j = N - 1; j > i ; j--)
            rez[i] = rez[i] - a[i][j] * rez[j] / a[i][i];
    }
}

void toTriangularMatrices(double rez[N][M], double matr[N][M]) {// ���������� ������� � ����������� ���� ������� �����
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

int determinant(double a[N][M]){//���������� ������������ ������� ������ �������
    double res = 1;
    double matr[N][M];
    toTriangularMatrices(matr, a);
    for (int i = 0; i < a.getStr(); i++)
        res *= matr[i][i];
    return res;
}

void getUnitMatrix(double rez[N][N], int n){//�������� ��������� ������� ������� �������

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (i == j)
                rez[i][j] = 1;
            else
                rez[i][j] = 0;
    }
}

