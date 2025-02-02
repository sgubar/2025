//
//  pline.c
//  line24
//
//  Created by Slava Gubar on 3/1/24.
//

#include "pline.h"
#include <stdlib.h>

Pline *createPline(Point *A, Point *B) {
	Pline *result = (Pline *)malloc(sizeof(Pline));

	if (NULL != result) {
		result->points = createAPoint(4);
		if (NULL != result->points) {
			addPointToArray(result->points, createPoint(A->x, A->y));
			addPointToArray(result->points, createPoint(B->x, B->y));
		} else {
			free(result);
			result = NULL;
		}
	}

	return result;
}

void destroyPline(Pline *L) {
	if (NULL == L) {
		return ;
	}

	for (int i = 0; i < countPointsArray(L->points); i++) {
		destroyPoint(getPointAtIndexArray(L->points, i));
	}

	free(L->points);
	free(L);
}

void addPointToPline(Pline *L, Point *P) {
	if (NULL == L || NULL == P) {
		return ;
	}

	addPointToArray(L->points, createPoint(P->x, P->y));
}

void printPline(Pline *L) {
	if (NULL == L) {
		printf("Invalid reference to the Line");
	}

	int i = 0;
	for (; i < countPointsArray(L->points) - 1; i++) {
		printPoint(getPointAtIndexArray(L->points, i));
		printf("-");
	}

	printPoint(getPointAtIndexArray(L->points, i));
}

double lenghtPline(Pline *L) {
	return 0;
}

int countPointsPline(Pline *L) {
	if (NULL == L) {
		return -1;
	}

	return countPointsArray(L->points);
}
