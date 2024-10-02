#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

typedef struct
{
    int x,y;
}t_struct;

int main()
{
    setlocale(LC_ALL, "Rus");
    int i,n1=9,n2=13;

    int **m1;
    m1=(int **)calloc(n1,sizeof(int*));
    for (i=0;i<n1;i++)
        m1[i]=(int *)calloc(n1,sizeof(int));
    int **m2;
    m2=(int **)calloc(n2,sizeof(int*));
    for (i=0;i<n2;i++)
        m2[i]=(int *)calloc(n2,sizeof(int));
    t_struct a1[n1],a2[n2];

    formt(a1,a2);   printf ("\nчто-то");
    formR(m1,a1,n1);   printf ("\nздесь");
    formR(m2,a2,n2);   printf ("\nидет");
    output(m1,n1);
    f_max(m1,n1,a1);
    f_min(m1,n1,a1);
    i=f_b(m1,n1);
    check (m1,n1);
    if(i>=0)
        printf ("\nНаибольший элемент M1  %d",i);
    else
        printf ("\nНаибольшего элемента в М1 нет");
    i=f_sm(m1,n1);
    if(i>=0)
        printf ("\nНаименьший элемент M1  %d",i);
    else
        printf ("\nНаименьшего элемента в М1 нет");

    output(m2,n2);
    f_max(m2,n2,a2);
    f_min(m2,n2,a2);
    i=f_b(m2,n2);
    check (m2,n2);
    if(i>=0)
        printf ("\nНаибольший элемент M2  %d",i);
    else
        printf ("\nНаибольшего элемента в М2 нет");
    i=f_sm(m2,n2);
    if(i>=0)
        printf ("\nНаименьший элемент M2  %d",i);
    else
        printf ("\nНаименьшего элемента в М2 нет");

    arefl(m1,n1);
    arefl(m2,n2);
    dom (m1,n1); printf ("\nне");
    dom (m2,n2);
    output(m1,n1);
    output(m2,n2);
    int w1[n1],w2[n2];
    printf ("\nM1\n");
    topsort(m1,w1,n1);
    printf ("\nM2\n");
    topsort(m2,w2,n2);




}
/*
void arefl (int **a, int n)
{
    int x;
    for (x=0;x<n;x++)
        a[x][x]=0;
}
*/
void output (int **a, int n)
{
    int x,y;
    printf("\n");
    for (x=0;x<n;x++)
    {
        for (y=0;y<n;y++)
            printf ("%d  ",a[x][y]);
        printf("\n");
    }
}

void dom (int **a, int n)
{
    int x,y,z;
    for (x=0;x<n;x++)
        for(y=0;y<n;y++)
            for (z=x+1;z<y;z++)
            {
                if (a[x][z]&&a[z][y])
                    a[x][y]=0;
            }
}
void formt (t_struct *a1, t_struct *a2)
{
    int x,y,i=0;
    for (x=-1;x<2;x++)
        for (y=-1;y<2;y++)
        {
            a1[i].x=x;
            a1[i].y=y;
            i++;
        }

    a2[0].x=-2;  a2[0].y=0;
    a2[1].x=-1;  a2[1].y=-1;
    a2[2].x=-1;  a2[2].y=0;
    a2[3].x=-1;  a2[3].y=1;
    a2[4].x=0;   a2[4].y=-2;
    a2[5].x=0;   a2[5].y=-1;
    a2[6].x=0;   a2[6].y=0;
    a2[7].x=0;   a2[7].y=1;
    a2[8].x=0;   a2[8].y=2;
    a2[9].x=1;   a2[9].y=-1;
    a2[10].x=1;  a2[10].y=0;
    a2[11].x=1;  a2[11].y=1;
    a2[12].x=2;  a2[12].y=0;

}
void formR (int **m,t_struct *a,int n)
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            if ((a[i].x-a[j].x) < (a[j].y-a[i].y))
                m[i][j]=1;
}

void topsort (int **m, int *w, int n)
{
    int x,y,lvl = 0;

    for (x=0;x<n;x++)
    {
        w[x]=0;
        for (y=0;y<n;y++)
            w[x]+=m[x][y];
    }

	while (empty(w,n))
    {
		printf("\nУровень %d: { ", lvl);
		lvl++;
		for (x=0;x<n;x++)
			if (w[x] == 0)
			{
				printf("%i ", x+1);
				w[x] = -1;
			}
		printf("}\n");

		for (x=0;x<n;x++)
			if (w[x] == lvl)
				w[x] = 0;

	}


}

int empty (int *w, int n)
{
    int i=0;
    while (i<n && w[i]<0)
        i++;
    return (i<n);
}
//наибольший элемент
int f_b (int **m, int n)
{
    int x,y;
    for (x=0;x<n;x++)
        if (search (m[x],n))
            return x;
    return -1;
}
//наименьший
int f_sm (int **m, int n)
{
    int x,y;
    for (y=0;y<n;y++)
        for (x=0;x<n;x++)
        {
            if (!m[x][y])
                break;
            if (x==n-1)
                return y;
        }
    return -1;
}

int f_max (int **m, int n, t_struct*a)
{
    int x,b,fl=1;
    for (b=0;b<n;b++)
    {
        for (x=0;x<n && fl;x++)
        {
            fl=(m[x][b]||(!m[x][b]&&!m[b][x]));
            if (x==n-1 && fl)
                printf ("\nMax = (%d,%d)",a[b].x,a[b].y);
        }
        fl=1;
    }
    return -1;
}
int f_min (int **m, int n,t_struct *a)
{
    int x,b,fl=1;
    for (b=0;b<n;b++)
    {
        for (x=0;x<n && fl;x++)
        {
            fl=(m[b][x]||(!m[x][b]&&!m[b][x]));
            if (x==n-1 && fl)
                printf ("\nMin = (%d,%d)",a[b].x,a[b].y);
        }
        fl=1;
    }

    return -1;
}

