
#ifndef ASD_6_LIST_H
#define ASD_6_LIST_H
static const short ListOk = 0;
static const short ListEmpty = 1;
static const short ListNotMem = 2;
static const short ListEnd = 4;

short ListError;

typedef struct{
    int data;
    unsigned time;
    int p;
} TInquiry;

typedef TInquiry BaseType;
typedef struct element* elptr;

typedef struct element
{
    BaseType data;
    elptr next;
};

typedef struct
{
    elptr start;
    elptr ptr;
} List;

void InitList(List* l);
void PutList(List* l, BaseType e);
void GetList(List* l, BaseType* e);
short EmptyList(List* l);
void BeginListPtr(List* l);
void EndListPtr(List* l);
void MovePtr(List* l);
void DoneList(List* l);

#endif //ASD_6_LIST_H
