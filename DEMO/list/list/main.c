//
//  main.c
//  list
//
//  Created by Slava Gubar on 01.03.2021.
//

#include <stdio.h>
#include "signle_list.h"
#include "list.h"

int main(int argc, const char * argv[]) {

	printf("*** TEST SINGLE LINKED LIST *** \n");
	IntSingleList *list = createIntSingleList();

	printIntSingleList(list);

	addIntValueToIntSingleList(list, 5);
	printIntSingleList(list);

	addIntValueToIntSingleList(list, 6);
	printIntSingleList(list);

	removeFirstElementFromIntSingleList(list);
	printIntSingleList(list);

	removeLastElementFromIntSingleList(list);
	printIntSingleList(list);

	printf("*** FINISH SINGLE LINKED LIST *** \n");

	printf("*** TEST LINKED LIST *** \n");
	IntList *l = createIntList();

	printIntList(l);

	addIntValueToIntList(l, 5);
	printIntList(l);

	addIntValueToIntList(l, 6);
	printIntList(l);

	insertIntElementToIntListAtIndex(l, 1, 7);
	printIntList(l);

	addIntValueToIntList(l, 8);
	printIntList(l);

	insertIntElementToIntListAtIndex(l, 2, 8);
	printIntList(l);

	removeFirstElementFromIntList(l);
	printIntList(l);

	removeLastElementFromIntList(l);
	printIntList(l);

	// insert code here...
	printf("Hello, World!\n");

	deleteIntSingleList(list);
	deleteIntList(l);
	return 0;
}
