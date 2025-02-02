//
//  polyline.h
//  d02_hw
//
//  Created by Slava Gubar on 17.02.2021.
//

#ifndef polyline_h
#define polyline_h

#include <stdio.h>
#include "point.h"

#define MAX_POINTS 128

typedef struct tag_PolyLine {
	Point *points[MAX_POINTS];
} PolyLine;

PolyLine *createPolyLineByPoints(Point *p1, Point *p2);
PolyLine *createPolyLineByCoords(int x1, int y1, int x2, int y2);
PolyLine *createPolyLine(void);

void deletePolyLine(PolyLine *l);
int countPoints(PolyLine *l);

void addPointToPolyLine(PolyLine *l, Point *p);
void addPointByXYToPoliLine(PolyLine *l, int x, int y);
void deleteLastPointFromPolyLine(PolyLine *l);

void printPolyLine(PolyLine *l);
PolyLine *copyPolyLine(PolyLine *l);
int isEqualPolyLine(PolyLine *ll, PolyLine *rl);

double lenghtPolyLine(PolyLine *l);

#endif /* polyline_h */
