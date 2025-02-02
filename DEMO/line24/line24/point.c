//
//  point.c
//  line24
//
//  Created by Slava Gubar on 23.02.2024.
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

void destroyPoint(Point *P) {
	if (P != NULL) {
		free(P);
	}
}

void printPoint(Point *P) {
	if (P == NULL) {
		printf("Invalid reference to point");
	}

	printf("(%d; %d)", P->x, P->y);
}
