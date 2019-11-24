//
// Created by nayht on 22/11/2019.
//

#include "Box.h"

Box::Box(b2Body* body, float x, float y, float w, float h, float a) : Entity(), m_body(body)
{
    m_rectangle = sf::RectangleShape(sf::Vector2f(w, h));
    m_rectangle.setPosition(x, y);
    m_rectangle.setOrigin(w / 2, h / 2);
    m_rectangle.setRotation(a);
    m_rectangle.setFillColor(sf::Color(150,200,255));
    m_rectangle.setOutlineThickness(3);
    m_rectangle.setOutlineColor(sf::Color(0,64,192));
}

Box::~Box() {

}

void Box::update() {
    m_rectangle.setPosition(m_body->GetPosition().x, -m_body->GetPosition().y);
    m_rectangle.setRotation(-m_body->GetAngle()*180/3.14);
}

void Box::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_rectangle, states);
}
