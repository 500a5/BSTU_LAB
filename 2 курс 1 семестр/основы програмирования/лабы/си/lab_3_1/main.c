#include <stdio.h>
#include <stdbool.h>
#include <process.h>
#include "zagalovok_bool_arr.h"
int const n=7;
_Bool A[7]={true,false,true,false,true,false,true},B[7]={false,true,true,false,false,true,true},C[7]={false,false,false,true,true,true,true};
void F_3(_Bool *A,_Bool *B,_Bool *C, _Bool *Rez){
    _Bool Q[n],M[n],Z[n];
    A_minus_B(C,A,n,Q);
    A_minus_B(Q,B,n,M);
    dop_A(M,n,Q);

    A_minus_B(A,C,n,M);
    dop_A(M,n,Z);
    A_and_B(Q,Z,n,M);
    dop_A(M,n,Rez);
}
void F_4(_Bool *A, _Bool *B,_Bool *C, _Bool *Rez){
    _Bool Q[n],M[n],Z[n];
    A_minus_B(C,A,n,Q);
    A_minus_B(Q,B,n,M);
    dop_A(M,n,Q);

    A_minus_B(A,C,n,M);
    A_minus_B(Q,M,n,Z);
    dop_A(Z,n,Rez);
}
int main() {

    _Bool Rez3[n],Rez4[n];
    F_3(A,B,C,Rez3);
    F_4(A,B,C,Rez4);
    if (A_ravn_B(Rez3,Rez4,n)) {
        printf( "Множесва равны\n" );
        output(Rez3,n);
    }
    else{
        printf( "Множесва не равны\n" );
        output(Rez3,n);
        output(Rez4,n);
    }
    printf("\n");
system("pause");
    return 0;
}