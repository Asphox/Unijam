//
// Created by nayht on 23/11/2019.
//

#include "Level.h"

Level::Level()
{
}

void Level::addEntityTop(Entity* entity)
{
    m_objects_top.push_back(entity);
}

void Level::addEntityBot(Entity* entity)
{
    m_objects_bot.push_back(entity);
}


std::vector<Entity*>& Level::getEntitiesTop()
{
    return m_objects_top;
}

std::vector<Entity*>& Level::getEntitiesBot()
{
    return m_objects_bot;
}

void Level::drawTop(sf::RenderWindow& window)
{
    for (int i = 0; i < m_objects_top.size(); i++)
    {
        window.draw(*m_objects_top[i]);
    }
}

void Level::drawBot(sf::RenderWindow& window)
{
    for (int i = 0; i < m_objects_bot.size(); i++)
    {
        window.draw(*m_objects_bot[i]);
    }
}

void Level::update()
{
    for (int i = 0; i < m_objects_top.size(); i++)
    {
        m_objects_top[i]->update();
    }
    for (int i = 0; i < m_objects_bot.size(); i++)
    {
        m_objects_bot[i]->update();
    }
}