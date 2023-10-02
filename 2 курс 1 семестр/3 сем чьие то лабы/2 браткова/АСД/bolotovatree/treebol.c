#include "treebol.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

tree* InitTree(tree *t)
{
    t=NULL;
    treeError=treeOk;
    return t;
}

tree* CreateRoot(tree *t, char *w)
{
    t=(tree*)malloc(sizeof(tree));
    t->word=strdup(w);
    t->count=1;
    t->L_son=NULL;
    t->R_son=NULL;
    return t;
}

tree* PutTree(tree *t, char *w)
{
    short f;
    if(!t)
    {
        t=CreateRoot(t,w);
        return t;
    }
    f=strcmp(w,t->word);
    if(f==0)
        t->count++;
    else
        if(f<0)
            t->L_son=PutTree(t->L_son,w);
    else
        t->R_son=PutTree(t->R_son,w);
    return t;
}

tree* GetTree(tree *t, char *w)
{
    tree *z;
    short f;
    if(!t)
    {
        treeError=treeEmpty;
        return;
    }
    w=strdup(t->word);
    if(!t->L_son && !t->R_son)
        {
            free(t);
            t=NULL;
        }
    else
        if(t->L_son && t->R_son)
        {
            z=t->R_son;
            while(z->L_son)
                z=z->L_son;
            z->L_son=t->L_son;
            z->R_son=t->R_son;
            t=z;
        }
        else
            if(!t->L_son && t->R_son)
                t=t->R_son;
            else
                if(t->L_son && !t->R_son)
                    t=t->L_son;
    return t;
}

void OutputTree(tree *t)
{
    if(t)
    {
        OutputTree(t->L_son);
        printf("%i %s\n", t->count,t->word);
        OutputTree(t->R_son);
    }
}

tree* DeleteTree(tree *t)
{
    if(t)
    {
        free(t->L_son);
        free(t->R_son);
        free(t);
    }
    return t;
}

int isL_son(tree *t)
{
    if(!t)
    {
        treeError=treeEmpty;
        return 0;
    }
    if(t->L_son)
        return 1;
return 0;
}

int isR_son(tree *t)
{
    if(!t)
    {
        treeError=treeEmpty;
        return 0;
    }
    if(t->R_son)
        return 1;
return 0;
}

int isEmpty(tree *t)
{
    if(!t)
    {
        treeError=treeEmpty;
        return 1;
    }
    return 0;
}
