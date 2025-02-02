//
//  point.h
//  line23
//
//  Created by Slava Gubar on 21.02.2023.
//

#ifndef point_h
#define point_h

#include <stdio.h>

typedef struct tagPoint {
	int x;
	int y;
} Point;

Point *createPoint(int x, int y);
void destroyPoint(Point *aPoint);
void printPoint(Point *aPoint);

#endif /* point_h */
