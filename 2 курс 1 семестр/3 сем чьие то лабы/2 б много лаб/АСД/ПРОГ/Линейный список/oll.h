#ifndef OLL_H
#define OLL_H

#ifndef base_type
	#define base_type int
#else
	#define base_type_non_include_list
#endif

#ifndef t_index
	#define t_index long long unsigned int
#endif

const short List_OK = 0;
const short List_Empty = -1;
const short List_Not_Memory = -2;
const short List_End = -3;

extern short List_Error = 0;

struct elem_list
{
	base_type data;
	struct elem_list *ptr;
};

typedef struct elem_list elem_list;

typedef elem_list* elptr;

typedef struct{elptr start; elptr uk;} List;

void ListInit(List *L);
void ListDelete(List *L);

void ListPut(List * L, base_type E);
void ListGet(List * L, base_type* E);

void PtrBegin(List *L);
void ListMovePtr(List *L);
void PtrEnd(List *L);

int ListEmpty(List *L);
int ListEnd(List* L);


#include "OLL.c"

#ifndef base_type_non_include_list
	#undef base_type
#else
	#undef base_type_non_include_list
#endif

#endif
