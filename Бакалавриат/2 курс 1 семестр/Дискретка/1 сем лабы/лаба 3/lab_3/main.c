#include <stdio.h>
#include <stdbool.h>
#include <process.h>

void Log_F_2(int *a){
    for (int i=0;i<8;i++){
        int A=(1<<2&i)>>2;
        int B=(1<<1&i)>>1;
        int C=1&i;
        a[i]=C&~A&~B|A&~C;
    }
}

void Log_F_4(int *a){
    for (int i=0;i<8;i++){
        int A=(1<<2&i)>>2;
        int B=(1<<1&i)>>1;
        int C=1&i;
        a[i]=C&~A&~B|A&~C;
    }
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
void PrintTable(int *a,int *b){
    printf("A B C 2 4""\n");
    for(int i=0;i<8;i++){
        printf("%d %d %d %d %d \n",((1<<2&i)>>2),((1<<1&i)>>1),(1&i),a[i],b[i]);
    }
}

int main() {
    int n=8;
    int a[n],b[n];
    Log_F_2(a);
    Log_F_4(b);
    PrintTable(a,b);
    if(A_ravn_B(a,b,n)){
        printf("Таблицы истинности равны");
    }
    else{
        printf("Таблицы истинности не равны");
    }
    system("pause");
    return 0;
}