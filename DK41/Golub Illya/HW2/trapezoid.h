#pragma once

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point* points;
    int num_points;
} Figure;

// Допоміжна функція для ініціалізації фігури
Figure* initialize_figure(int num_points);

// Функція для створення фігури з масиву точок
Figure* create_figure_from_points(Point* points, int num_points);

// Функція для створення фігури зі списку вказівників на точки
Figure* create_figure_from_point_list(Point** point_list, int num_points);

// Функція для створення фігури зі списку координат
Figure* create_figure_from_coordinates(double* coordinates, int num_points);

// Функція для знищення фігури
void destroy_figure(Figure* figure);

// Функція для обчислення площі фігури
double calculate_area(Figure* figure);

// Функція для друку параметрів фігури
void print_figure(Figure* figure);
