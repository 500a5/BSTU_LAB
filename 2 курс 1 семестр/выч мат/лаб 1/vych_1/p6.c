#include <stdio.h>
void input(float  **A,int N, int M){
    for (int i = 0; i <N ; ++i) {
        for (int j = 0; j <M ; ++j) {
            scanf("%f", &A[i][j]);
        }
    }
}
void output(float **A,int N, int M){
    for (int i = 0; i <N ; ++i) {
        for (int j = 0; j <M ; ++j) {
            printf("%f  ", A[i][j]);
        }
        printf("\n");
    }
}
void mult_A_B(float **A, int N, int M,float **B, float **C){
    float temp ;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            temp=0;
            for(int k = 0; k < N; k++){
                temp += A[i][k] * B[k][j];
            }
            C[i][j] = temp;
        }
    }
}
void mult_A_X(float **A, int N, int M, float X, float **C){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            C[i][j]=A[i][j]*X;
        }
    }
}
void sum_A_B(float **A, int N, int M, float **B, float **C){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void dif_A_B(float **A, int N, int M, float **B, float **C){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            C[i][j]=A[i][j]-B[i][j];
        }
    }
}
void transpose(float **A, int N, int M,float **C){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            C[i][j]=A[j][i];
        }
    }
}
void mult_with_vect(float **A, int N, int M, float *vect, float *rez){
    for (int i = 0; i < N; ++i) {
        rez[i]=0;
        for (int j = 0; j < M; ++j) {
            rez[i]+=A[i][j]*vect[j];
        }
    }
}
