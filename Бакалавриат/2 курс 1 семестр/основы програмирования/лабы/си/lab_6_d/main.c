#include <stdio.h>

int balance(int *a,int n){
    int sum1=0,sum2=0;
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <i+1 ; ++j) {
            sum1+=a[j]*(j+1);
        }
        for (int k = i+2; k <= n; ++k) {
            sum2+=a[k]*(n-k);
        }
        if(sum1==sum2){
            for (int j = 0; j < n; ++j) {
                printf(" %d",a[j]);
            }
            printf("\n");
            return 1;
        } else{
            sum1=0;
            sum2=0;
        }
    }
    return 0;

}
void output(int a){
    if(a>0){
        printf("Да можно");
    } else
        {printf("Нет нельзя");
    }
}

void transposition(int *a, int *M, int i,int N,int *rez){
    for (int j = 0; j <N ; ++j) {
        if(M[j]){
            a[i] = M[j];
            M[j] = 0;
            if( i == N - 1) {

                if(balance(a,N)==1){
                    ++*rez;
                }
            }else {
                transposition(a, M, i + 1,N,&*rez);
            }
            M[j] = a[i];
        }
    }

}
int input(int *a){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
}

int main() {
    int M[100],a[100];
    int N,q=0;
    N=input(M);
    transposition(a,M,0,N,&q);
    output(q);
    return 0;
}