#include <stdio.h>
#include "dk_tool.h"

void input_string(char *buffer, int size, const char *prompt) {
    printf("%s", prompt);
    if (scanf("%s", buffer) != 1) {
        fprintf(stderr, "Input error!\n");
    }
}

int main() {
    char hex_input[10]; 
    
    input_string(hex_input, sizeof(hex_input), "enter a 16-character expression (no more than 4 characters): ");
    
    int value = hex_to_int(hex_input);
    if (value == -1) {
        printf("error.\n");
    } else {
        printf("decimal value: %d\n", value);
    }
    
    return 0;
}
