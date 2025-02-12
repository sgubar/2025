#include <stdio.h>
#include "dk_tool.h"
#include <string.h>

int main() {
    float a, b; 
    int c; 
    enter_numbers(&a, &b, &c); // Function to input numbers
    getchar(); // Consume the newline character left in the buffer
    display_math_operations(a, b, c); // Function to display math operations

    char sentence[100], pattern[50]; // Arrays to store strings
    printf("Enter a string: ");
    fgets(sentence, sizeof(sentence), stdin); // Input a string

    printf("Enter a search string: ");
    fgets(pattern, sizeof(pattern), stdin); // Input a search string

    // Remove newline characters (if exists)
    sentence[strcspn(sentence, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    int position = find_substring(sentence, pattern); // Find the position of the pattern in the sentence
    if (position != -1) {
        printf("String found in position: %d\n", position); // Pattern found
    } else {
        printf("String not found.\n"); // Pattern not found
    }

    return 0;
}
