//
// Created by nayht on 23/11/2019.
//

#ifndef UNIJAM_CIRCLE_H
#define UNIJAM_CIRCLE_H


#include <SFML/Graphics.hpp>
#include <Box2D/Dynamics/b2Body.h>
#include "Entity.h"

class Circle : public Entity
{
private:
    b2Body* m_body;
    sf::CircleShape m_circle;
public:
    Circle(b2Body* body,  float x, float y, float r);
    ~Circle();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //UNIJAM_CIRCLE_H
