#include <GL/glut.h>
#include "pentagon.h"

void Square::draw() const {
    float halfSize = size / 2.0f;
    glBegin(GL_POLYGON);
    glVertex2f(x - halfSize, y - halfSize);
    glVertex2f(x + halfSize, y - halfSize);
    glVertex2f(x + halfSize, y + halfSize);
    glVertex2f(x - halfSize, y + halfSize);
    glEnd();
}
