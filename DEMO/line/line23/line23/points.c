//
//  points.c
//  line23
//
//  Created by Slava Gubar on 28.02.2023.
//

#include "points.h"
#include <stdlib.h>
#include <strings.h>

int extendArrayOfPoints(ArrayOfPoints *anArray);

ArrayOfPoints *createArrayOfPoints(int aReserved) {
	ArrayOfPoints *result = (ArrayOfPoints *)malloc(sizeof(ArrayOfPoints));

	if (NULL != result) {
		result->preservedCount = (aReserved > 0) ? aReserved : 2;
		result->count = 0;
		result->storage = (Point **)malloc(sizeof(Point *) * result->preservedCount);

		if (NULL == result->storage) { // if failed to alloc memory for internal storage
			free(result);
			return NULL;
		} else {
			bzero(result->storage, sizeof(Point *) * result->preservedCount);
			// memset(result->storage, 0, sizeof(Point *) * result->preservedCount);
		}
	}

	return result;
}

void destroyArrayOfPoints(ArrayOfPoints *anArray) {
	if (NULL == anArray) {
		return ;
	}

	free(anArray->storage);
	free(anArray);
}

void addPoint(ArrayOfPoints *anArray, Point *aPoint) {
	if (NULL == anArray) {
		return ;
	}

	if (anArray->count == anArray->preservedCount) {
		if (0 != extendArrayOfPoints(anArray)) {
			return ;
		}
	}

	anArray->storage[anArray->count] = aPoint;
	anArray->count ++;
}

void printArrayOfPoints(ArrayOfPoints *anArray) {
	if (NULL == anArray) {
		return ; //Bad input parameters
	}

	for (int i = 0; i < anArray->count; i ++) {
		printPoint(anArray->storage[i]);
	}
}

Point *getPointAt(ArrayOfPoints *anArray, int aIndex) {
	if (NULL == anArray || aIndex >= anArray->count) {
		return NULL; //Bad input parameters
	}

	return anArray->storage[aIndex];
}

int countArrayOfPoints(ArrayOfPoints *anArray) {
	return (NULL != anArray) ? anArray->count : -1;
}

int extendArrayOfPoints(ArrayOfPoints *anArray) {
	if (NULL == anArray) {
		return 1; //Bad input parameters
	}

	printf("realloc \n");

	anArray->preservedCount *= 2;
	Point **local = (Point **)malloc(sizeof(Point *) * anArray->preservedCount);

	if (NULL == local) {
		return 2;
	}

	memcpy(local, anArray->storage, anArray->count * sizeof(Point *));

	free(anArray->storage);

	anArray->storage = local;

	return 0;
}
