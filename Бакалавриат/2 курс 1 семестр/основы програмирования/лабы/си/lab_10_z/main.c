#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *F ;
    int number[]={5, 1, 2 };
    char *fname="g.bin";
    F = fopen(fname, "wb");


    for (int i = 0; i <3 ; ++i) {
        fwrite(number, sizeof(int), 3, F);
    }


    fclose(F);
    return 0;
}