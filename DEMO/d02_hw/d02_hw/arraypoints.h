//
//  arraypoints.h
//  d02_hw
//
//  Created by Slava Gubar on 23.02.2021.
//

#ifndef arraypoints_h
#define arraypoints_h

#include <stdio.h>
#include "point.h"

#define ArrayPointIndexError (-1)

typedef struct tag_ArrayPoints {
	Point **storage;
	long count;
} ArrayPoints;

ArrayPoints *createArrayPoints(long preservedCount);
void deleteArrayPoints(ArrayPoints *a);

int setPointAtIndex(ArrayPoints *a, Point *value, int index);
Point *getPointAtIndex(ArrayPoints *a, int index);

void printArrayPoints(ArrayPoints *a);
long countArrayPoints(ArrayPoints *a);

#endif /* arraypoints_h */
