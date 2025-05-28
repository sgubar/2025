#include <GL/glut.h>

float rotation_angle = 0.0f;

// Вершини паралелепіпеда (основа на (0,0,0))
GLfloat vertices[][3] = {
    {-1.0f, -1.0f, 0.0f},  // 0 - низ
    {1.0f, -1.0f, 0.0f},   // 1
    {1.0f, 1.0f, 0.0f},    // 2
    {-1.0f, 1.0f, 0.0f},   // 3
    {-1.0f, -1.0f, 2.0f},  // 4 - верх
    {1.0f, -1.0f, 2.0f},   // 5
    {1.0f, 1.0f, 2.0f},    // 6
    {-1.0f, 1.0f, 2.0f}    // 7
};

// Індекси граней (по 4 вершини)
int faces[][4] = {
    {0, 1, 2, 3},  // основа
    {4, 5, 6, 7},  // верх
    {0, 1, 5, 4},  // бічні грані
    {1, 2, 6, 5},
    {2, 3, 7, 6},
    {3, 0, 4, 7}
};

// Кольори граней (RGB)
GLfloat colors[][3] = {
    {1.0f, 0.0f, 0.0f},  // червоний
    {0.0f, 1.0f, 0.0f},  // зелений
    {0.0f, 0.0f, 1.0f},  // синій
    {1.0f, 1.0f, 0.0f},  // жовтий
    {1.0f, 0.0f, 1.0f},  // пурпурний
    {0.0f, 1.0f, 1.0f}   // бірюзовий
};

void drawParallelepiped() {
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++) {
        glColor3fv(colors[i]);
        for (int j = 0; j < 4; j++) {
            glVertex3fv(vertices[faces[i][j]]);
        }
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Камера - відсунемо назад по осі Z
    glTranslatef(0.0f, 0.0f, -10.0f);

    // Обертання навколо осі Z (Oz)
    glRotatef(rotation_angle, 0.0f, 0.0f, 1.0f);

    drawParallelepiped();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float aspect = (float)w / (float)h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Перспективна проекція
    gluPerspective(45.0, aspect, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        rotation_angle += 5.0f;
        if (rotation_angle > 360) rotation_angle -= 360;
    }
    if (key == GLUT_KEY_DOWN) {
        rotation_angle -= 5.0f;
        if (rotation_angle < 0) rotation_angle += 360;
    }
    glutPostRedisplay();  // Перемалювати сцену
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Паралелепіпед з обертанням");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);  // Обробка клавіш ↑ та ↓

    glutMainLoop();
    return 0;
}
