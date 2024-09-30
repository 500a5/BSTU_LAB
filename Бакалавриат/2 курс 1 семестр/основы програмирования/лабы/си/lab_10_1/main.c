#include <stdio.h>
#include <string.h>
#include <malloc.h>

void get_word(char *s, int *pos, char *w) {
    int n = strlen(s);
    int i = 0;

    while (*pos < n && s[*pos] <= ' ') {
        ++*pos;
    }

    while (*pos < n && s[*pos] > ' ') {
        w[i] = s[*pos];
        i++;
        ++*pos;
    }
    w[i] = '\0';
}

void new_text(char *fname, char *str){
    FILE *F,*newF;
    char s[250],
         word[20],
         new_f[]={"new.txt"};
    int pos=0,n;

    F = fopen(fname, "r+");
    newF= fopen(new_f, "w+");
    while ( fgets(s, 100, F)   ) {
        char news[100]={} ;
        n = strlen(s);
        while (pos < n) {
            get_word(s, &pos, word);
            if (strstr(word,str)!=NULL){
                strcat(news,word);
                strcat(news," ");

            }
        }
        fputs(news,newF);
        fputs("\n",newF);
        pos=0;
    }
    fclose(F);
    fclose(newF);
    remove(fname);
    rename(new_f,fname);
}

int main() {
    char fname[20],
         STR[]="dv";
    gets(fname);
    new_text(fname,STR);
    return 0;
}