#include <stdio.h>
#include <math.h>
#include <process.h>

int count_bit(unsigned long int a){
    int k = 16;
    double bit = pow(2,k);
    while ( a < bit ){
        k--;
        bit /=2;
    }
    return k;
}

unsigned long int invert2(unsigned long int a,int n){
    unsigned long int m=0;
    for(int i=n; i >= 0; i--){
        if (i%2==0) {

            m+=(((~a >> i) & 1)<<i);
        }
        else{

            m+=(((a >> i) & 1)<<i);
        }
    }
    printf("\n");
    return m;
}

void translate10to2(unsigned long int a){

    if (a){
        translate10to2(a>>1);
        printf("%lu",a&1);
    }
}


int main() {
    unsigned long int a,newa;
    int n;
    scanf("%lu",&a);
    n=count_bit(a);
    translate10to2(a);
    newa=invert2(a,n);
    printf("%lu\n",newa);
    translate10to2(newa);
    printf("\n");
    system("pause");
    return 0;
}