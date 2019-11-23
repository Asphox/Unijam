//
// Created by nayht on 23/11/2019.
//

#ifndef UNIJAM_ENTITYFACTORY_H
#define UNIJAM_ENTITYFACTORY_H


#include "World.h"
#include "Box.h"
#include "Circle.h"
#include "Convex.h"
#include "../Entities/Car.h"

class EntityFactory {
private:
    Box* createBox(World& world, float x, float y, float width, float height, float density, float friction, float angle, bool isStatic);
    Circle* createCircle(World& world, float x, float y, float r, float density, float friction, bool isStatic);
    Convex* createConvex(World &world, float x, float y, float a, std::vector<std::pair<float, float>>& relativeVertices, float density, float friction, bool isStatic);
public:
    Box* createBoxStatic(World& world, float x, float y, float halfWidth, float halfHeight);
    Box* createBoxStatic(World& world, float x, float y, float halfWidth, float halfHeight, float angle);
    Box* createBoxDynamic(World& world, float x, float y, float halfWidth, float halfHeight, float density, float friction);
    Box* createBoxDynamic(World& world, float x, float y, float halfWidth, float halfHeight, float density, float friction, float angle);
    Circle* createCircleStatic(World& world, float x, float y, float r);
    Circle* createCircleDynamic(World& world, float x, float y, float r, float density, float friction);
    Car* createCar(World& world, float x, float y);
    Car* createCar(World& world, float x, float y, float size);

    Convex* createConvexStatic(World &world, float x, float y, std::vector<std::pair<float, float>>& vertices);
    Convex* createConvexStatic(World &world, float x, float y, float a, std::vector<std::pair<float, float>>& vertices);
    Convex* createConvexDynamic(World &world, float x, float y, std::vector<std::pair<float, float>>& vertices, float density, float friction);
    Convex* createConvexDynamic(World &world, float x, float y, float a, std::vector<std::pair<float, float>>& vertices, float density, float friction);

};


#endif //UNIJAM_ENTITYFACTORY_H
