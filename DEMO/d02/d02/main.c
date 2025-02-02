//
//  main.c
//  d02
//
//  Created by Slava Gubar on 15.02.2021.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct tag_test {
	int a;
	int b;
	char c[3];
	char c1;
} TTest, *PTTest;

//typedef struct tag_test TTest;
//typedef unsigned int uint_32;

void try_to_change(TTest B);
long size_of_variables(TTest A);

void try_to_change_pointer(struct tag_test *B);
long size_of_variables_pointer(PTTest A);

int main(int argc, const char * argv[]) {
	TTest A;
	TTest B = {10, 20};
	TTest C = {.b = 20, .a = 40, .c = {'A', 'B', 'C'} };

	struct tag_test *pA = &A;
	PTTest pB = &B;

	int a = B.a;
	int z = B.b;

	int a1 = pB->a;
	int z1 = pB->b;

	int a2 = (*pB).a;
	int z2 = (*pB).b;

	struct tag_test *test1 = (struct tag_test *)malloc(sizeof(struct tag_test));

	TTest *test2 = (TTest *)malloc(sizeof(TTest));

	PTTest test = (PTTest)malloc(sizeof(TTest));

	test2->b = 56;
	try_to_change_pointer(test2);

	free(test2);
	free(test);
	free(test1);

	A.a = 50;
	A.b = z;

	int g = sizeof(A);

	try_to_change(A); //A.a = 50
	printf("A.a = %d\n", A.a);

	try_to_change_pointer(&A); //A.a = 20
	printf("A.a = %d\n", A.a);

	// insert code here...
	printf("Hello, World!\n");
	return 0;
}


long size_of_variables(TTest A) {
	return sizeof(A.a) + sizeof(A.b) + sizeof(A.c) + sizeof(A.c1);
}

void try_to_change(TTest B) {
	B.a = 20;
}

void try_to_change_pointer(struct tag_test *B) {
	B->a = 20;
}

long size_of_variables_pointer(PTTest A) {
	return sizeof(A->a) + sizeof(A->b) + sizeof(A->c) + sizeof(A->c1);
}
