//
//  signle_list.h
//  list
//
//  Created by Slava Gubar on 01.03.2021.
//

#ifndef signle_list_h
#define signle_list_h

#include <stdio.h>

typedef struct tagSingleListIntElement SingleListIntElement;

struct tagSingleListIntElement {
	SingleListIntElement *next;
	int value;
};

SingleListIntElement *createSingleListIntElement(int value);
void deleteSingleListIntElement(SingleListIntElement *element);
void printSingleListIntElement(SingleListIntElement *element);

typedef struct tagIntSingleList {
	SingleListIntElement *head;
	//long count;
} IntSingleList;

IntSingleList *createIntSingleList(void);
void deleteIntSingleList(IntSingleList *list);

void printIntSingleList(IntSingleList *list);

long countOfIntSingleList(IntSingleList *list);
// 1: success, 0 - fail
int addIntValueToIntSingleList(IntSingleList *list, int value);
void removeLastElementFromIntSingleList(IntSingleList *list);
void removeFirstElementFromIntSingleList(IntSingleList *list);

// 1: success, 0 - fail
int insertIntElementToIntSingleListAtIndex(IntSingleList *list, int index, int value);
// 1: success, 0 - fail
int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index);


#endif /* signle_list_h */
