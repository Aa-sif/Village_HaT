/**
 * ShopKeeper.h
 *
 * Represents the shopkeeper character standing at the shop counter.
 * Similar to Person but static and positioned at the shop.
 *
 * Author: VillageHat3D Project
 */

#ifndef SHOPKEEPER_H
#define SHOPKEEPER_H

/**
 * ShopKeeper class - static shopkeeper character
 */
class ShopKeeper {
public:
    float x;  // X position
    float z;  // Z position

    /**
     * Constructor
     * @param posX X position
     * @param posZ Z position
     */
    ShopKeeper(float posX, float posZ);

    /**
     * Draw the shopkeeper
     */
    void draw() const;
};

#endif // SHOPKEEPER_H

