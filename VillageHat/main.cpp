/**
 * main.cpp
 *
 * Main entry point for VillageHat3D application.
 * Sets up OpenGL window, camera, keyboard controls, and animation loop.
 *
 * Author: VillageHat3D Project
 */

#include <GL/glut.h>
#include <GL/glu.h>
#include <vector>
#include <cmath>
#include "Environment.h"
#include "Person.h"
#include "Shop.h"
#include "ShopKeeper.h"
#include "Hut.h"
#include "Woman.h"
#include "Common.h"

// ========== GLOBAL SCENE OBJECTS ==========
// ----------------- World objects (use object instances, not pointers) -----------------
std::vector<Person> people;
std::vector<Hut>    huts;
std::vector<Woman>  women;

// single big shop and single shopkeeper as objects (constructed with sensible defaults)
Shop bigShop(70.0f, 40.0f, 22.0f, 18.0f);   // (x, z, width, depth)
ShopKeeper keeper(81.0f, 37.0f);            // (x, z)


// ========== CAMERA PARAMETERS ==========
float cameraDistance = 35.0f;  // Distance from center
float cameraAngleDeg = 45.0f;  // Rotation angle (degrees)
float cameraHeight = 12.0f;    // Height above ground

// ========== ANIMATION STATE ==========
bool animationPaused = false;

/**
 * Initialize scene objects (shops, huts, people, etc.)
 */
void initObjects()
{
    // clear dynamic lists
    people.clear();
    huts.clear();
    women.clear();

    // Initialize people
    people.push_back(Person(30.0f, 18.0f,  0.20f));
    people.push_back(Person(60.0f, 18.0f, -0.18f));

    // Initialize huts
    huts.push_back(Hut(15.0f, 45.0f));
    huts.push_back(Hut(20.0f, 60.0f));
    huts.push_back(Hut(85.0f, 50.0f));

    // Initialize women
    women.push_back(Woman(40.0f, 35.0f));
    women.push_back(Woman(55.0f, 50.0f));

    // If you want to change bigShop or keeper position at runtime, do it here:
    // bigShop = Shop(70.0f, 40.0f, 22.0f, 18.0f); // reassign (works because Shop has copy/move)
    // keeper = ShopKeeper(81.0f, 37.0f);        // reassign
}


/**
 * Setup OpenGL rendering state
 */
