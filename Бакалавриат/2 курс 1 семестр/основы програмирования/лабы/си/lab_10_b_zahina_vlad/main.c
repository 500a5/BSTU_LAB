#include <stdio.h>
#include <string.h>
#include <io.h>
#define N 5
void inputFile(char* fname,int n){
    FILE *F ;
    int number;
    F = fopen(fname, "wb");
    for (int i = 0; i <n ; ++i) {
        scanf("%d",&number);
        fwrite(&number, sizeof(int), 1, F);
    }
    fclose(F);
}

void new_text(char *fname, int n){
    FILE *F;
    int a;
    int j=0,pos=0,m,flag=0;

    F=fopen(fname,"rb+");
    pos=ftell(F);
    while (fread(&a, sizeof(int),1,F)){
        if(a<0&& flag==0){
            flag++;
            pos=ftell(F)-  sizeof(int);
        }  else if(a>0) {
            j++;
            m=ftell(F);
            fseek(F,pos,SEEK_SET);
            fwrite(&a, sizeof(int),1,F);
            pos+=  sizeof(int);
            fseek(F,m,SEEK_SET);
        }
    }
    int df=fileno(F);
    chsize(df, sizeof(int) * j);
    fclose(F);
}
void output(char* fname){
    int a;
    FILE *F;
    F=fopen(fname,"rb");
    printf("\n");
    while (fread( &a, sizeof(int), 1, F)) {
        printf("%d ", a);
    }
    fclose(F);
}

int main() {
    char fname[20];
    gets(fname);
    inputFile(fname,N);
    new_text(fname,N);
    output(fname);
    return 0;
}