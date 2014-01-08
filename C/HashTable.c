/*
 * HashMap.c
 *
 *  Created on: Jan 7, 2014
 *      Author: rashmi
 */

#include<stdio.h>
#include "HashTable.h"
#include <stdlib.h>


HashTable *createHashTable(int sizeOfTable)
{
	HashTable *hashTable;

	if((hashTable = malloc(sizeof(HashTable)))==NULL)
	{
		return NULL;
	}
	if((hashTable->table=malloc(sizeof(Table *)*sizeOfTable))==NULL)
	{
		return NULL;
	}
	return hashTable;
}





