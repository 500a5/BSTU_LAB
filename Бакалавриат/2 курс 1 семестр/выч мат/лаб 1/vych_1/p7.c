#include <math.h>
#include <stdio.h>

//находит макс элемент и отправляет на обмен строки в swap_str

int max_el_str(float **A, int y, int i){
    float maximym;
    int max;
    max = y;
    maximym = abs(A[y][y]);
    for(int n = y+1; n < i; n++)
    {
        if(maximym < abs(A[n][y]))
        {
            maximym = A[n][y];
            max = n;
        }
    }
    return max;
}

//обмен строк

void swap_str(float **A, float *B, int y, int max, int i){
    float a;
    a = B[y];
    B[y] = B[max];
    B[max] = a;

    for(int z = 0; z < i; z++){
        a = A[y][z];
        A[y][z] = A[max][z];
        A[max][z] = a;
    }
}

//обратный ход

void reverse_move(float **A, float *B, float *X, int n){
    X[n - 1] = B[n - 1] / A[n - 1][n - 1];
    printf("\nx%d = %f\n", n, X[n-1]);
    for (int i = n - 2; i >= 0; i--){
        X[i] = B[i];
        for (int j = i + 1; j < n; j++) {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
        printf("x%d = %f\n", i+1, X[i]);
    }
}

//прямой ход

void first_move(float **A, int i, float *B){
    int max;
    float m;
    for(int y = 0; y < i; y++){
        max = max_el_str(A, y, i);
        swap_str(A, B, y, max, i);

        for(int z = y+1; z < i; z++){
            m = -(A[z][y]/A[y][y]);

            for(int t = 0; t < i; t++) { // работа со свободными членами
                A[z][t] = A[z][t] + m * A[y][t];
            }
            B[z] = B[z] + m * B[y];
        }
    }
}
