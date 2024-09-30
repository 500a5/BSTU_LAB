

#ifndef ASD_6_HASH_TABLE_H
#define ASD_6_HASH_TABLE_H
static const short TableOk = 0;
static const short TableNotMem = 1;
static const short TableNotKey = 2;
static const short TableEmpty = 3;

short TableError;

typedef int KeyType;
typedef int BaseType;

typedef int (*hash)(int);

typedef struct eltable
{
    KeyType key;
    BaseType e;
    struct eltable* next;
};

typedef struct
{
    hash h;
    struct eltable** buf;
    unsigned n;
    unsigned sizeBuf;
} Table;

void InitTable(Table* t, unsigned sizeBuf, hash h);
int PutTable(Table* t, KeyType key, BaseType e);
int GetTable(Table* t, KeyType key, BaseType* e);
int EmptyTable(Table* t);
void DoneTable(Table* t);

#endif //ASD_6_HASH_TABLE_H
