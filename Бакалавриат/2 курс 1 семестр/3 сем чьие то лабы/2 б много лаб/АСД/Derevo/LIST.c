#include <stdio.h>
#include <stdlib.h>
#include "LIST.h"

short int ListError;

void InitList(List **L){
  *L=(List *)malloc(sizeof(List));
  if(*L){
    (*L)->start=(ptrel)malloc(sizeof(Element));
    if((*L)->start){
      (*L)->start->next=NULL;
      (*L)->ptr=(*L)->start;
      (*L)->n=0;
      ListError=ListOk;
    } else ListError = ListNotMem;
  } else ListError = ListNotMem;

}

int EmptyList(List *L){
  ListError = ListOk;
  return (L->n == 0);
}

int EndList(List *L){
  ListError = ListOk;
  return (L->ptr->next == NULL);
}

unsigned int Count(List *L){
  return L->n;
}

void PutList(List *L,Basetype E){
    ptrel buf=(ptrel)malloc(sizeof(Element));
    if(buf){

      buf->next=L->ptr->next;
      L->ptr->next=buf;
      L->ptr=L->ptr->next;
      L->ptr->data=E;
      L->n++;
      ListError = ListOk;
    }
    else
      ListError=ListNotMem;
    }

void ReadList(List *L,Basetype *E){
  if(!EmptyList(L)){
    if (L->ptr != L->start)
    {
      *E = L->ptr->data;
      ListError = ListOk;
    }
    else{
      *E = L->ptr->next->data;
      ListError = ListOk;
    }
  }
  else
    ListError = ListEmpty;
}

void GetList(List *L,Basetype *E){
  if(!EmptyList(L)){
    ptrel buf=L->ptr->next;
    *E=buf->data;
    //if (buf->next)
      L->ptr->next=buf->next;
    L->n--;
    free(buf);
    ListError = ListOk;
   }
   else
     ListError = ListEmpty;
}

void BeginPtr(List *L){
  if (!EmptyList(L)){
    L->ptr = L->start;
    ListError = ListOk;
  } else
    ListError = ListEmpty;
}

void EndPtr(List *L){
  if (!EmptyList(L)){
    while(!EndList(L)){
      L->ptr = L->ptr->next;
    }
    ListError = ListOk;
  } else
    ListError = ListEmpty;
}

void MovePtr(List *L){
  if (!EmptyList(L)){
    if (!EndList(L)){
      L->ptr = L->ptr->next;
      ListError = ListOk;
    } else
      ListError = ListEnd;
  } else
    ListError = ListEmpty;
}

void MoveTo(List *L,unsigned int n){
  int k;
  if (!EmptyList(L)){
    if (n<=L->n){
      L->ptr = L->start;
      for(k = 0; k < n; k++)
        MovePtr(L);
      ListError = ListOk;
    }
  } else
    ListError = ListEmpty;
}

void DoneList(List *L){
  ListError = ListOk;
  EndPtr(L);
  int i;
  for(i = L->n; i>0; i--){
    Basetype E;
    GetList(L, &E);
  }
  free(L);
}

void CopyList(List *L1,List *L2){
  Basetype E;
  if(!EmptyList(L1)){
    InitList(&L2);
    L1->ptr=L1->start->next;
    int i;
    for(i=0; (i<L1->n)&&ListError!=ListNotMem; i++){
      ReadList(L1,&E);
      PutList(L2,E);
      MovePtr(L1);
    }
  }
}



