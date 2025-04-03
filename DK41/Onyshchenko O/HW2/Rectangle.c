#include "Rectangle.h"
#include <stdio.h>
#include <stdlib.h>

Rectangle* createRectangle(double x1, double y1, double x2, double y2) {
    Rectangle* rect = (Rectangle*)malloc(sizeof(Rectangle));
    if (rect == NULL) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    rect->topLeft.x = x1;
    rect->topLeft.y = y1;
    rect->bottomRight.x = x2;
    rect->bottomRight.y = y2;
    return rect;
}

void destroyRectangle(Rectangle* rect) {
    if (rect != NULL) {
        free(rect);
    }
}

double calculateArea(const Rectangle* rect) {
    if (rect == NULL) {
        printf("Rectangle does not exist!\n");
        return 0.0;
    }
    double width = rect->bottomRight.x - rect->topLeft.x;
    double height = rect->topLeft.y - rect->bottomRight.y;
    return width * height;
}

void printRectangle(const Rectangle* rect) {
    if (rect == NULL) {
        printf("Rectangle does not exist!\n");
        return;
    }
    printf("Rectangle:\n");
    printf("Upper left point : (%.2f, %.2f)\n", rect->topLeft.x, rect->topLeft.y);
    printf("Lower right point: (%.2f, %.2f)\n", rect->bottomRight.x, rect->bottomRight.y);
}


Rectangle* inputRectangle() {
    double x1, y1, x2, y2;
    printf("Enter the coordinates of the upper left point (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of the lower right point (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    if (x1 >= x2 || y1 <= y2) {
        printf("Error: coordinates do not form a rectangle!\n");
        return NULL;
    }

    return createRectangle(x1, y1, x2, y2);
}
