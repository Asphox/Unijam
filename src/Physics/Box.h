//
// Created by nayht on 22/11/2019.
//

#ifndef UNIJAM_BOX_H
#define UNIJAM_BOX_H


#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.h"

class Box : public Entity
{
private:
    b2Body* m_body;
    sf::RectangleShape m_rectangle;
public:
    Box(b2Body* body,  float x, float y, float w, float h, float a);
    ~Box();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //UNIJAM_BOX_H
