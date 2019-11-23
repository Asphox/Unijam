//
// Created by nayht on 23/11/2019.
//

#include "Circle.h"

Circle::Circle(b2Body& body, float x, float y, float r) : sf::CircleShape(r), Entity(), m_body(body)
{
    setPosition(x, -y);
    setOrigin(r, r);
}

Circle::~Circle() {

}

void Circle::update() {

}