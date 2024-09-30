#include <stdio.h>
#define Write(a,f) fwrite(&a, sizeof(char), 1, f)
#define Read(a,f) fread(&a, sizeof(char), 1, f)

char Read_word(FILE *f, char s[], char *c);
int include(char nametwo[], char s[]);
void aAbBcC(char s[]);
void AaBbCc(char s[]);

void main(){
    char nameone[30], nametwo[128], namethree[128], c, s[128];
    printf("enter name file f: ");
    scanf("%s",nameone); // C:\Users\Home\Desktop\f.txt
    printf("enter name file slovo: ");
    scanf("%s",nametwo);
    FILE *f = fopen(nameone,"r");

    while(Read_word(f,s,&c)){
        if(include(nametwo,s))
            aAbBcC(s);
        else
            AaBbCc(s);
        printf("%s",s);
        printf("%c",c);
    }
    fclose(f);
}

char Read_word(FILE *f, char s[], char *c){
    int j=0;
    while(Read(*c,f))
    if((*c >= 'A')&&(*c <= 'Z')||(*c >= 'a')&&(*c <= 'z'))
        s[j++] = *c;
    else{
        s[j] = '\0';
        return *c;
    }
}

int include(char nametwo[], char s[]){
    FILE *f = fopen(nametwo,"r");
    char c, e[128];
    int i;
    while(Read_word(f,e,&c)){
        i=0;
        while((s[i]==e[i])&&(s[i]!='\0'))
            i++;
        if(s[i]==e[i]){
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void aAbBcC(char s[]){
    int i=0;
    while(s[i]!='\0'){
        if((s[i]>'a'-1)&&(s[i]<='z'))
            s[i] = s[i]-('a'-'A');
        i++;
    }
}

void AaBbCc(char s[]){
    int i=0;
    while(s[i]!='\0'){
        if((s[i] > 'A'-1)&&(s[i]<='Z'))
            s[i] = s[i]+('a'-'A');
        i++;
    }
}
