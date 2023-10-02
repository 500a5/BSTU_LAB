#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//������������ ������

void in_arr(int*, int, int);// ���� ��������� �������
void out_arr(int [], int, int);
void mult_arr(int*, int *, int *, int, int, int);

int main()
{
    setlocale(LC_ALL, "Rus");
    int row1, row2, col1, col2;

    //���� ��������� ������ �������
    printf("������� ���������� ����� ������ �������: ");
    scanf("%d", &row1);
    printf("������� ���������� �������� ������ �������: ");
    scanf("%d", &col1);
    printf("---------------------------------------\n");
    int a[row1*col1];
    in_arr(a ,row1, col1);
    // ���� ��������� ������ �������
    printf("������� ���������� ����� ������ �������: ");
    scanf("%d", &row2);
    printf("������� ���������� �������� ������ �������: ");
    scanf("%d", &col2);
    printf("---------------------------------------\n");
    int b[row2][col2];
    in_arr(b, row2, col2);
    printf("---------------------------------------\n");
    // ����� ��������� ������ �������
    out_arr(b, row2, col2);
    printf("---------------------------------------\n");

    if (col1 != row2){
        printf("��������� ����������!");
        return 0;
    }


    // ��������� ������
    int c[row1*col2];

    mult_arr(c, a, b, row1, col1, col2);

    // ����� ������� ������������
    printf("������� ������������\n");
    printf("---------------------------------------\n");
    out_arr(c, row1, col2);
    printf("---------------------------------------\n");
    return 0;
}

void in_arr(int *a, int row, int col){//��������
    int i,j;
    printf("������� �������� �������\n");
    for (i = 0; i < (row*col); i++)
            scanf("%d", &a[i]);
    printf("---------------------------------------\n");
}

void out_arr(int a[], int row, int col){//��������
    int i;
    for (i = 0; i < row*col; i++){
        printf("%d ", a[i]);
        if((i+1)%row == 0)
            printf("\n");
    }
}

void mult_arr(int *c ,int *a, int *b, int row1, int col1, int col2){
    int i,j,k;
    for (i = 0; i < row1; i++){
        for (j = 0; j < col2; j++){
            c[i*row1+j] = 0;
            for(k = 0; k < col1; k++)
                c[i*row1+j] += a[i*row1+k] * b[k*col2+j];
        }
    }
}
