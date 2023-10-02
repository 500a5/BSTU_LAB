#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n;
int j;
int s;

void output_arr (int d[], int n)
{
    for (int j = 0; j < n; j++)
        printf ("%d ", d[j]);
    printf ("\n");
}

void binary_vectors (int d[], int i, int n)
{
    for (int x = 0; x < 2; x++){
        d[i] = x;
        if (i == (n - 1))
            output_arr (d, n);
        else
            binary_vectors (d, i+1, n);
    }
}


int main()
{
    setlocale (LC_ALL, "rus");

    printf ("Введте размер множества: ");
    scanf ("%d", &n);
    int i = 0;
    int d[n];
    binary_vectors(d, i, n);
    printf ("Количество подмножеств: %d", j);
}
