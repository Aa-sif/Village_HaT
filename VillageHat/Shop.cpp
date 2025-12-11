/**
 * Shop.cpp
 *
 * Implementation of the main shop building.
 * Includes body, roof, counter, pillars, and decorative elements.
 *
 * Coordinate mapping:
 * - Path runs from z=-50 (front) to z=50 (back)
 * - Shop is positioned at back-right area (x=15, z=40)
 * - Front counter faces toward negative Z (market entrance)
 *
 * Author: VillageHat3D Project
 */

#include <GL/glut.h>
#include <GL/glu.h>
#include "Shop.h"
#include "Common.h"

/**
 * Constructor
 */
Shop::Shop(float posX, float posZ, float width, float depth)
    : x(posX), z(posZ), w(width), d(depth) {
}

/**
 * Draw the shop building
 */
void Shop::draw() const {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);

    // ========== MAIN BODY ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glColor3f(0.7f, 0.6f, 0.5f); // Beige walls
    drawBox(w, 3.0f, d);
    glPopMatrix();

    // ========== TIN ROOF ==========
    glPushMatrix();
    glTranslatef(0.0f, 3.5f, 0.0f);
    glColor3f(0.4f, 0.4f, 0.4f); // Gray metal roof
    drawBox(w * 1.1f, 0.3f, d * 1.1f);
    glPopMatrix();

    // ========== FRONT COUNTER ==========
    glPushMatrix();
    glTranslatef(0.0f, 0.8f, -d * 0.4f);
    glColor3f(0.5f, 0.3f, 0.2f); // Brown wood counter
    drawBox(w * 0.8f, 0.6f, 0.3f);
    glPopMatrix();

    // ========== PILLARS (supporting roof) ==========
    glColor3f(0.4f, 0.3f, 0.2f); // Dark brown pillars
    // Front-left pillar
    glPushMatrix();
    glTranslatef(-w * 0.4f, 1.5f, -d * 0.4f);
    drawCylinder(0.2f, 2.5f);
    glPopMatrix();

    // Front-right pillar
    glPushMatrix();
    glTranslatef(w * 0.4f, 1.5f, -d * 0.4f);
    drawCylinder(0.2f, 2.5f);
    glPopMatrix();

    // Back-left pillar
    glPushMatrix();
    glTranslatef(-w * 0.4f, 1.5f, d * 0.4f);
    drawCylinder(0.2f, 2.5f);
    glPopMatrix();

    // Back-right pillar
    glPushMatrix();
    glTranslatef(w * 0.4f, 1.5f, d * 0.4f);
    drawCylinder(0.2f, 2.5f);
    glPopMatrix();

    // ========== HANGING ITEMS (decorative lines) ==========
    glDisable(GL_LIGHTING);
    glColor3f(0.6f, 0.4f, 0.2f); // Brown strings
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    // String 1
    glVertex3f(-w * 0.3f, 2.5f, -d * 0.4f);
    glVertex3f(-w * 0.3f, 1.8f, -d * 0.4f);
    // String 2
    glVertex3f(0.0f, 2.5f, -d * 0.4f);
    glVertex3f(0.0f, 1.8f, -d * 0.4f);
    // String 3
    glVertex3f(w * 0.3f, 2.5f, -d * 0.4f);
    glVertex3f(w * 0.3f, 1.8f, -d * 0.4f);
    glEnd();
    glEnable(GL_LIGHTING);

    // ========== DOOR (simple box) ==========
    glPushMatrix();
    glTranslatef(0.0f, 0.9f, d * 0.45f);
    glColor3f(0.3f, 0.2f, 0.1f); // Dark brown door
    drawBox(0.8f, 1.8f, 0.1f);
    glPopMatrix();

    // ========== WINDOWS (small boxes) ==========
    glColor3f(0.6f, 0.8f, 1.0f); // Light blue windows
    // Left window
    glPushMatrix();
    glTranslatef(-w * 0.3f, 2.0f, d * 0.45f);
    drawBox(0.6f, 0.6f, 0.05f);
    glPopMatrix();

    // Right window
    glPushMatrix();
    glTranslatef(w * 0.3f, 2.0f, d * 0.45f);
    drawBox(0.6f, 0.6f, 0.05f);
    glPopMatrix();

    glPopMatrix();
}

