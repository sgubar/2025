//
//  listpoints.c
//  d02_hw
//
//  Created by Slava Gubar on 15.03.2021.
//

#include "listpoints.h"
#include <stdlib.h>

ListPointElement *createListPointElement(Point *value) {
	ListPointElement *result = (ListPointElement *)malloc(sizeof(ListPointElement));

	if (NULL != result) {
		result->value = value;
		result->next = NULL;
	}

	return result;
}

void deleteListPointElement(ListPointElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printListPointElement(ListPointElement *element) {
	if (NULL != element) {
		printPoint(element->value);
	}
}

ListPoint *createListPoint(void) {
	ListPoint *result = (ListPoint *)malloc(sizeof(ListPoint));

	if (NULL != result) {
		result->head = NULL;
	}

	return result;
}

void deleteListPoint(ListPoint *list) {
	if (NULL == list) {
		return ;
	}

	ListPointElement *element = list->head;

	while(NULL != element) {
		ListPointElement *tmp = element->next;
		deleteListPointElement(element);
		element = tmp;
	}

	free(list);
}

void printListPoint(ListPoint *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");
	for (ListPointElement *element = list->head; element != NULL; element = element->next) {
		printListPointElement(element);
		if (element->next != NULL) {
			printf(",");
		}
	}

	printf("]\n");
}

long countOfListPoint(ListPoint *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (ListPointElement *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addPointValueToListPoint(ListPoint *list, Point *value) {
	if (NULL == list) {
 		return 0;
	}

	ListPointElement *element = createListPointElement(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		return 1;
	}

	ListPointElement *tail = list->head;

	while(NULL != tail->next) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

Point *removeLastElementFromListPoint(ListPoint *list) {
	Point *value = NULL;
	if (NULL == list) {
 		return value;
	}

	if (NULL == list->head) {
		return value;
	}

	ListPointElement *element = list->head;

	if (NULL == element->next) {
		list->head = NULL;
		value = element->value;
		deleteListPointElement(element);
		return value;
	}

	while(NULL != element->next && NULL != element->next->next) {
		element = element->next;
	}
	value = element->next->value;
	deleteListPointElement(element->next);
	element->next = NULL;

	return value;
}

Point *removeFirstElementFromListPoint(ListPoint *list) {
	Point *value = NULL;
	if (NULL == list) {
 		return value;
	}

	if (NULL == list->head) {
		return value;
	}

	ListPointElement *element = list->head->next;
	value = list->head->value;
	deleteListPointElement(list->head);
	list->head = element;
	return value;
}

ListPointElement *nextListPointElement(ListPointElement *current) {
	if (NULL == current) {
		return NULL;
	}

	return current->next;
}
