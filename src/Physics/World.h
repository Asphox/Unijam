//
// Created by nayht on 22/11/2019.
//

#ifndef UNIJAM_WORLD_H
#define UNIJAM_WORLD_H


#include <Box2D/Box2D.h>
#include <vector>
#include "Entity.h"


class World {
private:
    b2World m_world;
    std::vector<Entity*> m_entities;
public:
    World(float gravity);
    ~World();
    std::vector<Entity*>& getEntities();
    b2World& getWorld();
    void addEntity(Entity* entity);
    void step(float deltaTime);
};


#endif //UNIJAM_WORLD_H
