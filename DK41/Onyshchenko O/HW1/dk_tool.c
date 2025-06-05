#include "dk_tool.h"
#include <string.h>

int count_substring_occurrences(const char *str, const char *substr) {
    int count = 0;
    size_t len = strlen(substr);

    if (len == 0 || strlen(str) < len)
        return 0;

    const char *pos = str;

    while ((pos = strstr(pos, substr)) != NULL) {
        count++;
        pos += len;
    }

    return count;
}
