#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <math.h>



int cmp_int(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}



int cmp_str(const void* a, const void* b){
    return strcmp(*(char**)a, *(char**)b);
}


int cmp_float(const void* a, const void* b) {
    float f = *((float*) a) - *((float*) b);
    if (f < 0) {
        return -1;
    } else {
        return 1;
    }
}


void swap(void *a, void *b, size_t size) {
    char tmp;
    char* ac = (char*)(a);
    char* bc = (char*)(b);
    for( int i = 0; i < size; i++){
        tmp = ac[i];
        ac[i] = bc[i];
        bc[i] = tmp;
    }
}

/*  array   - 㪠��⥫� �� ����㥬� ���ᨢ;
	n       - �᫮ ����⮢ � ���ᨢ�
	width   - ࠧ��� ("�ਭ�") ������ ����� � �����
	compare - 㪠��⥫� �� �㭪�� �ࠢ�����, ����� ������ ��������:
		- ����⥫쭮� ���祭��, �᫨ ���� ����� ����� ��ண�;
		- ������⥫쭮� - �᫨ ���� ����� ��ண�;
		- 0, �᫨ ������ ࠢ��.
*/
void sort( void* arr, size_t n, size_t size, int (*cmp)(const void* a, const void* b) ){
    size_t i, j, iMin;
    // ����� �ᯮ��㥬 ⨯ char*, ��᪮��� sizeof(char)==1
    char *pMin, *pi, *pj;
    pi = (char*)arr;
    for( i = 0; i < n-1; ++i, pi += size ){
        pMin = pi;
        iMin = i;
        // ��室�� �������쭮� ���祭��
        for( pj = pi+size, j = i+1; j < n; ++j, pj += size  ){
            if( cmp( pj, pMin ) < 0 ){
                pMin = pj;
                iMin = j;
            }
        }
        // �ந������ ����� �������쭮�� ���祭�� � ���祭��� �� �������஢����� ����樨
        if( iMin != i ){
            for( j = 0; j < size; ++j ){
                swap(&pi[j],&pMin[j], sizeof(*pi));
            }
        }
    }
}


#define N 5

int main(){
    int i;
    int d[N] = {3,2,5,4,1};
    char* s[N] = {"adf", "dpkjw", "blkjd", "cvklj", "ecjq"};
    float f[N]={3.2, 1.5, 5.8, 0.5 ,-7.8 };
    sort(d, N, sizeof(int), cmp_int);
    for(i = 0; i < N; ++i)
        printf("%d ", d[i]);
    putchar('\n');

    sort(s, N, sizeof(char*), cmp_str);
    for(i = 0; i < N; ++i)
        printf("%s ", s[i]);
    putchar('\n');

    sort(f, N, sizeof(float *), cmp_float);
    for(i = 0; i < N; ++i)
        printf("%f ", f[i]);
    putchar('\n');

    return 0;
}