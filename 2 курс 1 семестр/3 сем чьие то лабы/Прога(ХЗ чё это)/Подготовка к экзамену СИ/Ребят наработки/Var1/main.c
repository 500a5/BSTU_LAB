#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int size;
    char color[20];
} xyi;
xyi dima_shlen[5][4];
dima_shlen[2][3].size = 4;

выделение памяти
int **a; int n = 3; int m = 5;
a = (int **) malloc(n*sizeof(int *));
int i;
for(i = 0; i < n; i++)
    a[i] = (int *) malloc(m* sizeof(int));

удаление памяти
int **a; int n = 3; int m = 5;
int i;
for(i = 0; i < n; i++)
    free(a[i]);
free([a]);





void strCopy(char a[],char b[]); a[i] = 'y';

void (int **a,int m,int n); a[i][j]  = *(*(a+i) + j)
int *lol(char kek);

void strCopy(char *a,char *b); *(a+i) = 'x'
//указатель на функцию strCopy
void (*pCopy)(char *,char *) = &strCopy;

//перадача указателя на функцию
void lol(char a, char b, void (*pCopy)(char *,char *)){
    pCopy(a,b);
}

файлы

FILE * lox = fopen("chlen.txt","r");
текстовые
r чтение(если нет  файла, то fopen вернёт NULL)
w записи
r+ для чтения и записи (если нет  файла, то fopen вернёт NULL)
w+ для чтения и записи

функции для текстовые теже, что  и для консоли
только  в начле  функции дописывается буквочка f
и первый параметр FILE *
Пример: fprintf(FILE *,"твоя строка с переменнымит", сами переменные);



бинарные (тоже самое что и  в текстовом)
FILE * lox = fopen("chlen.bin","rb");
rb
wb
r+b
w+b

fread(адрес переменной, её размер в байтах, 1, указатель на твой файл);
fwrite(тоже самое);

fseek(твой файл, позиция элемента * sizeof(тип, который записан в твой файл), SEEK_SET);

для всего
fclose(указатель на файл);
remove("путь пример : твоямамка\\мойчлен\\ты.(что угодно сука)");
rename("старый путь","новый путь");







