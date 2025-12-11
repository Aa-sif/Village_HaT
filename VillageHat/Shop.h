/**
 * Shop.h
 *
 * Represents the main shop building in the market.
 * Includes body, roof, counter, pillars, and decorative elements.
 *
 * Author: VillageHat3D Project
 */

#ifndef SHOP_H
#define SHOP_H

/**
 * Shop class - main market building
 */
class Shop {
public:
    float x;  // X position (center)
    float z;  // Z position (center)
    float w;  // Width
    float d;  // Depth

    /**
     * Constructor
     * @param posX X position
     * @param posZ Z position
     * @param width building width
     * @param depth building depth
     */
    Shop(float posX, float posZ, float width, float depth);

    /**
     * Draw the shop building
     */
    void draw() const;
};

#endif // SHOP_H

