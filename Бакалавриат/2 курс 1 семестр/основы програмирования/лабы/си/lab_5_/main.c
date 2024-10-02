#include <stdio.h>
#include <process.h>

const int N=4;
void input_a(float a[][N]){
    for (int i = 0; i <N ; ++i) {
        for (int j = 0; j <N ; ++j) {
            scanf("%f", &a[i][j]);
        }
    }
}
float sum_max_in_diag(float a[][N],int i , int j){
    int kmax=1;
    float max;
    max=a[i][j];
    while (j<N-1 && i<N-1){
        i++;
        j++;
        if (a[i][j]>max){
            max=a[i][j];
            kmax=1;
        }
        else if (a[i][j]==max){
            kmax++;
        }
    }
    return max*kmax;
}

float sum_max_el(float a[][N]){
    int q=0,i,j;
    float sum=0;
    while (q<N-1){
        i=0;
        q++;
        j=q;
        sum+=sum_max_in_diag(a,i,j);
        sum+=sum_max_in_diag(a,j,i);
    }
    return sum;


}


int main( )
{
    float a[N][N],sum_max_diag;
    input_a(a);
    sum_max_diag=sum_max_el(a);
    printf("%g",sum_max_diag);
    system("pause");
    return 0;
}
