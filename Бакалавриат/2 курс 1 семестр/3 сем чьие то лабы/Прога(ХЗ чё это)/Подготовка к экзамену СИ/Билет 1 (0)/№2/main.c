#include <stdio.h>

#define SQR(x) ((x)*(x))

float sqr (float);
void main (void){
    float x, y;
    x=y=1;
    printf("SQR(2)=%4.1f\nsqr(2)=%4.1f \n", SQR(++x), sqr(++y));
    printf("x = %f y = %f", x, y);
}

float sqr (float f){
    return SQR(f);
}

