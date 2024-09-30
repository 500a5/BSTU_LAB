#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num{
    char s[10];
    char a[11];
}num;


void search(num **);

int main()
{
    int sizeList = 26;
    struct num** list = (struct num**) malloc(sizeList*sizeof(struct *num));




}




void search(num **list){

    int i = 0;
    char s[10];
    gets(s);

    int n = s[i] - 'A';
    num *p = list[n];
    while ( i < 20 ){

        if (strcmp(s, p[i].s)){
            gets(p[i].a);
            break;
        }
        i++;
    }
}
