/**
 * Environment.cpp
 *
 * Implementation of background scene rendering.
 * Draws sky, hills, ground, fields, path, and trees.
 *
 * Author: VillageHat3D Project
 */

#include <GL/glut.h>
#include <GL/glu.h>
#include "Environment.h"
#include "Common.h"

/**
 * Draw the complete background scene
 */
void Environment::drawBackground() {
    // Disable lighting for flat background elements
    glDisable(GL_LIGHTING);

    // ========== SKY ==========
    glPushMatrix();
    glColor3f(0.5f, 0.7f, 1.0f); // Light blue sky
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 50.0f, -100.0f);
    glVertex3f(100.0f, 50.0f, -100.0f);
    glVertex3f(100.0f, 50.0f, 100.0f);
    glVertex3f(-100.0f, 50.0f, 100.0f);
    glEnd();
    glPopMatrix();

    // ========== DISTANT HILLS ==========
    glPushMatrix();
    glColor3f(0.3f, 0.5f, 0.2f); // Dark green hills
    glBegin(GL_TRIANGLES);
    // Left hill
    glVertex3f(-80.0f, 0.0f, -80.0f);
    glVertex3f(-60.0f, 15.0f, -70.0f);
    glVertex3f(-40.0f, 0.0f, -80.0f);
    // Right hill
    glVertex3f(40.0f, 0.0f, -80.0f);
    glVertex3f(60.0f, 18.0f, -70.0f);
    glVertex3f(80.0f, 0.0f, -80.0f);
    // Center hill
    glVertex3f(-20.0f, 0.0f, -85.0f);
    glVertex3f(0.0f, 20.0f, -75.0f);
    glVertex3f(20.0f, 0.0f, -85.0f);
    glEnd();
    glPopMatrix();

    // ========== FAR TREE BELT ==========
    glPushMatrix();
    glColor3f(0.2f, 0.4f, 0.1f); // Dark green trees
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -90.0f);
    glVertex3f(100.0f, 0.0f, -90.0f);
    glVertex3f(100.0f, 25.0f, -90.0f);
    glVertex3f(-100.0f, 25.0f, -90.0f);
    glEnd();
    glPopMatrix();

    // ========== MAIN GROUND PLANE ==========
    glPushMatrix();
    glColor3f(0.4f, 0.6f, 0.3f); // Green grass
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(100.0f, 0.0f, -100.0f);
    glVertex3f(100.0f, 0.0f, 100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glEnd();
    glPopMatrix();

    // ========== LEFT CROP FIELD ==========
    glPushMatrix();
    glColor3f(0.5f, 0.7f, 0.2f); // Yellow-green crops
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.01f, -50.0f);
    glVertex3f(-30.0f, 0.01f, -50.0f);
    glVertex3f(-30.0f, 0.01f, 50.0f);
    glVertex3f(-100.0f, 0.01f, 50.0f);
    glEnd();
    glPopMatrix();

    // ========== RIGHT CROP FIELD ==========
    glPushMatrix();
    glColor3f(0.5f, 0.7f, 0.2f); // Yellow-green crops
    glBegin(GL_QUADS);
    glVertex3f(30.0f, 0.01f, -50.0f);
    glVertex3f(100.0f, 0.01f, -50.0f);
    glVertex3f(100.0f, 0.01f, 50.0f);
    glVertex3f(30.0f, 0.01f, 50.0f);
    glEnd();
    glPopMatrix();

    // ========== CURVED SAND PATH ==========
    // Path runs from front (z=-50) to back (z=50), curving slightly
    glPushMatrix();
    glColor3f(0.9f, 0.8f, 0.6f); // Sand/tan color
    // Front segment (wider)
    glBegin(GL_QUADS);
    glVertex3f(-8.0f, 0.02f, -50.0f);
    glVertex3f(8.0f, 0.02f, -50.0f);
    glVertex3f(6.0f, 0.02f, -20.0f);
    glVertex3f(-6.0f, 0.02f, -20.0f);
    glEnd();
    // Middle segment (curved)
    glBegin(GL_QUADS);
    glVertex3f(-6.0f, 0.02f, -20.0f);
    glVertex3f(6.0f, 0.02f, -20.0f);
    glVertex3f(4.0f, 0.02f, 10.0f);
    glVertex3f(-4.0f, 0.02f, 10.0f);
    glEnd();
    // Back segment (narrower, curves toward shop)
    glBegin(GL_QUADS);
    glVertex3f(-4.0f, 0.02f, 10.0f);
    glVertex3f(4.0f, 0.02f, 10.0f);
    glVertex3f(8.0f, 0.02f, 50.0f);
    glVertex3f(-2.0f, 0.02f, 50.0f);
    glEnd();
    glPopMatrix();

    // ========== NEAR TREES ==========
    // Re-enable lighting for 3D trees
    glEnable(GL_LIGHTING);
    glColor3f(0.2f, 0.5f, 0.1f); // Tree green

    // Tree 1 (left side)
    glPushMatrix();
    glTranslatef(-25.0f, 0.0f, -10.0f);
    // Trunk
    glColor3f(0.4f, 0.2f, 0.1f); // Brown trunk
    drawCylinder(0.5f, 3.0f);
    // Leaves
    glTranslatef(0.0f, 3.5f, 0.0f);
    glColor3f(0.2f, 0.5f, 0.1f); // Green leaves
    drawSphere(2.5f);
    glPopMatrix();

    // Tree 2 (right side)
    glPushMatrix();
    glTranslatef(25.0f, 0.0f, -10.0f);
    // Trunk
    glColor3f(0.4f, 0.2f, 0.1f); // Brown trunk
    drawCylinder(0.5f, 3.0f);
    // Leaves
    glTranslatef(0.0f, 3.5f, 0.0f);
    glColor3f(0.2f, 0.5f, 0.1f); // Green leaves
    drawSphere(2.5f);
    glPopMatrix();

    // Tree 3 (behind market area)
    glPushMatrix();
    glTranslatef(-15.0f, 0.0f, 30.0f);
    // Trunk
    glColor3f(0.4f, 0.2f, 0.1f); // Brown trunk
    drawCylinder(0.5f, 3.0f);
    // Leaves
    glTranslatef(0.0f, 3.5f, 0.0f);
    glColor3f(0.2f, 0.5f, 0.1f); // Green leaves
    drawSphere(2.5f);
    glPopMatrix();

    // Tree 4 (behind market area, right)
    glPushMatrix();
    glTranslatef(15.0f, 0.0f, 30.0f);
    // Trunk
    glColor3f(0.4f, 0.2f, 0.1f); // Brown trunk
    drawCylinder(0.5f, 3.0f);
    // Leaves
    glTranslatef(0.0f, 3.5f, 0.0f);
    glColor3f(0.2f, 0.5f, 0.1f); // Green leaves
    drawSphere(2.5f);
    glPopMatrix();

    // Re-enable lighting for rest of scene
    glEnable(GL_LIGHTING);
}

