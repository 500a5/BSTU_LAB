#include <stdio.h>
#include "zagalovok_arr_sort.h"
int const NA=5;
int const NB=4;
int const NC=4;
int const NU=10;
int const NNoU =0;
int f(int *A,int *B, int*C ,int* U_or_noU,int nU_or_noU,  int *F1){
    int tmp1[10],ntmp1;
    int tmp2[10],ntmp2;
    int tmp3[10],ntmp3,
    nF1;
    ntmp1=A_minus_B(U_or_noU,B,nU_or_noU,NB,tmp1);
    ntmp2=A_and_B(A,U_or_noU,NA,nU_or_noU,tmp2);
    ntmp3=A_or_B(tmp1,tmp2,ntmp1,ntmp2,tmp3);
    ntmp1=dop_A(B,NB,tmp1);
    ntmp2=A_and_B(U_or_noU,tmp1,nU_or_noU,ntmp1,tmp2);
    ntmp1=A_minus_B(tmp2,C,ntmp2,NC,tmp1);
    nF1=A_sm_minus_B(tmp3,tmp1,ntmp3,ntmp1,F1);

    return nF1;
}
int main() {
    int U[]={1,2,3,4,5,6,7,8,9,10},
    NoU[]={},
        A[]={2,3,4,7,10},
        B[]={1,2,6,9},
        C[]={3,5,7,9},
        F0[10],
        F1[10],nf0,nf1,tmp[10],ntmp;
    nf0=f(A,B,C,NoU,NNoU,F0);
    output(F0,nf0);
    ntmp=f(A,B,C,U,NU,tmp);
    nf1=dop_A(tmp,ntmp,F1);
    output(F1,nf1);
    return 0;
}