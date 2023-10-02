#include <stdio.h>
#include <stdlib.h>

int strlen (char *s)
{
    int i=0;
    while(s[i])
        i++;
    return i;
}

int main ()
{
    char s[120],mask=1;
    int i,j,k=0,n;
    scanf("%s",s);
    n=strlen(s)/8;
    char a[n];
    for(i=n-1;i>=0;i--)
        for (j=0;j<8;j++)
        {
            a[i]<<=1;
            if(s[k++]=='1')
                a[i]|=mask;
        }
    printf("%lf",*((long double*)a));
    return 0;
}
