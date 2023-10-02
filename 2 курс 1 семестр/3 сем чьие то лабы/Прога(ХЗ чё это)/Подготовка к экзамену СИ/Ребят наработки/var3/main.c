#include <stdio.h>
#include <stdlib.h>

#define STRLEN 30

#define SIZESTEK 50
char stek[SIZESTEK];
int pos = 0;

void put(char);//��������  � ����
char pop(void);//�����  �� �����
char get(void);// �������� �������� �� �������� �����


int main()
{
    char c;//������ �� ������
    char prov;

    //�������� ����
    while ((c = getchar()) != '\n'){
        if((c == '(') || (c == ')')  || (c == '[') || (c == ']')){
            if(pos == 0)
                put(c);
            else {
                prov = get();
                if( (prov == '(') && (c == ')'))
                    pop();
                else if( (prov == '[') && (c == ']'))
                    pop();
                else
                    put(c);
            }
        }
    }

    if(pos == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

//��������  � ����
void put(char c){
    stek[pos++]= c;
}

//�����  �� �����
char pop(void){
    return stek[pos--];
}

//�������� �������� �� �������� �����
char get(void){
    return stek[pos-1];
}
