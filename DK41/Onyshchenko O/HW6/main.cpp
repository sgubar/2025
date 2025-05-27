#ifdef WIN64
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <math.h>
#include <stdio.h>

// Ôóíêö³ÿ äëÿ ìàëþâàííÿ ñöåíè
void display()
{
    glClearColor(1.0f, 0.65f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT); // Î÷èùåííÿ áóôåðó êîëüîðó

    // Ìàëþâàííÿ ãðàô³êà ôóíêö³¿
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f); // Çåëåíèé êîë³ð ãðàô³êà
        for (float t = 0.01f; t <= M_PI; t += 0.01f) {
            float x = sin(3 * t) * cos(t);
            float y = sin(3 * t) * sin(t);
            glVertex2f(x, y);
        }
    glEnd();

    // Ìàëþâàííÿ êîîðäèíàòíèõ îñåé
    glColor3f(0.0f, 0.0f, 1.0f); // Ñèí³é êîë³ð îñåé
    glBegin(GL_LINES);
        // Â³ñü X
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        // Â³ñü Y
        glVertex2f(0.0f, -1.0f);
        glVertex2f(0.0f, 1.0f);
    glEnd();

    // Äîäàâàííÿ ïîä³ëîê íà êîîðäèíàòíèõ îñÿõ
    for (float i = -1.0f; i <= 1.0f; i += 0.2f) {
        glBegin(GL_LINES);
            glVertex2f(i, -0.02f);
            glVertex2f(i, 0.02f);
            glVertex2f(-0.02f, i);
            glVertex2f(0.02f, i);
        glEnd();
    }

    glFlush(); // Âèêîíàòè ìàëþâàííÿ
}

int main(int argc, char* argv[])
{
    printf("Creating...\n");
    glutInit(&argc, argv); // ²í³ö³àë³çàö³ÿ GLUT
    glutInitWindowSize(800, 600); // Øèðèíà òà âèñîòà â³êíà
    glutInitWindowPosition(0, 0); // Ïîëîæåííÿ â³êíà
    glutCreateWindow("HW6_Var9"); // Ñòâîðåííÿ â³êíà ³ç çàäàíèì ³ì'ÿì
    glutDisplayFunc(display); // Ðåºñòðàö³ÿ ôóíêö³¿ çâîðîòíîãî âèêëèêó äëÿ ìàëþâàííÿ â³êíà
    glutMainLoop(); // Âõ³ä ó öèêë îáðîáêè ïîä³é GLUT
    return 0;
}
