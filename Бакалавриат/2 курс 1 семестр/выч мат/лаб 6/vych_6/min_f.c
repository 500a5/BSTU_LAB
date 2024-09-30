

#include "min_f.h"

#include "stdio.h"
#include "math.h"
double f_x(double x) {
    return (powl(x,4)+6*powl(x,2)-x+2);
}
double optimal_find(double exp, double a, double b) {
    double min = f_x(a);
    double znach;
    for (double count = a + exp; count <= b; count = count + exp) {
        znach = f_x(count);
        if (znach < min)
            min = znach;
    }
    return min;
}
double cat_in_half(double exp, double a, double b) {
    float q = exp/2, c, a1, b1;
    while (fabs(b - a - exp) > exp){
        c = (b + a)/2;
        a1 = c - q;
        b1 = c + q;
        if (f_x(a1) <= f_x(b1))
            b = b1;
        else
            a = a1;
    }
    return f_x((a+b)/2);

}
double metod_fibanachi(double exp, double a, double b) {
    int F[100];
    F[0] = 1; F[1] = 1;
    int i = 2, n = 1;
    while (F[i-2] + F[i-1] < (b-a)/exp){
        F[i] = F[i-2] + F[i-1];
        i++;
        n++;
    }
    float a1,b1;
    for (int j = 1; j < n; j++){
        a1 = a + (float)F[n - j - 1]/F[n - j + 1]*(b - a);
        b1 = a + (float)F[n - j]/F[n - j + 1]*(b - a);
        if (f_x(a1) <= f_x(b1))
            b = b1;
        else
            a = a1;
    }
    return f_x(a);}

