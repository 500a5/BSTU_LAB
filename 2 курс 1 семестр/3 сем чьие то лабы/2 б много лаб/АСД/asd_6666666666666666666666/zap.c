#include <stdio.h>
#include <stdlib.h>
#include "zap.h"

void WriteOneZapr (TInquiry a)
{
    printf("name  : %s\n", a.Name);
    printf("time  : %d\n", a.Time);
    printf("prior : %d\n", a.P);
}

void ReadOneZapr (TInquiry a)
{
    printf("name  : %s\n", &a.Name);
    printf("time  : %d\n", &a.Time);
    printf("prior : %d\n", &a.P);
}
