#include <stdio.h>
#include <string.h>
#include "dk_tool.h"

#define MAX_LEN 256

void read_input(char *prompt, char *buffer, int size);
void print_result(const char *sentence, const char *sequence, int count);

int main() {
    char sentence[MAX_LEN];
    char sequence[MAX_LEN];

    read_input("Enter a sentence: ", sentence, MAX_LEN);
    read_input("Enter a character sequence: ", sequence, MAX_LEN);
    int result = count_substring_occurrences(sentence, sequence);

    print_result(sentence, sequence, result);

    return 0;
}

void read_input(char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }
}

void print_result(const char *sentence, const char *sequence, int count) {
    printf("In the sentence:\n\"%s\"\n", sentence);
    printf("the sequence \"%s\" occurs %d time(s).\n", sequence, count);
}
