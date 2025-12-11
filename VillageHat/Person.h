/**
 * Person.h
 *
 * Represents a simple low-poly 3D person that walks along the path.
 * Uses basic primitives (boxes, spheres, cylinders) for body parts.
 *
 * Author: VillageHat3D Project
 */

#ifndef PERSON_H
#define PERSON_H

/**
 * Person class - animated walking character
 */
class Person {
public:
    float x;      // X position
    float z;      // Z position
    float speed;  // Walking speed

    /**
     * Constructor
     * @param startX initial X position
     * @param startZ initial Z position
     * @param walkSpeed movement speed
     */
    Person(float startX, float startZ, float walkSpeed);

    /**
     * Update person position (called each frame)
     */
    void update();

    /**
     * Draw the person at current position
     */
    void draw() const;

private:
    float direction;  // Walking direction (1.0 forward, -1.0 backward)
    float minX, maxX; // Movement boundaries
};

#endif // PERSON_H

