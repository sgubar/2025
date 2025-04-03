#include "Rectangle.h"

int main() {
    Rectangle* rect = inputRectangle();
    if (rect == NULL) {
        return 1; // Помилка введення
    }
    printRectangle(rect);
    double area = calculateArea(rect);
    printf("Area of ​​the rectangle: %.2f\n", area);
    destroyRectangle(rect);
    return 0;
}
