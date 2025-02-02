//
//  line.c
//  line24
//
//  Created by Slava Gubar on 23.02.2024.
//

#include "line.h"
#include <stdlib.h>

Line *createLine(Point *A, Point *B) {
	Line *result = (Line *)malloc(sizeof(Line));

	if (NULL != result) {
		result->A = createPoint(A->x, A->y);
		result->B = createPoint(B->x, B->y);
	}

	return result;
}

void destroyLine(Line *L) {
	if (NULL != L) {
		destroyPoint(L->A);
		destroyPoint(L->B);

		free(L);
	}
}

void printLine(Line *L) {
	if (NULL == L) {
		printf("Invalid reference to the Line");
	}

	printPoint(L->A);
	printf("-");
	printPoint(L->B);
}

double lenghtLine(Line *L) {
	return 0;
}
