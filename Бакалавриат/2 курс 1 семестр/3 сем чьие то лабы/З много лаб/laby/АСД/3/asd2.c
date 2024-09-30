#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

#define N 4500
void Sift(int A[],int L,int R);
int main()
{
    double start, end, s;
    setlocale(LC_ALL,"Rus");
    int a[N];
/*
    form(a,1);
    start=clock();
    Sis(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeSis = %f\n",s);

    form(a,3);
    start=clock();
    StrSel(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeStrSel = %f\n",s);

    form(a,3);
    start=clock();
    BblSort(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeBBl = %f\n",s);

    form(a,3);
    start=clock();
    BblSort1(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeBBl1 = %f\n",s);

    form(a,3);
    start=clock();
    BblSort2(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeBBl2 = %f\n",s);

    form(a,3);
    start=clock();
    ShellSort(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeShell = %f\n",s);
*/
    form(a,3);
    start=clock();
    HoarSort(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeHoar = %f\n",s);

    form(a,2);
    start=clock();
    HoarSort(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeHoar = %f\n",s);
/*
    form(a,3);
    start=clock();
    HeapSort(a,N);
    end=clock();
    s=((double) end - start) / ((double) CLOCKS_PER_SEC);
    printf ("timeHeap = %f\n",s);
*/

    int i;
  /*  for (i=1;i<10;i++)
    {
        N=500*i;
        form(a,1);
        start=clock();
        HoarSort(a,N);
        end=clock();
        s=((double) end - start) / ((double) CLOCKS_PER_SEC);
        printf ("timeHoar = %f\n",s);
    }
    for (i=1;i<10;i++)
    {
        N=500*i;
        form(a,2);
        start=clock();
        HoarSort(a,N);
        end=clock();
        s=((double) end - start) / ((double) CLOCKS_PER_SEC);
        printf ("timeHoar = %f\n",s);
    }
    for (i=1;i<10;i++)
    {
        N=500*i;
        form(a,3);
        start=clock();
        HoarSort(a,N);
        end=clock();
        s=((double) end - start) / ((double) CLOCKS_PER_SEC);
        printf ("timeHoar = %f\n",s);
    }

*/


}

void form (int a[], int k)
{
    int i;
    switch (k)
    {
    case 1:
        srand(N);
        for (i=0;i<N;i++)
            a[i]=rand();

        break;
    case 2:
        for (i=0;i<N;i++)
            a[i]=i;
    case 3:
        for (i=0;i<N;i++)
            a[i]=N-i;
    }

}

/*============СОРТИРОВКА ВКЛЮЧЕНИЕМ=============*/

/* функция сортировки включением  */
void Sis(int A[],int nn)
{
    int i,j,k;
    for ( j=1; j<nn; j++ )
    {
        k = A[j];
        i = j -1;
        while ( k < A[i] && i >= 0)
		{
            A[i+1] = A[i];
			i -= 1;
        }
        A[i+1] = k;
    }
}

/*==============СОРТИРОВКА ВЫБОРОМ===============*/

/*функция сортировки выбором  */
void StrSel(int A[],int nn)
{
    int i,j,x,k;
    for ( i=0; i<nn-1; i++ )
    {
        x = A[i]; k = i;
        for (j=i+1; j<nn; j++)
            if (A[j] < x)
            {
                k = j;
                x = A[k];
            }
	  A[k] = A[i];
	  A[i] = x;
    }
}

/*============СОРТИРОВКА ОБМЕНОМ=============*/

/*  функция сортировки обменом  */
void BblSort(int A[],int nn)
{
    int i,j,k;
    for ( i=0; i<nn-1; i++ )
    {
        for (j=nn-1; j>i; j--)
        if (A[j] <A[j-1])
        {
            k = A[j];
            A[j] = A[j-1];
            A[j-1] = k;
        }
  }
}

void BblSort1(int A[],int nn)
{
    int i,j,k,p;
    for ( i=0; i<nn-1; i++ )
    {
        p = 0;
        for (j=nn-1; j>i; j--)
        if (A[j] <A[j-1])
        {
            k = A[j];
            A[j] = A[j-1];
            A[j-1] = k;
            p = 1;
        }
      /* Если перестановок не было, то сортировка выполнена */
	 if (p == 0)
	break;
  }
}

void BblSort2(int A[],int nn)
{
    int i,j,k,p,q;
    for ( i=0; i<nn-1; i=q )
    {
        p = 0;
        for (j=nn-1; j>i; j--)
        if (A[j] <A[j-1])
        {
            k = A[j];
            A[j] = A[j-1];
            A[j-1] = k;
            p = 1;
            q=j-1;
        }
      /* Если перестановок не было, то сортировка выполнена */
	 if (p == 0)
	break;
  }
}

/*============СОРТИРОВКА МЕТОДОМ ШЕЛЛА=============*/

/* функция сортировки методом Шелла */
void ShellSort(int a [], int n)
{
    int i,j,k,hh,t,s;
    int h [1000];
    t = round(log(n)/log(3))-1;
    if (t < 1)
        t = 1;
    h[t] = 1;
    for (k=t; k >= 1; k--) {
	  h[k-1] = 3*h[k]+1;
	 // printf ("\n%d",h[k-1]);
    }

    for (s=t-1;s>=0;s--)
    {
    //    printf ("\nестьконтакт s = %d",s);
        hh = h[s];
      //          printf ("\nестьконтакт hh = %d",hh);
        for (j = hh;j<=n;j++)
        {
        //    printf ("\nестьконтакт j = %d",j);
            i = j-hh;
            k = a[j];
            while ((k <= a[i])&&(i >= 0))
            { //printf ("\nестьконтакт i = %d",i);
                a[i+hh] = a[i];
                i = i-hh;
            }
            a[i+hh] = k;
        }
    }
}

/*============СОРТИРОВКА МЕТОДОМ ХОАРА=============*/


void QSort(int a [], int L, int R)
{
    int x = a[L], i = L, j = R, t; // в качестве разделителя выбираем первый элемент
    while (i<=j)
    {
        while (a[i]<x)
            i++;
        while (a[j]>x)
            j--;
        if (i<=j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (L<j)
        QSort(a,L,j);
    if (i<R)
        QSort(a,i,R);
}
/*функция сортировки методом Хоара*/
void HoarSort(int a[], int n)
{
  QSort(a,1,n);
}
/*============ПИРАМИДАЛЬНАЯ СОРТИРОВКА=============*/

/* пирамидальная функция сортировки  */
void HeapSort(int A[],int nn)
{
    int L,R,x,i;
	L = nn/2 ; R = nn-1;
 /*  Построение пирамиды из исходного массива */
	while ( L>0 )
    {
        L = L - 1;
		Sift(A,L,R);
    }
 /* Сортировка: пирамида => отсортированный массив */
	while ( R>0 )
    { x = A[0]; A[0] = A[R]; A[R] = x;
		R--;
		Sift(A,L,R);
    }
}
/* ============================================ */
void Sift(int A[],int L,int R)
{
    int i,j,x,k;
    i = L;
    j = 2*L+1;
    x = A[L];
    if ((j<R) && (A[j]<A[j+1]))
        j++;
    while ((j<=R) && (x<A[j]))
    {
        k=A[i]; A[i] = A[j];  A[j]=k;
        i = j;
        j = 2*j+1;
        if ((j<R) && (A[j]<A[j+1]))
            j++;
    }
}
/* ***************************************************** */

