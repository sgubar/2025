#include <stdio.h>
#include "dk_tool.h"

int main() {

    char sentence[100], pattern[50]; // Arrays to store strings
    printf("Enter a string: ");
    fgets(sentence, sizeof(sentence), stdin); // Input a string

    printf("Enter a search string: ");
    fgets(pattern, sizeof(pattern), stdin); // Input a search string

    // Remove newline characters (if exists)
    remove_newline(sentence);
    remove_newline(pattern);

    int position = find_substring(sentence, pattern); // Find the position of the pattern in the sentence
    if (position != -1) {
        printf("String found in position: %d\n", position); // Pattern found
    } else {
        printf("String not found.\n"); // Pattern not found
    }

    return 0;
}
