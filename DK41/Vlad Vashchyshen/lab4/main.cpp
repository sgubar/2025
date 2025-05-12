#include <GL/glut.h>
#include <vector>
#include <cmath>

// Структура фігури
struct Shape {
    float x, y;      // координати (зміщення від центру)
    float angle;     // кут обертання
    float r, g, b;   // колір
};

// Список фігур
std::vector<Shape> shapes;
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

    for (const auto& shape : shapes) {
        glPushMatrix();
        glTranslatef(shape.x, shape.y, 0.0f);
        glRotatef(shape.angle, 0.0f, 0.0f, 1.0f);
        glColor3f(shape.r, shape.g, shape.b);
        drawTriangle();
        glPopMatrix();
    }

    glutSwapBuffers();
}

// Обробка таймера — обертання фігур
void timer(int value) {
    for (auto& shape : shapes) {
        shape.angle += rotationSpeed;
        if (shape.angle >= 360.0f) shape.angle -= 360.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// Додавання нової фігури
void addShape(float x, float y) {
    Shape s;
    s.x = x;
    s.y = y;
    s.angle = 0.0f;
    s.r = static_cast<float>(rand() % 100) / 100.0f;
    s.g = static_cast<float>(rand() % 100) / 100.0f;
    s.b = static_cast<float>(rand() % 100) / 100.0f;
    shapes.push_back(s);
}

// Видалення останньої фігури
void removeShape() {
    if (!shapes.empty())
        shapes.pop_back();
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
    gluOrtho2D(-2, 2, -2, 2); // 2D ортографічна проекція
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("ЛР: 2D графіка з обертанням");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
}
