//
//  arraypoints.c
//  d02_hw
//
//  Created by Slava Gubar on 23.02.2021.
//

#include "arraypoints.h"
#include <stdlib.h>
#include <string.h>

long reallocateInternalStorage(ArrayPoints *a, int requestedCount);

ArrayPoints *createArrayPoints(long preservedCount) {
	ArrayPoints *array = (ArrayPoints *)malloc(sizeof(ArrayPoints));

	if (NULL != array) {
		array->count = (preservedCount > 0) ? preservedCount : 1;
		array->storage = (Point **)malloc(sizeof(Point *) * array->count);
		bzero(array->storage, sizeof(Point *) * array->count);
	}

	return array;
}

void deleteArrayPoints(ArrayPoints *a) {
	if (NULL != a) {
		if (NULL != a->storage) {
			free(a->storage);
		}

		free(a);
	}
}

int setPointAtIndex(ArrayPoints *a, Point *value, int index) {
	if (NULL == a || index < 0) {
		return ArrayPointIndexError;
	}

	if (index >= a->count) {
		//reallocate internal storage
		if (ArrayPointIndexError == reallocateInternalStorage(a, index + 1)) {
			return ArrayPointIndexError;
		}
	}

	a->storage[index] = value;
	return index;
}

Point *getPointAtIndex(ArrayPoints *a, int index) {
	if (NULL == a || index < 0 || index >= a->count) {
		return NULL;
	}

	return a->storage[index];
}

void printArrayPoints(ArrayPoints *a) {
	if (NULL == a) {
		return ;
	}

	for (int i = 0; i < a->count; i ++) {
		if (a->storage[i] != NULL) {
			printPoint(a->storage[i]);
		} else {
			printf("NULL");
		}

		if (i < (a->count - 1)) {
			printf(",");
		}
	}
	printf("\n");
}

long countArrayPoints(ArrayPoints *a) {
	if (NULL == a) {
		return ArrayPointIndexError;
	}

	return a->count;
}

long reallocateInternalStorage(ArrayPoints *a, int requestedCount) {
	if (a->count >= requestedCount) {
		return a->count;
	}

	int count  = requestedCount * 2;

	// reallocate ???
	Point **storage = (Point **)malloc(sizeof(Point *) * count);
	if (NULL == storage) {
		return ArrayPointIndexError;
	}

	bzero(storage, sizeof(Point *) * count);

	memcpy(storage, a->storage, sizeof(Point *) * a->count);
	free(a->storage);

	a->storage = storage;
	a->count = count;

	return count;
}
