//
//  list_points.h
//  line24
//
//  Created by Slava Gubar on 3/8/24.
//

#ifndef list_points_h
#define list_points_h

#include <stdio.h>
#include "point.h"

typedef struct tagNodePoint {
	Point *point;
	struct tagNodePoint *next;
} NodePoint;

typedef struct tagListPoint {
	NodePoint *head;
	NodePoint *tail;

	int count;
} ListPoint;

ListPoint *createListPoint(void);
void destroyListPoint(ListPoint *list);

// return 0 - ok, < 0 - fails
int appendListPoint(ListPoint *list, Point *point);
Point *pointAtIndexListPoint(ListPoint *list, unsigned int index);

int countListPoint(ListPoint *list);

#endif /* list_points_h */
