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


_Bool check_sort(int* a, int n){
    int i=0;
    while ((i<n-1)&&(a[i]<a[i+1])){
        i++;
    }
    return i==n;
}

void sort_vst(int* a, int n){
    int x,j;
    for (int i = 0; i < n ; ++i) {
        x=a[i];
        j=i;
        while ((j>0)&&(a[j-1]>x)){
            a[j]=a[j-1];
            j--;
        }
        a[j]=x;
    }
}

void input (int* a,int* n){
    for(int i=0;i<*n;i++) {
        scanf("%d", &a[i]);
    }
    del_el(a,&*n);
    if (!check_sort(a,*n)){
        sort_vst(a,*n);
    }
}


void output (int* a,int n) {
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}


_Bool  A_vkl_B (int* a, int* b, int n, int m ){
    _Bool F=((n<=m)&&(a[n]<=b[m]));
    int i=0,j=0;
    while ((i<n) && (F==true)) {
        if (a[i] == b[j]) {
            i++;
            j++;
        }
        else {
            if (a[i] > b[j]) {
                j++;
            }
            else {
                F = false;
            }
        }
    }
    return F;
}


_Bool A_ravn_B (int* a, int* b, int n, int m ){
    _Bool  F= (n==m);
    int i=0;
    while (i<n && F==true){
        F=(a[i]==b[i]);
        i++;
    }
    return F;
}


_Bool A_st_vkl_B (int* a, int* b, int n, int m ){
    _Bool F=(n < m) && A_vkl_B(a,b,n,m);
    return F;
}


int A_or_B (int* a, int* b, int n, int m, int* c){
    int i=0,j=0,kc=0;
    while ((i<n)&&(j<m)){
        if (a[i]==b[j]){
            c[kc]=a[i];
            i++;
            j++;
        }
        else{
            if(a[i]>b[j]){
                c[kc]=b[j];
                j++;
            }
            else{
                c[kc]=a[i];
                i++;
            }
        }
        kc++;
    }
    while (i<n){
        c[kc++]=a[i];
        i++;
    }
    while (j<m){
        c[kc++]=b[j];
        j++;
    }
    return kc;
}


int A_and_B (int* a, int* b, int n, int m,int* c ){
    int i=0,j=0,kc=0;
    while ((i<n)&&(j<m)){
        if (a[i]==b[j]){
            c[kc++]=a[i];
            i++;
            j++;
        }
        else {
            if(a[i]>b[j]){
                j++;
            }
            else{
                i++;
            }
        }
    }
    return kc;
}


int A_minus_B (int* a, int* b, int n, int m,int* c ){
    int i=0,j=0,kc=0;
    while ((i<n)&&(j<m)){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        else{
            if (a[i]>b[j]){
                j++;
            }
            else{
                c[kc++]=a[i];
                i++;
            }
        }
    }
    while (i<n){
        c[kc++]=a[i];
        i++;
    }
    return kc;
}


int A_sm_minus_B (int* a, int* b, int n, int m,int* c ){
    int i=0,j=0,kc=0;
    while ((i<n)&&(j<m)){
        if (a[i]==b[j]){
            i++;
            j++;
        }
        else{
            if(a[i]>b[j]){
                c[kc++]=b[j];
                j++;
            }
            else{
                c[kc++]=a[i];
                i++;
            }
        }
    }
    while (i<n){
        c[kc++]=a[i];
        i++;
    }
    while (j<m){
        c[kc++]=b[j];
        j++;
    }
    return kc;
}


int dop_A (int* a, int n, int* c ){
    int u=1, j=0,kc=0;
    while ((u<=10)&&(j<n)){
        if (u==a[j]){
            u++;
            j++;
        }
        else{
            if (u>a[j]){
                j++;
            }
            else{
                c[kc++]=u;
                u++;
            }
        }
    }
    while (u<=10){
        c[kc++]=u;
        u++;
    }
    return kc;
}