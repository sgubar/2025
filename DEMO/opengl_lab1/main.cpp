#include <windows.h>
#include <GL/glut.h> //
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"

// Назва та розміри вікна
char title[] = "Rotating Graph";
int curr_width = 600, curr_height = 600;

int t = 1000 / 24; // Період обертання фігури навколо початку координат (в даному прикладі робимо 1 оберт за 24 кадри/с)
float theta_spd = 360.0f / t; // Кут оберту між кадрами
float theta = 0.0f; // Кут оберту як глобальна змінна
FigureList_s* figlist; // Наш список фігур

// В цьому прикладі викликатимемо display() лише один раз на почаку роботи програми
// для малювання фігур на початкових позиціях
void display()
{
    // Малювання фігур по одній
    drawFigList(figlist);

    // Запит на малювання сцени
    glFlush();
}

// Ця функція викликається через t мс після увімкнення таймеру і перемальовує фігури
void timer_dis(int v)
{
    // Очищуємо буфер щоб зображення не накладалися
    glClear(GL_COLOR_BUFFER_BIT);

    // В нашому прикладі виконується обертання сцени,
    // параметри обертання буде покладено в стек перетворень
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    // Малювання фігур по одній
    drawFigList(figlist);

    // Запит на малювання сцени
    glFlush();

    // Повернення до початкових налаштувань виду сцени
    glPopMatrix();

    // Перезапуск таймера
    glutTimerFunc(t, timer_dis, 0);

    // Оновлення кута оберту
    theta += theta_spd;
    if (theta >= (360)){
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[3];
    Point* points2[3];
    Point* points3[3];
    Point* points4[3];
    Figure_s *figure1, *figure2, *figure3, *figure4;

    // Створимо список фігур
    figlist = createFigList();

    // Створимо фігури і додамо їх до списку
    points1[0] = createPoint(0, 50);
    points1[1] = createPoint(0, 0);
    points1[2] = createPoint(30, 0);
    figure1 = createFigure(points1, createColor(1.0, 0.0, 0.0));

    addFigToFigList(figlist, figure1);

    points2[0] = createPoint(-60, 0);
    points2[1] = createPoint(-30, 0);
    points2[2] = createPoint(-40, -60);
    figure2 = createFigure(points2, createColor(1.0, 1.0, 0.0));

    addFigToFigList(figlist, figure2);

    points3[0] = createPoint(-30, -10);
    points3[1] = createPoint(60, -20);
    points3[2] = createPoint(40, -60);
    figure3 = createFigure(points3, createColor(0.5, 0.5, 0.5));

    addFigToFigList(figlist, figure3);

    // Замінимо 2 фігуру в списку на іншу
    removeFigFromFigListAtIndex(figlist, 1);

    points4[0] = createPoint(-70, 10);
    points4[1] = createPoint(-40, 20);
    points4[2] = createPoint(-60, -70);
    figure4 = createFigure(points4, createColor(0.0, 0.0, 1.0));

    insertFigToFigListAtIndex(figlist, 1, figure4);

    // Ініціалізуємо середовище OpenGL
    glutInit(&argc, argv);
    // Створюємо вікно
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // Реєструємо display як функцію малювання (в нашому прикладі початкового)
    glutDisplayFunc(display);
    // Одразу запускаємо таймер для того, щоб фігури обертались одразу після запуску
    glutTimerFunc(0, timer_dis, 0);
    // Запускаємо головний цикл OpenGL
    glutMainLoop();

    return 0;
}
