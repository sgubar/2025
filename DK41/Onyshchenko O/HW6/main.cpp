#ifdef WIN64
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <math.h>
#include <stdio.h>

// ������� ��� ��������� �����
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ������ ��� ��� ��������
    //glClearColor(1.0f, 0.65f, 0.0f, 1.0f); // ������������ ��� ��� ��������
    glClear(GL_COLOR_BUFFER_BIT); // �������� ������ �������

    // ��������� ������� �������
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f); // ������� ���� �������
        for (float t = 0.01f; t <= M_PI; t += 0.01f) {
            float x = sin(3 * t) * cos(t);
            float y = sin(3 * t) * sin(t);
            glVertex2f(x, y);
        }
    glEnd();

    // ��������� ������������ ����
    glColor3f(0.0f, 0.0f, 1.0f); // ���� ���� ����
    glBegin(GL_LINES);
        // ³�� X
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        // ³�� Y
        glVertex2f(0.0f, -1.0f);
        glVertex2f(0.0f, 1.0f);
    glEnd();

    // ��������� ������ �� ������������ ����
    for (float i = -1.0f; i <= 1.0f; i += 0.2f) {
        glBegin(GL_LINES);
            glVertex2f(i, -0.02f);
            glVertex2f(i, 0.02f);
            glVertex2f(-0.02f, i);
            glVertex2f(0.02f, i);
        glEnd();
    }

    glFlush(); // �������� ���������
}

int main(int argc, char* argv[])
{
    printf("��������� �������...\n");
    glutInit(&argc, argv); // ����������� GLUT
    glutInitWindowSize(800, 600); // ������ �� ������ ����
    glutInitWindowPosition(0, 0); // ��������� ����
    glutCreateWindow("HW6_Var9"); // ��������� ���� �� ������� ��'��
    glutDisplayFunc(display); // ��������� ������� ���������� ������� ��� ��������� ����
    glutMainLoop(); // ���� � ���� ������� ���� GLUT
    return 0;
}
