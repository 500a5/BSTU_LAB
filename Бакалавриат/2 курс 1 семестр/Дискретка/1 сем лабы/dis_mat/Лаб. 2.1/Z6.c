#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n;
int k;
int s;

void combination (int c[], int i, int b)
{
    for (int x = b; x <=(n-k+i+1); x++){
        c[i] = x;
        if (i == (k-1)){
            ++s;
            for (int j = 0; j < k; j++)
                printf ("%d ", c[j]);
            printf ("\n");
        }else
            combination (c, i+1, x+1);
    }
}

int main()
{
    setlocale (LC_ALL, "rus");

    printf ("Введте размер множества: ");
    scanf ("%d", &n);
    printf ("Введте количество элеменов в сочетании: ");
    scanf ("%d", &k);
    int c[n];
    s = 0;
    combination(c, n, k);
    printf ("Количество сочетаний: %d", s);
}
