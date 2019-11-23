//
// Created by nayht on 23/11/2019.
//

#ifndef UNIJAM_ENTITYFACTORY_H
#define UNIJAM_ENTITYFACTORY_H


#include "World.h"

class EntityFactory {
private:
    Entity* createBox(World& world, float x, float y, float width, float height, float density, float friction, float angle, bool isStatic);
    Entity* createCircle(World& world, float x, float y, float r, float density, float friction, bool isStatic);
public:
    Entity* createBoxStatic(World& world, float x, float y, float width, float height);
    Entity* createBoxStatic(World& world, float x, float y, float width, float height, float angle);
    Entity* createBoxDynamic(World& world, float x, float y, float width, float height, float density, float friction);
    Entity* createBoxDynamic(World& world, float x, float y, float width, float height, float density, float friction, float angle);
    Entity* createCircleStatic(World& world, float x, float y, float r);
    Entity* createCircleDynamic(World& world, float x, float y, float r, float density, float friction);
};


#endif //UNIJAM_ENTITYFACTORY_H
