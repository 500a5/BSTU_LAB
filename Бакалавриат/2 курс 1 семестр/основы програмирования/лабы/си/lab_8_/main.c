#include <stdio.h>
#include <malloc.h>
#include <process.h>
#include <string.h>

int get_word(char*s,int *pos,char*w){
    int n=strlen(s);
    int i=0;
    while (*pos<n &&s[*pos]<=' ' ){
        ++*pos;
    }
    while (*pos<n &&s[*pos]>' ' ){
        w[i]=s[*pos];
        i++;
        ++*pos;
    }
    w[i]='\0';
    return i;
}

void SetWord(char s[20], char *a){
    int i = 0;
    while( s[i] != '\0' ){
        a[i] = s[i];
        i++;
    }
    a[i] = '\0';
}

int poisk_el (char ** a,int n, char *key){
    int k=0,m=0;
    int lenkey=strlen(key);
   for (int i=0;i<n;i++){
        for (int j = 0; j < lenkey; ++j) {
            if (key[j]==a[i][j]){
                k++;
            }
        }
        if (k==lenkey){
            m++;
        }
        k=0;

    }
    if(m>0){
        return 1;
    }
    else{
        return 0;
    }
}

char **giv_memory(int length,int n, char**t){
    t = (char **) realloc(t, (n + 1) * sizeof(char *));
    t[n] = (char *) calloc(length, sizeof(char));
    return t;
}

char **write_arr_str(char *text, int *n){
    int i = 0;
    char **t = NULL;
    char word[20] = {};
    while( text[i] != '\0'){
        int  length =  get_word(text,&i,word);
        if(poisk_el(t,*n,word)==0) {
            t = giv_memory(length,*n,t);
            SetWord(word, t[*n]);
            ++*n;
        }
    }
    return t;

}

char **A_and_B (char ** t1, char ** t2, int nt1, int nt2, int* n_newt ){
    char **t = NULL;
    for (int i = 0; i < nt1 ; ++i) {
        int length=strlen(t1[i]);
        if(poisk_el(t2,nt2,t1[i])==1){
            t = giv_memory(length,*n_newt,t);
           t[*n_newt]=t1[i];
            ++*n_newt;
        }
    }
    return t;
}
void freee (char **newt, int n_newt) {
    for (int i = 0; i < n_newt; i++) {
        free(newt[i]);
    }
    free(newt);
}

void  output(char **newt, int n_newt){
    for(int i = 0; i < n_newt; i++){
        puts(newt[i]);
    }
}
int main() {
    char text1[] = {"vfd fvdvv df world! df world! world!"},
         text2[] = {" vfd Hello  world!"},
         **t1 = NULL,
         **t2 = NULL,
         **newt=NULL;
    int nt1 = 0,
        nt2 = 0,
        n_newt=0;
    t1=write_arr_str(text1,&nt1);
    t2=write_arr_str(text2,&nt2);
    newt=A_and_B(t1,t2,nt1,nt2,&n_newt);
    output(newt,n_newt);
    freee(newt,n_newt);
    freee(t1,nt1);
    freee(t2,nt2);
    return 0;
}