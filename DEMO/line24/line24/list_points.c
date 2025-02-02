//
//  list_points.c
//  line24
//
//  Created by Slava Gubar on 3/8/24.
//

#include "list_points.h"
#include <stdlib.h>
#include <string.h>

ListPoint *createListPoint(void) {
	ListPoint *result = (ListPoint *)malloc(sizeof(ListPoint));

	if (NULL != result) {
		result->count = 0;
		result->head = NULL;
		result->tail = NULL;
	}

//	memset(result, 0, sizeof(ListPoint));
//	bzero(result, sizeof(ListPoint));

	return result;
}

void destroyListPoint(ListPoint *list) {
	if (NULL == list) {
		return ;
	}

	NodePoint *node = list->head;

	while (NULL != node) {
		NodePoint *next = node->next;
		free(node);
		node = next;
	}

//	for (NodePoint *node = list->head; node != NULL; ) {
//		NodePoint *next = node->next;
//		free(node);
//
//		node = next;
//	}

	free(list);
}

// return 0 - ok, < 0 - fails
int appendListPoint(ListPoint *list, Point *point) {
	int result = 0;

	if (NULL == list) {
		return -1;
	}

	//1 - create service node
	NodePoint *node = (NodePoint *)malloc(sizeof(NodePoint));
	if (NULL == node) {
		return -2;
	}

	node->point = point;
	node->next = NULL;

	//2 - search position for append
	//3 appending
	if (NULL == list->head) {
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}

	list->count ++;

	return result;
}

Point *pointAtIndexListPoint(ListPoint *list, unsigned int index) {
	if (NULL == list || index > list->count) {
		return NULL;
	}

	NodePoint *node = list->head;
	unsigned int i = 0;

	while (NULL != node && i != index) {
		node = node->next;
		i ++;
	}

	return node->point;
}

int countListPoint(ListPoint *list) {
	if (NULL == list) {
		return -1;
	}

	return list->count;
}
