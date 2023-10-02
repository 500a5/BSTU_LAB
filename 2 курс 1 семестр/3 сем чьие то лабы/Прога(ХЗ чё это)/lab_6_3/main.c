#include <stdio.h>
#include <stdlib.h>

int length(char *);
char *get_word(char *, int *);
int lenWord(char *);
int equalStr(char [], char[]);
int *search(char *s1, char *s2);

int main()
{
    char s1[100], s2[100];//������
    char *s;//�����

    gets(s1);
    gets(s2);

    s = search(s1,s2);

    puts(s);

    return 0;
}

//����� ����� � ������
int lenWord(char *s){
    int i=0;
    while(*(s+i) <= ' ')
        i++;
    int count = 0;
    while(*(s+i) > ' '){
        i++;
        count++;
    }
    return count;
}

// ��������� ��������� �� �����, ������� � ������� s
// ������ ����������� ����� ������������ � b
char *get_word(char *s, int *b){
    int i=0;
    while(*(s+i) <= ' ')
        i++;

    *b = lenWord(s+i);

    return (s+i);
}


// 0 ���� ����� �� �����
// 1 ���� ����� �����
int equalStr(char a[], char b[]){
    char i = 0, flag = 1;


    while(((*(a + i) > ' ') || (*(b + i) > ' ')) && (flag) ){
        if (*(a + i) != *(b + i))
            flag = 0;
        i++;
    }

    if (flag)
        return 1;
    else
        return 0;

}


int *search(char *s1, char *s2){
    int c;
    char *s;

    char *w1 = s1;//��������� �� ����� �� ������ ������
    int i, j; //������� ������� ����

    while( *(w1) != '\0' ){

        w1 = get_word(w1, &i);
        char *w2 = s2;//��������� �� ����� �� ������ ������

        while( *(w2) != '\0' ){
            w2 = get_word(w2, &j);
            if (equalStr(w1, w2)){
                s = w1;
                c = i;
            }
            w2 = w2 + j;
        }

        w1 = w1 + i;
    }

    *(s + c) = '\0';

    return s;

}
