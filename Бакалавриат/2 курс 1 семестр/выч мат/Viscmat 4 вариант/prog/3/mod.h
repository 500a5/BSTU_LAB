#ifndef MOD_H_INCLUDED
#define MOD_H_INCLUDED

typedef float(*func_f)(float);

float fun_1(float x);
float fun_2(float x);
float fun_3(float x);
float CentrPry (func_f f, float a, float b, size_t n);
float RungeCentrPry (func_f f, float a, float b, size_t n);
float Trap (func_f f, float a, float b, size_t n);
float RungeTrap (func_f f, float a, float b, size_t n);
float Simp (func_f f, float a, float b, size_t n);
float RungeSimp (func_f f, float a, float b, size_t n);
float Gauss (func_f f, float a, float b, size_t n);


#endif // MOD_H_INCLUDED
