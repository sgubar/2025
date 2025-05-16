#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Визначаємо тип фігури (наразі тільки трапеція)
typedef enum { TRAPEZOID } ShapeType;

// Кольори для фігур
typedef struct {
    float r, g, b;
} Color;

// Структура фігури з параметрами обертання
typedef struct {
    ShapeType type;
    float width;      // Ширина основи
    float height;     // Висота
    float topWidth;   // Ширина верху трапеції
    float x, y;       // Позиція
    float rotationAngle;
    float rotationSpeed;
    Color color;
} Shape;

// Вузол двозв'язного списку
typedef struct Node {
    Shape shape;
    struct Node* next;
    struct Node* prev;  // Додаємо покажчик на попередній елемент
} Node;

// Глобальна структура для управління списком
typedef struct {
    Node* head;
    Node* tail;  // Додаємо покажчик на останній елемент для швидкого доступу
    int count;   // Лічильник елементів
} List;

// Глобальний список
List trapezoidList = {NULL, NULL, 0};

// Створити новий вузол з трапецією
Node* createNode(float width, float height, float topWidth, float x, float y, 
                float speed, float r, float g, float b) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return NULL;
    
    node->shape.type = TRAPEZOID;
    node->shape.width = width;
    node->shape.height = height;
    node->shape.topWidth = topWidth;
    node->shape.x = x;
    node->shape.y = y;
    node->shape.rotationAngle = 0.0f;
    node->shape.rotationSpeed = speed;
    node->shape.color.r = r;
    node->shape.color.g = g;
    node->shape.color.b = b;
    node->next = NULL;
    node->prev = NULL;  // Ініціалізуємо покажчик на попередній елемент
    
    return node;
}

// Створити випадкову трапецію
Node* createRandomNode() {
    float width = (float)(rand() % 50 + 30) / 100.0f;
    float height = (float)(rand() % 30 + 20) / 100.0f;
    float topWidth = width * ((float)(rand() % 60 + 20) / 100.0f);
    float x = (float)(rand() % 100 - 50) / 100.0f;
    float y = (float)(rand() % 100 - 50) / 100.0f;
    float speed = ((float)(rand() % 20) / 10.0f) + 0.1f;
    float r = (float)(rand() % 100) / 100.0f;
    float g = (float)(rand() % 100) / 100.0f;
    float b = (float)(rand() % 100) / 100.0f;
    
    return createNode(width, height, topWidth, x, y, speed, r, g, b);
}

// Додати фігуру в кінець списку
void appendNode(List* list) {
    Node* newNode = createRandomNode();
    if (list->head == NULL) {
        // Якщо список порожній, новий вузол стає і головою, і хвостом
        list->head = newNode;
        list->tail = newNode;
    } else {
        // Додаємо новий вузол в кінець списку
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->count++;
    printf("Трапецію додано\n");
}

// Вставити фігуру за індексом
void insertNode(List* list, int index) {
    Node* newNode = createRandomNode();
    
    // Перевірка особливих випадків
    if (list->head == NULL) {
        // Якщо список порожній, просто зробимо новий вузол головним
        list->head = newNode;
        list->tail = newNode;
        list->count++;
        printf("Додано першу трапецію в порожній список\n");
        return;
    }
    
    // Якщо індекс 0 або менше - вставляємо на початок
    if (index <= 0) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        list->count++;
        printf("Нову трапецію розміщено на початку списку\n");
        return;
    }
    
    // Знаходимо позицію для вставки
    Node* current = list->head;
    int position = 0;
    
    // Рухаємось по списку до потрібної позиції або кінця
    while (position < index && current->next != NULL) {
        current = current->next;
        position++;
    }
    
    // Виконуємо вставку
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    }
    current->prev = newNode;
    
    // Якщо вставка відбулась на кінці списку, оновлюємо хвіст
    if (newNode->next == NULL) {
        list->tail = newNode;
    }
    
    list->count++;
    printf("Трапецію додано після елемента %d\n", position);
}

