#include <stdio.h>
#include <process.h>
//#include "zagalovok_arr_no_sort.h"  //������⥪� ��� �࠭���� � ��ࠡ�⪨ ������⢠ ���
                                    //�� �����஢������ ���ᨢ� ����ࠫ��� �ᥫ
#include "zagalovok_arr_sort.h"   //������⥪� ��� �࠭���� � ��ࠡ�⪨ ������⢠ ���
                                    //���஢������ ���ᨢ� ����ࠫ��� �ᥫ
//#include "zagalovok_bool_arr.h"   //������⥪� ��� �࠭���� � ��ࠡ�⪨ ������⢠ ��� ���ᨢ�
                                    //� ������� ⨯�� boolean
int main() {
    int na,nb,nc,nd,nm1,nm2;
    int a[100], b[100], c[100], d[100], m1[100], m2[100];
    printf("������� �������, ����㯭�� ��� �����: {1,2,3,4,5,6,7,8,9,10} \n");
    printf("������⢮ ����⮢ ������⢠ >0 � <=10 \n");

    printf("������ ������⢮ ����⮢ A:  ");
    scanf("%d",&na);
    printf("������ ������⢮ A:  ");
    input(a,&na);

    printf("������ ������⢮ ����⮢ B:  ");
    scanf("%d",&nb);
    printf("������ ������⢮ B:  ");
    input(b,&nb);

    printf("������ ������⢮ ����⮢ C:  ");
    scanf("%d",&nc);
    printf("������ ������⢮ C:  ");
    input(c,&nc);
/**
 *
 *
 */
    nd=A_sm_minus_B(b,c,nb,nc,d);
    nm1=A_minus_B(a,d,na,nd,m1);
    nd=A_or_B(b,c,nb,nc,d);
    nm2=A_minus_B(d,a,nd,na,m2);
    nd=A_or_B(m1,m2,nm1,nm2,d);
    printf("�������:");
    output(d,nd);

    system("pause");
    return 0;
}