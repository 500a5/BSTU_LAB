#ifndef VI6_H_INCLUDED
#define VI6_H_INCLUDED

typedef float(*func)(float);

float func_var(float x);
float OptPoisk (func f, float a, float b, float eps);
float DelOtr(func f, float a, float b, float eps);

int F (int n);
float MetFib (func f, float a, float b, float eps);




#endif // VI6_H_INCLUDED
