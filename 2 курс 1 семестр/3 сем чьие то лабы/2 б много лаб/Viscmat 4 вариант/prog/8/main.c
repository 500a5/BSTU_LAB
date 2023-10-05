#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float(*func_f)(float);
float fun(float x);
float proizv1(float x);
float proizv2(float x);
float Zhnach (func_f f, func_f p, func_f p2, float a, float b, float eps);

int main()
{
    float a, b, eps;
    printf("eps >> ");
    scanf("%f", &eps);
    printf("a >> ");
    scanf("%f", &a);
    printf("b >> ");
    scanf("%f", &b);
    printf("%.2f ", Zhnach(fun, proizv1, proizv2, a, b, eps));
    return 0;
}

float fun(float x) //функция варианта
{
    return x*x*x-9*x*x+27*x-27;
}

float proizv2(float x) //вторая производная
{
    return 6*x-18;
}

float proizv1(float x) //первая производная
{
    return 3*x*x-18*x+27;
}

float Zhnach (func_f f, func_f p, func_f p2, float a, float b, float e)
{
/*Если значение функции и ее второй производной
имеют один и тот же знак в точке х = a,
то x0x = b,  x0k = а,  иначе x0x = а,  x0k = b.*/
{
    float x0k,x0x;
    FILE *F = fopen("Rez.txt", "w");
    fprintf(F, "eps = %.5f;  ", e);
    if ((f(a)*p2(a))>0) //если вторая производная и значение функции в точке
    {// а имеют однаковый знак, то x0xорд = b, х0к = а
        x0x=b;
        x0k=a;
        fprintf(F, "a = %.2f; ", x0k);
        fprintf(F, "b = %.2f \n\n", x0x);
    }
    else
    {//иначе наоборот
        x0x=a;
        x0k=b;
        fprintf(F, "  a = %.2f; ", x0x);
        fprintf(F, "  b = %.2f \n\n", x0k);
    }
    float x1k=x0k-f(x0k)/p(x0k); //значение в точке х1 хорд
    float x1x=x0x-(f(x0x)*(x1k-x0x))/(f(x1k)-f(x0x)); //значение в точке х1 касательных
    float c=fabsf(x1k-x1x); //с ддля сравнения и проверки точности


    while (c>e) //пока разность х1к и х1х больше эпсилон
    {
        fprintf(F, "x0k = %.3f; ", x0k); //запись значения в файл
        fprintf(F, "  x0x = %.3f \n", x0x);
        x1k=x0k-f(x0k)/p(x0k); //высчитывание нового значения касательных
        x1x=x0x-(f(x0x)*(x1k-x0x))/(f(x1k)-f(x0x));//хорд
        x0x=x1x; //переприсваивание значений для дальнейшего подсчета
        x0k=x1k;
        c=fabsf(x1k-x1x); //подсчет нового с для сравнения
    }
    fclose(F); //закрытие файла
    return (x1k+x1x)/2; //если точность достигнута, возвращаем сумму деленную на два
}


}












