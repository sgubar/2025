//
//  points.h
//  line23
//
//  Created by Slava Gubar on 28.02.2023.
//

#ifndef points_h
#define points_h

#include <stdio.h>
#include "point.h"

typedef struct tagArryOfPoints {
	Point **storage;
	int preservedCount;
	int count;
} ArrayOfPoints;

ArrayOfPoints *createArrayOfPoints(int aReserved);
void destroyArrayOfPoints(ArrayOfPoints *anArray);

void addPoint(ArrayOfPoints *anArray, Point *aPoint);
Point *getPointAt(ArrayOfPoints *anArray, int aIndex);

void printArrayOfPoints(ArrayOfPoints *anArray);
int countArrayOfPoints(ArrayOfPoints *anArray);

//void addPointAtIndex(ArrayOfPoints *anArray, Point *aPoint, int anIndex);
//Point *remotePointAtIndex(ArrayOfPoints *anArray, int anIndex);


#endif /* points_h */
