//
// Created by nayht on 22/11/2019.
//

#include "World.h"

World::World(float yGravity) : m_world(b2Vec2(0.0f, yGravity))
{

}

World::~World()
{
    for (Entity* entityPtr : m_entities)
    {
        free(entityPtr);
    }
}

std::vector<Entity*>& World::getEntities() {
    return m_entities;
}

void World::addEntity(Entity* entity) {
    m_entities.push_back(entity);
}

b2World& World::getWorld() {
    return m_world;
}

void World::step(float deltaTime) {
    m_world.Step(deltaTime, 6, 2);
}
