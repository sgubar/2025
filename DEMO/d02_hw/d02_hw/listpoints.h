//
//  listpoints.h
//  d02_hw
//
//  Created by Slava Gubar on 15.03.2021.
//

#ifndef listpoints_h
#define listpoints_h

#include <stdio.h>
#include "point.h"

typedef struct tagListPointElement ListPointElement;

struct tagListPointElement {
	ListPointElement *next;
	Point *value;
};

ListPointElement *createListPointElement(Point *value);
void deleteListPointElement(ListPointElement *element);
void printListPointElement(ListPointElement *element);

typedef struct tagListPoint {
	ListPointElement *head;
	//long count;
} ListPoint;

ListPoint *createListPoint(void);
void deleteListPoint(ListPoint *list);

void printListPoint(ListPoint *list);

long countOfListPoint(ListPoint *list);
// 1: success, 0 - fail
int addPointValueToListPoint(ListPoint *list, Point *value);
Point *removeLastElementFromListPoint(ListPoint *list);
Point *removeFirstElementFromListPoint(ListPoint *list);

ListPointElement *nextListPointElement(ListPointElement *current);

//// 1: success, 0 - fail
//int insertPoinElementToIntSingleListAtIndex(IntSingleList *list, int index, int value);
//// 1: success, 0 - fail
//int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index);

#endif /* listpoints_h */
