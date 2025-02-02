//
//  main.c
//  line24
//
//  Created by Slava Gubar on 23.02.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "pline.h"
#include "pl_line.h"

int main(int argc, const char * argv[]) {
	Point A = {5, 5};
	Point B = {6, 7};

//	Point *A = createPoint(5, 5);
//	Point *B = createPoint(6, 7);
//	Point *C = createPoint(10, 10);

	Line *AB = createLine(&A, &B);
	Line *CD = createLine(&A, &B);

	Line *array[2] = {AB, CD};
	Line **dyn = malloc(sizeof(Line *) * 10);
	dyn[0] = AB;
	dyn[1] = CD;

	CD->A->x = 0;
	CD->A->y = 0;

	printLine(AB);
	printf("\n");
	printLine(CD);
	printf("\n");

	printf("** Poly Line **\n");

	Pline *pl = createPline(&A, &B);
	PLline *pl2 = createPLline(&A, &B);
	printPline(pl);
	printf("\n");
	printPLline(pl2);
	printf("\n");

	Point A1 = {1, 1};
	addPointToPline(pl, &A1);
	addPointToPLline(pl2, &A1);
	printPline(pl);
	printf("\n");
	printPLline(pl2);
	printf("\n");

	Point A2 = {2, 1};
	addPointToPline(pl, &A2);
	addPointToPLline(pl2, &A2);
	printPline(pl);
	printf("\n");
	printPLline(pl2);
	printf("\n");

	Point A3 = {3, 1};
	addPointToPline(pl, &A3);
	addPointToPLline(pl2, &A3);
	printPline(pl);
	printf("\n");
	printPLline(pl2);
	printf("\n");

	Point A4 = {4, 1};
	addPointToPline(pl, &A4);
	addPointToPLline(pl2, &A4);
	printPline(pl);
	printf("\n");
	printPLline(pl2);
	printf("\n");

//	destroyPoint(A);
//	destroyPoint(B);
	destroyLine(AB);
	destroyLine(CD);
	destroyPline(pl);
	destroyPLline(pl2);
	free(dyn);
	return 0;
}
