/**
 * Hut.h
 *
 * Represents a simple hut building with a triangular roof.
 * Used for small dwellings around the market area.
 *
 * Author: VillageHat3D Project
 */

#ifndef HUT_H
#define HUT_H

/**
 * Hut class - simple dwelling structure
 */
class Hut {
public:
    float x;  // X position (center)
    float z;  // Z position (center)

    /**
     * Constructor
     * @param posX X position
     * @param posZ Z position
     */
    Hut(float posX, float posZ);

    /**
     * Draw the hut
     */
    void draw() const;
};

#endif // HUT_H

