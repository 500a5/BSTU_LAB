#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int f_del11(int);//�������� ������� �� 11
void f_sum(int , int* , int* );/*����� n, ����� �� �������� sn, �� ������ sc*/

int main()
{
    int m;
    setlocale(LC_ALL, "Rus");
    printf("������� �� ������ ����� ���������: ");
    scanf("%d", &m);
    int i;
    for(i = 0; i <= m; i++)
        if(f_del11(i))
            printf("%d ", i);
    return 0;
}

int f_del11(int n){
    int sn = 0,sc = 0;
    int s = 0;
    f_sum(n, &sn, &sc);
    s = sn - sc;
    if((s%11) == 0)
        return 1;
    return 0;
}

void f_sum(int n, int *sn, int *sc){/*����� n, ����� �� �������� sn, �� ������ sc*/
    int i = 0;
    while(n != 0){
        *sn = *sn + n%10;
        n = n/10;
        i++;
        if(n != 0){
            *sc = *sc + n%10;
            n = n/10;
            i++;
        }
    }

    if(i%2 == 0){
        int path = *sn;
        *sn = *sc;
        *sc = path;
    }
}
