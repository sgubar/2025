//
//  line.c
//  line23
//
//  Created by Slava Gubar on 21.02.2023.
//

#include "line.h"
#include <stdlib.h>
#include <math.h>

Line *createLine(int ax, int ay, int bx, int by) {
	Line *result = (Line *)malloc(sizeof(Line));

	if (NULL != result) {
		result->A = createPoint(ax, ay);
		result->B = createPoint(bx, by);
	}

	return result;
}

Line *createLineByPoints(Point *anA, Point *aB) {

	if (NULL == anA || NULL == aB) {
		return NULL;
	}

//	Line *result = (Line *)malloc(sizeof(Line));
//
//	if (NULL != result) {
//		result->A = createPoint(anA->x, anA->y);
//		result->B = createPoint(aB->x, aB->y);
//	}
//
//	return result;
	return createLine(anA->x, anA->y, aB->x, aB->y);
}

void destroyLine(Line *aLine) {
	if (NULL == aLine) {
		return;
	}

	destroyPoint(aLine->A);
	destroyPoint(aLine->B);

	free(aLine);
}

void printLine(Line *aLine) {
	if (NULL == aLine) {
		return;
	}

	printPoint(aLine->A);
	printf("-");
	printPoint(aLine->B);
	printf("\n");
}

double lenghtLine(Line *aLine) {
	if (NULL == aLine) {
		return -1;
	}

	return sqrt((aLine->B->x - aLine->A->x) * (aLine->B->x - aLine->A->x) + (aLine->B->y - aLine->A->y)*(aLine->B->y - aLine->A->y));
}
