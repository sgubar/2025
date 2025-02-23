#include "dk_tool.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int hex_to_int(const char *hex_str) {
    
    int len = strlen(hex_str);
    if (!hex_str || len > 4) {
        return -1;
    }
    
    
    int result = 0;
    for (int i = 0; i < len; i++) {
        char ch = toupper(hex_str[i]);
        int digit = 0;
        
        if (ch >= '0' && ch <= '9') {
            digit = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            digit = ch - 'A' + 10;
        } else {
            fprintf(stderr, "error '%c'.\n", hex_str[i]);
            return -1;
        }
        
        result = result * 16 + digit;
    }
    
    return result;
}
