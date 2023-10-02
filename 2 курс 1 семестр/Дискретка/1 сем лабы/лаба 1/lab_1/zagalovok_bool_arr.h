
#ifndef LAB_1_3_A_ZAGALOVOK_BOOL_ARR_H
#define LAB_1_3_A_ZAGALOVOK_BOOL_ARR_H

void input (_Bool* a, int* n);
void output (_Bool * a,int n);
_Bool  A_vkl_B (_Bool * a, _Bool * b, int n );
_Bool A_ravn_B (_Bool * a, _Bool * b, int n );
_Bool A_st_vkl_B (_Bool * a, _Bool * b, int n, int m );
void A_or_B (_Bool* a, _Bool* b, int n, _Bool* c);
void A_and_B (_Bool* a, _Bool* b, int n, _Bool* c );
void A_minus_B (_Bool* a, _Bool* b, int n, _Bool* c);
void A_sm_minus_B (_Bool* a, _Bool* b, int n, int m , _Bool* c );
int dop_A (_Bool * a, int n, _Bool* c );
#endif //LAB_1_3_A_ZAGALOVOK_BOOL_ARR_H
