#include "dk_tool.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int oct_to_int(const char *oct_str)
{
    unsigned long len = strlen(oct_str);
    int result = 0;

    for (int i = 0; i < len; i++) {
        char ch = oct_str[i];
        
        // Перевіряємо, чи символ є допустимою цифрою у восьмковій системі (0..7)
        if (ch < '0' || ch > '7') {
            fprintf(stderr, "Помилка: недопустимий символ \"%c\".\n", ch);
            return -1;  // Повертаємо -1, щоб позначити помилку
        }

        int digit = ch - '0';
        result = result * 8 + digit;
    }

    return result;
}
