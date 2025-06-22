#include "point.h"
#include <stdlib.h>

Point* createPoint(float x, float y) {
    Point* p = (Point*)malloc(sizeof(Point));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void deletePoint(Point* p) {
    if (p != NULL) {
        free(p);
    }
}
