#include <stdio.h>
#include <stdlib.h>
#include "TABLEE.h"

void TableInit(Table_M* T)
{
    T -> uk = 0;
}

void TableDone(Table_M* T)
{
    T -> uk = 0;
}

void TablePut(Table_M* T, t_index key, base_type E)
{
	if(!T -> uk)
	{
		T -> mass[0].key = key;
		T -> mass[0].data = E;
		T -> uk = 1;
	}
	else
	{
		t_index uk_center;
		{t_index left = 0, right = T -> uk;
		while( left <= right )
		{
			uk_center = (right - left) / 2;
			if(key < T -> mass[uk_center].key) right = uk_center - 1;
			else if(key > T -> mass[uk_center].key) left = uk_center - 1;
			else break;
		}}
		if(key == T -> mass[uk_center].key) T -> mass[uk_center].data = E;
		else if(T -> uk != Table_Size)
		{
			t_index i = T -> uk;
			if(key > T -> mass[uk_center].key)	++uk_center;
			while(i > uk_center)
			{
				T -> mass[i] = T -> mass[i - 1];
				--i;
			}
			T -> mass[i].key = key;
			T -> mass[i].data = E;
			T -> uk += 1;
		}
		else Table_Error = Table_FULL;
	}
}

void TableGet(Table_M* T, t_index key, base_type* E)
{
	if(!T -> uk) {Table_Error = Table_EMPTY; return;}
	t_index uk_center;
	{t_index left = 0, right = T -> uk;
	while( left <= right )
	{
		uk_center = (right - left) / 2;
		if(key < T -> mass[uk_center].key) right = uk_center - 1;
		else if(key > T -> mass[uk_center].key) left = uk_center - 1;
		else break;
	}}
	if(key == T -> mass[uk_center].key) *E = T -> mass[uk_center].data;
	else Table_Error = NoKey;
}

int TableEmpty(Table_M* T)
{return !T -> uk;}

int TableFull(Table_M* T)
{return T -> uk == Table_Size;}
