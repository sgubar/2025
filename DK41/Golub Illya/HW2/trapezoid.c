#include <stdio.h>
#include <stdlib.h>
#include "trapezoid.h"

// Допоміжна функція для ініціалізації фігури
Figure* initialize_figure(int num_points) {
    if (num_points < 3) {
        printf("Помилка: Фігура повинна мати щонайменше 3 точки.\n");
        return NULL;
    }
    Figure* figure = (Figure*)malloc(sizeof(Figure));
    figure->points = (Point*)malloc(num_points * sizeof(Point));
    figure->num_points = num_points;
    return figure;
}

// Функція для створення фігури з масиву точок
Figure* create_figure_from_points(Point* points, int num_points) {
    Figure* figure = initialize_figure(num_points);
    if (!figure) return NULL;
    for (int i = 0; i < num_points; ++i) {
        figure->points[i] = points[i];
    }
    return figure;
}

// Функція для створення фігури зі списку вказівників на точки
Figure* create_figure_from_point_list(Point** point_list, int num_points) {
    Figure* figure = initialize_figure(num_points);
    if (!figure) return NULL;
    for (int i = 0; i < num_points; ++i) {
        figure->points[i] = *point_list[i];
    }
    return figure;
}

// Функція для створення фігури зі списку координат
Figure* create_figure_from_coordinates(double* coordinates, int num_points) {
    Figure* figure = initialize_figure(num_points);
    if (!figure) return NULL;
    for (int i = 0; i < num_points; ++i) {
        figure->points[i].x = coordinates[2 * i];
        figure->points[i].y = coordinates[2 * i + 1];
    }
    return figure;
}

// Функція для знищення фігури
void destroy_figure(Figure* figure) {
    if (figure) {
        free(figure->points);
        free(figure);
    }
}

// Функція для обчислення площі фігури (трапеція)
double calculate_area(Figure* figure) {
    if (figure->num_points != 4) {
        printf("Помилка: Підтримуються лише трапеції з 4 точками.\n");
        return -1;
    }
    double a = figure->points[1].x - figure->points[0].x;
    double b = figure->points[2].x - figure->points[3].x;
    double h = figure->points[0].y - figure->points[3].y;
    return 0.5 * (a + b) * h;
}

// Функція для друку параметрів фігури
void print_figure(Figure* figure) {
    printf("Фігура з %d точками:\n", figure->num_points);
    for (int i = 0; i < figure->num_points; ++i) {
        printf("Точка %d: (%.2f, %.2f)\n", i + 1, figure->points[i].x, figure->points[i].y);
    }
}
