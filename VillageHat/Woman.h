/**
 * Woman.h
 *
 * Represents a female villager character.
 * Features a longer skirt and a basket on the head.
 * Can be static or lightly animated.
 *
 * Author: VillageHat3D Project
 */

#ifndef WOMAN_H
#define WOMAN_H

/**
 * Woman class - female villager character
 */
class Woman {
public:
    float x;  // X position
    float z;  // Z position

    /**
     * Constructor
     * @param posX X position
     * @param posZ Z position
     */
    Woman(float posX, float posZ);

    /**
     * Draw the woman character
     */
    void draw() const;
};

#endif // WOMAN_H

