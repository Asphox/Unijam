//
// Created by nayht on 22/11/2019.
//

#include "Box.h"

Box::Box(b2Body& body, float x, float y, float w, float h, float a) : sf::RectangleShape(sf::Vector2f(w,h)), Entity(), m_body(body)
{
    setPosition(x, -y);
    setOrigin(w/2, h/2);
    setRotation(a);
}

Box::~Box() {

}

void Box::update() {

}
