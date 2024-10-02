#include <stdio.h>
#include <Time.h>
#include <process.h>

#define U 2
#define K 3
void output2MN(const int *a) {
    int j,i;
    printf("{");
    for(i=0;i<U;i++){
        if (a[i]==1){
            printf("%d", i+1);
            break;
        }
    }
    i++;
    for ( j=i; j < U; ++j){
        if(a[j]==1) {
            printf(",%d", j + 1);
        }
    }
    printf("}\n");
}

void outputMN(int *a,int n){
    printf("{%d",a[0]);
    for(int i=1;i<n;i++) {
        printf(",%d", a[i]);
    }
    printf("}\n");
}

void SetMN(int * r, int i){
    for (int x = 0; x <= 1 ; x++) {
        r[i] = x;
        if( i == U-1 ) {
            output2MN(r);
        } else{
            SetMN(r,i+1);
        }
    }
}


void combination(int *a,int i,int b){
    for(int x=b;x<=(U-K+i+1);x++){
        a[i]=x;
        if (i==K-1) {
            outputMN(a,K);
        }else {
            combination(a, i + 1, x + 1);
        }
    }
}


void transposition(int *a, int *M, int i){
    for (int j = 0; j < U; ++j) {
        if(M[j]){
            a[i] = M[j];
            M[j] = 0;
            if( i == U - 1) {
                outputMN(a,U);
            }else {
                transposition(a, M, i + 1);
            }
            M[j] = a[i];
        }
    }
}

void location(int *a,int *M,int i){
    for (int j = 0; j < U; ++j){
        if(M[j]!=0){
            a[i] = M[j];
            M[j]=0;
            if (i == K - 1) {
                outputMN(a,K);
            }else {
                location(a, M, i + 1);
            }
            M[j]=a[i];
        }
    }
}


int main() {
    int a[U],
        M[]={1,2};
 //   SetMN(a,0);
//    combination(a,0,1);
      transposition (a,M,0);
      //location(a,M,0);
    printf("%f\n",((float)clock())/CLOCKS_PER_SEC);
    system("pause");
    return 0;
}