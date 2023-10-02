

#ifndef VYCH_1_P6_H
#define VYCH_1_P6_H
void input(float  **A,int N, int M);
void output(float **A,int N, int M);
void mult_A_B(float **A, int N, int M,float **B, float **C);
void mult_A_X(float **A, int N, int M, float X, float **C);
void sum_A_B(float **A, int N, int M, float **B, float **C);
void dif_A_B(float **A, int N, int M, float **B, float **C);
void transpose(float **A, int N, int M,float **C);
void mult_with_vect(float **A, int N, int M, float *vect, float *rez);


#endif //VYCH_1_P6_H
