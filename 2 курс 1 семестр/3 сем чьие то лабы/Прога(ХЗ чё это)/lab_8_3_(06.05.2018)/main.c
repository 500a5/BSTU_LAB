#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define BUF 15 //������������ ������ �����

struct word{
    char *s;
    int length;
};

int getListWords(struct word **,int *);// ���������� ����� �� ������ � ������
int get_word(char *,int);//�������� ����� �� ������
void copyStr(char *,char *);//�������� ������ 1 � ������ 2
void freeList(struct word *,int);//������� ������ ���������� ������
struct word *getMoreMemory(struct word *,int *);//����������� ������ � 2 ���� ��� ������ ������

int main()
{
    int sizeList = 3;
    struct word* list = (struct word*) malloc(sizeList*sizeof(struct word));
    int countElem = getListWords(&list,&sizeList);


    return 0;
}

int get_word(char *s, int n){
    char c;
    int i = 0;
    //���������� ��� ������ �������
    c = getchar();
    while((c != '\n') && (c <= ' '))
        c = getchar();

    if(c != '\n'){
        do{
            if (i > n)
                return EOF;
            *(s+i++) = c;
            c = getchar();
        }while(c > ' ');
        *(s+i) = '\0';
        return i;
    }

    return 0;
}

int getListWords(struct word **list, int *size){
    int lenWord;
    int count = 0;
    char *s = (char *) malloc(BUF*sizeof(char));
    //������ ���� �� ���������� �����
    while((lenWord = get_word(s,BUF)) != 0){
        //���� ����� ��� ������ ���� ���� �� �������,
        //�� �������� �٨ ������
        if(count >= *size)
            *list = getMoreMemory(*list,size);

        (*list)[count].s = (char *) malloc(lenWord*sizeof(char));
        copyStr(s,(*list)[count].s);
        (*list)[count].length = lenWord;
        count++;
    }
    free(s);
    return count;
}

struct word *getMoreMemory(struct word *list,int *size){
    int i;
    struct word* t = (struct word*) malloc((*size*2)*sizeof(struct word));//����� ��� ������ ������� ������
    //�������� ������ ������ �� ������ ������
    for (i = 0; i < *size; i++){
        t[i].length = list[i].length;
        t[i].s = list[i].s;
    }
    free(list);//������� ������ ������� �������
    *size *= 2;
    return t;
}

void copyStr(char *a,char *b){//�������� ������ 1 � ������ 2
    int i = 0;
    while(*(a+i) != '\0'){
        *(b+i) = *(a+i);
        i++;
    }
    *(b+i) = '\0';
}

void freeList(struct word *list,int countElement){
    int i; //������� ������� ������ � ������ ����������, �������������� ��� �����
    for(i = 0; i < countElement; i++)
        free(list[i].s);
    free(list);
}

