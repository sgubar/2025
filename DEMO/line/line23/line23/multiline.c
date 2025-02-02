//
//  multiline.c
//  line23
//
//  Created by Slava Gubar on 28.02.2023.
//

#include "multiline.h"
#include <stdlib.h>
#include <math.h>

double lenghtLineByPoints(Point *A, Point *B);

MultiLine *createEmptyMultiLine(void) {
	MultiLine *result = (MultiLine *)malloc(sizeof(MultiLine));

	if (NULL != result) {
		result->points = createArrayOfPoints(2);
		if (NULL == result->points) { //failed to create internal storage
			free(result);
			return NULL;
		}
	}

	return result;
}

MultiLine *createMultiLine(int ax, int ay, int bx, int by) {
	MultiLine *result = createEmptyMultiLine();

	if (NULL != result) {
		addPoint(result->points, createPoint(ax, ay));
		addPoint(result->points, createPoint(bx, by));
	}

	return result;
}

MultiLine *createMultiLineByPoints(Point *anA, Point *aB) {
	if (NULL == anA || NULL == aB) {
		return NULL;
	}

	return createMultiLine(anA->x, anA->y, aB->x, aB->y);
}

void addPointToMultiLine(MultiLine *aLine, Point *aPoint) {
	if (NULL == aLine || NULL == aPoint) {
		return ;
	}

	addPoint(aLine->points, createPoint(aPoint->x, aPoint->y));
}

void destroyMultiLine(MultiLine *aLine) {
	if (NULL == aLine) {
		return ;
	}

	// destroy all owned points which are present in our storage
	for (int i = 0; i < countArrayOfPoints(aLine->points); i++) {
		destroyPoint(getPointAt(aLine->points, i));
	}
}

void printMultiLineLine(MultiLine *aLine) {
	if (NULL == aLine) {
		return ;
	}

	// destroy all owned points which are present in our storage
	for (int i = 0; i < countArrayOfPoints(aLine->points); i++) {
		printPoint(getPointAt(aLine->points, i));
	}
}

double lenghtMultiLineLine(MultiLine *aLine) {
	if (NULL == aLine) {
		return 0;
	}

	int count = countArrayOfPoints(aLine->points);

	if (count <= 1) {
		return 0;
	}

	Point *first = getPointAt(aLine->points, 0);
	double length = 0;

	for (int i = 1; i < count; i++) {
		Point *second = getPointAt(aLine->points, i);
		length += lenghtLineByPoints(first, second);
		first = second;
	}

	return length;
}

double lenghtLineByPoints(Point *A, Point *B) {
	if (NULL == A || NULL == B) {
		return 0;
	}

	return sqrt((B->x - A->x) * (B->x - A->x) + (B->y - A->y)*(B->y - A->y));
}
