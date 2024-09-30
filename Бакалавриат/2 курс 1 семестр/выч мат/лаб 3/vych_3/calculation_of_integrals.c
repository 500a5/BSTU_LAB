
#include "calculation_of_integrals.h"
//Метод центральных прямоугольников
float pryamougolnik(float (*funct)(float x), float a, float b, int n, float e)
{
    float out = 0, x1 = 0, x2 = 0, i, y;
    float h = (b - a)/n;

    do
    {
        x2 = x1;
        x1 = 0;
        i = a + h/2;

        while(i < b)
        {
            y = funct(i);
            x1 = x1 + y;
            i += h;
        }
        x1 = x1*h;
        h = h/2;

    } while (fabs(x1 - x2)/3 > e);

    out = x2 + (x2 - x1)/3;
    return out;
}

//Метод трапеций
float trapeze(float (*funct)(float x), float a, float b, int n, float e)
{
    float out = 0, x1 = 0, x2 = 0, i, y;
    float h = (b - a)/n;

    do
    {
        x2 = x1;
        x1 = 0;
        i = a + h;

        float s = 0;

        while(i < b)
        {
            y = funct(i);
            s = s + y;
            i += h;
        }
        x1 = h*((funct(a)+funct(b))/2 + s);
        h = h/2;
    } while (fabs(x1 - x2)/3 > e);

    out = x2 + (x2 - x1)/3;

    return out;
}

//Метод параболы
float parabola(float (*funct)(float x), float a, float b, int n, float e)
{
    float out = 0, x1 = 0, x2 = 0, i, y;
    float h = (b - a)/n;

    do
    {
        x2 = x1;
        x1 = 0;
        i = a + h;

        float s = funct(a) + funct(b);
        int k = 1;

        while(i < b)
        {
            y = funct(i);

            if (k%2 == 0)
                s = s + 2*y;
            else
                s = s + 4*y;

            i += h;
            k++;
        }

        x1 = h/3*s;
        h = h/2;

    } while (fabs(x1 - x2)/15 > e);

    out = x2 + (x2- x1)/15;
    return out;
}


//Метод Гаусса
float gauss(float (*funct)(float x), float a, float b, int n)
{
    float **A = calloc(4, sizeof(float *));
    float **t = calloc(4, sizeof(float *));

    for (int i = 0; i < 4; i++)
    {
        A[i] = calloc(i + 1, sizeof(float));
        t[i] = calloc(i + 1, sizeof(float));
    }

    A[0][0] = 2; A[1][0] = 1; A[2][0] = 0.555555556; A[3][0] = 0.347854845;
    A[1][1] = 1; A[2][1] = 0.888888889; A[3][1] = 0.652145155;
    A[2][2] = 0.555555556; A[3][2] = 0.652145155;
    A[3][3] = 0.347854845;

    t[0][0] = 0; t[1][0] = -0.577350269; t[2][0] = -0.774596669; t[3][0] = -0.861136312;
    t[1][1] = 0.577350269; t[2][1] = 0; t[3][1] = -0.339981044;
    t[2][2] = 0.774596669; t[3][2] = 0.339981044;
    t[3][3] = 0.861136312;

    float out = (b - a)/2, s = 0, x = (b + a)/2;

    for (int i = 0; i < n; i++)
        s += A[n-1][i] * funct(x + (b-a)/2*t[n-1][i]);

    out = out*s;
    return out;
}
