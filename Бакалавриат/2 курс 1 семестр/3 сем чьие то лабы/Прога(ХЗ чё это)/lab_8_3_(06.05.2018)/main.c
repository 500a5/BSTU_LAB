#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define BUF 15 //максимальная длинна слова

struct word{
    char *s;
    int length;
};

int getListWords(struct word **,int *);// записываем слова из потока в список
int get_word(char *,int);//получает слово из потока
void copyStr(char *,char *);//копирует строку 1 в строку 2
void freeList(struct word *,int);//очищает память выделенную списку
struct word *getMoreMemory(struct word *,int *);//увеличивает список в 2 раза без потери данных

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
    //пропускаем все пустые символы
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
    //читаем пока не закончатся слова
    while((lenWord = get_word(s,BUF)) != 0){
        //ЕСЛИ МЕСТА ДЛЯ ЗАПИСИ ВСЕХ СЛОВ НЕ ХВАТИЛО,
        //ТО ВЫДЕЛИТЬ ЕЩЁ ПАМЯТИ
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
    struct word* t = (struct word*) malloc((*size*2)*sizeof(struct word));//место под массив двойной длинны
    //копируем первый массив во второй массив
    for (i = 0; i < *size; i++){
        t[i].length = list[i].length;
        t[i].s = list[i].s;
    }
    free(list);//очищаем память первого массива
    *size *= 2;
    return t;
}

void copyStr(char *a,char *b){//копирует строку 1 в строку 2
    int i = 0;
    while(*(a+i) != '\0'){
        *(b+i) = *(a+i);
        i++;
    }
    *(b+i) = '\0';
}

void freeList(struct word *list,int countElement){
    int i; //сначало очищаем память в каждой струкутуре, преднозначеную для слова
    for(i = 0; i < countElement; i++)
        free(list[i].s);
    free(list);
}

