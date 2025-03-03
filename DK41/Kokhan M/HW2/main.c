    #include "ellipse.h"

    int main() {
        Point center = {0.0, 0.0};
        double major_axis = 5.0;
        double minor_axis = 3.0;

        Ellipse* my_ellipse = create_ellipse(center, major_axis, minor_axis);

        if (my_ellipse == NULL) {
            return 1;
        }

        print_ellipse(my_ellipse);

        double area = calculate_ellipse_area(my_ellipse);
        printf("Площа еліпса: %.2lf\n", area);

        Point point1 = {2.0, 1.0};
        Point point2 = {6.0, 4.0};

        if (is_point_inside_ellipse(my_ellipse, &point1)) {
            printf("Точка (%.2lf, %.2lf) знаходиться всередині еліпса.\n", point1.x, point1.y);
        } else {
            printf("Точка (%.2lf, %.2lf) знаходиться зовні еліпса.\n", point1.x, point1.y);
        }

        if (is_point_inside_ellipse(my_ellipse, &point2)) {
            printf("Точка (%.2lf, %.2lf) знаходиться всередині еліпса.\n", point2.x, point2.y);
        } else {
            printf("Точка (%.2lf, %.2lf) знаходиться зовні еліпса.\n", point2.x, point2.y);
        }


        int num_ellipses = 3;
        Ellipse* ellipse_array[num_ellipses];

        for (int i = 0; i < num_ellipses; ++i) {
            Point new_center = {i * 1.0, i * 1.0};
            ellipse_array[i] = create_ellipse(new_center, major_axis + i, minor_axis + i);
            if (ellipse_array[i] == NULL) {
                for (int j = 0; j < i; ++j) {
                    destroy_ellipse(ellipse_array[j]);
                }
                destroy_ellipse(my_ellipse);
                return 1;
            }
            printf("Еліпс %d:\n", i + 1);
            print_ellipse(ellipse_array[i]);
        }

        for (int i = 0; i < num_ellipses; ++i) {
            destroy_ellipse(ellipse_array[i]);
        }

        destroy_ellipse(my_ellipse);

        return 0;
    }
