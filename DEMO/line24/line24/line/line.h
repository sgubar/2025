//
//  line.h
//  line24
//
//  Created by Slava Gubar on 23.02.2024.
//

#ifndef line_h
#define line_h

#include <stdio.h>
#include "point.h"

typedef struct tagLine {
	Point *A;
	Point *B;
} Line;

Line *createLine(Point *A, Point *B);
void destroyLine(Line *L);

void printLine(Line *L);
double lenghtLine(Line *L);

#endif /* line_h */