void initGL() {
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f); // Sky blue background
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Setup light
    GLfloat lightAmbient[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat lightDiffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat lightPosition[] = {20.0f, 30.0f, 20.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // Enable color material
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

/**
 * Reshape callback - handles window resize
 */
void reshape(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

/**
 * Display callback - renders the scene
 */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ========== SETUP CAMERA (ORBITING) ==========
    float angleRad = cameraAngleDeg * 3.14159f / 180.0f;
    float camX = cameraDistance * cosf(angleRad);
    float camZ = cameraDistance * sinf(angleRad);
    float centerX = 0.0f;
    float centerY = 5.0f;
    float centerZ = 0.0f;

    gluLookAt(camX, cameraHeight, camZ,  // Camera position
              centerX, centerY, centerZ, // Look at center
              0.0f, 1.0f, 0.0f);         // Up vector
 // ========== BASIC LIGHTING SETUP ==========
    // (safe to call each frame; keeps a consistent light position)
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    {
        GLfloat lightPos[]  = { 40.0f, 80.0f, 40.0f, 1.0f };
        GLfloat lightAmb[]  = { 0.25f, 0.25f, 0.25f, 1.0f };
        GLfloat lightDiff[] = { 0.9f, 0.9f, 0.9f, 1.0f };
        GLfloat lightSpec[] = { 0.6f, 0.6f, 0.6f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
        glLightfv(GL_LIGHT0, GL_AMBIENT,  lightAmb);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  lightDiff);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
    }

    // ========== DRAW BACKGROUND ==========
    Environment::drawBackground();

    // ========== DRAW SHOPS ==========
    // draw the big shop and keeper (objects, not pointers)
bigShop.draw();
keeper.draw();


    // ========== DRAW HUTS ==========
    for (auto& hut : huts) {
        hut.draw();
    }

    // ========== DRAW PEOPLE ==========
    for (auto& person : people) {
        person.draw();
    }

    // ========== DRAW SHOPKEEPER ==========
    // draw the big shop and keeper (objects, not pointers)
bigShop.draw();
keeper.draw();


    // ========== DRAW WOMEN ==========
    for (auto& woman : women) {
        woman.draw();
    }

    // ========== DRAW SMALL STALLS (simple boxes) ==========
    glColor3f(0.6f, 0.5f, 0.4f); // Brown stalls
    // Stall 1
    glPushMatrix();
    glTranslatef(-10.0f, 0.5f, -5.0f);
    drawBox(2.0f, 1.0f, 1.5f);
    glPopMatrix();

    // Stall 2
    glPushMatrix();
    glTranslatef(5.0f, 0.5f, -8.0f);
    drawBox(2.0f, 1.0f, 1.5f);
    glPopMatrix();

    // Stall 3
    glPushMatrix();
    glTranslatef(-5.0f, 0.5f, 10.0f);
    drawBox(2.0f, 1.0f, 1.5f);
    glPopMatrix();

    // ========== DRAW BASKETS/POTS (decorative elements) ==========
    glColor3f(0.5f, 0.4f, 0.3f); // Brown baskets
    // Basket 1
    glPushMatrix();
    glTranslatef(-12.0f, 0.3f, -5.0f);
    drawCylinder(0.3f, 0.4f);
    glPopMatrix();

    // Basket 2
    glPushMatrix();
    glTranslatef(7.0f, 0.3f, -8.0f);
    drawCylinder(0.3f, 0.4f);
    glPopMatrix();

    // Pot
    glPushMatrix();
    glTranslatef(-7.0f, 0.2f, 10.0f);
    drawCylinder(0.25f, 0.5f);
    glPopMatrix();

    glutSwapBuffers();
}

/**
 * Timer callback - updates animation
 */
void timer(int value) {
    if (!animationPaused) {
        // Update people positions
        for (auto& person : people) {
            person.update();
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

/**
 * Keyboard callback - handles regular key presses
 */
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
        case '=':
            cameraDistance -= 2.0f;
            if (cameraDistance < 10.0f) cameraDistance = 10.0f;
            break;
        case '-':
        case '_':
            cameraDistance += 2.0f;
            if (cameraDistance > 80.0f) cameraDistance = 80.0f;
            break;
        case 'p':
        case 'P':
            animationPaused = !animationPaused;
            break;
        case 'r':
        case 'R':
            // Reset camera
            cameraDistance = 35.0f;
            cameraAngleDeg = 45.0f;
            cameraHeight = 12.0f;
            break;
        case 27: // ESC
            exit(0);
            break;
    }
    glutPostRedisplay();
}

/**
 * Special key callback - handles arrow keys
 */
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            cameraAngleDeg -= 5.0f;
            break;
        case GLUT_KEY_RIGHT:
            cameraAngleDeg += 5.0f;
            break;
        case GLUT_KEY_UP:
            cameraHeight += 1.0f;
            if (cameraHeight > 30.0f) cameraHeight = 30.0f;
            break;
        case GLUT_KEY_DOWN:
            cameraHeight -= 1.0f;
            if (cameraHeight < 3.0f) cameraHeight = 3.0f;
            break;
    }
    glutPostRedisplay();
}

/**
 * Main function
 */
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("VillageHat3D - Village Market Scene");

    // Initialize OpenGL
    initGL();

    // Initialize scene objects
    initObjects();

    // Register callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(16, timer, 0);

    // Start main loop
    glutMainLoop();


    return 0;
}

