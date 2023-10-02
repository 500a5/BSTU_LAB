#include <stdio.h>
#include <stdlib.h>

#define MAXSTRLN 10

int f_scan(char *);

int i = 0;

int main()
{
    int m, n;
    float f;
    char s[MAXSTRLN];

    gets(s);

    m = f_scan(s);
    i++;
    n = f_scan(s);

    f = m/n;

    printf("%4.2f", f);
}
int f_scan(char *s){
    extern int i;
    int a = s[i] - '0';
    int c;
    while ( i < MAXSTRLN ){
        i++;
        if ( (s[i] == '/') || (s[i] == '\0') )
            break;
        c = (s[i] - '0');
        a = a*10 + c;
    }
    printf("%d\n", a);
    return a;
}
