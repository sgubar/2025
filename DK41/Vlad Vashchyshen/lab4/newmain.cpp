#include <GL/glut.h>
#include <cstdlib>  // для rand()
#include <cmath>

// Структура фігури
struct Shape {
    float x, y;      // координати
    float angle;     // кут обертання
    float r, g, b;   // колір
};

// Вузол однозв'язного списку
struct Node {
    Shape data;
    Node* next;
};

// Глобальні змінні
Node* head = nullptr;
float rotationSpeed = 1.0f;

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.43f, -0.25f);
    glVertex2f(0.43f, -0.25f);
    glEnd();
}

// Функція малювання
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Node* current = head;
    while (current != nullptr) {
        Shape& shape = current->data;

        glPushMatrix();
        glTranslatef(shape.x, shape.y, 0.0f);
        glRotatef(shape.angle, 0.0f, 0.0f, 1.0f);
        glColor3f(shape.r, shape.g, shape.b);
        drawTriangle();
        glPopMatrix();

        current = current->next;
    }

    glutSwapBuffers();
}

// Обробка таймера — обертання фігур
void timer(int value) {
    Node* current = head;
    while (current != nullptr) {
        current->data.angle += rotationSpeed;
        if (current->data.angle >= 360.0f) current->data.angle -= 360.0f;
        current = current->next;
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// Додавання фігури в кінець списку
void addShape(float x, float y) {
    Node* newNode = new Node;
    newNode->data.x = x;
    newNode->data.y = y;
    newNode->data.angle = 0.0f;
    newNode->data.r = static_cast<float>(rand() % 100) / 100.0f;
    newNode->data.g = static_cast<float>(rand() % 100) / 100.0f;
    newNode->data.b = static_cast<float>(rand() % 100) / 100.0f;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }
}

// Видалення останньої фігури
void removeShape() {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr)
        current = current->next;

    delete current->next;
    current->next = nullptr;
}

// Клавіатура
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': addShape(0.0f, 0.0f); break;
        case 'd': removeShape(); break;
        case 27: exit(0); break;
    }
}

// Ініціалізація
void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2, 2, -2, 2);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("ЛР: 2D графіка з обертанням (власний список)");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
}

// Замість std::vector<Shape> використано однозв'язний список, який реалізується через Node* head. 
// Додано функції для: додавання елемента в кінець списку (addShape) видалення останнього елемента (removeShape)
// Замість циклу for (auto& shape : shapes) використано while (current != nullptr).
