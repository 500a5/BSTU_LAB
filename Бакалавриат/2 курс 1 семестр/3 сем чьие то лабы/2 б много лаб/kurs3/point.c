#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#define EPS 0.00001
#include "inout.h"

float *urav (tochka *t, int nom, size_t n)
// Возвращает массив коэффициентов уравнения плоскости Ax+By+Cz+D;
{
    float *koef = (float*)calloc(4, sizeof(float));
    float yz = (t[nom+1].y-t[nom].y)*(t[nom+2].z-t[nom].z);
    float zy = (t[nom+1].z-t[nom].z)*(t[nom+2].y-t[nom].y);
    float zx = (t[nom+1].z-t[nom].z)*(t[nom+2].x-t[nom].x);
    float xz = (t[nom+1].x-t[nom].x)*(t[nom+2].z-t[nom].z);
    float xy = (t[nom+1].x-t[nom].x)*(t[nom+2].y-t[nom].y);
    float yx = (t[nom+1].y-t[nom].y)*(t[nom+2].x-t[nom].x);
    koef[0] = yz - zy; //A
    koef[1] = zx - xz; //B
    koef[2] = xy - yx; //C
    koef[3] = -(t[nom].x)*yz-(t[nom].y)*zx-(t[nom].z)*xy+(t[nom].z)*yx+(t[nom].y)*xz+(t[nom].x)*zy; //D
    return koef;
}




int check (tochka *t, size_t n, float *koef)
// Возвращает 1, если точки лежат в одной плоскости и 0 в противном случае.
{
    int i=0;
    while (i<n)
    { //Ax+By+Cx+D=0
        if ((((koef[0]*t[i].x)+(koef[1]*t[i].y)+(koef[2]*t[i].z)+koef[3])) < EPS)
            i++;
        else
            return 0;
    }
    return 1;
}

/*	Если A=0, то плоскость параллельна оси Ox;
	Если B=0, то плоскость параллельна оси Oy;
	Если C=0, то плоскость параллельна оси Oz;*/


int orientation (float *koef, size_t n)
{ //Ax+By+Cz+D=0 = koef
    int i=0;
    if (koef[0]!=0) // yz
        return 0;
    if(koef[1]!=0) // остаются xz
        return 1;
    if(koef[2]!=0) // остаются xy
        return 2;
    return 0;
}

void toch_new (int or, tochka *t, tochka_xy *p, size_t n)
{// Производит перезапись массива точек t размера n в массив точек p размера n в зависимости от значение or.
    int i;
    switch (or)
    {
    case 0:
        {
            for (i=0; i<n; i++)
            {
                p[i].xn = t[i].y;
                p[i].yn = t[i].z;
            }
            break;
        }
    case 1:
        {
            for (i=0; i<n; i++)
            {
                //p[i].xn = t[i].z;
               // p[i].yn = t[i].x;
                p[i].xn = t[i].x;
                p[i].yn = t[i].z;
            }
            break;
        }
    case 2:
        {
            for (i=0; i<n; i++)
            {
                p[i].xn = t[i].x;
                p[i].yn = t[i].y;
            }
            break;
        }
    }
}

int x_min (tochka_xy *t, size_t n)
// Возвращает точку с минимальной координатой x и y.
{
    int i=0;
    char nom = 0;
    float xmin = t[nom].xn;
    float ymin = t[nom].yn;
    for (i=0; i < n; i++)
    {
        if (t[i].xn < xmin)
        {
            xmin = t[i].xn;
            ymin = t[i].yn;
            nom = i;
        }
        if (t[i].xn == xmin)
        {
            if (t[i].yn < ymin)
            {
                xmin = t[i].xn;
                ymin = t[i].yn;
                nom = i;
            }
        }
    }
    return nom;
}

int x_max (tochka_xy *t, size_t n)
//Возвращает точку с максимальной координатой x и y.
{
    int i=0;
    char nom = 0;
    float xmax = t[nom].xn;
    float ymax = t[nom].yn;
    for (i=0; i < n; i++)
    {
        if (t[i].xn > xmax)
        {
            xmax = t[i].xn;
            ymax = t[i].yn;
            nom = i;
        }
        if (t[i].xn == xmax)
        {
            if (t[i].yn > ymax)
            {
                xmax = t[i].xn;
                ymax = t[i].yn;
                nom = i;
            }
        }
    }
    return nom;
}

