//
//  point.c
//  line23
//
//  Created by Slava Gubar on 21.02.2023.
//

#include "point.h"
#include <stdlib.h>

Point *createPoint(int x, int y) {
	Point *result = (Point *)malloc(sizeof(Point));
	if (NULL != result) {
		result->x = x;
		result->y = y;
	}

	return result;
}

void destroyPoint(Point *aPoint) {
	if (NULL != aPoint) {
		free(aPoint);
	}
}

void printPoint(Point *aPoint) {
	if (NULL == aPoint) {
		printf("Invalid object");
		return;
	}

	printf("{%d, %d}", aPoint->x, aPoint->y);
}
