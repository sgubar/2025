#include <GL/glut.h>
#include <stdlib.h>

typedef enum { SQUARE } ShapeType;

// Структура Shape зберігає тип фігури, розмір, поточний кут обертання та швидкість обертання
typedef struct {
    ShapeType type;
    float size;
    float rotationAngle;
    float rotationSpeed;
} Shape;

typedef struct Node {
    Shape shape;
    struct Node* next;
} Node;

Node* head = NULL;


// Створити новий вузол
Node* createNode(ShapeType type, float size, float speed) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->shape.type          = type;
    node->shape.size          = size;
    node->shape.rotationAngle = 0.0f;
    node->shape.rotationSpeed = speed;
    node->next                = NULL;
    return node;
}

// Додати нову фігуру в кінець списку
void appendNode(Node** headRef, ShapeType type, float size, float speed) {
    Node* newNode = createNode(type, size, speed);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Вставити нову фігуру за індексом (0 = на початок)
void insertNode(Node** headRef, int index, ShapeType type, float size, float speed) {
    Node* newNode = createNode(type, size, speed);
    if (index <= 0 || *headRef == NULL) {
        newNode->next = *headRef;
        *headRef      = newNode;
    } else {
        Node* temp = *headRef;
        for (int i = 0; i < index - 1 && temp->next; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next    = newNode;
    }
}

// Видалити вузол за індексом
void deleteNode(Node** headRef, int index) {
    if (*headRef == NULL)
        return;
    Node* temp = *headRef;
    if (index == 0) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
        return;
    Node* toDelete = temp->next;
    temp->next     = toDelete->next;
    free(toDelete);
}

// Малює квадрат з центром у початку координат стороною size
void drawSquare(float size) {
    float h = size * 0.5f;
    glBegin(GL_QUADS);
        glVertex2f(-h, -h);
        glVertex2f( h, -h);
        glVertex2f( h,  h);
        glVertex2f(-h,  h);
    glEnd();
}

// Викликається кожного кадру: очищає екран, малює і оновлює всі фігури
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Node* current = head;
    while (current) {
        glPushMatrix();
            // Обертання навколо початку координат на поточний кут
            glRotatef(current->shape.rotationAngle, 0.0f, 0.0f, 1.0f);
            if (current->shape.type == SQUARE) {
                drawSquare(current->shape.size);
            }
        glPopMatrix();

        // Оновлюємо кут обертання для наступного кадру
        current->shape.rotationAngle += current->shape.rotationSpeed;
        if (current->shape.rotationAngle >= 360.0f)
            current->shape.rotationAngle -= 360.0f;

        current = current->next;
    }

    glutSwapBuffers();
}

//Дял безперервної анімації
void idle() {
    glutPostRedisplay();
}

// ─── Головна функція та демонстрація роботи зі списком ────────────────────────────
int main(int argc, char** argv) {
    // 1. Додаємо квадрат розміром 0.5, що обертається зі швидкістю +0.5°/кадр
    appendNode(&head, SQUARE, 1.0f,  0.1f);

    // 2. Вставляємо менший квадрат на початок, що обертається зі швидкістю −1°/кадр
    insertNode(&head, 0, SQUARE, 0.3f, 0.1f);

    // 3. Видаляємо другий вузол (індекс 1) для демонстрації видалення
    deleteNode(&head, 1);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D OpenGL з використанням списків");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
