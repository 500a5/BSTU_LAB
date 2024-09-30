
#include <stdlib.h>
#include "DLL.h"

short DLL_ERROR;

void  initDLList(DLL *list)
{
    list->last  = NULL;
    list->first = NULL;
    list->ptr   = NULL;
    list->size  = 0;
    DLL_ERROR = DLL_OK;
}
void  putDLListPred(DLL *list, t_baseDLL E)
{
    ELptr newEl = malloc(sizeof(elementDLL));
    if(newEl == NULL){
        DLL_ERROR = DLL_NOT_MEM;
        return;
    }
    newEl->Data = E;
    if(DLListEmpty(list)){
        list->first = newEl;
        list->last  = newEl;
        list->ptr   = newEl;
        newEl->Llink = NULL;
        newEl->Rlink = NULL;
    }else{
        newEl->Llink = list->ptr->Llink;
        newEl->Rlink = list->ptr;
        list->ptr->Llink = newEl;
        if(newEl->Llink == NULL)
            list->first = newEl;
    }
    DLL_ERROR = DLL_OK;
    ++(list->size);
}
void  putDLListPost(DLL *list, t_baseDLL E)
{
    ELptr newEl = malloc(sizeof(elementDLL));
    if(newEl == NULL){
        DLL_ERROR = DLL_NOT_MEM;
        return;
    }
    newEl->Data = E;
    if(DLListEmpty(list)){
        list->first = newEl;
        list->last  = newEl;
        list->ptr   = newEl;
        newEl->Llink = NULL;
        newEl->Rlink = NULL;
    }else{
        newEl->Rlink = list->ptr->Rlink;
        newEl->Llink = list->ptr;
        list->ptr->Rlink = newEl;
        if(newEl->Rlink == NULL)
            list->last = newEl;
    }
    DLL_ERROR = DLL_OK;
    ++(list->size);
}

void  getDLListPred(DLL *list, t_baseDLL *E)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return;
    }
    if(list->size == 1){
        *E = list->ptr->Data;
        free(list->ptr);
        list->last  = NULL;
        list->first = NULL;
        --(list->size);
        return;
    }
    if(DLListBegin(list)){
        DLL_ERROR = DLL_BEGIN;
        return;
    }
    ELptr delEl = list->ptr->Llink;
    list->ptr->Llink = delEl->Llink;
    if(list->ptr->Llink == NULL)
        list->first = list->ptr;
    else
        delEl->Llink->Rlink = list->ptr;
    *E = delEl->Data;
    free(delEl);
    DLL_ERROR = DLL_OK;
    --(list->size);
}
void  getDLListPost(DLL *list, t_baseDLL *E)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return;
    }
    if(list->size == 1){
        *E = list->ptr->Data;
        free(list->ptr);
        list->last  = NULL;
        list->first = NULL;
        --(list->size);
        return;
    }
    if(DLListEnd(list)){
        DLL_ERROR = DLL_END;
        return;
    }
    ELptr delEl = list->ptr->Rlink;
    list->ptr->Rlink = delEl->Rlink;
    if(list->ptr->Rlink == NULL)
        list->last = list->ptr;
    else
        delEl->Rlink->Llink = list->ptr;
    *E = delEl->Data;
    free(delEl);
    DLL_ERROR = DLL_OK;
    --(list->size);
}

void  DLListMoveL(DLL *list)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return;
    }
    if(DLListBegin(list)){
        DLL_ERROR = DLL_BEGIN;
        return;
    }
    list->ptr = list->ptr->Llink;
    DLL_ERROR = DLL_OK;
}
void  DLListMoveR(DLL *list)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return;
    }
    if(DLListEnd(list)){
        DLL_ERROR = DLL_END;
        return;
    }
    list->ptr = list->ptr->Rlink;
    DLL_ERROR = DLL_OK;
}
short DLListEmpty(DLL *list)
{
    return list->size == 0;
}
short DLListBegin(DLL *list)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return 1;
    }
    return list->ptr->Llink == NULL;
}
short DLListEnd(DLL *list)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return 1;
    }
    return list->ptr->Rlink == NULL;
}
void  DLListPtrEnd(DLL *list)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return;
    }
    list->ptr = list->last;
    DLL_ERROR = DLL_OK;
}


void  DLListPtrBegin(DLL *list)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return;
    }
    list->ptr = list->first;
    DLL_ERROR = DLL_OK;
}
void  DLListDone(DLL *list)
{
    if(DLListEmpty(list)){
        DLL_ERROR = DLL_EMPTY;
        return;
    }
    DLListPtrBegin(list);
    t_baseDLL E;
    while (DLListEnd(list)){
        getDLListPost(list, &E);
    }
    free(list->ptr);
    list->ptr   = NULL;
    list->last  = NULL;
    list->first = NULL;
    DLL_ERROR = DLL_OK;
}
