#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void form_end_sub (float **a, int n, float x);
void form_div_sub (float **b, int n, float x);

void main ()
{
    setlocale(LC_ALL,"Rus");
    int i,j,n,k;
    float x;
    char name[]="2.txt";
    printf ("n = ");
    scanf ("%d",&n);
    printf ("x = ");
    scanf ("%f",&x);
    n++;
    float **a;
    a=(float **)calloc(n,sizeof(float*));
    for (i=0;i<n;i++)
        a[i]=(float*)calloc(n+1,sizeof(float));
    printf ("\nВвод данных из файла = 1\nВвод данных с клавиатуры = 2\n");
    scanf ("%d",&k);
    if (k==2)
        read_root(a,n);
    else
        read_root_f (a,n,name);
   /* if (check_x(a,n))
    {
        form_end_sub(a,n,x);
        printf ("Какую строку удалить? ");
        scanf ("%d",&j);

        for (i=j;i+1<n;i++)
        {
            a[i][0]=a[i+1][0];
            a[i][1]=a[i+1][1];
        }
        n--;
    }
    */
    form_div_sub(a,n,x);
}

void read_root_f (float **a, int n, char *name)
{
    FILE *f;
    f=fopen(name,"r+b");
    int i;
    for (i=0;i<n;i++)
    {
        fscanf(f, "%f",&a[i][0]); printf ("x[%d] = %f\n",i,a[i][0]);
        fscanf(f, "%f",&a[i][1]); printf ("y[%d] = %f\n",i,a[i][1]);
    }
}

void read_root (float **a, int n)
{
    int i;
    for (i=0;i<n;i++)
    {

        printf("\nx[%d]= ",i);
        scanf("%f",&a[i][0]);
        printf("\ny[%d]= ",i);
        scanf("%f",&a[i][1]);
    }
    printf("\n");
}

void form_end_sub (float **a, int n, float x)
{
    int i,j,m,nn,b,c;
    float q,t,q1,t1,In,f=1;
    m=n+1;
    nn=n-1;
    for (j=2;j<m;j++,nn--)
        for (i=0;i<nn;i++)
            a[i][j]=(float)(a[i+1][j-1]-a[i][j-1]);

    if (fabs(a[0][0] - x) > fabs(a[n-1][0]-x))
        //ближе к нижней границе
    {
        q=(float)((x-a[n-1][0])/(n-1));
        q1=q;
        In=a[n-1][1];
        for(i=n-2,j=2;i>0;i--,j++)
        {
            In+=(float)(a[i][j]*q1*f);
            q+=1;
            q1*=q;
            f/=i;
        }
    }
    else
    {
        t=(float)((x-a[0][0])/(a[1][0]-a[0][0]));
        t1=t;
        In=a[0][1];
        for(i=2,j=1;i<n+1;i++,j++)
        {
            In+=(float)(a[0][i]*t1*f);
            t-=1;
            t1*=t;
            f/=j;
        }
    }
    printf ("\nIn = %f\n",In);
}

void form_div_sub (float **a, int n, float x)
{
    int i, j,k,t;
    float y,s=1,In;
    k=n+1;
    for (j=2,t=1;j<k;j++,t++)
        for (i=0;i<n-j+1;i++)
            a[i][j]=(float)((a[i+1][j-1]-a[i][j-1])/(a[i+t][0]-a[i][0]));
    In = a[0][1];
    for (j=2;j<k;j++)
    {
        y=x-a[j-2][0];
        s=s*y;
        In+=(float)(a[0][j]*s);
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<=n;j++)
            printf ("%.4f   ",a[i][j]);
        printf ("\n");
    }


    printf ("\nIn = %f\n",In);
}

int check_x (float **a, int n)
{
    int i,fl=1;
    for  (i=0;i<n-2 && fl;i++)
        fl=(fabs(fabs(a[i+1][0]-a[i][0]) - fabs(a[i+2][0]-a[i+1][0]))<0,0001);
    return fl;
}

