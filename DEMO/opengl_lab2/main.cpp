#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//#include <stdlib.h>

// Глобальні змінні
char title[] = "Cube";
bool perspective = true;
bool moveScene = false;
int mouse_x,
mouse_y;
float a_x = 0, a_y = 0;
float zoom_param = -7.0;
float zoom_delta = 0.1;


// Ініціалізація OpenGL
void initGL()
{
    glClearColor(0.f, 0.f, 0.f, 1.f); // Фон - чорний та прозорий
    glClearDepth(1.f); // Глибина фону - найбільш віддалена
    glEnable(GL_DEPTH_TEST); // Дозвіл тестування глибини
    glDepthFunc(GL_LEQUAL); // Тип функції тестування глибини
    glShadeModel(GL_SMOOTH); // Дозвіл гладкого зафарбовування
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Корекція перспективи
}


// Функція обробки запиту на перемалювання. Виконує малювання сцени.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | // Очищення буферу кольору
    GL_DEPTH_BUFFER_BIT); // та буферу глибини
    glMatrixMode(GL_MODELVIEW); // Вибір матриці модель-вигляд
    glLoadIdentity(); // Скидання параметрів матриці шляхом
    // завантаження одиничної матриці

    glTranslatef(0.f, 0.f, zoom_param); // Зміщення об'єкта у глибину екрану
    glRotatef(a_x, 1, 0, 0); // Обертання навколо осі x
    glRotatef(a_y, 0, 1, 0); // Обертання навколо осі y
    // Малювання об'єкта – куба з гранями різного кольору
    glBegin(GL_QUADS); // Куб складається з 6 квадратів (чотирикутників)

    // Верхня грань (y = 1.0f)
    glColor3f(0.0f, 1.0f, 0.0f); // Зелена
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);

    // Нижня грань (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f); // Помаранчева
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Передня грань (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f); // Червона
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);

    // Задня грань (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f); // Жовта
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);

    // Ліва грань (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f); // Синя
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Права грань (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f); // Пурпурова
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd(); // Завершення малювання кубу
    glutSwapBuffers(); // Обмін буферів кадру
    // (використовується подвійна буферизація)
}


// Функція обробки події, що виникає при масштабуванні вікна
void reshape(int width, int height)
{
    // Обчислення відношення сторін вікна нового розміру
    if (height == 0) // Перевірка для уникнення ділення на 0
    height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Встановлення розміру поля огляду відповідно до нових розмірів вікна
    glViewport(0, 0, width, height);

    // Встановлення параметрів проекційної матриці
    glMatrixMode(GL_PROJECTION); // Вибір матриці проекції
    glLoadIdentity(); // Скидання матриці

    // Використання перспективної проекції з
    // параметрами fovy = 45, aspect, zNear = 0.1 та zFar = 100
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


// Функція обробки події, що виникає при натисканні клавіш клавіатури
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27: // Esc
            exit(0);
            break;
    }
}


// Функція обробки події, що виникає при натисканні клавіш мишки
void mouseClick(int button, int state, int x, int y)
{
    if (GLUT_LEFT_BUTTON == button && state == GLUT_DOWN) {
        moveScene = true;
        mouse_x = x;
        mouse_y = y;
    }

    if (GLUT_LEFT_BUTTON == button && state == GLUT_UP) {
        moveScene = false;
    }
}


// Функція обробки події, що виникає при натисканні клавіш клавіатури
void specKeyHandler(int sk, int x, int y)
{
    // Якщо натискаємо стрілку вгору - наближуємось до фігури, якщо вниз - віддаляємось від неї
    if (sk == GLUT_KEY_UP) {
        zoom_param += zoom_delta;
    }
    else if (sk == GLUT_KEY_DOWN) {
        zoom_param -= zoom_delta;
    }
}


// Функція обробки події, що виникає при виникнення руху мишки
void mouseMove(int x, int y)
{
    int dx = mouse_x - x,
    dy = mouse_y - y;
    a_x -= 0.250f * dy;
    a_y -= 0.250f * dx;
    mouse_x = x;
    mouse_y = y;
}


// Функція обробки події, що виникає при спрацюванні таймеру
void Timer(int value)
{
    glutPostRedisplay(); // Генерування запиту на перемалювання
    // сцени викликає функцію display()

    glutTimerFunc(30, Timer, 0); // Новий запуск таймера на 30 мс
}


// Головна функція: програма GLUT виконується як консольний додаток
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Ввімкнення подвійної буферизації
    glutInitWindowSize(640, 480); // Встановлення розміру вікна
    glutInitWindowPosition(50, 50); // Встановлення положення вікна
    glutCreateWindow(title); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація обробника запиту перемалювання
    glutReshapeFunc(reshape); // Реєстрація обробника запиту масштабування
    glutKeyboardFunc(keyboard); // Реєстрація обробника подій клавіатури
    glutMouseFunc(mouseClick); // Реєстрація обробника натискання клавіш миші
    glutMotionFunc(mouseMove); // Реєстрація обробника руху миші
    glutSpecialFunc(specKeyHandler); // Реєстрація обробника подій клавіатури (спеціальні клавіши)
    glutTimerFunc(0, Timer, 0); // Запуск та реєстрація обробки таймера
    initGL(); // Ініціалізація OpenGL
    glutMainLoop(); // Вхід у головний нескінченний цикл обробки
    // подій
return 0;
}
