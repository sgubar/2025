//
//  point.h
//  line24
//
//  Created by Slava Gubar on 23.02.2024.
//

#ifndef point_h
#define point_h

#include <stdio.h>

typedef struct tagPoint {
	int x;
	int y;
} Point, *PPoint;

Point *createPoint(int x, int y);
void destroyPoint(Point *P);
void printPoint(Point *P);

#endif /* point_h */
