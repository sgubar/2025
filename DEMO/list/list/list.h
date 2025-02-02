//
//  list.h
//  list
//
//  Created by Slava Gubar on 03.03.2021.
//

#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct tagIntListElement IntListElement;
struct tagIntListElement {
	int value;
	IntListElement *prev;
	IntListElement *next;
};

IntListElement *createIntListElement(int value);
void deleteIntListElement(IntListElement *element);
void printIntListElement(IntListElement *element);

// IntList

typedef struct tagIntList {
	IntListElement *head;
	IntListElement *tail;
} IntList;

IntList *createIntList(void);
void deleteIntList(IntList *list);

void printIntList(IntList *list);

long countOfIntList(IntList *list);
// 1: success, 0 - fail
int addIntValueToIntList(IntList *list, int value);
void removeLastElementFromIntList(IntList *list);
void removeFirstElementFromIntList(IntList *list);

// 1: success, 0 - fail
int insertIntElementToIntListAtIndex(IntList *list, int index, int value);
// 1: success, 0 - fail
int removeIntElementFromIntListAtIndex(IntList *list, int index);


#endif /* list_h */
