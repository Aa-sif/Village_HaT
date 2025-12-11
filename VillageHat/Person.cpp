/**
 * Person.cpp
 *
 * Implementation of animated walking person character.
 * Uses simple primitives to create a low-poly human figure.
 *
 * Author: VillageHat3D Project
 */

#include <GL/glut.h>
#include <GL/glu.h>
#include "Person.h"
#include "Common.h"

/**
 * Constructor - initialize person at starting position
 */
Person::Person(float startX, float startZ, float walkSpeed)
    : x(startX), z(startZ), speed(walkSpeed), direction(1.0f) {
    // Set movement boundaries along the path
    minX = -30.0f;
    maxX = 30.0f;
}

/**
 * Update person position (called each frame)
 */
void Person::update() {
    // Move along X axis (path direction)
    x += speed * direction;

    // Reverse direction at boundaries
    if (x >= maxX) {
        direction = -1.0f;
        x = maxX;
    } else if (x <= minX) {
        direction = 1.0f;
        x = minX;
    }
}

/**
 * Draw the person at current position
 */
void Person::draw() const {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);

    // Rotate to face walking direction
    if (direction > 0) {
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    }

    // ========== HEAD ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    drawSphere(0.2f);
    glPopMatrix();

    // ========== BODY ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glColor3f(0.2f, 0.4f, 0.8f); // Blue shirt
    drawBox(0.3f, 0.4f, 0.2f);
    glPopMatrix();

    // ========== ARMS ==========
    // Left arm
    glPushMatrix();
    glTranslatef(-0.25f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    drawBox(0.1f, 0.3f, 0.1f);
    glPopMatrix();

    // Right arm
    glPushMatrix();
    glTranslatef(0.25f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    drawBox(0.1f, 0.3f, 0.1f);
    glPopMatrix();

    // ========== LEGS ==========
    // Left leg
    glPushMatrix();
    glTranslatef(-0.1f, 0.3f, 0.0f);
    glColor3f(0.3f, 0.2f, 0.1f); // Brown pants
    drawBox(0.12f, 0.5f, 0.12f);
    glPopMatrix();

    // Right leg
    glPushMatrix();
    glTranslatef(0.1f, 0.3f, 0.0f);
    glColor3f(0.3f, 0.2f, 0.1f); // Brown pants
    drawBox(0.12f, 0.5f, 0.12f);
    glPopMatrix();

    // ========== HAT/CAP ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.7f, 0.0f);
    glColor3f(0.8f, 0.2f, 0.2f); // Red hat
    drawCylinder(0.22f, 0.15f);
    glPopMatrix();

    glPopMatrix();
}

