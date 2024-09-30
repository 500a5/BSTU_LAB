
#include "LFN.h"

int meth_newton(float (*f)(float x, float y, int f), float (*g)(float x, float y, int f), float *x, float *y, float e, int n){
    float d,d1,d2;
    float h = 0, l = 0;
    int k = 0;
    do{
        k++;
        d = f(*x,*y,1)*g(*x,*y,2) - f(*x,*y,2)*g(*x,*y,1);
        d2 = -f(*x,*y,1)*g(*x,*y,0) + g(*x,*y,1)*f(*x,*y,0);
        d1 = -f(*x,*y,0)*g(*x,*y,2) + g(*x,*y,0)*f(*x,*y,2);
        h = d1/d;
        l = d2/d;
        *x = *x + h;
        *y = *y + l;
    }

    while(k < n && fabs(f(*x,*y,0)) + fabs(g(*x,*y,0)) > e);

    return (fabs(f(*x,*y,0)) + fabs(g(*x,*y,0)) < e);

}