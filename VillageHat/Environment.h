/**
 * Environment.h
 *
 * Handles rendering of the background scene elements:
 * sky, hills, ground, fields, path, and trees.
 *
 * Author: VillageHat3D Project
 */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

/**
 * Environment class for background rendering
 */
class Environment {
public:
    /**
     * Draw the complete background scene
     * Includes: sky, distant hills, tree-line, ground, fields, path, and trees
     */
    static void drawBackground();
};

#endif // ENVIRONMENT_H