int search (int *s, int n)
{
    int i=0;
    while (i<n && s[i])
        i++;
    return (i==n);
    //если i=n, то все нули
}

//проврка на равенство
int equal (int **a, int **b, int N)
{
    int x,y,f=1;
    for (x=1;(x<N)&&(f);x++)
        for (y=1;(y<N)&&(f);y++)
            f=(a[x][y]==b[x][y]);
    return f;
}
//проверка на включение
int incl (int **a, int **b, int N)
{
    int x,y,f=1;
    for (x=1;(x<N)&&(f);x++)
        for (y=1;(y<N)&&(f);y++)
            f=(a[x][y]<=b[x][y]);
    return f;
}
//объединение
void unit (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=a[x][y] || b[x][y];
}

//пересечение
void cross (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=a[x][y] && b[x][y];
}

//разность
void subs (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y] = a[x][y] > b[x][y];
}

//симметрическая разность
void symm_subs (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y] = (a[x][y]>b[x][y]) || (b[x][y]>a[x][y]);
}

//дополнение
void add (int **a,int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=!a[x][y];
}

//обращение
void resort (int **a,int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=a[y][x];
}

//композиция
void compose (int **a,int **b, int **res, int N)
{
    int x, y, z;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
        {
            res[x][y]=0;
            for(z=1;z<N;z++)
                res[x][y]=res[x][y] || a[x][z] && b[z][y];
        }
}
/*
void output (int **a, int n)
{
    int x,y;
    for (x=1;x<n;x++)
    {
        for (y=1;y<n;y++)
            printf ("%d  ",a[x][y]);
        printf("\n");
    }
}
*/
void clear (int **a, int n)
{
    int x,y;
    for (x=0;x<n;x++)
        for (y=0;y<n;y++)
            a[x][y]=0;
}

//рефлексивность
int refl (int **a, int N)
{
    int i;
    for (i=1;i<N && a[i][i];i++);
    if (i==N)
        printf ("\nОтношение рефлексивно\n");
    else
        printf ("\nОтношение не рефлексивно\n");
    return (i==N);
}
//антирефлексивность
int arefl (int **a, int N)
{
    int i;
    for (i=1;i<N && !a[i][i];i++);

    if (i==N)
        printf ("\nОтношение антирефлексивно\n");
    else
        printf ("\nОтношение не антирефлексивно\n");
    return (i==N);
}
//симметричность
int simm (int **a, int N)
{
    int x,y,fl=1;
    for (x=1;x<N && fl;x++)
        for (y=x+1;y<N && fl;y++)
            fl=a[x][y]==a[y][x];
    if (fl)
        printf ("\nОтношение симметрично\n");
    else
        printf ("\nОтношение не симметрично\n");
    return fl;
}
//антисимметричность
int asimm (int **a, int N)
{
    int x,y,fl=1;
    for (x=1;x<N-1 && fl;x++)
        for (y=x+1;y<N && fl; y++)
        {
            if (a[x][y]==0)
                fl=1;
            else
            fl= a[x][y]!=a[y][x];
        }

    if (fl)
        printf ("\nОтношение антисимметрично\n");
    else
        printf ("\nОтношение не антисимметрично\n");
    return fl;
}
//транзитивность
int tranz (int **a, int N)
{
    int x,y,z,fl=1;
    for (x=1;x<N && fl;x++)
        for (y=1;y<N && fl;y++)
            for(z=1;z<N && fl;z++)
                fl=!((a[x][z]&&a[z][y]))||a[x][y];
    if (fl)
        printf ("\nОтношение транзитивно\n");
    else
        printf ("\nОтношение не транзитивно\n");
    return fl;
}

//антитранзитивность
int atranz (int **a, int N)
{
    int x,y,z,fl=1;
    for (x=1;x<N && fl;x++)
        for (y=1;y<N && fl;y++)
            for(z=1;z<N && fl;z++)
                fl=((a[x][z]&&a[z][y]))||a[x][y];
    if (fl)
        printf ("\nОтношение антитранзитивно\n");
    else
        printf ("\nОтношение не антитранзитивно\n");
    return fl;
}

//полнота
int poln (int **a, int N)
{
    int x,y,fl=1;
    for (x=1;x<N && fl;x++)
        for (y=x+1;y<N && fl;y++)
            fl = (a[x][y] || a[y][x]);
    if (fl)
        printf ("\nОтношение полно\n");
    else
        printf ("\nОтношение не полно\n");
    return fl;
}
int check (int **a, int N)
{
    int r,t,s,ar,as,at,p;
    r=refl(a,N);
    ar=arefl(a,N);
    s=simm(a,N);
    as=asimm(a,N);
    t=tranz(a,N);
    at=atranz(a,N);
    p=poln(a,N);
    if(s&&r)
        printf ("\nОтношение толерантности\n");
    if (r&&s&&t)
        printf("\nОтношение эквивалентности\n");
    if (as&&t)
        printf("\nОтношение порядка\n");
    if (as&&t&&r)
        printf("\nОтношение нестрогого порядка\n");
    if (as&&t&&ar)
        printf("\nОтношение строгого порядка\n");
    if (as&&t&&p)
        printf("\nОтношение линейного порядка\n");
    if (as&&t&&r&&p)
        printf("\nОтношение нестрогого линейного порядка\n");
    if (as&&t&&ar&&p)
        printf("\nОтношение строгого линейного порядка порядка\n");
}
