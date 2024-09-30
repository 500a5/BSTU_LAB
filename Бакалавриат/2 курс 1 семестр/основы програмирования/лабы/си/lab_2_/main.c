
#include <stdio.h>
#include <process.h>

int minus_poly(double* p, double* q, int len, double* sx, int *len_sx)
{
    double coeff;

    int  zero_count = 0;
    int  i;
    coeff = p[0] / q[0];     // при умножении на этот коэффициент убивается старший коэфф.
    p[0] = 0;
    sx[*len_sx]=coeff;
    ++*len_sx;
    for (i = 1; i < len; i++)
        p[i] = p[i] - coeff * q[i];
    while (p[zero_count] == 0)
        zero_count++;

    return zero_count;
}
void deli(int len1, double* poly1, int len2, double* poly2, double* sx, int* len_sx){
    int i=0, zero_count;
    while ((len1 - i) >= len2)     // пока еще возможно разделить остаток на делитель
    {
        zero_count = minus_poly(poly1 + i, poly2, len2,sx,&*len_sx);   // вычитаем коэффициенты
        i += zero_count;
    }
}
void input(int* len, double* poly){
    int i;
    printf("Ввете длину многочлена  ");
    scanf("%d",&*len);
    printf("Введите коэфиценты многочлена  ");
    for ( i = 0; i < *len; i++){
        scanf("%lg",&poly[i]);
    }
    printf("\n");
}
void output(int len_sx, double* sx){
    int i;
    for ( i=0; i < len_sx; i++) {
        if (sx[i]>0 && i==0) {
            printf("%gx^%d", sx[i], len_sx - i - 1);
        }
        else if (sx[i]>0){
            printf("+%gx^%d", sx[i], len_sx - i - 1);

        }
        else {
            printf("%gx^%d", sx[i], len_sx - i - 1);
        }
    }
    printf("\n");
}
int main()
{
    double poly1[20] ;
    double poly2[20] ;
    int    len1, len2;
    double sx[10];
    int len_sx=0;

    input(&len1,poly1);
    input(&len2,poly2);
    deli(len1,poly1,len2,poly2,sx,&len_sx);
    output(len_sx,sx);
    system("pause");
    return 0;
}