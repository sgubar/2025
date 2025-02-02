//
//  lpline.c
//  d02_hw
//
//  Created by Slava Gubar on 15.03.2021.
//

#include "lpline.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

void internalAddPointToLPLine(LPLine *l, Point *p);

LPLine *createDPLine(void) {
	LPLine *l = (LPLine *)malloc(sizeof(LPLine));
	if (NULL != l) {
		l->points = createListPoint();
	}
	return l;
}

void addPointToLPLine(LPLine *l, Point *p) {
	internalAddPointToLPLine(l, copyPoint(p));
}

void addPointByXYToLPLine(LPLine *l, int x, int y) {
	internalAddPointToLPLine(l, createPoint(x, y));
}

void internalAddPointToLPLine(LPLine *l, Point *p) {
	if (NULL == l || NULL == p) {
		return ;
	}

	addPointValueToListPoint(l->points, p);
}

void deleteLastPointFromLPLine(LPLine *l) {
	if (NULL == l) {
		return ;
	}

	Point *removePoint = removeLastElementFromListPoint(l->points);
	deletePoint(removePoint);
}

void deleteLPLine(LPLine *l) {
	if (NULL != l) {

		Point *removePoint = removeFirstElementFromListPoint(l->points);

		while (NULL != removePoint) {
			deletePoint(removePoint);
			removePoint = removeFirstElementFromListPoint(l->points);
		}

		deleteListPoint(l->points);
		free(l);
	}
}


int countPointsOfLPLine(LPLine *l) {
	if (NULL == l) {
		return 0;
	}

	return (int)countOfListPoint(l->points);
}

LPLine *createLPLineByPoints(Point *p1, Point *p2) {
	if (NULL == p1 || NULL == p2) {
		return NULL;
	}

	LPLine *l = createLPLine();
	addPointToLPLine(l, p1);
	addPointToLPLine(l, p2);

	return l;
}

LPLine *createLPLineByCoords(int x1, int y1, int x2, int y2) {
	return createLPLineByPoints(createPoint(x1, y1), createPoint(x2, y2));
}

void printLPLine(LPLine *l) {
	if (NULL == l) {
		return ;
	}

//	for (int i = 0; i < countArrayPoints(l->points) && getPointAtIndex(l->points, i) != NULL; i ++) {
//		printPoint(getPointAtIndex(l->points, i));
//
//		if ((i + 1) < countArrayPoints(l->points) && getPointAtIndex(l->points, i + 1) != NULL) {
//			printf("-"); //(x1, y1)-(x2,y2)
//		}
//	}
	printListPoint(l->points);

	printf("\n");
}

//DPLine *copyDPLine(DPLine *l) {
//	if (NULL == l) {
//		return NULL;
//	}
//
//	DPLine *copy = createDPLine();
//
//	for (int i = 0; i < countArrayPoints(l->points) && getPointAtIndex(l->points, i); i ++) {
//		//addPointToPolyLine(copy, l->points[i]);
//		setPointAtIndex(copy->points, copyPoint(getPointAtIndex(l->points, i)), i);
//	}
//
//	return copy;
//}
//
//int isEqualDPLine(DPLine *ll, DPLine *rl) {
//	if (NULL == ll || NULL == rl) {
//		return 0;
//	}
//
//	if (ll == rl) {
//		return 1;
//	}
//
//	int count = countPointsOfDPLine(ll);
//	if (count != countPointsOfDPLine(rl)) {
//		return 0;
//	}
//
//	for (int i = 0; i < count; i ++) {
//		if (!isEqualPoints(getPointAtIndex(ll->points, i), getPointAtIndex(rl->points, i))) {
//			return 0;
//		}
//	}
//
//	return 1;
//}

double lenghtLPLine(LPLine *l) {
	if (NULL == l) {
		return -1;
	}

	double result = 0;
	int count = countPointsOfLPLine(l);

	if (count < 2) {
		return result;
	}

	for (int i = 0; i < (count - 1); i ++) {

////		Point *B = l->points[i + 1];
////		Point *A = l->points[i];
////
////		long dx = B->x - A->x;
////		long dy = B->y - A->y;
//
//		long dx = getPointAtIndex(l->points, i + 1)->x - getPointAtIndex(l->points, i)->x;
//		long dy = getPointAtIndex(l->points, i + 1)->y - getPointAtIndex(l->points, i)->y;
//
//		result += sqrt(dx*dx + dy+dy);
	}
	// A, B, C, D
	return result;
}
