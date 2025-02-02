//
//  pline.h
//  line24
//
//  Created by Slava Gubar on 3/1/24.
//

#ifndef pline_h
#define pline_h

#include <stdio.h>
#include "point.h"
#include "array_points.h"

typedef struct tagPline {
	ArrayPoint *points;
} Pline;

Pline *createPline(Point *A, Point *B);
void destroyPline(Pline *L);

void addPointToPline(Pline *L, Point *P);

void printPline(Pline *L);
double lenghtPline(Pline *L);
int countPointsPline(Pline *L);

#endif /* pline_h */
