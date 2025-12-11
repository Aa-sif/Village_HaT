/**
 * Woman.cpp
 *
 * Implementation of female villager character.
 * Features a longer skirt and a basket on the head.
 *
 * Author: VillageHat3D Project
 */

#include <GL/glut.h>
#include <GL/glu.h>
#include "Woman.h"
#include "Common.h"

/**
 * Constructor
 */
Woman::Woman(float posX, float posZ)
    : x(posX), z(posZ) {
}

/**
 * Draw the woman character
 */
void Woman::draw() const {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);

    // ========== HEAD ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    drawSphere(0.2f);
    glPopMatrix();

    // ========== BODY ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glColor3f(0.8f, 0.3f, 0.5f); // Pink/red blouse
    drawBox(0.3f, 0.35f, 0.2f);
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

    // ========== SKIRT (longer than pants) ==========
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
    glColor3f(0.4f, 0.2f, 0.6f); // Purple skirt
    drawBox(0.35f, 0.6f, 0.3f);
    glPopMatrix();

    // ========== LEGS (shorter, under skirt) ==========
    // Left leg
    glPushMatrix();
    glTranslatef(-0.1f, 0.2f, 0.0f);
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    drawBox(0.1f, 0.3f, 0.1f);
    glPopMatrix();

    // Right leg
    glPushMatrix();
    glTranslatef(0.1f, 0.2f, 0.0f);
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    drawBox(0.1f, 0.3f, 0.1f);
    glPopMatrix();

    // ========== BASKET ON HEAD ==========
    glPushMatrix();
    glTranslatef(0.0f, 1.75f, 0.0f);
    glColor3f(0.5f, 0.4f, 0.3f); // Brown basket
    drawBox(0.3f, 0.15f, 0.3f);
    // Basket rim
    glTranslatef(0.0f, 0.1f, 0.0f);
    glColor3f(0.6f, 0.5f, 0.4f); // Lighter brown rim
    drawBox(0.32f, 0.05f, 0.32f);
    glPopMatrix();

    glPopMatrix();
}