void swap_xy(int i, int j, tochka_xy *tn)
//Обмен i и j точек массива точек tn местами (для плоскости).
{
    tochka_xy t = tn[i];
    tn[i] = tn[j];
    tn[j] = t;
}

void swap_t(int i, int j, tochka *tn)
//Обмен i и j точек массива точек tn местами (в пространстве).
{
    tochka t = tn[i];
    tn[i] = tn[j];
    tn[j] = t;
}

float* abc_xy(tochka_xy tmin, tochka_xy tmax) //-
//Записывает по адресу k и b коэффициенты уравнения kx+b=y для минимальной и максимальной точек.
{
    float *abc = (float*)calloc(3, sizeof(float));
    abc[0] = tmax.yn - tmin.yn;// A
    abc[1] = tmax.xn - tmin.xn;// B
    //abc[2] = -tmin.xn * abc[0] + tmin.yn * abc[1];
    abc[2] = tmin.xn * abc[0] + tmin.yn * abc[1];

    /*k = abc[0]/abc[1];
    b = abc[2]/abc[1]; */

    return abc;
}

int compare_xy(tochka_xy t1, tochka_xy t2, float *abc)
{
    if ((t1.xn == t2.xn) * (t1.yn == t2.yn)) //Если точки одинаковы
        return 0;

    //Если обе точки лежат под прямой
   if ((t1.xn*(abc[0]/abc[1]) + (abc[2]/abc[1]) <= t1.yn)
       && (t2.xn*(abc[0]/abc[1]) + (abc[2]/abc[1]) <= t2.yn))
        return !((t1.xn >= t2.xn ) || (t1.xn == t2.xn )&& (t1.yn < t2.yn));

    //если первая и вторая точка лежат над прямой
    if ((t1.xn*(abc[0]/abc[1]) + (abc[2]/abc[1]) >= t1.yn)
         && (t2.xn*(abc[0]/abc[1]) + (abc[2]/abc[1]) >= t2.yn)) //если обе точки лежат над прямой
        return !((t1.xn <= t2.xn ) || (t1.xn == t2.xn )&& (t1.yn < t2.yn)); //и по иксу и по игрику

    return t1.xn*(abc[0]/abc[1])+(abc[2]/abc[1]) <= t1.yn;
}

void sort_vst (tochka_xy *tn, tochka *pn, size_t n, float *abc)
//Сортировка ВСТАВКАМИ точек массивов tn и pn размерами n в зависимости от коэффициентов уравнения kx+b=y.
{
    int i, j;
    for(i=1; i<n; i++)
    //for(i=2; i<n; i++)
        for(j=i; (j>0) && (compare_xy(tn[j-1], tn[j], abc)); j--)
        //for(j=i; (j>1) && (compare_xy(tn[j-1], tn[j], abc)); j--)
        {
            swap_xy(j-1, j, tn);
            swap_t(j-1, j, pn);
           // output_xy(tn, n);
        }
}


void sort_vst2 (tochka_xy *tn, tochka *pn, size_t n, float *abc)
//Сортировка ВСТАВКАМИ точек массивов tn и pn размерами n в зависимости от коэффициентов уравнения kx+b=y.
{
    int i, j;
    for(i=1; i<n; i++){
    //for(i=2; i<n; i++)
    j=i;
    while((j>0) && (compare_xy(tn[j-1], tn[j], abc)))

        //for(j=i; (j>1) && (compare_xy(tn[j-1], tn[j], abc)); j--)
        {
            swap_xy(j-1, j, tn);
            swap_t(j-1, j, pn);
           // output_xy(tn, n);
           j--;
        }
    }
}


void sortt (tochka_xy *pn, tochka *tn, size_t n, float *abc)
{
    int i, j, k;
    printf("%.2f, %.2f, %.2f", abc[0], abc[1], abc[2]);
    tochka t;
    tochka_xy p;
    for (i=0; i<n; i++)
    {
        k=i;
        p = pn[i];
        t = tn[i];
        for (j=j+1; j<n; j++)
            if (compare_xy(pn[j], p, abc))
            {
                k=j;
                p=pn[j];
                t=tn[j];
            }
        pn[k] = pn[i];
        pn[i] = p;
        tn[k] = tn[i];
        tn[i] = t;
    }
}

