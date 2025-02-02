//
//  point.h
//  d02_hw
//
//  Created by Slava Gubar on 17.02.2021.
//

#ifndef point_h
#define point_h

#include <stdio.h>

typedef struct tag_point {
	int x;
	int y;
} Point;

Point *createPoint(int x, int y);
void deletePoint(Point *p);
void printPoint(Point *p);
Point *copyPoint(Point *p);
int isEqualPoints(Point *lp, Point *rp);

#endif /* point_h */
