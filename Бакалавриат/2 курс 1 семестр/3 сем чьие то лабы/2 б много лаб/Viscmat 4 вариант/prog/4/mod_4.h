#ifndef MOD_4_H_INCLUDED
#define MOD_4_H_INCLUDED

typedef float(*func_1)(float);
typedef float(*func_2)(float, float);

float f_xy (float x, float y);
float g_xy (float x, float y);
float df_dx (float x);
float df_dy (float y);
float dg_dx (float x);
float dg_dy (float y);
float det_2 (float a11, float a12, float a21, float a22);
int kram_resh (float a11, float a12, float a21, float a22, float b1, float b2, float* x1, float* x2);
int booll (func_2 f, func_1 df_dx, func_1 df_dy, func_2 g, func_1 dg_dx, func_1 dg_dy, float*x0, float*y0, float eppss, int n);




#endif // MOD_4_H_INCLUDED
