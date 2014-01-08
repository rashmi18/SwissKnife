/*
 * Driver.c
 *
 *  Created on: Jan 7, 2014
 *      Author: rashmi
 */


#include<stdio.h>
#include "HashTable.h"


int main()
{

	HashTable *hashTable;
	int size = 5;
	hashTable = createHashTable(size);
	if(hashTable==NULL)
		printf("\nHashTable could not be created");
	else
		printf("\nHashTable created successfully");
	return 0;
}

