//
//  lpline.h
//  d02_hw
//
//  Created by Slava Gubar on 15.03.2021.
//

#ifndef lpline_h
#define lpline_h

#include <stdio.h>
#include "listpoints.h"

typedef struct tag_LPLine {
	ListPoint *points;
} LPLine;

LPLine *createLPLineByPoints(Point *p1, Point *p2);
LPLine *createLPLineByCoords(int x1, int y1, int x2, int y2);
LPLine *createLPLine(void);

void deleteLPLine(LPLine *l);
int countPointsOfLPLine(LPLine *l);

void addPointToLPLine(LPLine *l, Point *p);
void addPointByXYToLPLine(LPLine *l, int x, int y);
void deleteLastPointFromLPLine(LPLine *l);

void printLPLine(LPLine *l);
LPLine *copyLPLine(LPLine *l);
int isEqualLPLine(LPLine *ll, LPLine *rl);

double lenghtLPLine(LPLine *l);

#endif /* lpline_h */
