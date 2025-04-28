#include "struc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Rectangle* create_rectangle() {
    Rectangle* rect = (Rectangle*)malloc(sizeof(Rectangle));
    if (!rect) return NULL;

    printf("Enter the coordinates of 4 points (x y):\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: ", i + 1);
        if (scanf("%lf %lf", &rect->points[i].x, &rect->points[i].y) != 2) {
            printf("Error.\n");
            free(rect);
            return NULL;
        }
    }

    return rect;
}

void print_rectangle(Rectangle* rect) {
    if (!rect) return;
    printf("\nRectangle with points:\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, rect->points[i].x, rect->points[i].y);
    }
}

int check_if_rectangle(Rectangle* rect) {
    if (!rect) return 0;

    Point* p = rect->points;

    double d01 = distance(p[0], p[1]);
    double d12 = distance(p[1], p[2]);
    double d23 = distance(p[2], p[3]);
    double d30 = distance(p[3], p[0]);
    double d02 = distance(p[0], p[2]);
    double d13 = distance(p[1], p[3]);

    if (fabs(d01 - d23) < 0.001 &&
        fabs(d12 - d30) < 0.001 &&
        fabs(d02 - d13) < 0.001)
        return 1;

    return 0;
}

double rectangle_area(Rectangle* rect) {
    if (!rect) return 0;

    double area = 0;
    for (int i = 0; i < 4; i++) {
        Point p1 = rect->points[i];
        Point p2 = rect->points[(i + 1) % 4];
        area += (p1.x * p2.y - p2.x * p1.y);
    }

    return fabs(area) / 2.0;
}

void delete_rectangle(Rectangle* rect) {
    if (rect) free(rect);
}
