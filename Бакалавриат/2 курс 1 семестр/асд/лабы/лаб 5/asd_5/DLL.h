
#ifndef ASD_5_DLL_H
#define ASD_5_DLL_H
#include "malloc.h"

static const short DLL_OK      = 0;
static const short DLL_EMPTY   = 1;
static const short DLL_NOT_MEM = 2;
static const short DLL_END     = 3;
static const short DLL_BEGIN   = 4;

extern short DLL_ERROR;

typedef int t_baseDLL;

typedef struct elementDLL *ELptr;

typedef struct elementDLL
{

    t_baseDLL Data;
    ELptr Llink;
    ELptr Rlink;

}elementDLL;

typedef struct
{

    ELptr first;
    ELptr last;
    ELptr ptr;
    int size;

}DLL;

void  initDLList(DLL *list);
void  putDLListPred(DLL *list, t_baseDLL E);
void  putDLListPost(DLL *list, t_baseDLL E);

void  getDLListPred(DLL *list, t_baseDLL *E);
void  getDLListPost(DLL *list, t_baseDLL *E);


void  DLListMoveL(DLL *list);
void  DLListMoveR(DLL *list);

short DLListEmpty(DLL *list);
short DLListBegin(DLL *list);
short DLListEnd(DLL *list);

void  DLListPtrEnd(DLL *list);
void  DLListPtrBegin(DLL *list);

void  DLListDone(DLL *list);

#endif //ASD_5_DLL_H
