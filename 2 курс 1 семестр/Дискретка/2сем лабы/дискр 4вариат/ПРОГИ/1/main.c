#include <stdio.h>
#include <stdlib.h>
#define N 11

char** get_matrA(/*size_t N*/)
{
    size_t i,j;
    char **a;

    a=(char**)calloc(N, sizeof(char*));
    for(i=0;i<N;i++)
        a[i]=(char*)calloc(N, sizeof(char));

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(i>j||j>7) a[i][j]=1;
    return a;
}

char** get_matrB(/*size_t N*/)
{
    size_t i,j;
    char **a;

    a=(char**)calloc(N, sizeof(char*));
    for(i=0;i<N;i++)
        a[i]=(char*)calloc(N, sizeof(char));

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if((10*i+j)%3==0) a[i][j]=1;
    return a;
}

char** get_matrC(/*size_t N*/)
{
    size_t i,j;
    char **a;

    a=(char**)calloc(N, sizeof(char*));
    for(i=0;i<N;i++)
        a[i]=(char*)calloc(N, sizeof(char));

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(i%2==0&&j%2!=0) a[i][j]=1;
    return a;
}

int output_matr(char**a/*size_t N*/)
{
    size_t i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ", a[i][j]);
            printf("\n");
    }
    printf("\n");
    return 0;

}

char is_equ(char**a, char**b, size_t n)
{
    size_t i=0,j;
    char f=1;

    while(i<n && f)
    {
        j=1;
        while(j<n && f)
        {
            f=a[i][j]==b[i][j];
            j++;
        }
        i++;
    }

    return f;
}

char is_incl(char**a, char**b, size_t n)
{
    size_t i=0,j;
    char f=1;

    while(i<N && f)
    {
        j=1;
        while(j<N && f)
        {
            f=(a[i][j]<=b[i][j]);
            j++;
        }
        i++;
    }

    return f;
}

char** union_matr(char** a, char** b, size_t n)
{
    size_t i,j;
    char** c;

    c=(char**)calloc(n, sizeof(char*));
    for(i=0;i<n;i++)
        c[i]=(char*)calloc(n, sizeof(char));


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=(a[i][j]||b[i][j]);
    return c;
}

char** cross_matr(char** a, char** b, size_t n)
{
    size_t i,j;
    char** c;

    c=(char**)calloc(n, sizeof(char*));
    for(i=0;i<n;i++)
        c[i]=(char*)calloc(n, sizeof(char));


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=(a[i][j]*b[i][j]);
    return c;
}

char** sub_matr(char** a, char** b, size_t n)
{
    size_t i,j;
    char** c;

    c=(char**)calloc(n, sizeof(char*));
    for(i=0;i<n;i++)
        c[i]=(char*)calloc(n, sizeof(char));


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=(a[i][j]>b[i][j]);
    return c;
}

char** simmetr_matr(char** a, char** b, size_t n)
{
    size_t i,j;
    char** c;

    c=(char**)calloc(n, sizeof(char*));
    for(i=0;i<n;i++)
        c[i]=(char*)calloc(n, sizeof(char));


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=(a[i][j]!=b[i][j]);
    return c;
}

char** dop_matr(char** a, size_t n)
{
    size_t i,j;
    char** c;

    c=(char**)calloc(n, sizeof(char*));
    for(i=0;i<n;i++)
        c[i]=(char*)calloc(n, sizeof(char));


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=1-a[i][j];
    return c;
}

char** obr_matr(char** a, size_t n)
{
    size_t i,j;
    char** c;

    c=(char**)calloc(n, sizeof(char*));
    for(i=0;i<n;i++)
        c[i]=(char*)calloc(n, sizeof(char));


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=a[j][i];
    return c;
}

char** comp_matr(char** a, char** b, size_t n)
{
    size_t i,j,z;
    char** c;

    c=(char**)calloc(n, sizeof(char*));
    for(i=0;i<n;i++)
        c[i]=(char*)calloc(n, sizeof(char));


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(z=0;z<n;z++)
                c[i][j]=(c[i][j]||(a[i][z]&&b[z][j]));

    return c;
}


int main()
{
    printf("Hello world!\n");
    char** a;
    char** b;
    char** c;
    char f;

    return 0;
}
