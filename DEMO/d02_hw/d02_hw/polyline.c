//
//  line.c
//  d02_hw
//
//  Created by Slava Gubar on 17.02.2021.
//

#include "polyline.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

int countPoints(PolyLine *l);
void internalAddPoint(PolyLine *l, Point *p);

PolyLine *createPolyLine(void) {
	PolyLine *l = (PolyLine *)malloc(sizeof(PolyLine));
	if (NULL != l) {
		bzero(l, sizeof(PolyLine));
	}
	return l;
}

void addPointToPolyLine(PolyLine *l, Point *p) {
	internalAddPoint(l, copyPoint(p));
}

void addPointByXYToPoliLine(PolyLine *l, int x, int y) {
	internalAddPoint(l, createPoint(x, y));
}

void internalAddPoint(PolyLine *l, Point *p) {
	if (NULL == l || NULL == p) {
		return ;
	}

	int count = countPoints(l);
	if (count < MAX_POINTS) {
		l->points[count] = p;
	}
}

void deleteLastPointFromPolyLine(PolyLine *l) {
	if (NULL == l) {
		return ;
	}

	int count = countPoints(l);
	if (count > 0) {
		deletePoint(l->points[count - 1]);
		l->points[count - 1] = NULL;
	}
}

void deletePolyLine(PolyLine *l) {
	if (NULL != l) {

		for (int i = 0; i < MAX_POINTS && l->points[i] != NULL; i ++) {
			deletePoint(l->points[i]);
		}

		free(l);
	}
}


int countPoints(PolyLine *l) {
	if (NULL == l) {
		return 0;
	}

	int count = 0;

//	Point **storage = l->points;
//	while(*storage != NULL) {
//		storage ++;
//		count ++;
//	}
	for (count = 0; count < MAX_POINTS; count ++) {
		if (l->points[count] == NULL) { // define NULL (void *)0
			break;
		}
	}

	return count;
}

PolyLine *createPolyLineByPoints(Point *p1, Point *p2) {
	if (NULL == p1 || NULL == p2) {
		return NULL;
	}

	PolyLine *l = createPolyLine();
	addPointToPolyLine(l, p1);
	addPointToPolyLine(l, p2);

	return l;
}

PolyLine *createPolyLineByCoords(int x1, int y1, int x2, int y2) {
	return createPolyLineByPoints(createPoint(x1, y1), createPoint(x2, y2));
}

void printPolyLine(PolyLine *l) {
	if (NULL == l) {
		return ;
	}

	for (int i = 0; i < MAX_POINTS && l->points[i] != NULL; i ++) {
		printPoint(l->points[i]);

		if ((i + 1) < MAX_POINTS && l->points[i + 1] != NULL) {
			printf("-"); //(x1, y1)-(x2,y2)
		}
	}

	printf("\n");
}

PolyLine *copyPolyLine(PolyLine *l) {
	if (NULL == l) {
		return NULL;
	}

	PolyLine *copy = createPolyLine();

	for (int i = 0; i < MAX_POINTS && l->points[i] != NULL; i ++) {
		//addPointToPolyLine(copy, l->points[i]);
		copy->points[i] = copyPoint(l->points[i]);
	}

	return copy;
}

int isEqualPolyLine(PolyLine *ll, PolyLine *rl) {
	if (NULL == ll || NULL == rl) {
		return 0;
	}

	if (ll == rl) {
		return 1;
	}

	int count = countPoints(ll);
	if (count != countPoints(rl)) {
		return 0;
	}

	for (int i = 0; i < count; i ++) {
		if (!isEqualPoints(ll->points[i], rl->points[i])) {
			return 0;
		}
	}

	return 1;
}

double lenghtPolyLine(PolyLine *l) {
	if (NULL == l) {
		return -1;
	}

	double result = 0;
	int count = countPoints(l);

	if (count < 2) {
		return result;
	}

	for (int i = 0; i < (count - 1); i ++) {

//		Point *B = l->points[i + 1];
//		Point *A = l->points[i];
//
//		long dx = B->x - A->x;
//		long dy = B->y - A->y;

		long dx = l->points[i + 1]->x - l->points[i]->x;
		long dy = l->points[i + 1]->y - l->points[i]->y;

		result += sqrt(dx*dx + dy+dy);
	}
	// A, B, C, D
	return result;
}
