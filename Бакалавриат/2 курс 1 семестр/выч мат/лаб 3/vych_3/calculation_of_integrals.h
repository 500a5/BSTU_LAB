
#ifndef VYCH_3_CALCULATION_OF_INTEGRALS_H
#define VYCH_3_CALCULATION_OF_INTEGRALS_H
float pryamougolnik(float (*funct)(float x), float a, float b, int n, float e);
float trapeze(float (*funct)(float x), float a, float b, int n, float e);
float parabola(float (*funct)(float x), float a, float b, int n, float e);
float gauss(float (*funct)(float x), float a, float b, int n);
#endif //VYCH_3_CALCULATION_OF_INTEGRALS_H
