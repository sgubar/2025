#include <stdio.h>
#include "dk_tool.h"

void remove_newline(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}
// Function to find substring in a string without using string.h
int find_substring(const char *sentence, const char *pattern) 
{
    int i, j, k;
    for (i = 0; sentence[i] != '\0'; i++) {
        for (j = i, k = 0; pattern[k] != '\0' && sentence[j] == pattern[k]; j++, k++);
        if (pattern[k] == '\0') {
            return i; // Position of the pattern
        }
    }
    return -1; // If not found
}
