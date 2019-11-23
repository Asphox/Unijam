//
// Created by nayht on 23/11/2019.
//

#ifndef UNIJAM_CONVEX_H
#define UNIJAM_CONVEX_H


#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Convex: public Entity
{
private:
    b2Body* m_body;
    sf::ConvexShape m_convex;
public:
    Convex(b2Body* body, float x, float y, float a, b2Vec2* vertices, int verticesCount);
    Convex(b2Body* body, float x, float y, float a, std::vector<std::pair<float, float>>& vertices);
    ~Convex();
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //UNIJAM_CONVEX_H
