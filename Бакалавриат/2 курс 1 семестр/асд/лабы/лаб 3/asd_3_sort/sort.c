#include "sort.h"
#include <math.h>
// функция сортировки включением
void Sis(int *A,int nn){
    int i,j,k;
    for ( j=1; j<nn; j++ ){
        k = A[j];
        i = j -1;
        while ( k < A[i] && i >= 0){
            A[i+1] = A[i];
            i -= 1;
        }
    A[i+1] = k;
    }
}

//функциясортировкивыбором
void StrSel(int *A,int nn){
    int i,j,x,k;
    for ( i=0; i<nn-1; i++ ){
        x = A[i];
        k = i;
        for (j=i+1; j<nn; j++)
            if (A[j] < x){
                k = j;
                x = A[k];
            }
            A[k] = A[i];
            A[i] = x;
    }
}

//  функциясортировкиобменом
void BblSort(int *A,int nn){
    int i,j,k,p;
    for ( i=0; i<nn-1; i++ ){
        p = 0;
        for (j=nn-1; j>i; j--)
            if (A[j] <A[j-1]){
                k = A[j];
                A[j] = A[j-1];
                A[j-1] = k;
                p = 1;
            }/* Если перестановок не было, то сортировка выполнена*/
            if( p== 0)
                break;
    }
}

/* функция сортировки методом Шелла */
void ShellSort(int *a, int n){
    int i,j,k,hh,t,s;
    int h [1000];
    t = round(log(n)/log(3))-1;
    if (t < 1){
        t = 1;
    }
    h[t-1] = 1;
    for (k=t-1; k>= 1; k--) {
        h[k-1] = 3*h[k]+1;
    }
    for (s=t-1;s>=0;s--){
        hh = h[s];
        for (j = hh;j<=n;j++){
            i = j-hh;
            k = a[j];
            while ((k <= a[i])&&(i >= 0))
            {a[i+hh] = a[i];
            i = i-hh;};
            a[i+hh] = k;
        }
    }

}

void QSort(int *a, int L, int R){
    int  x=a[L], i= L, j= R, t;  //в качестве разделителя выбираем первый элемент
    while (i<=j){
        while (a[i]<x)
            i++;
        while (a[j]>x)
            j--;
        if (i<=j){
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (L<j)
    QSort(a,L,j);
    if (i<R)
    QSort(a,i,R);
}
//функция сортировки методом Хоара
void HoarSort(int *a, int n){
    QSort(a,1,n);
}

void Sift(int *A,int L,int R){
    int i,j,x,k;
    i = L;
    j = 2*L+1;
    x = A[L];
    if ((j<R) && (A[j]<A[j+1]))
        j++;
    while ((j<=R) && (x<A[j])){
        k=A[i];
        A[i] = A[j];
        A[j]=k;
        i = j;
        j = 2*j+1;
        if ((j<R) && (A[j]<A[j+1]))
            j++;
    }
}

/*пирамидальная функциясортировки*/
void HeapSort(int *A,int nn){
    int L,R,x,i;
    L = nn/2 ;
    R = nn-1;
    /*  Построение пирамиды из исходного массива*/
    while ( L>0 ){
        L = L -1;
        Sift(A,L,R);
    }/* Сортировка: пирамида => отсортированный массив*/
    while ( R>0 ){
        x = A[0];
        A[0] = A[R];
        A[R] = x;
        R--;
        Sift(A,L,R);
    }
}
