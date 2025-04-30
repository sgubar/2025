 #include <stdio.h>
 #include <stdlib.h>
 
 /* Approximation of PI */
 #define PI 3.14159265358979323846
 
 /**
  * Compute absolute value of a double.
  */
 static double abs_double(double x) {
     return (x < 0.0) ? -x : x;
 }
 
 /**
  * Compute square root using Newton's method.
  * Returns 0.0 if input is non-positive.
  */
 static double sqrt_newton(double value) {
     if (value <= 0.0) {
         return 0.0;
     }
     double estimate = value;
     double diff;
     do {
         diff = (estimate * estimate - value) / (2.0 * estimate);
         estimate -= diff;
     } while (abs_double(diff) > 1e-6);
     return estimate;
 }
 
 /* Supported figure types */
 typedef enum {
     FIGURE_CIRCLE
 } FigureType;
 
 /* 2D point */
 typedef struct {
     double x;
     double y;
 } Point;
 
 /* Circle: center point and radius */
 typedef struct {
     Point center;
     double radius;
 } Circle;
 
 /* Generic figure wrapper */
 typedef struct {
     FigureType type;
     void *shape;  /* Points to a Circle when type == FIGURE_CIRCLE */
 } Figure;
 
 /**
  * Compute the area of the figure.
  * Currently only supports circles.
  */
 double compute_area(const Figure *fig) {
     if (fig == NULL || fig->type != FIGURE_CIRCLE || fig->shape == NULL) {
         fprintf(stderr, "compute_area: invalid figure\n");
         return 0.0;
     }
     const Circle *c = (const Circle *)fig->shape;
     return PI * c->radius * c->radius;
 }
 
 /**
  * Create a circle figure from an array of exactly two points:
  * pts[0] is the center, pts[1] is a point on the circumference.
  */
 Figure *create_circle_from_points(const Point pts[], size_t count) {
     if (pts == NULL || count != 2) {
         fprintf(stderr, "create_circle_from_points: require exactly 2 points\n");
         return NULL;
     }
 
     /* Allocate memory for Figure and Circle */
     Figure *fig = malloc(sizeof(Figure));
     Circle *circle = malloc(sizeof(Circle));
     if (fig == NULL || circle == NULL) {
         perror("malloc");
         free(circle);
         free(fig);
         return NULL;
     }
 
     /* Set circle center */
     circle->center = pts[0];
 
     /* Compute radius as distance between pts[0] and pts[1] */
     double dx = pts[1].x - pts[0].x;
     double dy = pts[1].y - pts[0].y;
     circle->radius = sqrt_newton(dx * dx + dy * dy);
 
     fig->type = FIGURE_CIRCLE;
     fig->shape = circle;
     return fig;
 }
 
 /**
  * Create a circle figure from an array of two Point pointers.
  */
 Figure *create_circle_from_point_ptrs(Point *pts[], size_t count) {
     if (pts == NULL || count != 2 || pts[0] == NULL || pts[1] == NULL) {
         fprintf(stderr, "create_circle_from_point_ptrs: require 2 non-null pointers\n");
         return NULL;
     }
     Point temp[2] = { *pts[0], *pts[1] };
     return create_circle_from_points(temp, 2);
 }
 
 /**
  * Create a circle figure from a flat array of four coordinates:
  * coords[0]=x_center, coords[1]=y_center,
  * coords[2]=x_on_circ, coords[3]=y_on_circ.
  */
 Figure *create_circle_from_coords(const double coords[], size_t count) {
     if (coords == NULL || count != 4) {
         fprintf(stderr, "create_circle_from_coords: require exactly 4 values\n");
         return NULL;
     }
     Point temp[2] = {
         { coords[0], coords[1] },
         { coords[2], coords[3] }
     };
     return create_circle_from_points(temp, 2);
 }
 
 /**
  * Free memory allocated for the figure and its shape.
  */
 void destroy_figure(Figure *fig) {
     if (fig == NULL) {
         return;
     }
     free(fig->shape);
     free(fig);
 }
 
 /**
  * Print circle parameters: center, radius, and area.
  */
 void print_figure(const Figure *fig) {
     if (fig == NULL || fig->type != FIGURE_CIRCLE || fig->shape == NULL) {
         printf("print_figure: invalid figure\n");
         return;
     }
     const Circle *c = (const Circle *)fig->shape;
     printf("Figure: Circle\n");
     printf("  Center: (%.3f, %.3f)\n", c->center.x, c->center.y);
     printf("  Radius: %.3f\n", c->radius);
     printf("  Area:   %.3f\n", compute_area(fig));
 }
 
 int main(void) {
     /* Example 1: from array of Points */
     Point pts1[2] = { {0.0, 0.0}, {1.0, 0.0} };
     Figure *circle1 = create_circle_from_points(pts1, 2);
     print_figure(circle1);
 
     /* Example 2: from Point pointers */
     Point p1 = { 2.0, 2.0 };
     Point p2 = { 2.0, 4.0 };
     Point *ptrs[2] = { &p1, &p2 };
     Figure *circle2 = create_circle_from_point_ptrs(ptrs, 2);
     print_figure(circle2);
 
     /* Example 3: from flat coordinate array */
     double coords[4] = { -1.0, -1.0, -1.0, 5.0 };
     Figure *circle3 = create_circle_from_coords(coords, 4);
     print_figure(circle3);
 
     /* Print all figures */
     Figure *all_figs[3] = { circle1, circle2, circle3 };
     printf("\nTotal figures: %zu\n", (size_t)(sizeof(all_figs) / sizeof(all_figs[0])));
     for (size_t i = 0; i < 3; ++i) {
         printf("Figure %zu:\n", i + 1);
         print_figure(all_figs[i]);
     }
 
     /* Clean up */
     for (size_t i = 0; i < 3; ++i) {
         destroy_figure(all_figs[i]);
     }
 
     return 0;
 }
 