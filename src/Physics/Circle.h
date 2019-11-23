//
// Created by nayht on 23/11/2019.
//

#ifndef UNIJAM_CIRCLE_H
#define UNIJAM_CIRCLE_H


#include <SFML/Graphics/CircleShape.hpp>
#include <Box2D/Dynamics/b2Body.h>
#include "Entity.h"

class Circle : public sf::CircleShape, public Entity
{
private:
    b2Body m_body;
public:
    Circle(b2Body& body,  float x, float y, float r);
    ~Circle();
    void update() override;
};


#endif //UNIJAM_CIRCLE_H
