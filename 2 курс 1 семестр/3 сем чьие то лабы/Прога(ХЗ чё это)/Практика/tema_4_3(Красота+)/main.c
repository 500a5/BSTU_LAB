#include <stdio.h>
#include <stdlib.h>

#define m 10
//�������� ������� �������� �� ���� ��������� �������
int in_arr(int*);
int out_arr(int*);

int main()
{
    int a[m], i;

    int sr = in_arr(a) / m;//��������� �������� ��������

    for(i = 0; i < m; i++){
        a[i] = a[i] - sr;
    }

    out_arr(a);

    return 0;
}

int in_arr(int a[m]){//���� ������� a � ������� ����� ����� sr
    int i, sr = 0;
    for(i = 0; i < m; i++){
        scanf("%d", &a[i]);
        sr = sr + a[i];
    }
    return sr;
}

int out_arr(int a[m]){//����� ������� a
    int i;
    for(i = 0; i < m; i++)
        printf("%d ", a[i]);
}
