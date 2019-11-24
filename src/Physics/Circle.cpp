//
// Created by nayht on 23/11/2019.
//

#include "Circle.h"

Circle::Circle(b2Body* body, float x, float y, float r) : Entity(), m_body(body)
{
    m_circle = sf::CircleShape(r);
    m_circle.setPosition(x, y);
    m_circle.setOrigin(r, r);
    m_circle.setFillColor(sf::Color(255,100,0));
    m_circle.setOutlineThickness(3);
    m_circle.setOutlineColor(sf::Color(0,64,192));
}

Circle::~Circle() {

}

void Circle::update() {
    m_circle.setPosition(m_body->GetPosition().x, -m_body->GetPosition().y);
}

void Circle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_circle, states);
}
