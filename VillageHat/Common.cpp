#include <GL/freeglut.h>
#include "Common.h"
#include <cmath>

void drawBox(float sx, float sy, float sz) {
    glPushMatrix();
      glScalef(sx, sy, sz);
      glutSolidCube(1.0);
    glPopMatrix();
}

void drawCylinder(float r, float h) {
#if defined(GLUT_API_VERSION) || defined(FREEGLUT)
    glutSolidCylinder(r, h, 20, 4);
#else
    GLUquadric* q = gluNewQuadric();
    gluCylinder(q, r, r, h, 20, 4);
    gluDeleteQuadric(q);
#endif
}

void drawSphere(float r) {
    glutSolidSphere(r, 20, 20);
}
