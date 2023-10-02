#include <stdio.h>
#include <time.h>
#define MAX 100

int a[MAX];
int m[MAX];
int n;

int array_output(int a[])
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i])
        printf("%d",a[i]);
        printf("\n");
}

int array_input (int a[])
// ввод множества а мощности n
{
    int i;
    for (i=0; i<n; i++) scanf("%d", &a[i]);
}

void permutation(int m[], int i)
{
    int x;
    for (x=0; x<n; x++)
    {
        a[i]=x;
        if (i==n)
            array_output(a);
        else
        {
            m[x]=0;
            permutation(m-x, i+1);
            m[x]=1;
        }
    }
}



void main()
{
    clock_t time;
    time = clock();
    int i = 0;
    printf("n >> ");
    scanf("%d\n", &n);
    array_input(m);
    permutation(m, i);
    time = clock() - time;
    printf("%f", (double)time/CLOCKS_PER_SEC);
}
