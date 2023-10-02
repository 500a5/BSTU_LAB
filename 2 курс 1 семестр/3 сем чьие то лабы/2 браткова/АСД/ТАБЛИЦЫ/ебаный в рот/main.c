#include <stdio.h>
#include <stdlib.h>
#include "tabll.h"

int main()
{
    printf("Hello world!\n");

    table *tab = (table*)calloc(5, sizeof(table));
    int f = isEmptyTable(tab);

    printf("%d", f);
    return 0;
}
