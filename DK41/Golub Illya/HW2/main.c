#include <stdio.h>
#include "trapezoid.h"

int main() {
    // Створення точок для трапеції
    Point points[4] = {{0, 0}, {4, 0}, {3, 3}, {1, 3}};
    
    // Створення фігури з точок
    Figure* figure = create_figure_from_points(points, 4);
    if (!figure) {
        return 1;
    }

    print_figure(figure);

    // Обчислення та друк площі
    double area = calculate_area(figure);
    if (area != -1) {
        printf("Площа фігури: %.2f\n", area);
    }

    // Знищення фігури
    destroy_figure(figure);

    return 0;
}
