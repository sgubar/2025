//
//  main.c
//  d02_hw
//
//  Created by Slava Gubar on 17.02.2021.
//

#include <stdio.h>
#include "line.h"
#include "polyline.h"
#include "arraypoints.h"
#include "dpline.h"

int main(int argc, const char * argv[]) {

	Point *p = createPoint(5, 6);

	printPoint(p);
	printf("\n");

	Point *copy = copyPoint(p);
	copy->x = 10;
	printPoint(copy);
	printf("\n");

	printf("is equal points: %d\n", isEqualPoints(p, copy));

	Line *l = createLineByPoints(p, copy);
	printLine(l);

	printf("len: %f\n", lenghtLine(l));

	printf("Polyline test ...\n");
	PolyLine *line = createPolyLine();

	addPointToPolyLine(line, p);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 7, 8);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 97, 78);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 87, 58);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 77, 88);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	addPointByXYToPoliLine(line, 37, 48);
	printPolyLine(line);
	printf("len: %f\n", lenghtPolyLine(line));

	printf("ArrayPoints test ...\n");

	ArrayPoints *a = createArrayPoints(2);
	printArrayPoints(a);

	setPointAtIndex(a, p, 0);
	printArrayPoints(a);

	setPointAtIndex(a, p, 4);
	printArrayPoints(a);

	printf("Polyline test ...\n");
	DPLine *dp = createDPLine();

	addPointToDPLine(dp, p);
	printDPLine(dp);
	printf("len: %f\n", lenghtDPLine(dp));

	addPointByXYToDPLine(dp, 7, 8);
	printDPLine(dp);
	printf("len: %f\n", lenghtDPLine(dp));

	addPointByXYToDPLine(dp, 97, 78);
	printDPLine(dp);
	printf("len: %f\n", lenghtDPLine(dp));

	addPointByXYToDPLine(dp, 87, 58);
	printDPLine(dp);
	printf("len: %f\n", lenghtDPLine(dp));

	addPointByXYToDPLine(dp, 77, 88);
	printDPLine(dp);
	printf("len: %f\n", lenghtDPLine(dp));

	addPointByXYToDPLine(dp, 37, 48);
	printDPLine(dp);
	printf("len: %f\n", lenghtDPLine(dp));
	// insert code here...
	printf("Hello, World!\n");
	deletePoint(p);
	deletePoint(copy);
	deleteLine(l);
	deletePolyLine(line);
	deleteArrayPoints(a);
	deleteDPLine(dp);
	return 0;
}
