
#ifndef LAB_1_3_A_ZAGALOVOK_ARR_SORT_H
#define LAB_1_3_A_ZAGALOVOK_ARR_SORT_H

_Bool check_sort(int* a, int n);
void del_el(int* a, int *n);
void input (int a[], int* n);
void output (int a[],int n);
_Bool  A_vkl_B (int* a, int* b, int n, int m);
_Bool A_ravn_B (int* a, int* b, int n, int m);
_Bool A_st_vkl_B (int* a, int* b, int n, int m);
int A_or_B (int* a, int* b, int n, int m,int* c );
int A_and_B (int* a, int* b, int n, int m,int* c  );
int A_minus_B (int* a, int* b, int n, int m,int* c );
int A_sm_minus_B (int* a, int* b, int n, int m,int* c );
int dop_A (int* a, int n, int* c );
void sort_vst(int* a, int n);
#endif //LAB_1_3_A_ZAGALOVOK_ARR_SORT_H
