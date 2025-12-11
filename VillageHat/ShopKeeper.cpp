/**
 * ShopKeeper.cpp
 *
 * Implementation of the shopkeeper character.
 * Similar to Person but static and positioned at the shop counter.
 *
 * Author: VillageHat3D Project
 */

#include <GL/glut.h>
#include <GL/glu.h>
#include "ShopKeeper.h"
#include "Common.h"

/**
 * Constructor
 */
ShopKeeper::ShopKeeper(float posX, float posZ)
    : x(posX), z(posZ) {
}

/**
 * Draw the shopkeeper
 */
void ShopKeeper::draw() const {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f); // Face toward market

    // ========== HEAD ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    drawSphere(0.2f);
    glPopMatrix();

    // ========== BODY ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glColor3f(0.8f, 0.6f, 0.4f); // Tan/beige shirt
    drawBox(0.35f, 0.45f, 0.25f);
    glPopMatrix();

    // ========== ARMS ==========
    // Left arm (raised, as if gesturing)
    glPushMatrix();
    glTranslatef(-0.25f, 1.2f, 0.0f);
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    drawBox(0.1f, 0.35f, 0.1f);
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
    glColor3f(0.2f, 0.2f, 0.3f); // Dark pants
    drawBox(0.12f, 0.5f, 0.12f);
    glPopMatrix();

    // Right leg
    glPushMatrix();
    glTranslatef(0.1f, 0.3f, 0.0f);
    glColor3f(0.2f, 0.2f, 0.3f); // Dark pants
    drawBox(0.12f, 0.5f, 0.12f);
    glPopMatrix();

    // ========== APRON ==========
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, 0.15f);
    glColor3f(0.9f, 0.9f, 0.9f); // White apron
    drawBox(0.4f, 0.6f, 0.1f);
    glPopMatrix();

    // ========== HAT ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.7f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f); // Black hat
    drawCylinder(0.25f, 0.2f);
    glPopMatrix();

    glPopMatrix();
}

