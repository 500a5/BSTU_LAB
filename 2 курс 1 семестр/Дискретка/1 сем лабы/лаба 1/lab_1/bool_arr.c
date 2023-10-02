#include <stdio.h>
#include <stdbool.h>

void input (_Bool* a, int* n){
    int j;
    for (int i = 0; i <n ; ++i) {
        a[i]=false;
    }
    for (int i = 0; i <n ; ++i) {
        printf("%d",j);
        a[j-1]=true;
    }
}


void output (_Bool * a,int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i]){
            printf("%d",i+1);
        }
    }
}



_Bool  A_vkl_B (_Bool * a, _Bool * b, int n ){
    int i=0;
    _Bool F=true;
    while ((i<n)&&(F==true)){
        F=(a[i]<=b[i]);
        i++;
    }
    return F;
}


_Bool A_ravn_B (_Bool * a, _Bool * b, int n ){
    int i=0;
    _Bool F=true;
    while ((i<n)&&(F==true)){
        F=(a[i]==b[i]);
        i++;
    }
    return F;
}


_Bool A_st_vkl_B (_Bool * a, _Bool * b, int n, int m ){
    _Bool F=(n < m) && A_vkl_B(a,b,n);
    return F;
}


void A_or_B (_Bool* a, _Bool* b, int n, _Bool* c){
    for (int i = 0; i < n; ++i) {
        c[i]=(a[i]||b[i]);
    }
}


void A_and_B (_Bool* a, _Bool* b, int n, _Bool* c ){
    for (int i = 0; i < n; ++i) {
        c[i]=(a[i]&&b[i]);
    }
}


void A_minus_B (_Bool* a, _Bool* b, int n, _Bool* c){
    for (int i = 0; i < n; ++i) {
        c[i]=(a[i]>b[i]);
    }
}


void A_sm_minus_B (_Bool* a, _Bool* b, int n, int m , _Bool* c ){
    for (int i = 0; i < n; ++i) {
        c[i]=(a[i]!=b[i]);
    }
}


int dop_A (_Bool * a, int n, _Bool* c ){
    for (int i = 0; i < n; ++i) {
        c[i]=!a[i];
    }
}