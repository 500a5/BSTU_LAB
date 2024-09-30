#include <stdio.h>

#include "DLL.h"

int main() {

    DLL list;
    t_baseDLL E;
    initDLList(&list);

    printf("DLL_ERROR %d\n", DLL_ERROR);

    putDLListPost(&list, 3);
    printf("DLL_ERROR %d\n", DLL_ERROR);

    putDLListPost(&list, 2);
    printf("DLL_ERROR %d\n", DLL_ERROR);

    putDLListPred(&list, 1);
    printf("DLL_ERROR %d\n", DLL_ERROR);

    DLListPtrEnd(&list);
    getDLListPred(&list, &E);
    printf("%d\n", E);
    printf("DLL_ERROR %d\n", DLL_ERROR);

    DLListPtrBegin(&list);
    getDLListPost(&list, &E);
    printf("%d\n", E);
    printf("DLL_ERROR %d\n", DLL_ERROR);

    getDLListPost(&list, &E);
    printf("%d\n", E);
    printf("DLL_ERROR %d\n", DLL_ERROR);


    DLListDone(&list);

    return 0;
}
