#include <stdio.h>
#include <stdbool.h>

void del_el(int* a, int *n){
    int j,i =0;
    while (i<*n){
        j=i+1;
        while (j<*n){
            if (a[j]==a[i]){
                for (int k = j; k <*n ; ++k) {
                    a[k]=a[k+1];
                }
             --*n;
            }
            else{
                j++;
            }
        }
        i++;
        }

    }


void input (int* a,int* n){
    for(int i=0;i<*n;i++) {
        scanf("%d", &a[i]);
    }
    del_el(a,&*n);
}


void output (int* a,int n) {
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
printf("\n");
}



_Bool poisk_el (int* a,int n,int key){

    int i=0;
    while ((i<n) && (key!=a[i])) {
       i++;
    }
    return i<n;
}

_Bool  A_vkl_B (int* a, int* b, int n, int m ){
    _Bool  F=(n<=m);
    int i=0;
    while (i<n && F==true){
        F=poisk_el(b,m,a[i]);
        i++;
    }
    return F;
}


_Bool A_ravn_B (int* a, int* b, int n, int m ){
    _Bool  F= (n==m);
    int i=0;
    while (i<n && F==true){
        F=poisk_el(b,m,a[i]);
        i++;
    }
    return F;
}


_Bool A_st_vkl_B (int* a, int* b, int n, int m ){
    _Bool  F=false;
    if(n<m){
		F=A_vkl_B(a,b,n,m);
    return F;
}

  

int A_or_B (int* a, int* b, int n, int m, int* c){
    for (int i= 0; i < n; ++i) {
        c[i]=a[i];
    }
    int kc=n;
    for (int i = 0; i < m; ++i) {
        if (!poisk_el(c,kc,b[i])){
            c[kc++]=b[i];
        }
    }
    return kc;
}


int A_and_B (int* a, int* b, int n, int m,int* c ){
    int kc=0;
    for (int i = 0; i < n ; ++i) {
        if(poisk_el(b,m,a[i])){
            c[kc++]=a[i];
        }
    }
    return kc;
}


int A_minus_B (int* a, int* b, int n, int m,int* c ){
    int kc=0;
    for (int i = 0; i <n ; ++i) {
        if(!poisk_el(b,m,a[i])) {
            c[kc++] = a[i];
        }
    }
    return kc;
}


int A_sm_minus_B (int* a, int* b, int n, int m,int* c ){
    int kc=0;
    for (int i = 0; i <n; ++i) {
        if(!poisk_el(b,m,a[i])){
            c[kc++]=a[i];
        }
    }
    for (int i = 0; i <m; ++i) {
        if(!poisk_el(a,n,b[i])){
            c[kc++]=b[i];
        }
    }
    return kc;
}


int dop_A (int* a, int n, int* c ){
    int kc=0;
    for (int u = 1; u <= 10 ; ++u) {
        if(!poisk_el(a,n,u)){
            c[kc++]=u;
        }
    }
    return kc;
}