/*void selectSort(T a[], long size) {
  long i, j, k;
  T x;
  for( i=0; i < size; i++) {   	// i - номер текущего шага
    k=i; x=a[i];
    for( j=i+1; j < size; j++)	// цикл выбора наименьшего элемента
      if (  a[j] < x ) {
        k=j; x=a[j];	        // k - индекс наименьшего элемента
      }

    a[k] = a[i]; a[i] = x;   	// меняем местами наименьший с a[i]
  }
}*/

/*
void StrSel(int A[],int nn)
{
    int i, j, x, k;
    for (i=0; i<nn-1; i++)
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
}*/


int one_line_prostr2 (tochka *t, size_t n)
//Возвращает НОМЕР ПЕРВОЙ ТОЧКИ, следующие после которой не лежат на одной линии и 0 в противном случае
{
    int i=2;
    float xba = t[1].x - t[0].x;
    float yba = t[1].y - t[0].y;
    float zba = t[1].z - t[0].z;
    float xa = t[0].x, ya = t[0].y, za = t[0].z;
    float tmp1, tmp2, tmp3, tmp4;

    while (i<=n)
    {
        tmp1 = yba*(t[i].x-xa);
        tmp2 = xba*(t[i].y-ya);
        tmp3 = zba*(t[i].y-ya);
        tmp4 = yba*(t[i].z-za);
        printf("%.2f - %.2f - %.2f - %.2f\n", tmp1, tmp2, tmp3, tmp4);
        if (tmp1 != tmp2 || tmp3 != tmp4 || tmp2 != tmp3)
            return i;
        i++;
    }
    return -1;
}


int one_line_prostr (tochka *t, size_t n)
//Возвращает НОМЕР ПЕРВОЙ ТОЧКИ, следующие после которой не лежат на одной линии и 0 в противном случае
{
    int i=0, kol=0;
    float a=0, b=0, c=0;
    for (i=0; i<n-2; i++)
    {        //будем опять плюсовать количество, пока точки на одной линии разлеглись
        a = (t[i+2].x - t[i].x)/(t[i+1].x - t[i].x);
        b = (t[i+2].y - t[i].y)/(t[i+1].y - t[i].y);
        c = (t[i+2].z - t[i].z)/(t[i+1].z - t[i].z);
        if (a==b && b==c)
            kol++;
        else //как только точки не разлеглись на одной линии, можно смело попытаться вытащить номер точки которая НИТАКАЯКАКФСЕ
            return i;
    }
    return -1; //первый элемент тройки, в которой точки не лежат на одной линии
}

int one_line_prostr3 (tochka *t, size_t n)
//Возвращает НОМЕР ПЕРВОЙ ТОЧКИ, следующие после которой не лежат на одной линии и 0 в противном случае
{
    int i=0, kol=0;
    float a=0, b=0, c=0;
    while(i<n-2)
    {        //будем опять плюсовать количество, пока точки на одной линии разлеглись
        a = (t[i+2].x - t[i].x)*(t[i+1].y - t[i].y)*(t[i+1].z - t[i].z);
        b = (t[i+2].y - t[i].y)*(t[i+1].x - t[i].x)*(t[i+1].z - t[i].z);
        c = (t[i+2].z - t[i].z);
        if (a==b && b==c)
            i++;
        else //как только точки не разлеглись на одной линии, можно смело попытаться вытащить номер точки которая НИТАКАЯКАКФСЕ
            return i;
    }
    return -1; //первый элемент тройки, в которой точки не лежат на одной линии
}

