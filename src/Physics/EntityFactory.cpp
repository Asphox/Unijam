//
// Created by nayht on 23/11/2019.
//

#include "EntityFactory.h"
#include "Convex.h"

/** Box **/
Entity* EntityFactory::createBox(World& world, float x, float y, float halfWidth, float halfHeight, float density, float friction, float angle, bool isStatic) {
    //Body creation
    b2BodyDef bodyDef;
    if (!isStatic){
        bodyDef.type = b2_dynamicBody;
    }
    bodyDef.position.Set(x, -y);
    bodyDef.angle = angle*3.14/180;

    b2PolygonShape boxShape;
    boxShape.SetAsBox(halfWidth, halfHeight);

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
    Entity* box = new Box(body, x, y, halfWidth*2, halfHeight*2, angle*3.14/180);
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
    if (!isStatic){
        bodyDef.type = b2_dynamicBody;
    }
    bodyDef.position.Set(x, -y);

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
    Entity* circle = new Circle(body, x, y, r);
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

Entity *EntityFactory::createCar(World &world, float x, float y) {
    // car body
    b2Vec2 verticesPoly1[5];
    int32 countPoly1 = 5;

    // bottom half
    verticesPoly1[4].Set(-22.0f,-7.4f);
    verticesPoly1[3].Set(-22.0f,0);
    verticesPoly1[2].Set(10.0f,0);
    verticesPoly1[1].Set(22.0f,-2.0f);
    verticesPoly1[0].Set(22.0f,-7.4f);
    b2PolygonShape poly1;
    poly1.Set(verticesPoly1, countPoly1);
    b2FixtureDef fixtureDefPoly1;
    fixtureDefPoly1.filter.groupIndex = -1;
    fixtureDefPoly1.shape = &poly1;
    fixtureDefPoly1.density	= 2.0f;
    fixtureDefPoly1.friction = 0.68f;

    // top half
    b2Vec2 verticesPoly2[4];
    int32 countPoly2 = 4;
    verticesPoly2[3].Set(-17.0f,0);
    verticesPoly2[2].Set(-13.0f,7.0f);
    verticesPoly2[1].Set(5.0f,7.4f);
    verticesPoly2[0].Set(10.0f,0);
    b2PolygonShape poly2;
    poly2.Set(verticesPoly2, countPoly2);
    b2FixtureDef fixtureDefPoly2;
    fixtureDefPoly2.filter.groupIndex = -1;
    fixtureDefPoly2.shape = &poly2;
    fixtureDefPoly2.density	= 5.0f;
    fixtureDefPoly2.friction = 0.68f;

    b2BodyDef vehicleBodyDef;
    vehicleBodyDef.type = b2_dynamicBody;
    vehicleBodyDef.position.Set(x, y);

    b2Body* vehicleBody;
    vehicleBody = world.getWorld().CreateBody(&vehicleBodyDef);
    vehicleBody->CreateFixture(&fixtureDefPoly1);
    vehicleBody->CreateFixture(&fixtureDefPoly2);

    Entity* vehiclePoly1Entity = new Convex(vehicleBody, x, y, 0, verticesPoly1, countPoly1);
    world.addEntity(vehiclePoly1Entity);
    Entity* vehiclePoly2Entity = new Convex(vehicleBody, x, y, 0, verticesPoly2, countPoly2);
    world.addEntity(vehiclePoly2Entity);

    // vehicle wheels
    b2CircleShape circ;
    b2FixtureDef fixtureDefCirc;
    circ.m_radius = 5;
    fixtureDefCirc.shape = &circ;
    fixtureDefCirc.density = 10.0f;
    fixtureDefCirc.friction = 0.9f;
    fixtureDefCirc.filter.groupIndex = -1;

    b2BodyDef wheelBody;
    wheelBody.allowSleep = false;
    wheelBody.type = b2_dynamicBody;
    wheelBody.position.Set(x-12.0f, y-8.0f);
    b2Body* rightWheel;
    rightWheel = world.getWorld().CreateBody(&wheelBody);
    rightWheel -> CreateFixture(&fixtureDefCirc);
    Entity* rightWheelCircleEntity = new Circle(rightWheel, x-12.0f, y-8.0f, circ.m_radius);
    world.addEntity(rightWheelCircleEntity);

    wheelBody.position.Set(x+12.0f, y-8.0f);
    b2Body* leftWheel;
    leftWheel = world.getWorld().CreateBody(&wheelBody);
    leftWheel -> CreateFixture(&fixtureDefCirc);
    Entity* leftWheelCircleEntity = new Circle(leftWheel, x+12.0f, y-8.0f, circ.m_radius);
    world.addEntity(leftWheelCircleEntity);

    // join wheels to chassis
    b2WheelJointDef jd;
    jd.Initialize(vehicleBody, leftWheel, leftWheel->GetWorldCenter(), b2Vec2(0,-1));
    jd.collideConnected = false;
    jd.enableMotor = true;
    jd.maxMotorTorque = 1000.0f;
    jd.motorSpeed = -50.0f;
    b2RevoluteJoint* leftJoint = (b2RevoluteJoint*)world.getWorld().CreateJoint(&jd);

    jd.Initialize(vehicleBody, rightWheel, rightWheel->GetWorldCenter(), b2Vec2(0,-1));
    jd.collideConnected = false;
    b2RevoluteJoint* rightJoint = (b2RevoluteJoint*)world.getWorld().CreateJoint(&jd);
}
