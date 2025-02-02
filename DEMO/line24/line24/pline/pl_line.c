//
//  pl_line.c
//  line24
//
//  Created by Slava Gubar on 3/8/24.
//

#include "pl_line.h"
#include <stdlib.h>

PLline *createPLline(Point *A, Point *B) {
	PLline *result = (PLline *)malloc(sizeof(PLline));

	if (NULL != result) {
		result->points = createListPoint();
		if (NULL != result->points) {
			appendListPoint(result->points, createPoint(A->x, A->y));
			appendListPoint(result->points, createPoint(B->x, B->y));
		} else {
			free(result);
			result = NULL;
		}
	}

	return result;

}

void destroyPLline(PLline *L) {
	if (NULL == L) {
		return ;
	}

	for (int i = 0; i < countListPoint(L->points); i++) {
		Point *point = pointAtIndexListPoint(L->points, i);

		if (NULL != point) {
			destroyPoint(point);
		}
	}

	free(L->points);
	free(L);
}

void addPointToPLline(PLline *L, Point *P) {
	if (NULL == L || NULL == P) {
		return ;
	}

	appendListPoint(L->points, createPoint(P->x, P->y));
}

void printPLline(PLline *L) {
	if (NULL == L) {
		printf("Invalid reference to the Line");
	}

	int i = 0;

	for (; i < countListPoint(L->points) - 1; i++) {
		Point *point = pointAtIndexListPoint(L->points, i);
		if (NULL != point) {
			printPoint(point);
		} else {
			printf("invalid");
		}

		printf("-");
	}

	printPoint(pointAtIndexListPoint(L->points, i));
}

double lenghtPLline(PLline *L) {
	return 0.0;
}

int countPointsPLline(PLline *L) {
	if (NULL == L) {
		return -1;
	}

	return countListPoint(L->points);
}
