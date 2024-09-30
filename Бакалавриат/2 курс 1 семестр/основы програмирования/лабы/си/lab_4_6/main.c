#include <stdio.h>
#include "zagalovok_arr_sort.h"
int const NA=5;
int const NB=4;
int const NC=4;
int f1(int *A,int *B, int*C ,int* X,int nX,  int *F1){
    int tmp1[10],ntmp1;
    int tmp2[10],ntmp2;
    int nF1;
    ntmp1=A_minus_B(X,B,nX,NB,tmp1);
    ntmp2=A_and_B(A,X,NA,nX,tmp2);
    nF1=A_or_B(tmp1,tmp2,ntmp1,ntmp2,F1);


    return nF1;
}
int f2(int *A,int *B, int*C ,int* X,int nX,  int *F2){
    int tmp1[10],ntmp1;
    int tmp2[10],ntmp2;
    int  nF2;
    ntmp1=dop_A(B,NB,tmp1);
    ntmp2=A_and_B(X,tmp1,nX,ntmp1,tmp2);
    nF2=A_minus_B(tmp2,C,ntmp2,NC,F2);
    return nF2;
}

int main() {
    int A[]={2,3,4,7,10},
        B[]={1,2,6,9},
        C[]={3,5,7,9},
        F1[10],nf1,nf2,F2[10],X[10],nX;
    printf("введите мощьность Х ");
    scanf("%d",&nX);
    printf("введите множество Х ");
    input(X,&nX);
    nf1=f1(A,B,C,X,nX,F1);
    nf2=f2(A,B,C,X,nX,F2);
    if(A_ravn_B(F1,F2,nf1,nf2)){
        printf("решение подходит");
    } else{
        printf("решение не подходит");
    }

    return 0;
}