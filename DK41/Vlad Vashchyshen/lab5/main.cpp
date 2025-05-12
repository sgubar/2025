#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>

// Глобальні змінні
char title[] = "Призма з трикутною основою";
float angleY = 0.0f;

// Ініціалізація OpenGL
void initGL()
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// Функція малювання призми
void drawPrism()
{
    float radius = 1.0f;
    float height = 2.0f;
    const int sides = 3;
    float angleStep = 2.0f * M_PI / sides;

    // Нижня основа (y = 0)
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // червона
    for (int i = 0; i < sides; i++) {
        glVertex3f(0, 0, 0);
        glVertex3f(radius * cos(i * angleStep), 0, radius * sin(i * angleStep));
        glVertex3f(radius * cos((i + 1) * angleStep), 0, radius * sin((i + 1) * angleStep));
    }
    glEnd();

    // верхня основа (y = height)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); // зелена
    for (int i = 0; i < sides; i++) {
        glVertex3f(0, height, 0);
        glVertex3f(radius * cos((i + 1) * angleStep), height, radius * sin((i + 1) * angleStep));
        glVertex3f(radius * cos(i * angleStep), height, radius * sin(i * angleStep));
    }
    glEnd();

    // Бокові грані
    glBegin(GL_QUADS);
    for (int i = 0; i < sides; i++) {
        float r = (i % 3 == 0);
        float g = (i % 3 == 1);
        float b = (i % 3 == 2);
        glColor3f(r, g, b); // різні кольори

        float x0 = radius * cos(i * angleStep);
        float z0 = radius * sin(i * angleStep);
        float x1 = radius * cos((i + 1) * angleStep);
        float z1 = radius * sin((i + 1) * angleStep);

        glVertex3f(x0, 0, z0);
        glVertex3f(x0, height, z0);
        glVertex3f(x1, height, z1);
        glVertex3f(x1, 0, z1);
    }
    glEnd();
}

// Малювання сцени
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.f, -1.f, -6.f);
    glRotatef(angleY, 0, 1, 0); // Обертання по Oy
    drawPrism();

    glutSwapBuffers();
}

// Масштабування вікна
void reshape(int width, int height)
{
    if (height == 0) height = 1;
    float aspect = (float)width / height;
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

// Анімація (таймер)
void Timer(int value)
{
    angleY += 1.0f;
    if (angleY > 360) angleY -= 360;
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

// Вихід по Esc
void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) exit(0);
}

// ну і Головна функція
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, Timer, 0);
    initGL();
    glutMainLoop();
    return 0;
}
//фух воно працює
