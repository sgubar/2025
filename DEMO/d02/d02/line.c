//
//  line.c
//  d02
//
//  Created by Slava Gubar on 11.02.2022.
//

#include "line.h"
#include <stdlib.h>

//<type of return value><fun name><the list of input params: [type + name]>

Line *createLineByPoint(Point *a, Point *b) {
	Line *result = (Line *)malloc(sizeof(Line));

	if (NULL != result) {
		result->A = copyPoint(a); //copyPoint(a);
		result->B = copyPoint(b);
	}

	return result;
}

Line *createLineByXY(int ax, int ay, int bx, int by) {
	Line *result = (Line *)malloc(sizeof(Line));

	if (NULL != result) {
		result->A = createPoint(ax, ay);
		result->B = createPoint(bx, by);
	}

	return result;
}

void deleteLine(Line *l) {
	if (NULL != l) {
		if (NULL != l->A) {
			free(l->A);
		}
		if (NULL != l->B) {
			free(l->B);
		}

		free(l);
	}
}

void printLine(Line *l) {
	if (NULL != l) {
		printPoint(l->A);
		printf("-");
		printPoint(l->B);
		printf("\n");
	}
}
