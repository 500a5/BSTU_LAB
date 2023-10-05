#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int search (int **M, int m, int i, int j, int *f);
int sc (int *pc, int **a, int n, int s);
void osnovnaya (int **M, int n, int m);
void outputvect (int **p, int n, int k);

void main()
{
    setlocale (LC_ALL,"Rus");
    int n,m,i,j,k;
    printf ("¬ведите количество переменных\n");
    scanf ("%d",&n);

    printf ("\n¬ведите количество посылок\n");
    scanf ("%d",&m);
    m++;
    int **a;
    a=(int**)calloc(150,sizeof(int*));
    for (i=0;i<150;i++)
        a[i]=(int *)calloc (n, sizeof(int));
    for (i=0;i<150;i++)
        for (j=0;j<n;j++)
            a[i][j]=0;
    k=read (a,m,n);
    printf ("\n");
   // output(a,5,k);
    //osnovnaya (a,n,m);
    //des_true(a,m,n);
}

void read (int **a,int m,int n)
{
    //с - количество скобок
    //b - количество переменных
    char s[50];
    int i,j,k,x,sign;

    for (k=0;k<m;k++)
    {
        printf ("\n¬ведите дизъюнкт\n");
        scanf ("%s",s);
        i=0;
        {
            for (j=0;j<=n;j++)
            {
                while (s[i]==' '||s[i]=='|')
                    i++;
                if (s[i]=='-')
                {
                    sign=-1;
                    i++;
                }
                else
                    sign=1;
                x=s[i]-'A';
                a[k][x]=sign;
                i++;
            }
        }
    }
    output (a,n,k);
}

void output (int **p, int n, int s)
{
    int i,j;
    for (i=0;i<s;i++)
    {
        for (j=0;j<n;j++)
            printf ("%d  ",p[i][j]);
        printf ("\n");
    }


}

void outputvect (int **p, int n, int k)
{
    int i,j,f=0;
    f=0;
    for (j=0;j<n;j++)
    {
        if (p[k][j]==-1)
        {
            if (f)
                printf ("| ");
            else
                f=1;
            printf ("-%c ",'A'+j);
        }
        if (p[k][j]==1)
        {
            if (f)
                printf ("| ");
            else
                f=1;
            printf ("%c ",'A'+j);
        }
    }
    printf ("\n");
}

//*f - различающийс€ ндедкс
//возвращает 1, если найдена склейка
int search (int **a, int m, int i, int j, int *f)
{
    int k,fl=1;
    for (k=0;k<m&&fl;k++)
        fl=(a[i][k]==a[j][k]);
    if (!fl)//если нашли отличие
    {
        if (k==m-1)
        {
            *f=k;
            return 1;
        }
        fl=1;
        for (k++;k<m&&fl;k++)
            fl=(a[i][k]==a[j][k]);
        *f=k;
    }
    else
        return !fl && k==m-1;
}


int Matr_poiskblyat (int **M, int n, int m, int i, int *f)
//n - количество переменных
//m - количество строк
//f - найденна€ строка
//k - найденна€ позици€
{
    int j, k;

    for (j=i+1;j<n;j++)
    {
        *f=search(M,m,i,j,&k);
        if(*f)
            return k;
    }
    return 0;
}


void osnovnaya (int **M, int n, int m)
{
    int i, j, k,g=0,h, f=1;
    int **V,*z;
    V=(int **)calloc(150,sizeof(int*));
    for (i=0;i<150;i++)
        V[i]=(int *)calloc(n,sizeof(int));
    z=(int *)calloc(m,sizeof(int));
    while (f)
    {
        f=0;
        printf ("###");
        for(i=0;i<m;i++)
        {
            printf ("\ni=%d",i);
            k=Matr_poiskblyat(M,n,m,i,&j);
            printf ("\nkk=%d",k);
            //приделать вывод  //i-€ и j-€ строки, которые различаютс€ по k-му элементу
            if (k)
            {
                outputvect(M,n,i);
                outputvect(M,n,j);
                printf ("\n\n");
                for (h=0;h<n;h++)
                    V[g][h]=M[i][h];
                V[g][k]=0;
                g++;
                z[i]=z[j]=1;
            }
            printf ("\nk=%d",k);
        }
        copy_z(z,M,V,n,m,g);
        printf ("\ncopy");
        for (i=0;i<n;i++)
            z[i]=0;
        for (i=0;i<g;i++)
            for(j=0;j<n;j++)
            {
                M[i][j]=0;
                M[i][j]=V[i][j];
                V[i][j]=0;
            }
        m=g;
    }
}

void copy_z (int *z, int **M, int **V, int n, int m, int *g)
{
    int i,j,k=0;
    for (i=0;i<m;i++)
    {
        if(!z[i])
        {
            for (j=0;j<n;j++)
                V[*g][j]=M[i][j];
            (*g)++;
        }
    }
}
