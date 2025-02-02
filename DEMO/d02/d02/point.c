//
//  point.c
//  d02
//
//  Created by Slava Gubar on 11.02.2022.
//

#include "point.h"
#include <stdlib.h>

void printPoint(Point *a)
{
	if (NULL != a) {
		printf("{ x:%d, y:%d}", a->x, a->y);
	}
}

void fillPoint(Point *a)
{
	if (NULL != a) {
		a->x = 50;
		a->y = 30;
	}
}

Point *createPoint(int x, int y)
{
	Point *result = (Point *)malloc(sizeof(Point));
	if (NULL != result) {
		result->x = x;
		result->y = y;
	}

	return result;
}

Point *copyPoint(Point *a) {
	if (NULL == a) {
		return NULL;
	}

	return createPoint(a->x, a->y);
}

void deletePoint(Point *a) {
	if (NULL != a) {
		free(a);
	}
}
