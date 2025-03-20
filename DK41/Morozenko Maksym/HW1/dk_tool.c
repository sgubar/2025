#include "dk_tool.h"  

int count_words(const char* sentence) {
    int count = 0;
    int in_word = 0;
    
    while (*sentence) {
        if (*sentence == ' ' || *sentence == '\n' || *sentence == '\t') {
            
            in_word = 0;
        } else if (!in_word) {
            
            in_word = 1;
            count++;
        }
        sentence++;
    }
    return count;
}
