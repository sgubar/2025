#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// b) Структура точки
typedef struct {
    float x;
    float y;
} Point;

// a) Структура фігури: трикутник
typedef struct {
    Point* points[3];
} Triangle;

// e) Перевірка валідності трикутника (не лежать на одній прямій)
int isValidTriangle(Point* a, Point* b, Point* c) {
    if (!a || !b || !c) return 0;
    float area = 0.5f * fabsf(a->x * (b->y - c->y) +
                              b->x * (c->y - a->y) +
                              c->x * (a->y - b->y));
    return area > 0.0001f;
}

// f) Функція обчислення площі
float calculateArea(Triangle* t) {
    if (!t || !t->points[0] || !t->points[1] || !t->points[2]) return -1.0f;
    Point* a = t->points[0];
    Point* b = t->points[1];
    Point* c = t->points[2];
    return 0.5f * fabsf(a->x * (b->y - c->y) +
                       b->x * (c->y - a->y) +
                       c->x * (a->y - b->y));
}

// c) Створення фігури за координатами
Triangle* createTriangleFromCoordinates(float x1, float y1,
                                        float x2, float y2,
                                        float x3, float y3) {
    Point a = {x1, y1};
    Point b = {x2, y2};
    Point c = {x3, y3};
    if (!isValidTriangle(&a, &b, &c)) return NULL;

    Triangle* t = (Triangle*)malloc(sizeof(Triangle));
    if (!t) return NULL;

    t->points[0] = (Point*)malloc(sizeof(Point));
    t->points[1] = (Point*)malloc(sizeof(Point));
    t->points[2] = (Point*)malloc(sizeof(Point));
    if (!t->points[0] || !t->points[1] || !t->points[2]) return NULL;

    *(t->points[0]) = a;
    *(t->points[1]) = b;
    *(t->points[2]) = c;
    return t;
}

// d) Знищення фігури
void destroyTriangle(Triangle* t) {
    if (!t) return;
    for (int i = 0; i < 3; ++i) {
        free(t->points[i]);
    }
    free(t);
}

// f) Вивід параметрів фігури
void printTriangle(Triangle* t) {
    if (!t) {
        printf("Triangle is invalid or NULL.\n");
        return;
    }

    printf("Triangle vertices:\n");
    for (int i = 0; i < 3; ++i) {
        printf("  Point %d: (%.2f, %.2f)\n", i + 1, t->points[i]->x, t->points[i]->y);
    }
    float area = calculateArea(t);
    printf("Area: %.2f\n", area);
}

// g) Приклад використання з взаємодією з користувачем
int main() {
    Triangle* currentTriangle = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1 - Create triangle from coordinates\n");
        printf("2 - Show triangle parameters\n");
        printf("3 - Destroy triangle\n");
        printf("0 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                float x1, y1, x2, y2, x3, y3;
                printf("Enter coordinates (x1 y1 x2 y2 x3 y3): ");
                scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);

                Triangle* t = createTriangleFromCoordinates(x1, y1, x2, y2, x3, y3);
                if (t) {
                    if (currentTriangle) destroyTriangle(currentTriangle);
                    currentTriangle = t;
                    printf("Triangle created successfully.\n");
                } else {
                    printf("Invalid triangle. Points may be colinear.\n");
                }
                break;
            }
            case 2: {
                if (currentTriangle) {
                    printTriangle(currentTriangle);
                } else {
                    printf("No triangle created yet.\n");
                }
                break;
            }
            case 3: {
                if (currentTriangle) {
                    destroyTriangle(currentTriangle);
                    currentTriangle = NULL;
                    printf("Triangle destroyed.\n");
                } else {
                    printf("Nothing to destroy.\n");
                }
                break;
            }
            case 0:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    if (currentTriangle) destroyTriangle(currentTriangle);
    printf("Program finished.\n");
    return 0;
}
