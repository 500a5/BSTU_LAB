#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
//переводит дюймы в метры, сантиметры, миллиметры
    setlocale(LC_ALL,"Rus");

    int i;
    float inch;
    printf("¬ведите размер (в дюймах) = ");
    scanf("%f", &inch);

    inch = inch * 2.54;//переводим дюймы в сантиметры

    int m,s,mm;

    m = inch/100;//метры

    s = inch - m*100;//сантиметры
    mm = modf(inch, &i) * 100;//миллиметры

    printf("%d метров %d сантиметров %d миллиметров", m, s, mm);

    return 0;
}
