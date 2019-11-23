//
// Created by nayht on 22/11/2019.
//

#include "World.h"

World::World(float yGravity) : m_world(b2Vec2(0.0f, yGravity))
{
}

b2World& World::getWorld() {
    return m_world;
}

void World::step(float deltaTime) {
    m_world.Step(deltaTime, 6, 2);
}

void World::clear(){
    m_world.Dump();
}