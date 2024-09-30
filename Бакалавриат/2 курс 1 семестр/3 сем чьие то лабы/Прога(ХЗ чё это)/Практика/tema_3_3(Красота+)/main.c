#include <stdio.h>  //(x^2/a^2)+(y^2/b^2)<=1
#include <stdlib.h>

int a, b;

int main()
{
    extern int a, b;

    printf("¬ведите значение a = ");
    scanf("%d", &a);
    printf("¬ведите значение b = ");
    scanf("%d", &b);

    func_test(-a);

    return 0;
}

void func_test(int x){

    extern int a,b;
    int y;

    for(y = -b; y <= b; y++){
        if((((x*x)/(a*a))+((y*y)/(b*b)))<=1)
            printf("x = %d, y = %d\n", x, y);
    }

    if((((x+1)*(x+1))/(a*a))<=1)
        func_test(x+1);
}
