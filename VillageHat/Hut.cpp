/**
 * Hut.cpp
 *
 * Implementation of simple hut building with triangular roof.
 *
 * Author: VillageHat3D Project
 */

#include <GL/glut.h>
#include <GL/glu.h>
#include "Hut.h"
#include "Common.h"

/**
 * Constructor
 */
Hut::Hut(float posX, float posZ)
    : x(posX), z(posZ) {
}

/**
 * Draw the hut
 */
void Hut::draw() const {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);

    // ========== HUT BODY ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glColor3f(0.6f, 0.5f, 0.4f); // Brownish walls
    drawBox(2.0f, 2.0f, 2.0f);
    glPopMatrix();

    // ========== TRIANGULAR ROOF ==========
    glDisable(GL_LIGHTING);
    glColor3f(0.5f, 0.3f, 0.2f); // Dark brown roof
    glBegin(GL_TRIANGLES);
    // Front triangle
    glVertex3f(0.0f, 3.0f, -1.0f);
    glVertex3f(-1.2f, 2.0f, -1.0f);
    glVertex3f(1.2f, 2.0f, -1.0f);
    // Back triangle
    glVertex3f(0.0f, 3.0f, 1.0f);
    glVertex3f(1.2f, 2.0f, 1.0f);
    glVertex3f(-1.2f, 2.0f, 1.0f);
    glEnd();

    // Roof sides
    glBegin(GL_QUADS);
    // Left side
    glVertex3f(-1.2f, 2.0f, -1.0f);
    glVertex3f(0.0f, 3.0f, -1.0f);
    glVertex3f(0.0f, 3.0f, 1.0f);
    glVertex3f(-1.2f, 2.0f, 1.0f);
    // Right side
    glVertex3f(1.2f, 2.0f, -1.0f);
    glVertex3f(1.2f, 2.0f, 1.0f);
    glVertex3f(0.0f, 3.0f, 1.0f);
    glVertex3f(0.0f, 3.0f, -1.0f);
    glEnd();
    glEnable(GL_LIGHTING);

    // ========== DOOR ==========
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 1.01f);
    glColor3f(0.3f, 0.2f, 0.1f); // Dark brown door
    drawBox(0.6f, 1.2f, 0.05f);
    glPopMatrix();

    // ========== SMALL WINDOW ==========
    glPushMatrix();
    glTranslatef(0.7f, 1.5f, 1.01f);
    glColor3f(0.4f, 0.6f, 0.8f); // Blue window
    drawBox(0.4f, 0.4f, 0.05f);
    glPopMatrix();

    glPopMatrix();
}

