#include <stdio.h>
#include "dk_tool.h"
#include <string.h>

float add(float a, float b) 
{
    return a + b;
}

float subtract(float a, float b) 
{
    return a - b;
}

float multiply(float a, float b) 
{
    return a * b;
}

double divide(float a, float b) 
{
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0; 
    } else {
        return a / b;
    }
}

long factorial(int c)
{
    if (c < 0)
    {
        printf("Error: Factorial of a negative number\n");
        return 0;
    }
    else if (c == 0)
    {
        return 1;
    }
    else
    {
        return c * factorial(c - 1);
    }
}

// Function to input numbers
void enter_numbers(float *a, float *b, int *c) // Accept pointers
{
    printf("Enter a: ");
    scanf("%f", a); // Use pointers to modify values
    
    printf("Enter b: ");
    scanf("%f", b);
    
    printf("Enter c: ");
    scanf("%d", c);
}

// Function to display math operations
void display_math_operations(float a, float b, int c) 
{
    printf("Addition: %.2f + %.2f = %.2f\n", a, b, add(a, b));
    printf("Subtraction: %.2f - %.2f = %.2f\n", a, b, subtract(a, b));
    printf("Multiplication: %.2f * %.2f = %.2f\n", a, b, multiply(a, b));
    printf("Division: %.2f / %.2f = %.2f\n", a, b, divide(a, b));
    printf("Factorial of %d: %ld\n", c, factorial(c));
}

// Function to find substring in a string
int find_substring(const char *sentence, const char *pattern) 
{
    char *pos = strstr(sentence, pattern);
    if (pos) {
        return pos - sentence; // Position of the pattern
    }
    return -1; // If not found
}
