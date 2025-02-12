#pragma once

// Function prototypes for math operations
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
double divide(float a, float b);
long factorial(int c);

// Function prototypes for input and display
void enter_numbers(float *a, float *b, int *c); // Accept pointers
void display_math_operations(float a, float b, int c);

// Function prototype for finding substring
int find_substring(const char *sentence, const char *pattern);
