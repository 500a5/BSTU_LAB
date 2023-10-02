#include "stdio.h"
#include "stdlib.h"
#include "math.h"

const short ErrNotSolution = 0;
const short Ok = 1;
short Err;

//����譮���
double E;

//��� �㭪��

double fun(double x) {
    return pow(x, 3) - 9 * pow(x, 2) + 27 * x - 27;
}


//��ࢠ� �ந������� �㭪樨
double fun_1dx(double x) {
    return 3 * pow(x, 2) - 18 * x + 27;
}

//���� �ந������� �㭪樨
double fun_2dx(double x) {
    return 6 * x - 18;
}


//�������஢���� ��⮤
double comb_method(double a, double b) {
    if ((fun(a) * fun(b)) >= 0) {
        printf("���� �� ��१�� �� �������\n");
        Err = ErrNotSolution;
        return 0;
    }
    double x_K, x_X;
    if ((fun(a) * fun_2dx(a)) > 0) {
        x_X = b;
        x_K = a;

    }
    else {
        x_X = a;
        x_K = b;
    }
    do {
        x_K = x_K - (fun(x_K) / fun_1dx(x_K));
        x_X = x_X - (fun(x_X) * (x_K - x_X)) / (fun(x_K) - fun(x_X));
    } while (fabs(x_K - x_X) > E);
    Err = Ok;
    return (x_K + x_X) / 2;
}
int main() {


    printf("������ ����譮���: ");
    scanf("%lf", &E);


    double a, b;
    printf("������ ��१��: ");
    scanf("%lf%lf", &a, &b);

    double sol = comb_method(a, b);

    if (Err == Ok)
        printf("�ਡ����񭭮� �襭��: %lf\n", sol);
    return 0;
}





