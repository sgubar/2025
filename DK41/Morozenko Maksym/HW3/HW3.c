#include <stdio.h>
#include <stdlib.h>

// Структура трикутника
typedef struct {
    float a, b, c;
} Triangle;

// Структура масиву трикутників
typedef struct {
    Triangle* data;
    int size;
    int capacity;
} Array;

// Створення масиву
Array* createArray(int capacity) {
    if (capacity <= 0) return NULL;

    Array* array = (Array*)malloc(sizeof(Array));
    if (!array) return NULL;

    array->data = (Triangle*)malloc(sizeof(Triangle) * capacity);
    if (!array->data) {
        free(array);
        return NULL;
    }

    array->size = 0;
    array->capacity = capacity;
    return array;
}

// Знищення масиву
void destroyArray(Array* array) {
    if (array) {
        free(array->data);
        free(array);
    }
}

// Додавання елемента
int addElement(Array* array, Triangle* t) {
    if (!array || !t || array->size >= array->capacity) return -1;

    array->data[array->size] = *t;
    return array->size++;
}

// Вставка елемента за індексом
int insertElementAt(Array* array, Triangle* t, int index) {
    if (!array || !t || index < 0 || index >= array->capacity) return -1;

    array->data[index] = *t;
    if (index >= array->size) array->size = index + 1;
    return index;
}

// Друк масиву
void printArray(const Array* array) {
    if (!array) return;

    printf("\nArray of triangles (total %d):\n", array->size);
    for (int i = 0; i < array->size; ++i) {
        Triangle t = array->data[i];
        printf("  [%d]: a = %.2f, b = %.2f, c = %.2f\n", i, t.a, t.b, t.c);
    }
}

// Введення одного трикутника
Triangle inputTriangle() {
    Triangle t;
    printf("Enter triangle sides (a b c): ");
    scanf("%f %f %f", &t.a, &t.b, &t.c);
    return t;
}

// Меню
void menu() {
    printf("\nMenu:\n");
    printf("1 - Add triangle to array\n");
    printf("2 - Insert triangle at index\n");
    printf("3 - Show array\n");
    printf("0 - Exit\n");
}

int main() {
    int capacity;
    printf("Enter number of triangles to store: ");
    scanf("%d", &capacity);

    Array* triangles = createArray(capacity);
    if (!triangles) {
        printf("Failed to create array.\n");
        return 1;
    }

    int choice;
    do {
        menu();
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Triangle t = inputTriangle();
                int result = addElement(triangles, &t);
                if (result == -1)
                    printf("❌ Failed to add triangle (array is full)\n");
                else
                    printf("✅ Triangle added at index %d\n", result);
                break;
            }
            case 2: {
                Triangle t = inputTriangle();
                int index;
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                int result = insertElementAt(triangles, &t, index);
                if (result == -1)
                    printf("❌ Insert failed (invalid index)\n");
                else
                    printf("✅ Triangle inserted at index %d\n", result);
                break;
            }
            case 3:
                printArray(triangles);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    destroyArray(triangles);
    printf("Program finished.\n");
    return 0;
}
