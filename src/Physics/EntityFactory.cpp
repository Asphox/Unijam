//
// Created by nayht on 23/11/2019.
//

#include "EntityFactory.h"
#include "Box.h"
#include "Circle.h"

/** Box **/
Entity* EntityFactory::createBox(World& world, float x, float y, float width, float height, float density, float friction, float angle, bool isStatic) {
    //Body creation
    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(width*2, height*2);

    b2Body* body = world.getWorld().CreateBody(&bodyDef);

    if (isStatic) {
        body->CreateFixture(&boxShape, 0.0f);
    } else {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &boxShape;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        body->CreateFixture(&fixtureDef);
    }
    //Here, the body is created
    //Entity creation
    Entity* box = new Box(*body, x, y, width*2, height*2, angle*3.14/180);
    //Here, the entity is created
    //We add the entity to the world list of entities
    world.addEntity(box);
    return box;
}

Entity* EntityFactory::createBoxStatic(World& world, float x, float y, float width, float height) {
    return createBox(world, x, y, width, height, 0, 0, 0, true);
}

Entity* EntityFactory::createBoxStatic(World& world, float x, float y, float width, float height, float angle) {
    return createBox(world, x, y, width, height, 0, 0, angle, true);
}

Entity* EntityFactory::createBoxDynamic(World& world, float x, float y, float width, float height, float density, float friction) {
    return createBox(world, x, y, width, height, density, friction, 0, false);
}

Entity* EntityFactory::createBoxDynamic(World& world, float x, float y, float width, float height, float density, float friction, float angle) {
    return createBox(world, x, y, width, height, density, friction, angle, false);
}

/** Circle **/
Entity* EntityFactory::createCircle(World &world, float x, float y, float r, float density, float friction, bool isStatic) {
    //Body creation
    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);

    b2CircleShape circleShape;
    circleShape.m_radius=r;

    b2Body* body = world.getWorld().CreateBody(&bodyDef);

    if (isStatic) {
        body->CreateFixture(&circleShape, 0.0f);
    } else {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &circleShape;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        body->CreateFixture(&fixtureDef);
    }
    //Here, the body is created
    //Entity creation
    Entity* circle = new Circle(*body, x, y, r);
    //Here, the entity is created
    //We add the entity to the world list of entities
    world.addEntity(circle);
    return circle;
}

Entity* EntityFactory::createCircleStatic(World &world, float x, float y, float r) {
    return createCircle(world, x, y, r, 0, 0, true);
}

Entity *EntityFactory::createCircleDynamic(World &world, float x, float y, float r, float density, float friction) {
    return createCircle(world, x, y, r, density, friction, false);
}
