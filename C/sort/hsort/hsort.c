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

		if(right < num && comp(lchild, rchild) < 0)
			small = right;
		else
			small = left;

		midchild = (char *) base + mid * width;
		smallchild = (char *) base + small * width;

		if(comp(midchild, smallchild) > 0)
			return;			// since its already lesser, no need to swap

		// else bubble the lesser element up by swapping it
		swap(midchild, smallchild, width);

		mid = small;
	}
}

static void heapify(void *base, unsigned num, unsigned width, int (*comp)(const void *, const void *))
{
	int mid;

	mid = floor(num / 2);

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

	if(num == 0)
		return;

	heapify(base, num, width, comp);

	do
	{
		next = base;
		last = (char *) base + (num - 1) * width;

		swap(next, last, width);

		num--;

		if(num > 0) {
			sift(base, 0, num, width, comp);
		}

	}while(num > 0);
}
