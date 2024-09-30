#include "str.h"
#include <stdio.h>

short STRING_ERROR;



int maxN=1024;
//Запись данных в строку st из строки s
//Строка s заканчивается нулевым символом
void WriteToStr(string1 st, char *s){
    int i = 0;
    while (s[i] != '\0'){
        st->s[i] = s[i];
        i++;
    }
    st->N = i;
    st->s[i++] = '\0';
    if(i == maxN)
        STRING_ERROR = STRING_INPUT_ERROR;
    else
        STRING_ERROR = STR_SUCCESSFUL;

}

//Запись данных в строку s из строки st
//Строка s заканчивается нулевым символом
void WriteFromStr(char *s, string1 st){
    int i = 0;
    while (st->s[i] != '\0'){
        s[i] = st->s[i];
        i++;
    }
    st->N = i;
    s[i++] = '\0';

    STRING_ERROR = STR_SUCCESSFUL;

}

//Ввод строки s с клавиатуры
void InputStr(string1 st)
{

    char k = getchar();

    unsigned short i = 0;

    while ((k != EOF && k != '\n') && (i < maxN)){

        st->s[i] = k;

        ++i;
        k = getchar();

    }

    st->N = i;

    st->s[i++] = '\0';


    if((i == maxN) && (k != EOF && k != '\n'))
        STRING_ERROR = STRING_INPUT_ERROR;
    else
        STRING_ERROR = STR_SUCCESSFUL;

}
//Вывод строки s на экран монитора
void OutputStr(string1 st){
    int i = 0;
    char a;
    while (st->N != i){
        putchar(st->s[i]);
        i++;
    }
    STRING_ERROR = STR_SUCCESSFUL;
}

//Выполняет конкатенацию строк s1 и s2 результат помещает в sRez
void Concat(string1 s1, string1 s2, string1 srez){
    if(s1->N+s2->N>srez->N){
        STRING_ERROR = STRING_CONCATEN_ERROR;
    }
    for (int i = 0; i<s1->N; i++){ //Скопируем в срез первую строку
        srez->s[i] = s1->s[i];
    }
    int i = s1->N;
    for (int j = 0; j<s2->N; j++){ //Соединим срез со второй строкой
        srez->s[j+i] = s2->s[j];
    }
    srez ->N = s1->N + s2->N;
    srez->s[srez->N] = '\0';
}


//Сравнивает строки s1 и s2 возвращает 0 если
//s1 == s2; 1 если s1 > s2; -1 если s1 < s2
int Comp(string1 s1, string1 s2){
    int i = 0;
    if (s1->N > s2->N){
        STRING_ERROR = STR_SUCCESSFUL;
        return 1;
    }
    if (s2->N > s1->N){
        STRING_ERROR = STR_SUCCESSFUL;

        return -1;}
    while ((s1->s[i] == s2->s[i])&&(i < s1->N)){
        i++;
    }
    if ((i == s1->N)&&(i == s2->N)) {
        STRING_ERROR = STR_SUCCESSFUL;
        return 0;
    }
    if (s1->s[i] > s2->s[i]) {
        STRING_ERROR = STR_SUCCESSFUL;

        return 1;
    }//Первая строка больше, первый из неравных символов имеет больший код
    if (s1->s[i] < s2->s[i]){
        STRING_ERROR = STR_SUCCESSFUL;

        return -1;
}
}


//Удаляет count символов из строки s
//начиная с позиции index
void Delete(string1 s, unsigned Index, unsigned Count){
    for (int i = Index; i < s->N; i++){
        s->s[i] = s->s[i+Count];    }
    s->s[s->N - Count] = '\0';
    s->N = s->N - Count;
    STRING_ERROR = STR_SUCCESSFUL;
}


//Вставляет подстроку subS в строку s
//начиная с позиции index
void Insert(string1 subS, string1 s, unsigned index)
{

    if (index > s->N)
        STRING_ERROR = STRING_NO_PLACE;
    else if(subS->N + s->N > maxN)
        STRING_ERROR = STRING_INSERT_ERROR;
    else{

        unsigned short i = s->N + 1;

        while (i >= index){

            s->s[i + subS->N] = s->s[i];
            --i;
        }

        i = index;
        unsigned short j = 0;

        while (j < subS->N){

            s->s[i] = subS->s[j];
            ++i;
            ++j;

        }
        s->N=s->N+subS->N;


    }

}





//Записывает count символов в строку subS из строки s
//начиная с позиции index
void Copy(string1 s, unsigned index, unsigned count, string1 subS)
{
    if(index + count > s->N)
        STRING_ERROR =  STRING_NO_PLACE;
    else if(count > maxN)
        STRING_ERROR =  STRING_NO_PLACE;
    else{
        unsigned short i     = 0;
        unsigned short rBord = index + count;

        while (index < rBord){

            subS->s[i] = s->s[index];
            ++i;
            ++index;

        }
        subS->N = i;
        STRING_ERROR = STR_SUCCESSFUL;

    }

}

//Возвращает текущую длинну строки s
unsigned Length(string1 s){
    return s->N;
}
//Возвращает позицию начиная с которой в строке s
//распологается строка subS или длинну строки если ее нет то 0
unsigned Pos(string1 subS, string1 s)
{
    unsigned short j = 0;
    unsigned short lens = s->N;
    unsigned short lensubS = subS->N;
    unsigned short len=lens-lensubS;
    if(s->N<subS->N)
        STRING_ERROR = STRING_Pos_ERROR;
    else
        STRING_ERROR = STR_SUCCESSFUL;
    for (unsigned short i = 0; i <= len; ++i){
        j = 0;
        while ((j < subS->N) && (s->s[i + j] == subS->s[j]))
            ++j;
        if(j == subS->N)
            return i+1;
    }
    return 0;
}
