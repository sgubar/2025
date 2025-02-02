//
//  array_points.h
//  line24
//
//  Created by Slava Gubar on 3/1/24.
//

#ifndef array_points_h
#define array_points_h

#include <stdio.h>
#include "point.h"

typedef struct tagArrayPoint {
	Point **storage;
	int preserved;
	int lastElement;
} ArrayPoint;

ArrayPoint *createAPoint(int preserved);
void destroyAPoint(ArrayPoint *a);

void addPointToArray(ArrayPoint *a, Point *p);
Point *getPointAtIndexArray(ArrayPoint *a, int index);

int countPointsArray(ArrayPoint *a);

#endif /* array_points_h */
