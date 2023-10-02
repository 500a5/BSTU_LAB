

#ifndef ASD_5_OLL_H
#define ASD_5_OLL_H
#ifndef ASD_OLL_H
#define ASD_OLL_H

#include <malloc.h>

//Исключительные ситуации
static const int OLL_OK      = 0;
static const int OLL_EMPTY   = 1;
static const int OLL_NOT_MEM = 2;
static const int OLL_END     = 3;

//Переменная ошибки
extern short OLL_ERROR;

typedef int BaseTypeOLL;

//Элемент списка
typedef struct elementOLL
{

    BaseTypeOLL data;
    struct elementOLL *next;

}elementOLL;

typedef elementOLL *ELptr;

//Дескриптор списка
typedef struct
{
    //Указатель на фиктивный элемент(первый)
    ELptr Start;
    ELptr ptr;
    unsigned int N;

} OLList;

void InitOLList(OLList *L);
void PutOLList(OLList *L, BaseTypeOLL E);
void GetOLList(OLList *L, BaseTypeOLL *E);
void ReadOLList(OLList *L,BaseTypeOLL *E);
int EmptyOLList(OLList *L);
int EndOLList(OLList *L);
unsigned int Count(OLList *L);
void BeginPtr(OLList *L);
void EndPtr(OLList *L);
void MovePtr(OLList *L);
void MoveTo(OLList *L, unsigned int n);
void DoneOLList(OLList *L);
void CopyOLList(OLList *L1,OLList *L2);

#endif

#endif //ASD_5_OLL_H
