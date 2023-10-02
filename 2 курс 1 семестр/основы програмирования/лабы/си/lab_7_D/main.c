#include <stdio.h>
#include <malloc.h>


void input_matr(int **a, int n,int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <m ; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
}
void sum_line_matr(int **a, int n,int m,int *b){
    for (int i = 0; i < n; ++i) {
        b[i]=0;
        for (int j = 0; j <m ; ++j) {
            b[i]+=a[i][j];
        }
    }
}
void sort_mas(int *a,int n){
    int min,c;
    for (int i = 0; i <n-2 ; ++i) {
        min=i;
        for (int j = i+1; j <n-1 ; ++j) {
            if (a[j]<a[min]){
                c=a[j];
                a[j]=a[min];
                a[min]=c;
            }
        }
    }
}
int count_class_line(int **a, int n,int m){
    int b[n];
    int i,j,count=0;
    sum_line_matr(a,n,m,b);
    sort_mas(b,n);
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
    int **a;
    int count;
    size_t n,m;
    scanf("%d %d",&n,&m);
    printf("%d %d",n ,m );
    a=(int **) calloc(n, sizeof(int *));
    for (int i=0;i<n;i++) {
        a[i] = (int *) calloc(m, sizeof(int));
    }
    input_matr(a,n,m);
    count=count_class_line(a,n,m);
    printf("%d",count);
    for (int i=0;i<n;i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}