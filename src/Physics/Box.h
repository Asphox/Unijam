//
// Created by nayht on 22/11/2019.
//

#ifndef UNIJAM_BOX_H
#define UNIJAM_BOX_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <Box2D/Box2D.h>
#include "Entity.h"

class Box : public sf::RectangleShape, public Entity
{
private:
    b2Body m_body;
public:
    Box(b2Body& body,  float x, float y, float w, float h, float a);
    ~Box();
    void update() override;
};


#endif //UNIJAM_BOX_H
