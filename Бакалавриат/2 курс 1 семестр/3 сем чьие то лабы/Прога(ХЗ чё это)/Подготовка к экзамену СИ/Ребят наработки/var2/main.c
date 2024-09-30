#include <stdio.h>
#include <stdlib.h>

#define STRLEN 50
#define POWSET 30


int solution(char *);
//0 - если прописная
//1 - если  строчная
int isBig(char);


int main()
{
    char filename[STRLEN];
    gets(filename);

    int t = solution(filename);

    printf("%d\n",t);
    return 0;
}

int solution(char *namef){
    FILE *readF = fopen(namef,"r");
    FILE *writeF = fopen("tmp.txt","w");//временный файл


    int count = 0;//позиция для записи во множестве
    int setChar[POWSET] = {0}; //множество символов

    char c;// читаем символы из файла

    int t;
    int k;

    while(!feof(readF)){
        c = fgetc(readF);
        t = isBig(c);
        if (t >= 0){
            if(t)
                k = c - 'a';
            else
                k = c - 'A';

            if(setChar[k] == 0){
                setChar[k] = 1;
                count++;
                if(t) c = c - ('a' - 'A');

            }
        }

        fputc(c,writeF);
    }



    fclose(readF);
    remove(namef);

    fclose(writeF);
    rename("tmp.txt",namef);


    return count;
}

//0 - если прописная (большая)
//1 - если  строчная (маленькая)
//-1 - если не лат.
int isBig(char c){
    int b = -1;
    if((c >= 'A') && (c <= 'Z'))
        b = 0;

    if((c >= 'a') && (c <= 'z'))
        b = 1;

    return b;
}

