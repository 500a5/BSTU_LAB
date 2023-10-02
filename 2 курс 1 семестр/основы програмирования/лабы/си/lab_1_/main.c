
#include <stdio.h>
#include <process.h>


void inp_out_string(char *s){
    printf( "������ ��ப�: " );
    gets(s); // ���뢠�� �� ��⮪� ����� ��ப�
    printf( "�� �����: %s \n", s );
}

void inp_out_char(char c){
    printf("������ ᨬ���: ");
    c = getchar();    // ���� ᨬ����
    printf("�� �����: ");
    putchar(c);        // �뢮� ᨬ����
    printf("\n");
}

void inp_int(int a){
    printf("� 10-�筮� ��⥬� ��᫥���: %10d \n",a);
    printf("� 8-�筮� ��⥬� ��᫥���:  %10o \n",a);
    printf("� 16-�筮� ��⥬� ��᫥���:  %10X \n",a);
    printf("���� %p \n",&a);
}

void inp_float(float a){
    printf("�� �����: %5.4f \n",a);
    printf("���砩襥 �।�⠢�����: %g \n",a);
    printf("� 16-�筮� ��⥬� ��᫥��� %a \n",a);
    printf("���� %p \n",&a);
}

int main(void) {
    char String[100];
    inp_out_string(String);

    char c;
    inp_out_char(c);

    int a;
    printf("������ 楫�� �᫮ : ");
    scanf("%d", &a);
    inp_int(a);

    float e;
    printf("������ �஡��� �᫮: ");
    scanf("%f", &e);
    inp_float(e);
system("pause");
    return 0;
}
