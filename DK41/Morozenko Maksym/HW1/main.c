#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "dk_tool.h"

#define MAX_LENGTH 1000  

void remove_newline(char* sentence) {
    size_t len = strlen(sentence);  
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';  
    }
}

int main() {
    char sentence[MAX_LENGTH];  

    
    printf("Please enter a sentence: ");
    fgets(sentence, MAX_LENGTH, stdin);  

    
    remove_newline(sentence);

    
    printf("Sentence: %s\n", sentence);  
    
    
    int word_count = count_words(sentence);
    
    
    printf("Number of words: %d\n", word_count);  

    
    printf("Press Enter to exit...\n");
    getchar();  

    return 0;
}
