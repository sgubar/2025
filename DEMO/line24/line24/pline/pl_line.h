//
//  pl_line.h
//  line24
//
//  Created by Slava Gubar on 3/8/24.
//

#ifndef pl_line_h
#define pl_line_h

#include <stdio.h>
#include "list_points.h"

typedef struct tagPLline {
	ListPoint *points;
} PLline;

PLline *createPLline(Point *A, Point *B);
void destroyPLline(PLline *L);

void addPointToPLline(PLline *L, Point *P);

void printPLline(PLline *L);
double lenghtPLline(PLline *L);
int countPointsPLline(PLline *L);

#endif /* pl_line_h */
