#include <stdio.h>
#include <stdlib.h>
#include "str.h"



unsigned LastPost(string1 s1,string1 s2){
    unsigned short lens1=s1->N;
    unsigned short lens2=s2->N;
    STRING_ERROR = STR_SUCCESSFUL;
    unsigned short n,i=1,q=0;
    n=Pos(s2,s1);
    while(n!=0&&i<lens1&&lens1>lens2) {
        q+=n;
        n=Pos(s2,s1);
        Delete(s1,0,(n+lens2));
        i++;
    }
    return q;

}
int main() {
    string1 string_1 , string_2;

    InputStr(string_2);
    printf("Error: %d\n", STRING_ERROR);
    InputStr(string_1);
    printf("Error: %d\n\n", STRING_ERROR);

   printf("LastPost %d\n", LastPost(string_1,string_2));
    printf("Error: %d\n\n", STRING_ERROR);

    return 0;
}
