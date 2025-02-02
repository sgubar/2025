//
//  array_points.c
//  line24
//
//  Created by Slava Gubar on 3/1/24.
//

#include "array_points.h"
#include <stdlib.h>
#include <string.h>

void adoptInternalStorage(ArrayPoint *a);

ArrayPoint *createAPoint(int preserved) {
	if (preserved <= 0) {
		return NULL;
	}

	ArrayPoint *result = (ArrayPoint *)malloc(sizeof(ArrayPoint));

	if (NULL != result) {
		result->preserved = preserved;
		result->storage = (Point **)malloc(sizeof(Point *) * result->preserved);
		result->lastElement = 0;
	}

	return result;
}

void destroyAPoint(ArrayPoint *a) {
	if (NULL == a) {
		return ;
	}

	free(a->storage);
	free(a);
}

int countPointsArray(ArrayPoint *a) {
	if (NULL == a) {
		return -1;
	}

	return a->lastElement;
}

void addPointToArray(ArrayPoint *a, Point *p) {
	if (NULL == a || NULL == p) {
		return ;
	}

	if (a->lastElement == a->preserved) {

		adoptInternalStorage(a);

		if (a->lastElement == a->preserved) {
			return;
		}
	}

	a->storage[a->lastElement] = p;
	a->lastElement ++;
}

Point *getPointAtIndexArray(ArrayPoint *a, int index) {
	if (NULL == a && index >= a->lastElement) {
		return NULL;
	}

	return a->storage[index];
}

void adoptInternalStorage(ArrayPoint *a) {
	Point **newStorage = (Point **)malloc(sizeof(Point) * a->preserved * 2);

	if (NULL == newStorage) {
		return ;
	}

	memcpy(newStorage, a->storage, sizeof(Point) * a->preserved);

	free(a->storage);
	a->storage = newStorage;
	a->preserved *= 2;
}
