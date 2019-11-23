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
public:
    Box* createBoxStatic(World& world, float x, float y, float width, float height);
    Box* createBoxStatic(World& world, float x, float y, float width, float height, float angle);
    Box* createBoxDynamic(World& world, float x, float y, float width, float height, float density, float friction);
    Box* createBoxDynamic(World& world, float x, float y, float width, float height, float density, float friction, float angle);
    Circle* createCircleStatic(World& world, float x, float y, float r);
    Circle* createCircleDynamic(World& world, float x, float y, float r, float density, float friction);
    Car* createCar(World& world, float x, float y);
};


#endif //UNIJAM_ENTITYFACTORY_H
