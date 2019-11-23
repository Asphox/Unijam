//
// Created by nayht on 22/11/2019.
//

#ifndef UNIJAM_ENTITY_H
#define UNIJAM_ENTITY_H


class Entity {
public:
    Entity();
    ~Entity();
    virtual void update() = 0;
};


#endif //UNIJAM_ENTITY_H
