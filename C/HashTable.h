/*
 * HashTable.h
 *
 *  Created on: Jan 7, 2014
 *      Author: rashmi
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_


typedef struct Table
{
	int value;
	struct Table *next;
}Table;

typedef struct HashTable
{
	int size;
	Table **table;
}HashTable;

HashTable *createHashTable(int sizeOfTable);

#endif /* HASHMAP_H_ */
