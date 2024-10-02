#include <stdio.h>


int strLen(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

void get_word(char *s, int *pos, char *w) {
    int n = strLen(s);
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

void strCat(char *s1, char *s2) {
    int ns1 = strLen(s1);
    int ns2 = strLen(s2);
    int is1 = 0, is2 = 0;
    while (is2 < ns2) {
        s1[ns1 + is1] = s2[is2];
        is1++;
        is2++;
    }
    s1[ns1 + is1] = '\0';

}

void new_word(char *word, char *newword) {
    int i = 0, posnumber = 0, posword = 0;
    char number[100] = "";
    int nword = strLen(word);
    while (i < nword) {
        if (word[i] >= '0' && word[i] <= '9') {
            number[posnumber] = word[i];
            posnumber++;

        } else {
            newword[posword] = word[i];
            posword++;
        }
        i++;
    }
    strCat(newword, number);
    strCat(newword, " ");

}

void new_line(char *s, char *newline) {
    int n = strLen(s);
    int pos = 0;
    while (pos < n) {
        char word[100] = "";
        char newword[100] = "";
        get_word(s, &pos, word);
        new_word(word, newword);
        strCat(newline, newword);

    }
}


int main() {
    char s[100], newline[100] = "";
    gets(s);
    new_line(s, newline);
    puts(newline);
    return 0;
}