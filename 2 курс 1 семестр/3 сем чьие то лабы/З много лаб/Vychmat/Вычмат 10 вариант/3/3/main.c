#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float It;

int main()
{
    setlocale (LC_ALL, "Rus");
//    char s1[]="1.txt", s2[]="2.txt", s3[]="3.txt";
    float x0,xn,h1,h2,Ih1,Ih2;
    int n,k=1,m,i;
    printf ("\nВыберите формулу вычисления:\nФормула центральных треугольников - 1\nФормула трапеций - 2 \nФормула парабол - 3\n");
    scanf ("%d",&k);
    printf ("\nn = ");
    scanf ("%d",&n);
    if (k==1)
        m=2*n;
    else
    {
        m=2*n+1;// printf ("%d ",m);
        n++;
    }

    float **a;
    a=(float **)calloc(n,sizeof(float*));
    for (i=0;i<n;i++)
        a[i]=(float*)calloc(2,sizeof(float));
   // m=2*n;
    float **b;
    b=(float **)calloc(m,sizeof(float*));
    for (i=0;i<m;i++)
        b[i]=(float*)calloc(2,sizeof(float));
    printf ("Верхний предел :  ");
    scanf ("%f",&xn);
    //printf ("%f\n",*x);
        //нижний предел
    printf ("Нижний предел :  ");
    scanf ("%f",&x0); //*x1=x0;
    //printf ("%f\n",x0);

    input (a,b,n,m,&It);
    h1=(float)((xn-x0)/(n-1));  printf ("\nh1 = %f  \nxn = %f\nx0 = %f", h1,xn,x0);
    h2=(float)((xn-x0)/(m-1));  printf ("\nh2 = %f  \n", h2);
    printf ("It = %f",It);
                   // par(a,n,h1,&Ih1);
                   // par(b,m,h2,&Ih2);
                   // pr_run(Ih1, Ih2,2);

    switch (k)
        {
            case 1: printf ("It = %f",It);
                    centr_tr(a,n,h1,&Ih1);
                    centr_tr(b,m,h2,&Ih2);
                    pr_run(Ih1, Ih2,2);
                    break;
            case 2: trap(a,n,h1,It,&Ih1);
                    trap(b,m,h2,It,&Ih2);
                    pr_run(Ih1, Ih2,2);
                    break;
            case 3: printf ("It = %f",It);
                    par(a,n,h1,&Ih1);
                    par(b,m,h2,&Ih2);
                    pr_run(Ih1, Ih2,2);
                    break;
           /* case 4: printf ("n = ");
                    scanf ("%d",&n);
                    m=n*2;
                    input (a,b,n,m,&x0,&xn);
                    h1=(xn-x0)/n;
                    h2=(xn-x0)/m;
                    break;
            */
     //   }
    }
}

void pr_run (float Ih1, float Ih2,int p)
{
    float x;
    x=fabs(Ih1-Ih2)/(pow(2,p)-1);
    printf ("%f",x);
}

void input (float **a, float **b, int n,int m)
{
    int i,j,k;
    //float x0,xn;
    printf ("\nВвод с клавиатуры - 1\nВвод из файла - 0\n");
    scanf ("%d",&k);
    if (k)
    {
        /*
        printf ("Введите верхний предел  ");
        scanf ("%f",&xn);
        printf ("Введите нижний предел  ");
        scanf ("%f",&x0);
        *x=x0;
        *x1=xn;
        */
        scanf ("%f",&It);
        for (i=0;i<n;i++)
        {
            printf("\nx[%d]= ",i);
            scanf("%f",&a[i][0]);
            printf("\ny[%d]= ",i);
            scanf("%f",&a[i][1]);
        }
        for (i=0;i<m;i++)
        {
            printf("\nx[%d]= ",i);
            scanf("%f",&b[i][0]);
            printf("\ny[%d]= ",i);
            scanf("%f",&b[i][1]);
        }
    }
    else
    {
       // printf ("\nВведите имя файла\n");
        char s[]="par1.txt";
        //scanf ("%s",s);
        FILE *f;
        f=fopen(s,"r+b");
        //Верхний предел

      //  float I;
        fscanf (f,"%f",&It);
        //*It=I;
        printf ("\nТочное значение: %f\n", It);

        for (i=0;i<n;i++)
        {
            fscanf(f, "%f",&a[i][0]); printf ("x[%d] = %f\n",i,a[i][0]);
            fscanf(f, "%f",&a[i][1]); printf ("y[%d] = %f\n",i,a[i][1]);
        }
        printf ("\n\n");
        for (i=0;i<m;i++)
        {
            fscanf(f, "%f",&b[i][0]); printf ("x[%d] = %f\n",i,b[i][0]);
            fscanf(f, "%f",&b[i][1]); printf ("y[%d] = %f\n",i,b[i][1]);
        }
        fclose(f); //printf ("\nvsenorm\n");
    }

    //printf ("\nvsenorm\n");
}

void centr_tr (float **a, int n, float h, float *s)
{
    float sum=0,d1,d2;
    int i;
    printf ("\n%f\n",It);
    for (i=0;i<n;i++)
        sum+=(float)(a[i][1]);
    printf ("\nIt = %f\nIпр = %f\nh = %f\n",It,sum,h);
    sum=(float)(sum/h);
    d1=fabs(It-sum);
    d2=(float)(d1/It*100);
    printf ("\nIt = %f\nIпр = %f\nd1 = %f\nd2 = %f\n",It,sum,d1,d2);
    *s=sum;;
}

void trap (float **a, int n, float h, float *s)
{
    float sum=0,d1,d2;
    int i,j;
    for (i=1;i<n-1;i++)
        sum+=a[i][1];
    sum=sum+a[0][1]+a[n-1][1];
    sum=sum*h/2;
    d1=fabs(It-sum);
    d2=d1/It*100;
    printf ("\nIt = %f\nIпр = %f\nd1 = %f\nd2 = %f\n",It,sum,d1,d2);
    *s=sum;
}

void par (float **a, int n, float h, float *s)
{
    float sum=0,d1,d2;
     printf ("\nsum = %f  \n", sum);
    int i;
    for (i=1;i<n-1;i++)
    {
        if (i%2==1){
            sum=(float)(sum+4*a[i][1]); printf ("\n%f  %f\n", a[i][1], sum);
        }
        else{
            sum=(float)(sum+2*a[i][1]); printf ("\n%f  %f\n", a[i][1], sum);
        }
    }
    sum+=a[0][1]+a[n-1][1];  printf ("\nsum = %f  \n", sum);
    sum=(float)(sum*h/3);  printf ("\nsum = %f  \n", sum);  printf ("\nh = %f  \n", h);
    d1=fabs(It-sum);
    d2=(float)(d1/It*100);
    printf ("\nIt = %f\nsum = %f\nd1 = %f\nd2 = %f\n",It,sum,d1,d2);
    *s=sum;
}
