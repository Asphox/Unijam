//
// Created by nayht on 23/11/2019.
//

#include "Convex.h"

Convex::Convex(b2Body* body, float x, float y, float a, b2Vec2* vertices, int verticesCount)  : m_body(body){
    m_convex = sf::ConvexShape(verticesCount);
    for (int i = 0; i < verticesCount; i++) {
        m_convex.setPoint(i, sf::Vector2f(vertices[i].x, -vertices[i].y));
    }
    m_convex.setPosition(x, y);
    m_convex.setOrigin(body->GetLocalCenter().x, body->GetLocalCenter().y);
    m_convex.setRotation(a);
    //m_convex.setFillColor(sf::Color(255,255,255));
    m_convex.setOutlineColor(sf::Color(0,0,255));
    m_convex.setOutlineThickness(20);
}

Convex::Convex(b2Body* body, float x, float y, float a, std::vector<std::pair<float, float>>& vertices) : m_body(body){
    m_convex = sf::ConvexShape(vertices.size());
    int i = 0;
    for (auto it : vertices) {
        m_convex.setPoint(i, sf::Vector2f(it.first, -it.second));
        i++;
    }
    m_convex.setPosition(x, y);
    m_convex.setOrigin(body->GetLocalCenter().x, body->GetLocalCenter().y);
    m_convex.setRotation(a);
    //m_convex.setFillColor(sf::Color(255,255,255));
    m_convex.setOutlineColor(sf::Color(0,0,255));
    m_convex.setOutlineThickness(20);
}
Convex::~Convex() {

}

void Convex::update() {
    m_convex.setPosition(m_body->GetPosition().x, -m_body->GetPosition().y);
    m_convex.setRotation(-m_body->GetAngle()*180/3.14);
}

void Convex::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_convex, states);
}

