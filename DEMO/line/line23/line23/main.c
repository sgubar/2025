//
//  main.c
//  line23
//
//  Created by Slava Gubar on 21.02.2023.
//

#include <stdio.h>
#include "point.h"
#include "line.h"
#include "multiline.h"

int main(int argc, const char * argv[]) {

	// insert code here...
	printf("Hello, World!\n");

	Point *a = createPoint(5, 6);

	printPoint(a);
	printf("\n");

	destroyPoint(a);

	Point b = {10, 11};

	printPoint(&b);
	printf("\n");

	Line *ab = createLine(5, 6, 7, 8);

	printLine(ab);

	printf("length: %f\n", lenghtLine(ab));

	destroyLine(ab);

	Point c = {10, 12};
	Point d = {20, 22};

	Line *cd = createLineByPoints(&c, &d);

	printLine(cd);

	printf("length: %f\n", lenghtLine(cd));

	destroyLine(cd);

	MultiLine *line = createMultiLineByPoints(&c, &d);
	printMultiLineLine(line);
	printf("\n");
	printf("length: %f\n", lenghtMultiLineLine(line));

	addPointToMultiLine(line, &b);
	printMultiLineLine(line);
	printf("\n");
	printf("length: %f\n", lenghtMultiLineLine(line));

	destroyMultiLine(line);

	return 0;
}
