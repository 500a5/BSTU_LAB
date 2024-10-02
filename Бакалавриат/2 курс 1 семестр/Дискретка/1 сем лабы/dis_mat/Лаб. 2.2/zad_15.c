#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define M 10
#define N 10
#define Z 5040

size_t m, n;
int s;

void set_init(int w[])
{
    for (int i = 0; i < n; i++)
        w[i] = i + 1;
}

void output_set (int p[])
{
    int m = 0;
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);

    if (n == 0)
        printf("Пустое множество");
    puts("");
}

int resid(int m[], int n, int b[], int x)
{
    int len_b = 0;
    for (int i = 0; i < n; i++)
        if (m[i] != x){
            b[len_b] = m[i];
            ++len_b;
        }
    return len_b;
}

void zeroing_arr (int k[])
{
    for (int i = 0; i < M; i++)
        k[i] = 0;
}

int result_time (int k[])
{
    int max_time = k[0];
    for (int i = 1; i < m; i++){
        if (k[i] > max_time)
            max_time = k[i];
    }
    return max_time;
}

int counting_time (int a[][N], int p[])
{
    int k[M];
    zeroing_arr(k);
    for (int j = 0; j < n; j++){
        for (int i = 0; i < m-1; i++){
            k[i] += a[i][p[j]-1];
            for (int l = i+1; l < m; l++, i++)
                if (k[l] < k[i]){
                    k[l] = k[i] + a[l][p[j]-1];
                }else{
                    k[l] += a[l][p[j]-1];
                }
        }
    }
    return result_time(k);
}

int min_time_work (int z[], int *min_pos)
{
    int min_time = z[0];
    *min_pos = 0;
    for (int i = 1; i < s; i++){
        if (z[i] < min_time){
            min_time = z[i];
            *min_pos = i;
        }
    }
    return min_time;
}

void permutation(int p[], int i, int w[], int t, int a[][N], int z[], int r [][N])
{
    for (int j = 0; j < t; j++){
        p[i] = w[j];
        if (i == n-1){
            for (int l = 0; l < n; l++)
                r[s][l] = p[l];
            z[s] = counting_time(a, p);
            ++s;
        }else{
            int b[t-1], len_b;
            len_b = resid(w, t, b, p[i]);
            permutation(p, i+1, b, len_b, a, z, r);
        }
    }
}

void input_characteristics(int a[][N])
{
    printf ("Введите время обработки\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf ("На %d станке %d детали:\n", i+1, j+1);
            scanf ("%d", &a[i][j]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    printf ("Введите количество станков:\n");
    scanf ("%d", &m);
    printf ("Введите количество деталей:\n");
    scanf ("%d", &n);
    int a[M][N];
    input_characteristics (a);

    int w[N];
    int z[Z];
    set_init(w);
    int p[N];
    int i = 0;
    int t = n;
    s = 0;
    int r[Z][N];
    int min_pos;
    permutation(p, i, w, t, a, z, r);
    printf ("Самое быстрое выполнение работы: %d\n", min_time_work (z, &min_pos));
    printf ("Для последовательности: ");
    output_set(r[min_pos]);
    printf("Количество перестановок: %d\n", s);
}
