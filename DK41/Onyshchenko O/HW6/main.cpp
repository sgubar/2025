#ifdef WIN64
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <math.h>
#include <stdio.h>

// Функція для малювання сцени
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Чорний фон для зручності
    //glClearColor(1.0f, 0.65f, 0.0f, 1.0f); // Помаранчевий фон для завдання
    glClear(GL_COLOR_BUFFER_BIT); // Очищення буферу кольору

    // Малювання графіка функції
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f); // Зелений колір графіка
        for (float t = 0.01f; t <= M_PI; t += 0.01f) {
            float x = sin(3 * t) * cos(t);
            float y = sin(3 * t) * sin(t);
            glVertex2f(x, y);
        }
    glEnd();

    // Малювання координатних осей
    glColor3f(0.0f, 0.0f, 1.0f); // Синій колір осей
    glBegin(GL_LINES);
        // Вісь X
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        // Вісь Y
        glVertex2f(0.0f, -1.0f);
        glVertex2f(0.0f, 1.0f);
    glEnd();

    // Додавання поділок на координатних осях
    for (float i = -1.0f; i <= 1.0f; i += 0.2f) {
        glBegin(GL_LINES);
            glVertex2f(i, -0.02f);
            glVertex2f(i, 0.02f);
            glVertex2f(-0.02f, i);
            glVertex2f(0.02f, i);
        glEnd();
    }

    glFlush(); // Виконати малювання
}

int main(int argc, char* argv[])
{
    printf("Створення графіку...\n");
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitWindowSize(800, 600); // Ширина та висота вікна
    glutInitWindowPosition(0, 0); // Положення вікна
    glutCreateWindow("HW6_Var9"); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація функції зворотного виклику для малювання вікна
    glutMainLoop(); // Вхід у цикл обробки подій GLUT
    return 0;
}