int one_line_prostr4 (tochka *t, size_t n)
//Возвращает НОМЕР ПЕРВОЙ ТОЧКИ, следующие после которой не лежат на одной линии и 0 в противном случае
{
    int i=2, kol=0;
    tochka A = t[0], B = t[1];
    float a=0, b=0, c=0;
    while(i<=n)
    {        //будем опять плюсовать количество, пока точки на одной линии разлеглись
        a = (A.x - t[i].x)*(B.y - t[i].y)*(B.z - t[i].z);
        b = (A.y - t[i].y)*(B.x - t[i].x)*(B.z - t[i].z);
        c = (A.z - t[i].z);
        if (a==b && b==c)
            i++;
        else //как только точки не разлеглись на одной линии, можно смело попытаться вытащить номер точки которая НИТАКАЯКАКФСЕ
            return i;
    }
    return -1; //первый элемент тройки, в которой точки не лежат на одной линии
}


int one_line_prostr5 (tochka *t, size_t n)
//Возвращает НОМЕР ПЕРВОЙ ТОЧКИ, следующие после которой не лежат на одной линии и 0 в противном случае
{
    int i=0, kol=0;
    float a=0, b=0, c=0;
    tochka A = t[0], B = t[1];
    for (i=2; i<n; i++)
    {        //будем опять плюсовать количество, пока точки на одной линии разлеглись
        a = (t[i].x - A.x  )*(t[i].y -B.y )*(t[i].z -B.z );
        b = (t[i].y - A.y  )*(t[i].x -B.x  )*(t[i].z -B.z );
        c = (t[i].z - A.z  );
        if (a==b && b==c)
            kol++;
        else //как только точки не разлеглись на одной линии, можно смело попытаться вытащить номер точки которая НИТАКАЯКАКФСЕ
            return i;
    }
    return -1; //первый элемент тройки, в которой точки не лежат на одной линии
}



int one_line_prostr6 (tochka *t, size_t n)
{
    int i=0, kol=0;
    float a=0, b=0, c=0;
    tochka A = t[0], B = t[1];
    while(i<n-2)
    {
        a = (B.x - t[i].x)/(A.x - t[i].x);
        b = (B.y - t[i].y)/(A.y - t[i].y);
        c = (B.z - t[i].z)/(A.z - t[i].z);
        if (a==b && b==c)
            i++;
        else
            return i;
    }
    return -1;
}

int one_line_prostr7 (tochka *t, size_t n)
{
    int i=2, kol=0;
    float a=0, b=0, c=0;
    tochka A = t[0], B = t[1];
    float x = B.x - A.x;
    float y = B.y - A.y;
    float z = B.z - A.z;
    while(i<n)
    {
        a = (t[i].x - A.x)/x;
        b = (t[i].y - A.y)/y;
        c = (t[i].z - A.z)/z;
        if (a==b && b==c)
            i++;
        else
            return i;
    }
    return -1;
}

int one_line_prostr8 (tochka *t, size_t n)
{
    int i=2, kol=0;
    float a=0, b=0, c=0;
    tochka A = t[0], B = t[1];
    float xk = B.x - A.x;
    float yk = B.y - A.y;
    float zk = B.z - A.z;
    while(i<n)
    {
       /*(x-x1)*yk - (y-y1)*xk
        (y-y1)*zk - (z-z1)*yk
        (x-x1)*zk - (z-z1)*xk*/
        a = (t[i].x - A.x)*yk - (t[i].y - A.y)*xk;
        b = (t[i].y - A.y)*zk - (t[i].z - A.z)*yk;
        c = (t[i].x - A.x)*zk - (t[i].z - A.z)*xk;

//        if (a==b && b==c)
        if (abs(a)+abs(b)+abs(c) <= EPS)
            i++;
        else
            return i;
    }
    return -1;
}

/*void sort_vst2 (tochka_xy *tn, tochka *pn, size_t n, float *abc)//Сортировка ВСТАВКАМИ точек массивов tn и pn размерами n в зависимости от коэффициентов уравнения kx+b=y.
{
    int i, j;
    for(i=1; i<n; i++){    //for(i=2; i<n; i++)
    j=i;
    while((j>0) && (compare_xy(tn[j-1], tn[j], abc)))        //for(j=i; (j>1) && (compare_xy(tn[j-1], tn[j], abc)); j--)
        {
            swap_xy(j-1, j, tn);
            swap_t(j-1, j, pn); // output_xy(tn, n);
           j--;
        }
    }
}*/








