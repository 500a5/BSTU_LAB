

#include <iostream>
#include <fstream>
const int N = 4;
void input(int a[]) {
    FILE* F;
    F = fopen("input.txt", "w+");
    for (int i = 0; i < N; ++i) {
        fscanf(F, "%d", a[i]);

    }
    fclose(F);
}
void output(int a[]) {
    FILE* F;
    F = fopen("output.txt", "r+");
    for (int i = 0; i < N; ++i) {
        fprintf(F, "%d", a[i]);
    }
    fclose(F);
}
void swap(int a[], int b[]) {
    int q = 0, m = (N/2);
    for (int i = 0; i < N; i++)
    {
        if (a[i] > 0) {
            b[q] = a[i];
            q++;
        }
        else {
            b[m] = a[i];
            m++;
        }

    }
}
int main()
{
    int a[N], b[N];
    input(a);
    swap(a, b);
    output(b);
}
