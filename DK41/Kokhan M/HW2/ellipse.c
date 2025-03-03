#include "ellipse.h"
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Ellipse* create_ellipse(Point center, double major_axis, double minor_axis) {
    if (major_axis <= 0 || minor_axis <= 0) {
        fprintf(stderr, "Помилка: Довжина осей повинна бути більше нуля.\n");
        return NULL;
    }

    Ellipse* ellipse = (Ellipse*)malloc(sizeof(Ellipse));
    if (ellipse == NULL) {
        perror("Помилка: Не вдалося виділити пам'ять для еліпса.");
        return NULL;
    }

    ellipse->center = center;
    ellipse->major_axis = major_axis;
    ellipse->minor_axis = minor_axis;

    return ellipse;
}

void destroy_ellipse(Ellipse* ellipse) {
    if (ellipse != NULL) {
        free(ellipse);
    }
}

double calculate_ellipse_area(const Ellipse* ellipse) {
    if (ellipse == NULL) {
        fprintf(stderr, "Помилка: Вказівник на еліпс є NULL.\n");
        return -1.0;
    }

    return M_PI * ellipse->major_axis * ellipse->minor_axis;
}

void print_ellipse(const Ellipse* ellipse) {
    if (ellipse == NULL) {
        printf("Еліпс не існує (NULL pointer).\n");
        return;
    }

    printf("Еліпс:\n");
    printf("  Центр: (%.2lf, %.2lf)\n", ellipse->center.x, ellipse->center.y);
    printf("  Велика піввісь: %.2lf\n", ellipse->major_axis);
    printf("  Мала піввісь: %.2lf\n", ellipse->minor_axis);
    printf("  Площа: %.2lf\n", calculate_ellipse_area(ellipse));
}

bool is_point_inside_ellipse(const Ellipse* ellipse, const Point* point) {
    if (ellipse == NULL || point == NULL) {
        fprintf(stderr, "Помилка: Вказівник на еліпс або точку є NULL.\n");
        return false;
    }

    double x = point->x - ellipse->center.x;
    double y = point->y - ellipse->center.y;

    return (x * x) / (ellipse->major_axis * ellipse->major_axis) +
           (y * y) / (ellipse->minor_axis * ellipse->minor_axis) <= 1.0;
}
