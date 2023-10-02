#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    float x;
    float y;
}point;

void in_point(point *);//���� �����
int whi_trian(point, point, point);//����� �����������? 1-�����, 0-������, (-1)-������
float len_line(point, point);//������ �������
void swap(int *, int *);//������

int main()
{
    setlocale(LC_ALL, "Rus");//���������� �������

    point A,B,C;//������ ����������
    in_point(&A);//................
    in_point(&B);//................
    in_point(&C);//................

    int i = whi_trian(A,B,C);

    switch (i){
        case(0):
            printf("����������� �������������");
            break;
        case(1):
            printf("����������� ������������");
            break;
        case(-1):
            printf("����������� �������������");
            break;
    }

    return 0;
}

void in_point(point *A){//���� �����
    printf("���� �����\n");
    printf("          ������� ���������� ����� �� x = ");
    scanf("%f", &A->x);
    printf("          ������� ���������� ����� �� y = ");
    scanf("%f", &A->y);
    printf("------------------------------------------\n");
}

int whi_trian(point A, point B, point C){//����� �����������? 1-�����, 0-������, (-1)-������

    float hypo, cat1, cat2;

    hypo = len_line(A, B);
    cat1 = len_line(A, C);
    cat2 = len_line(B, C);

    if (cat1 > hypo)
        swap(&hypo, &cat1);
    if (cat2 > hypo)
        swap(&hypo, &cat2);

    hypo *= hypo;
    cat1 *= cat1;
    cat2 *= cat2;
    float s = cat1+cat2;
    if((s - hypo < 0.01)&&(s - hypo > -(0.01)))
        return 0;
    if(s - hypo > 0.01)
        return -1;
    else
        return 1;
}

float len_line(point A, point B){//������ ������� AB
    float s;
    float x, y;

    x = abs(A.x - B.x);
    y = abs(A.y - B.y);
    s = sqrt((x*x)+(y*y));

    return s;
}

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