// Функція видалення вузла за індексом
void deleteNode(List* list, int index) {
    // Перевірка на порожній список
    if (list->head == NULL) {
        printf("Неможливо видалити: список порожній\n");
        return;
    }
    
    Node* current = list->head;
    int position = 0;
    
    // Якщо індекс 0 - видаляємо перший елемент
    if (index == 0) {
        if (list->head == list->tail) {
            // Якщо в списку лише один елемент
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
        } else {
            // Більше ніж один елемент у списку
            list->head = list->head->next;
            free(list->head->prev);
            list->head->prev = NULL;
        }
        list->count--;
        printf("Видалено першу трапецію зі списку\n");
        return;
    }
    
    // Рухаємось до потрібної позиції або кінця списку
    while (position < index && current != NULL) {
        current = current->next;
        position++;
    }
    
    // Якщо позиція не знайдена, виводимо повідомлення
    if (current == NULL) {
        printf("Індекс поза межами списку\n");
        return;
    }
    
    // Якщо видаляється останній елемент
    if (current == list->tail) {
        list->tail = current->prev;
        list->tail->next = NULL;
    } else {
        // Пересилаємо покажчики для видалення вузла
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    
    free(current);
    list->count--;
    printf("Видалено трапецію з позиції %d\n", position);
}

// Порахувати кількість елементів у списку
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Малювання трапеції
void drawTrapezoid(Shape* shape) {
    float halfWidth = shape->width / 2.0f;
    float halfTopWidth = shape->topWidth / 2.0f;
    float halfHeight = shape->height / 2.0f;
    
    glColor3f(shape->color.r, shape->color.g, shape->color.b);
    glBegin(GL_POLYGON);
        glVertex2f(shape->x - halfWidth, shape->y - halfHeight);
        glVertex2f(shape->x + halfWidth, shape->y - halfHeight);
        glVertex2f(shape->x + halfTopWidth, shape->y + halfHeight);
        glVertex2f(shape->x - halfTopWidth, shape->y + halfHeight);
    glEnd();
}

// Функція обробки меню
void processMenu(int option) {
    switch (option) {
        case 1: // Додати трапецію
            appendNode(&trapezoidList);
            break;
        case 2: // Видалити останню трапецію
            deleteNode(&trapezoidList, trapezoidList.count - 1);
            break;
        case 3: // Вставити трапецію на позицію 1
            insertNode(&trapezoidList, 1);
            break;
        case 4: // Видалити трапецію з позиції 1
            deleteNode(&trapezoidList, 1);
            break;
        case 5: // Вихід
            exit(0);
            break;
    }
    
    glutPostRedisplay();
}

// Функція малювання
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Обхід списку і малювання кожної трапеції
    Node* current = trapezoidList.head;
    while (current != NULL) {
        glPushMatrix();
            // Обертаємо навколо початку координат
            glRotatef(current->shape.rotationAngle, 0.0f, 0.0f, 1.0f);
            drawTrapezoid(&current->shape);
            
            // Оновлюємо кут обертання для наступного кадру
            current->shape.rotationAngle += current->shape.rotationSpeed;
            if (current->shape.rotationAngle >= 360.0f)
                current->shape.rotationAngle -= 360.0f;
        glPopMatrix();
        
        current = current->next;
    }
    
    glutSwapBuffers();
}

// Функція для безперервної анімації
void animationUpdate() {
    // Запит на перемалювання вікна
    glutPostRedisplay();
}

// Ініціалізація OpenGL та створення інтерфейсу
void setupGraphicsEnvironment() {
    // Встановлюємо темно-синій колір фону
    glClearColor(0.0, 0.0, 0.2, 1.0);
    
    // Налаштовуємо проекцію
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    
    // Створюємо контекстне меню для правої кнопки миші
    glutCreateMenu(processMenu);
    glutAddMenuEntry("Додати трапецію", 1);
    glutAddMenuEntry("Видалити останню трапецію", 2);
    glutAddMenuEntry("Вставити трапецію на позицію 1", 3);
    glutAddMenuEntry("Видалити трапецію з позиції 1", 4);
    glutAddMenuEntry("Вихід", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Головна функція
int main(int argc, char** argv) {
    // Ініціалізуємо генератор випадкових чисел
    srand((unsigned int)time(NULL));
    
    // Додаємо початкові трапеції для демонстрації
    appendNode(&trapezoidList);  // Перша трапеція
    insertNode(&trapezoidList, 0);  // Вставляємо на початок
    insertNode(&trapezoidList, 1);  // Вставляємо в середину
    
    // Ініціалізуємо GLUT бібліотеку для створення графічного контексту
    glutInit(&argc, argv);
    // Встановлюємо режим відображення з подвійною буферизацією та RGB кольоровою моделлю
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // Задаємо розмір вікна додатку в пікселях
    glutInitWindowSize(800, 600);
    // Задаємо положення верхнього лівого кута вікна відносно екрану
    glutInitWindowPosition(100, 100);
    // Створюємо вікно з заголовком
    glutCreateWindow("Обертові трапеції (C)");
    
    // Реєструємо функцію renderScene як обробник для перемалювання вікна
    glutDisplayFunc(renderScene);  // Перейменовано з display на renderScene
    // Реєструємо функцію animationUpdate як обробник для анімації в час простою
    glutIdleFunc(animationUpdate);  // Перейменовано з idle на animationUpdate
    
    // Налаштовуємо OpenGL середовище та створюємо меню
    setupGraphicsEnvironment();  // Перейменовано з init на setupGraphicsEnvironment
    
    // Запускаємо головний цикл обробки подій GLUT
    glutMainLoop();
    
    return 0;
}
