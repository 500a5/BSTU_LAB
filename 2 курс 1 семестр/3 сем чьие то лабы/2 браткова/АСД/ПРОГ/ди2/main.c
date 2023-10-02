#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "form4.h"


int main()
{
    string1 s1,s2,s3;
    InputStr(&s1);
    InputStr(&s2);

    unsigned ch = LastPos(s1, s2);
    printf("%d", ch);

    return 0;
}

