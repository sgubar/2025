//
//  line.h
//  line23
//
//  Created by Slava Gubar on 21.02.2023.
//

#ifndef line_h
#define line_h

#include <stdio.h>
#include "point.h"

typedef struct tagLine {
	Point *A;
	Point *B;
} Line;

Line *createLine(int ax, int ay, int bx, int by);
Line *createLineByPoints(Point *anA, Point *aB);
void destroyLine(Line *aLine);

void printLine(Line *aLine);
double lenghtLine(Line *aLine);
//void drawLine(Line *aLine);

#endif /* line_h */
