#include <stdio.h>
#include <stdlib.h>
#include "struc.h"

int main() {
    Rectangle* rect = create_rectangle();
    if (!rect) return 1;

    print_rectangle(rect);

    if (check_if_rectangle(rect)) {
        printf("Area: %.2f\n", rectangle_area(rect));
    } else {
        printf("This is not rectangle.\n");
    }

    delete_rectangle(rect);
    return 0;
}
