#include "hsort.h"
#include<stdio.h>
#include<math.h>

static void swap(char *num1, char *num2, unsigned width) {
	char tmp;

	if (num1 != num2) {
		while (width--) {
			tmp = *num1;
			*num1++ = *num2;
			*num2++ = tmp;
    		}
  	}
}

// here the array ordering starts from zero but logically for sift operation, array indexing is assumed to start from 1.
static void sift(void *base, unsigned mid, unsigned num, unsigned width, int (*comp)(const void *, const void *))
{
	int left, right;
	int small;

	char *rchild, *lchild;
	char *midchild, *smallchild;

	while(mid < floor(num / 2)) {
		left = (mid + 1) * 2 - 1;
		right = left + 1;

		lchild = (char *) base + left * width;
		rchild = (char *) base + right * width;

#ifdef TEST
	printf("left index: %d, right index: %d\n", left, right);
	printf("lchild: %d, rchild: %d\n", *(int *) lchild, *(int *)rchild);
#endif

		if(right < num && comp(lchild, rchild) < 0)
			small = right;
		else
			small = left;

		midchild = (char *) base + mid * width;
		smallchild = (char *) base + small * width;

#ifdef TEST
	printf("mid: %d, small: %d\n", *(int *) midchild, *(int *) smallchild);
#endif

		if(comp(midchild, smallchild) > 0)
			return;			// since its already lesser, no need to swap

#ifdef TEST
	printf("small index: %d\n", small);
	printf("swapping %d with %d\n", *(int *)midchild, *(int *)smallchild);
#endif

		// else bubble the lesser element up by swapping it
		swap(midchild, smallchild, width);

		mid = small;

#ifdef TEST
	printf("mid: %d\n", mid);
#endif

	}
}

void heapify(void *base, unsigned num, unsigned width, int (*comp)(const void *, const void *))
{
	int mid;

	mid = floor(num / 2);

#ifdef TEST
	printf("mid: %d\n", mid);
#endif

	while(mid >= 0) {
		sift(base, mid - 1, num, width, comp);

		mid--;
	}
}

void hsort(void *base, unsigned num, unsigned width, int (*comp)(const void *, const void *))
{
	char *next;
	char *last;
	int i;

	heapify(base, num, width, comp);

#ifdef TEST
	printf("heapified array: ");

	for(i = 0; i < num ; i++) {
		printf("%d, ", *(int *) (base + i * width));
	}

	printf("\n");
#endif
	do
	{
		next = base;
		last = (char *) base + (num - 1) * width;

		swap(next, last, width);

		num--;

		if(num > 0) {
			heapify(base, num, width, comp);
		}

	}while(num > 0);
}
