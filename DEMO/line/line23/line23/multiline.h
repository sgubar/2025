//
//  multiline.h
//  line23
//
//  Created by Slava Gubar on 28.02.2023.
//

#ifndef multiline_h
#define multiline_h

#include <stdio.h>
#include "point.h"
#include "points.h"

typedef struct tagMultiLine {
	ArrayOfPoints *points;
} MultiLine;

MultiLine *createMultiLine(int ax, int ay, int bx, int by);
MultiLine *createMultiLineByPoints(Point *anA, Point *aB);
MultiLine *createEmptyMultiLine(void);

void addPointToMultiLine(MultiLine *aLine, Point *aPoint);

void destroyMultiLine(MultiLine *aLine);

void printMultiLineLine(MultiLine *aLine);
double lenghtMultiLineLine(MultiLine *aLine);

#endif /* multiline_h */
