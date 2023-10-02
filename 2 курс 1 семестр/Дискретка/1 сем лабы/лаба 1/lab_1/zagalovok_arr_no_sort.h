

#ifndef LAB_1_ZAGALOVOK_H_ARR_NO_SORT_H
#define LAB_1_ZAGALOVOK_H_ARR_NO_SORT_H


void del_el(int* a, int *n);
void input (int a[], int* n);
void output (int a[],int n);
_Bool poisk_el (int a[],int N,int key);
_Bool  A_vkl_B (int* a, int* b, int n, int m);
_Bool A_ravn_B (int* a, int* b, int n, int m);
_Bool A_st_vkl_B (int* a, int* b, int n, int m);
int A_or_B (int* a, int* b, int n, int m,int* c );
int A_and_B (int* a, int* b, int n, int m,int* c  );
int A_minus_B (int* a, int* b, int n, int m,int* c );
int A_sm_minus_B (int* a, int* b, int n, int m,int* c );
int dop_A (int* a, int n, int* c );
#endif //LAB_1_ZAGALOVOK_H_ARR_NO_SORT_H
