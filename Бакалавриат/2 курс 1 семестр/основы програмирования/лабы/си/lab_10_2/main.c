#include <stdio.h>
#include <string.h>
#include <io.h>

void inputFile(char* fname,int n){
    FILE *F ;
    int number[n];
    F = fopen(fname, "wb");
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <n ; ++j) {
            scanf("%d",&number[j]);
        }
        fwrite(number, sizeof(int), n, F);
    }
    fclose(F);
}

int max_el(const int *a,int n){
    int max=a[0];

    for (int i = 1; i <n ; ++i) {
        if (a[i]>max){
            max=a[i];
        }
    }

    return max;
}

void new_text(char *fname, int n){
    FILE *F;
    int a[n];
    int j=0,pos;
    F=fopen(fname,"rb+");
    while (fread(a, sizeof(int),n,F)){
        pos=ftell(F);
        int max=max_el(a,n);
        fseek(F, sizeof(int)*j,SEEK_SET);
        j++;
        fwrite(&max, sizeof(int),1,F);
        fseek(F,pos,SEEK_SET);
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
    int n=3;
    gets(fname);
    inputFile(fname,n);
    new_text(fname,n);
    output(fname);
    return 0;
}