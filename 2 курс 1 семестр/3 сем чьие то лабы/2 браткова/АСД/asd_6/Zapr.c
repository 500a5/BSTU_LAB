#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Zapr.h"

void ReadZapros (TInquiry *a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("name  >> ");
        scanf("%s", &a[i].Name);
        printf("time  >> ");
        scanf("%d", &a[i].Time);
        printf("prior >> ");
        scanf("%d", &a[i].P);
    }
}

void WriteZapros (TInquiry* a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("name  : %s\n", a[i].Name);
        printf("time  : %d\n", a[i].Time);
        printf("prior : %d\n", a[i].P);
        printf("\n");
    }
}

void GenZapros (TInquiry *a)
{
    int i;
    for (i=0; i<10; i++)
        a->Name[i] = rand()%(90-65+1) + 65;
        a->P = rand()%(2-0+1) + 0;
        a->Time = rand()%(90-65+1) + 65;
}

void WriteOneZapr (TInquiry a)
{
    printf("name  : %s\n", a.Name);
    printf("time  : %d\n", a.Time);
    printf("prior : %d\n", a.P);
}

void GenMassZapros (TInquiry *a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        GenZapros(&a[i]);
}
