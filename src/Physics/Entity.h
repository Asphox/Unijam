//
// Created by nayht on 22/11/2019.
//

#ifndef UNIJAM_ENTITY_H
#define UNIJAM_ENTITY_H


#include <SFML/Graphics/Drawable.hpp>

class Entity : public sf::Drawable
{
public:
    Entity();
    ~Entity();
    virtual void update() = 0;
};


#endif //UNIJAM_ENTITY_H
