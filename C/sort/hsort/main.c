#include <stdio.h>
#include "hsort.h"
#define MAX 1

typedef struct 
{
	int id;
	char name[20];
}block;

int cmpasc(const void *input1, const void *input2)
{
        const int elem1 = *(int *) input1;
        const int elem2 = *(int *) input2;

        if(elem1 < elem2)
                return -1;
        if(elem1 > elem2)
                return 1;

        return 0;
}

int main()
{
	block blk[MAX];

	int arr[MAX];// = {16, 47, 5, 12, 67, 21, 7};
	int i;
	int output[MAX];
	int limit = MAX - 1, outcntr = 0;

	for(i = 0; i < MAX; i++) {
		blk[i].id = MAX - i;
		arr[i] = rand() % MAX;
	}

	printf("array: ");

	for(i = 0; i < MAX; i++)
		printf("%d, ", arr[i]);

	printf("\n");

/*	heapify(arr, MAX);

	printf("min heap generated is: ");

	for(i = 0; i < MAX; i++)
		printf("%d, ", arr[i]);

	printf("now sorting\n");

	while(limit >= 0) {
		output[outcntr++] = arr[0];

		arr[0] = arr[limit];

		if(limit > 0) {
			limit--;	

			heapify(arr, limit + 1);
		}
		else
			break;
	}

	printf("sorted output: ");

	for(i = 0; i < MAX; i++)
		printf("%d, ", output[i]);

	printf("\n");*/

	hsort((void *) &arr, MAX, sizeof(int), cmpasc);

	printf("sorted output: ");

	for(i = 0; i < MAX; i++)
		printf("%d, ", arr[i]);

	printf("\n");

	return 0;
}
