
#include <math.h>
#include <ctype.h>
#include <stdio.h>


double atof1 (char *s,int *i)
{
    double val, power;
    int  sign;

    for (*i ; isspace (s[*i]); ++*i) /* игнорировать символы-разделители */
        ;
    sign = (s[*i] == '-') ? -1 : 1;
    if (s[*i] == '+' || s[*i] == '-') /* пропуск знака */
        ++*i;
    for (val = 0.0; isdigit (s[*i]); ++*i) // пока s[i] цифра
        val = 10.0 * val + (s[*i] - '0');
    if (s[*i] =='.')
        ++*i;
    for (power = 1.0; isdigit(s[*i]); ++*i) {
        val = 10.0 * val + (s[*i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}


double atof_and_e (char *s){
    int pos = 0;
    double x,t = 0;
    x=atof1(s,&pos);
    if (s[pos] == 'e' || s[pos] == 'E'){
        pos++;
        t = atof1(s, &pos);
        x *= pow(10,t);
    }

    return x;
}


int convert_10cc_to_4cc( int n ){
        int rez = 0, curr = 1,sign=1;
    if(n<0){
        n=abs(n);
        sign=-1;
    }
        while (n) {
            rez += (n - ((n >> 2) << 2)) * curr;
            n = n>> 2;
            curr *= 10;
        }

    return rez*sign;
}

int dec16(int num) {
    int m;
    if (num < 0) {
        num = abs(num);
        printf("-");
    }
    if (num >= 16) {
        dec16(num / 16);
    }
    m = num % 16;
    switch (m) {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
               printf("С");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                putchar(m + '0');
                break;
        }
}



void output(int n){
int m=0,a[10],i=0;
    if(n<0){
        putchar('-');
        n=abs(n);
    }
if (n==0){
    putchar('0');
}
    while (n){
       m=m*10+n%10;
        n/=10;
        a[i]=m;
        i++;
    }
    i--;
    while (i>=0){
        putchar(a[i]%10+'0');
        i--;
    }
}

int main() {
    char s[15];

    double x ;
    int n;
    gets(s);
    x=atof_and_e(s);
    n= (int)round(x);
    dec16(n);
  //  n=convert_10cc_to_4cc(n);
  //  output(n);

    return 0;
}