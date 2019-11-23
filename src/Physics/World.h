//
// Created by nayht on 22/11/2019.
//

#ifndef UNIJAM_WORLD_H
#define UNIJAM_WORLD_H


#include <Box2D/Box2D.h>
#include <vector>

class World {
private:
    b2World m_world;
public:
    World(float gravity);
    b2World& getWorld();
    void step(float deltaTime);
    void clear();
};


#endif //UNIJAM_WORLD_H
