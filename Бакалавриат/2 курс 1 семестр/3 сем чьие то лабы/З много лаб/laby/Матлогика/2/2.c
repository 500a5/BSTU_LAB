#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int search (int *pc, int **a, int n, int s);
int sc (int *pc, int **a, int n, int s);
void main()
{
    setlocale (LC_ALL,"Rus");
    int n,m,i,j;
    printf ("Введите количество переменных\n");
    scanf ("%d",&n);
    printf ("\nВведите количество скобок\n");
    scanf ("%d",&m);
    int **a;
    a=(int**)calloc(m,sizeof(int*));
    for (i=0;i<m;i++)
        a[i]=(int *)calloc (n, sizeof(int));
    read (a,m,n);
    output (a,n,m);
    des_true(a,m,n);
}

void read (int **a,int m,int n)
{
    //с - количество скобок
    //b - количество переменных
    char s[50];
    int i,j,k,x,sign;

    for (k=0;k<m;k++)
    {
        printf ("\nВведите дизъюнкт\n");
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
}
void des_true (int **a, int m, int n)
{
    int i,j,k,fl=0,g,res=1,t=0,s=0,f=0;
    int *pa; int *pb; int *pc;
    pa=(int*)calloc(m,sizeof(int)); //для НФ
    pb=(int*)calloc(n,sizeof(int)); //для переменных
    k=(int)pow(2,n);
    int **b;
    b=(int**)calloc(m,sizeof(int*));
    for (i=0;i<m;i++)
        b[i]=(int *)calloc(m,sizeof(int));
    int **c;
    c=(int**)calloc(k*k*k,sizeof(int*));
    for (i=0;i<k*k*k;i++)
        c[i]=(int *)calloc(n,sizeof(int));
    printf ("Формулы, являющиеся посылками для введенного следствия\n");
    for (i=0;i<k;i++)
    {
        for (j=0;j<m;j++)
            for (g=0;g<n;g++)
            {
                if (a[j][g]==0)
                    b[j][g]=-1;
                if (a[j][g]==-1)
                    b[j][g]=!pb[g];
                if (a[j][g]==1)
                    b[j][g]=pb[g];
            }
        for (j=0;j<m;j++)
        {   pa[j]=0;
            for (g=0;g<n;g++)
                if (b[j][g]>=0)
                    pa[j]=pa[j]||b[j][g];
        }
        res=1;
        for (j=0;j<m;j++)
            res=pa[j]&&res;
        if (res)
        {
            printf("\n");
            interpret(c,&s,pb,n);
        }
        bin_vect(pb,n);
    }
}

void interpret (int **c, int *s,int *pb, int n,int f)
{
    int i,j,k=pow(3,n),t,p=0;
    int *pc=(int*)calloc(n,sizeof(int)); //для интерпретаций
    for (i=0;i<n;i++)
        pc[i]=-1;
    for (i=0;i<k;i++)
    {
        for (j=0;j<n;j++)
        {
            if (pc[j]==-1)
                t=!pb[j];
            if (pc[j]==1)
                t=pb[j];
            if (pc[j]==0)
                t=0;
            p=p||t;
        }
        if (p)
        {
            if (search(pc,c,n,*s))
            {
                for (j=0;j<n;j++)
                    c[*s][j]=pc[j];
                (*s)++;
                outputvect(pc,n);
            }
        }
        vect(pc,n);
        p=0;
    }
}

void bin_vect (int *a, int n)
{
    int i,j=1,fl=a[n-1];
    i=n-1;
    a[i]=!a[i];
    i--;
    if (fl)
    {
        if (a[i]==0)
        {
            a[i]=1;
            i--;
        }
        else
        {
            while (a[i]==1 && i>=0)
            {
                a[i]=0;
                i--;
            }
            a[i]=1;
        }
    }
}

void vect (int *a, int n)
{
    int i,j=1,fl=1;
    i=n-1;
    if (a[i]!=1)
    {
        a[i]+=1;
        return;
    }
    a[i]=-1;
    i--;
    while (fl&&i>=0)
    {
        if(a[i]!=1)
        {
            a[i]+=1;
            fl=0;
        }
        else
            a[i]=-1;
        i--;
    }
}

void output (int **p, int n, int s)
{
    int i,j,f=0;

    for (i=0;i<s;i++)
    {
        f=0;
        for (j=0;j<n;j++)
        {
            if (p[i][j]==-1)
            {
                if (f)
                    printf ("| ");
                else
                    f=1;
                printf ("-%c ",'A'+j);
            }

            if (p[i][j]==1)
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

}

void outputvect (int *p, int n)
{
    int i,j,f=0;
    f=0;
    for (j=0;j<n;j++)
    {
        if (p[j]==-1)
        {
            if (f)
                printf ("| ");
            else
                f=1;
            printf ("-%c ",'A'+j);
        }
        if (p[j]==1)
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

//возвращает 1, если можно записать строку в матрицу
int search (int *pc, int **a, int n, int s)
{
    if (s==0)
        return 1;
    int i,j,fl=1;
    for (i=0;i<s&&fl;i++)
        for (j=0;j<n&&fl;j++)
            fl=(a[i][j]==pc[j]);

    return !fl && j<n;
}
