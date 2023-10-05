#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int chot(int x)
{
    return !(abs(x)%2);
}

void InpArr (int *a, int n)
{
    int i;
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);
}




int main()
{
    printf("Hello world!\n");
    int i, n=8;
    int *a = calloc(n, sizeof(int));
  //  InpArr(a, n);
   // for (i=0; i<n; i++)        printf("%d ", a[i]);
    int nch=0, ch=0;
   // for (i=0; i<n; i++)
    //{
       // if (chot(a[i]))
        //    ch++;
     //   else
       //     nch++;
  //  }

    printf("%f", 7.00/2.00);

    return 0;
}
























