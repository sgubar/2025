//
//  list.c
//  list
//
//  Created by Slava Gubar on 03.03.2021.
//

#include "list.h"
#include <stdlib.h>
#include <string.h>

IntListElement *createIntListElement(int value) {
	IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));

	if (NULL != result) {
		bzero(result, sizeof(IntListElement));
		result->value = value;
//		result->next = NULL;
//		result->prev = NULL;
	}

	return result;
}

void deleteIntListElement(IntListElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printIntListElement(IntListElement *element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}

// List

IntList *createIntList(void) {
	IntList *result = (IntList *)malloc(sizeof(IntList));

	if (NULL != result) {
//		result->head = NULL;
//		result->tail = NULL;
		memset(result, 0, sizeof(IntList));
	}

	return result;
}

void deleteIntList(IntList *list) {
	if (NULL == list) {
		return ;
	}

	IntListElement *element = list->head;

	while(NULL != element) {
		IntListElement *tmp = element->next;
		deleteIntListElement(element);
		element = tmp;
	}

	free(list);
}

void printIntList(IntList *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	IntListElement *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		printIntListElement(element);
		printf(",");
	}

	if (element != NULL) {
		printIntListElement(element);
	}

	printf("]\n");
}

long countOfIntList(IntList *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (IntListElement *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addIntValueToIntList(IntList *list, int value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	IntListElement *element = createIntListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		list->tail = list->head;
		return 1;
	}

	list->tail->next = element;
	element->prev = list->tail;
	list->tail = element;

	return 1;
}

void removeLastElementFromIntList(IntList *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	// is single element list?
	if (list->head == list->tail) {
		deleteIntListElement(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	IntListElement *toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteIntListElement(toDelete);
}

void removeFirstElementFromIntList(IntList *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteIntListElement(list->head);
		list->head = list->tail = NULL;
		return;
	}

	IntListElement *toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteIntListElement(toDelete);
}

int insertIntElementToIntListAtIndex(IntList *list, int index, int value) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfIntList(list);

	if (count == index) {
		return addIntValueToIntList(list, value);
	} else if (index > count) {
		return 0;
	}

	IntListElement *element = createIntListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	} else {
		int current = 0;
		IntListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

int removeIntElementFromIntListAtIndex(IntList *list, int index) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfIntList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromIntList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromIntList(list);
		return 1;
	} else {
		int current = 0;
		IntListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteIntListElement(ex_element);
	}

	return 1;
}
