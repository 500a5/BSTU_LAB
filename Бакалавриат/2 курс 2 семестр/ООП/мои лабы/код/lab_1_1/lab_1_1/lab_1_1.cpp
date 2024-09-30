
#include <iostream>
#include <fstream>

const int N = 3;
void output(int a[][N][N],int m){
    FILE* F;
    F = fopen("output.txt", "r+");
    for (int k = 0; k < m; k++) {
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
          fprintf( F, "%d", a[k][i][j], " ");
        }
        printf("\n");
    }
    }
    fclose(F);
}
void input(int a[][N][N],int m){
    FILE* F;
    F = fopen("input.txt", "w+");
  
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
               fscanf(F,"%d", a[k][i][j]);
            }
        }
    }
    fclose(F);
}


int main() {
    int a[N][N][N],
        m = 2;
    input(a, m);
    output(a, m);
}
