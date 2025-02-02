//
//  line.h
//  d02_hw
//
//  Created by Slava Gubar on 17.02.2021.
//

#ifndef line_h
#define line_h

#include <stdio.h>
#include "point.h"

typedef struct tag_line {
	Point *A;
	Point *B;
} Line;

Line *createLineByPoints(Point *p1, Point *p2);
Line *createLineByCoords(int x1, int y1, int x2, int y2);
void deleteLine(Line *l);

void printLine(Line *l);
Line *copyLine(Line *l);
int isEqualLine(Line *ll, Line *rl);

double lenghtLine(Line *l);

#endif /* line_h */
