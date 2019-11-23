//
// Created by nayht on 23/11/2019.
//

#ifndef UNIJAM_LEVEL_H
#define UNIJAM_LEVEL_H


#include <SFML/Graphics.hpp>
#include <Physics/EntityFactory.h>
#include <vector>
#include <Physics/Entity.h>

class Level{
private:
    std::vector<Entity*> m_objects_top;
    std::vector<Entity*> m_objects_bot;
    float m_distanceToWin;
public:
    Level(float distanceToWin);
    void addEntityTop(Entity* entity);
    void addEntityBot(Entity* entity);
    std::vector<Entity*>& getEntitiesTop();
    std::vector<Entity*>& getEntitiesBot();
    void drawTop(sf::RenderWindow& window);
    void drawBot(sf::RenderWindow& window);
    float getDistanceToWin();
};


#endif //UNIJAM_LEVEL_H
