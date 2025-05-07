#include <stdio.h>
#include <stdlib.h>

/* Структура для круга: центр по X/Y та радіус */
typedef struct {
    double x;
    double y;
    double radius;
} Circle;

/* Динамічний масив кругів */
typedef struct {
    Circle *data;    /* сюди світяться елементи */
    size_t size;     /* скільки вже є */
    size_t capacity; /* скільки можна максимально */
} Array;

/* a) Створюємо масив під `capacity` елементів */
Array *createArray(size_t capacity) {
    Array *arr = malloc(sizeof(Array));
    if (!arr) return NULL;

    arr->data = malloc(sizeof(Circle) * capacity);
    if (!arr->data) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

/* b) Звільняємо пам’ять масиву цілком */
void destroyArray(Array *arr) {
    if (!arr) return;
    free(arr->data);
    free(arr);
}

/* c) Додаємо круг в кінець, якщо є місце */
int addElement(Array *arr, const Circle *elem) {
    if (!arr || arr->size >= arr->capacity) {
        return -1;  /* щось пішло не так або вже нема місця */
    }
    arr->data[arr->size] = *elem;
    return (int)(arr->size++);
}

/* d) Вставляємо або замінюємо круг за вказаним індексом */
int insertElement(Array *arr, const Circle *elem, size_t index) {
    if (!arr || index >= arr->capacity) {
        return -1;  /* за межами ємності */
    }
    if (index > arr->size) {
        return -1;  /* не даємо "дір" між елементами */
    }
    arr->data[index] = *elem;
    if (index == arr->size) {
        arr->size++;
    }
    return (int)index;
}

/* e) Друкуємо масив на екран */
void printArray(const Array *arr) {
    if (!arr) {
        printf("Array not created.\n");
        return;
    }
    if (arr->size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array of circles (size = %zu, capacity = %zu):\n",
           arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++) {
        Circle c = arr->data[i];
        printf("  [%2zu] center=(%.2f, %.2f), radius=%.2f\n",
               i, c.x, c.y, c.radius);
    }
}

/* g) Приклад використання */
int main(void) {
    /* отут вирішуємо, що нам треба 5 кругів максимум */
    Array *circles = createArray(5);
    if (!circles) {
        fprintf(stderr, "Failed to create array.\n");
        return EXIT_FAILURE;
    }

    /* додаємо трохи кругів */
    Circle c1 = {0.0, 0.0, 1.0};
    Circle c2 = {2.0, 2.0, 0.5};
    Circle c3 = {-1.0, 1.0, 2.5};
    addElement(circles, &c1);
    addElement(circles, &c2);
    addElement(circles, &c3);

    /* замінюємо елемент під індексом 1 */
    Circle c4 = {5.0, -3.0, 1.5};
    insertElement(circles, &c4, 1);

    /* додаємо ще один в кінець */
    Circle c5 = {-2.5, 0.0, 0.75};
    addElement(circles, &c5);

    /* виводимо результат */
    printArray(circles);

    /* прибираємо все з пам’яті */
    destroyArray(circles);
    return EXIT_SUCCESS;
}
