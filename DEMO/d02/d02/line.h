//
//  line.h
//  d02
//
//  Created by Slava Gubar on 11.02.2022.
//

#ifndef line_h
#define line_h

#include <stdio.h>
#include "point.h"

typedef struct tagLine {
	Point *A;
	Point *B;
} Line;

Line *createLineByPoint(Point *a, Point *b);
Line *createLineByXY(int ax, int ay, int bx, int by);
void deleteLine(Line *l);
void printLine(Line *l);
void drawLine(Line *);




#endif /* line_h */
