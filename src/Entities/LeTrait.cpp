//
// Created by asphox on 24/11/2019.
//

#include "LeTrait.h"

#include <iostream>

LeTrait::LeTrait(sf::RenderWindow& window, GameScene& gameScene, Car *top, Car *bot) : m_window(window), m_gameScene(gameScene), m_carStart(top), m_carEnd(bot)
{
    m_texture1to2.loadFromFile("Assets/1to2.png");
    m_texture1to2.setRepeated(true);
    m_texture2to1.loadFromFile("Assets/2to1.png");
    m_texture2to1.setRepeated(true);
}

void LeTrait::update()
{
    sf::Vector2f posOnWorld(m_carStart->getPosition().x,-m_carStart->getPosition().y);
    sf::Vector2i posOnScreen(m_window.mapCoordsToPixel(posOnWorld,m_gameScene.getViewTop()));
    m_shape.setPosition(posOnScreen.x,posOnScreen.y);
    calcLength();
    calcAngle();
}

void LeTrait::show(bool b)
{
    m_show = b;
}

void LeTrait::calcLength()
{
    sf::Vector2f posOnWorldCar1(m_carStart->getPosition().x,-m_carStart->getPosition().y);
    sf::Vector2f posOnWorldCar2(m_carEnd->getPosition().x,-m_carEnd->getPosition().y);

    sf::Vector2i posOnScreen1(m_window.mapCoordsToPixel(posOnWorldCar1,m_gameScene.getViewTop()));
    sf::Vector2i posOnScreen2(m_window.mapCoordsToPixel(posOnWorldCar2,m_gameScene.getViewBot()));

    float dist_x =(posOnScreen1.x-posOnScreen2.x)*(posOnScreen1.x-posOnScreen2.x);
    float dist_y =(posOnScreen1.y-posOnScreen2.y)*(posOnScreen1.y-posOnScreen2.y);
    m_shape.setSize(sf::Vector2f(sqrt(dist_x+dist_y),30));

}

void LeTrait::calcAngle()
{
    sf::Vector2f posOnWorldCar1(m_carStart->getPosition().x,-m_carStart->getPosition().y);
    sf::Vector2f posOnWorldCar2(m_carEnd->getPosition().x,-m_carEnd->getPosition().y);

    sf::Vector2i posOnScreen1(m_window.mapCoordsToPixel(posOnWorldCar1,m_gameScene.getViewTop()));
    sf::Vector2i posOnScreen2(m_window.mapCoordsToPixel(posOnWorldCar2,m_gameScene.getViewBot()));



    float angle = atan2(posOnScreen1.y-posOnScreen2.y,posOnScreen1.x-posOnScreen2.x);
    m_shape.setRotation(angle*57.295779513+180);
}

void LeTrait::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(m_show)
    {
        target.draw(m_shape,states);
    }
}