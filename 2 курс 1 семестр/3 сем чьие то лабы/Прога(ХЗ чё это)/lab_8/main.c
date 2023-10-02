#include <stdio.h>
#include <stdlib.h>

int test_equil(char *, char *);
void search_short(FILE *, FILE *);
int get_word(FILE *, char *);

int main()
{
    FILE *fp1;

    FILE *fp2;

    search_short(fp1, fp2);

    return 0;
}

void search_short(FILE *fp1, FILE *fp2){
    int i = 1,j = 1, min = 100;
    int flag;
    char word[1000];
    int k;

    char name1[] = "file_1.txt";
    char name2[] = "file_2.txt";
    if ((fp1 = fopen(name1, "r")) == NULL){
        printf("Error");
    }

    while( !feof(fp1) ){
        char word1[100];
        i = get_word(fp1, word1);

        if ((fp2 = fopen(name2, "r")) == NULL){
            printf("Error");
            exit(0);
        }
        j = 1;
        flag = 1;
        while( (!feof(fp2)) && (flag) ){
            char word2[100];
            j = get_word(fp2, word2);

            if ((min >= i) && (i == j)){
                if (test_equil(word1, word2)){

                    if (min > i){
                        k = 0;
                        min = i;
                    }

                    int z = 0;
                    flag = 0;

                    while( z < i ){

                        word[k] = word1[z];
                        z++;
                        k++;
                    }

                    word[k] = ' ';
                    k++;
                }
            }
        }
        fclose(fp2);
    }
    fclose(fp1);
    word[k] = '\0';
    puts(word);

}

int get_word(FILE *fp1, char *word1){
    char c;
    int j = 0;

    while ( (c = fgetc(fp1)) == ' ' ){
        ;
    }
    while ( (c != ' ') && (c != EOF)){
        word1[j] = c;
        j++;
        c = fgetc(fp1);
    }
    word1[j] = '\0';
return j;
}

int test_equil(char *word1, char *word2){
    int i = 0;
    int flag = 1;

    while((flag) && (word1[i] != '\0') && (word2[i] != '\0')){

        if ( word1[i] != word2[i] )
            flag = 0;
        i++;
    }

    return flag;
}
