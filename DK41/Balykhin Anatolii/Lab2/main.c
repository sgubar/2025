#include <stdio.h>
#include "list.h"

int main() {
    char filename[100];

    printf("Enter name file: ");
    scanf("%99s", filename);

    int result = check_brackets(filename);

    if (result == -1) {
        printf("File not found.\n");
    }
    else if (result == 1) {
        printf("Bracket is balanced\n");
    }
    else {
        printf("Bracket is no balanced\n");
    }

    return 0;
}
