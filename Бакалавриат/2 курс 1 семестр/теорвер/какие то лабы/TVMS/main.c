#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#define rand01() ( fabs(sin(rand())) )

int main(void) {

    int i;
    float a[50]; // от 0 до 1 50 шт
    int x[50]; // значение на отрезке
    float b[50];
    int sum=0;
    int sum2=0;
    float sr;
    float disp_vib=0;
    float disp_isp=0;
    float mx=0;
    srand(time(NULL));

    for ( i = 0; i < 50; ++i ){
        a[i]=rand01();
        printf("%f ",a[i]);
    }
    printf("\n");
    for ( i = 0; i < 50; ++i ){
        if (a[i]<=0.16)
            x[i]=0;
        if ((a[i]<=0.25)&&(a[i]>0.16))
            x[i]=6;
        if ((a[i]<=0.41)&&(a[i]>0.25))
            x[i]=2;
        if ((a[i]<=0.76)&&(a[i]>0.41))
            x[i]=8;
        if (a[i]>0.76)
            x[i]=11;
        printf("%d ",x[i]);
    }
    printf("\n");
    for ( i = 0; i < 50; ++i ){
       b[i]=a[i]*(0.25)*log(i+2);
       printf("%f ",b[i]);
    }

    for ( i = 0; i < 50; ++i ){
        sum+=x[i]*a[i];
      //  sum2+=pow(x[i],2);
    }

    sr=sum/50;
    for ( i = 0; i < 50; ++i ){
       disp_vib+=a[i]*pow((x[i]-sr),2);
    }

    for ( i = 0; i < 50; ++i ){
        mx+=a[i]*x[i];

    }
    disp_isp=disp_vib/49;
    disp_vib=disp_vib/50;

   // disp=disp-(pow(sr,2));

    printf("\nСреднее арифметическое = %f\n",sr);
    printf("Выборочная Дисперсия = %f\n",disp_vib);
    printf("Исправленная Дисперсия = %f\n",disp_isp);
    printf("Мат ожидание = %f\n",mx/50);
    return 0;
}