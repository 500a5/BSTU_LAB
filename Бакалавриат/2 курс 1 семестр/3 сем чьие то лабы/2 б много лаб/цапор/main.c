#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i=0, n;
    printf(" M1 or M2 ");
    int ch;
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
        {
            n=9;
            int** a=(int**)calloc(n, sizeof(int*));
            for (i=0; i<n; i++)
                a[i]=(int*)calloc(n, sizeof(int));

            int** dom=(int**)calloc(n, sizeof(int*));
            for (i=0; i<n; i++)
                dom[i]=(int*)calloc(n, sizeof(int));

            init_M1(a, n);
            output_matr(a, n);
            printf("\n");
            dominat_2(a, n, dom);
            output_matr(dom, n);

            top_sort(a, n);

            for (i=0; i<n; i++)
                free(a[i]);
            free(a);
            for (i=0; i<n; i++)
                free(dom[i]);
            free(dom);
            break;
        }
        case 2:
        {
            n=13;
            int** a=(int**)calloc(n, sizeof(int*));
            for (i=0; i<n; i++)
                a[i]=(int*)calloc(n, sizeof(int));

            init_M2(a, n);
            output_matr(a, n);

            for (i=0; i<n; i++)
                free(a[i]);
            free(a);
            break;
        }
    }
    return 0;
}

void output_matr(int **a, size_t n)
{
    int i, j;

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void init_M1 (int **a, size_t n)
{
    int i, j, ch=-1;
    int x[9], y[9];
    for (i=0; i<=2; i++)
    {
        x[i]=-1; y[i]=ch; ch++;
    }
    ch=-1;
    for (i=3; i<=5; i++)
    {
        x[i]=0; y[i]=ch; ch++;
    }
    ch=-1;
    for (i=6; i<=9; i++)
    {
        x[i]=1; y[i]=ch; ch++;
    }

     for (i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if (x[i]-y[i] < x[j]-y[j])
                a[i][j]=1;
        }
}

void init_M2 (int **a, size_t n)
{
    int i, j, ch=-1;
    int x[13], y[13];

    for (i=0; i<=2; i++)
    {
        x[i]=0; y[i]=ch; ch++;
    }
    ch=-1;
    for (i=2; i<=5; i++)
    {
        x[i]=1; y[i]=ch; ch++;
    }
    ch=-1;
    for (i=5; i<=9; i++)
    {
        x[i]=-1; y[i]=ch; ch++;
    }
    x[10]=2; y[10]=0;
    x[11]=-2; y[11]=0;
    x[12]=y[10]; y[12]=x[10];
    x[13]=y[11]; y[13]=x[11];

     for (i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if (x[i]-x[j] <= y[i]-y[j])
                a[i][j]=1;
        }
}

void dominat_1 (int **a, size_t n)
{
    int x=0, y=0, z=0;
    for (x=0; x<n; x++)
        for (y=0; y<n; y++)
            if (a[x][y])
                for (z=x+1; z<y && a[x][y]; z++)
                    a[x][y]=!(a[x][z]&&a[z][y]);
            /*if (a[x][y])
            {
                z=x+1;
                while (z<y && a[x][y])
                {
                    a[x][y]=0;
                    z++;
                }
            }*/

}

int comp(int **a, int **b, int **c, size_t n)
//композиция
{
	int x = 0, y = 0, z, k = 0;
	for (; x<n; x++)
		for (y = 0; y<n; y++)
        {
			c[x][y] = 0;
			z = 0;
			while ((z<n) && !c[x][y])
			{
				c[x][y] =a[x][z] && b[z][y];
				k++;
				z++;
			}
               // printf("%i ",c[x][y]);
            //printf("\n");
		}
	return(k);
}

int  razn (int **a, int **b, int **c, size_t n)
// разность
{
    int i=0, j=0;
     for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            c[i][j]=(a[i][j]>b[i][j]);
}


void dominat_2 (int **a, size_t n, int** c)
{
    int i;
    int** c1=(int**)calloc(n, sizeof(int*));
            for (i=0; i<n; i++)
                c1[i]=(int*)calloc(n, sizeof(int));
    for (i=0; i<n; i++)
        a[i][i]=0;
    printf("\n");
    //output_matr(a, n);
    comp(a, a, c1, n);
    printf("\n");
    //output_matr(c1, n);
    razn(a, c1, c, n);
}

int proverka(int *a, size_t n)
{
	int k=0, i=0;
	for(i = 0; i<n && k == 0; i++)
		if(a[i] >= 0)
			k=1;
	return k;
}

void top_sort (int **a, size_t n)
{
    int i, j, k = 0, lvl = 0;
    int *w = (int*)calloc(n, sizeof(int));
    for (j=0; j<n; j++)
        for (i=0; i<n; i++)
            w[j]=w[j]+a[i][j];
    for (i=0; i<n; i++)
        printf("%d ", w[i]);
}
