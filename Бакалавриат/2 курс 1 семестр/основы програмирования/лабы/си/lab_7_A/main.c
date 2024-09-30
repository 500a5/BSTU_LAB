#include <stdio.h>
#include <malloc.h>

#define N 3
#define M 3
void input_matr(int a[][M], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <M ; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
}
void sum_line_matr(int a[][M], int n,int *b){
    for (int i = 0; i < n; ++i) {
        b[i]=0;
        for (int j = 0; j <M ; ++j) {
            b[i]+=a[i][j];
        }
    }
}
void sort_mas(int *a){
    int min,c;
    for (int i = 0; i <N-2 ; ++i) {
        min=i;
        for (int j = i+1; j <N-1 ; ++j) {
            if (a[j]<a[min]){
                c=a[j];
                a[j]=a[min];
                a[min]=c;
            }
        }
    }
}
int count_class_line(int a[][M], int n){
    int b[N];
    int i,j,count=0;
    sum_line_matr(a,n,b);
    sort_mas(b);
    i=0;
    while (i<n){
        j=0;
        while (++i<n && b[i]==b[i-1]){
            j++;
        }
        if(j!=0){
            count++;
        }
    }
    return count;
}
int main() {
    int (*a)[N][M];
    int count;
    a=(int(*)[N][M]) calloc(N,M*sizeof(int));
    input_matr(*a,N);
    count=count_class_line(*a,N);
    printf("%d",count);
    free(a);
    return 0;
}