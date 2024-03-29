//
// Created by nayht on 23/11/2019.
//

#include "EntityFactory.h"

/** Box **/
Box* EntityFactory::createBox(World& world, float x, float y, float halfWidth, float halfHeight, float density, float friction, float angle, bool isStatic) {
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

    return new Box(body, x, y, halfWidth*2, halfHeight*2, angle*3.14/180);;
}

Box* EntityFactory::createBoxStatic(World& world, float x, float y, float halfWidth, float halfHeight) {
    return createBox(world, x, y, halfWidth, halfHeight, 0, 0, 0, true);
}

Box* EntityFactory::createBoxStatic(World& world, float x, float y, float halfWidth, float halfHeight, float angle) {
    return createBox(world, x, y, halfWidth, halfHeight, 0, 0, angle, true);
}

Box* EntityFactory::createBoxDynamic(World& world, float x, float y, float halfWidth, float halfHeight, float density, float friction) {
    return createBox(world, x, y, halfWidth, halfHeight, density, friction, 0, false);
}

Box* EntityFactory::createBoxDynamic(World& world, float x, float y, float halfWidth, float halfHeight, float density, float friction, float angle) {
    return createBox(world, x, y, halfWidth, halfHeight, density, friction, angle, false);
}

/** Circle **/
Circle* EntityFactory::createCircle(World &world, float x, float y, float r, float density, float friction, bool isStatic) {
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

    return new Circle(body, x, y, r);;
}

Circle* EntityFactory::createCircleStatic(World &world, float x, float y, float r) {
    return createCircle(world, x, y, r, 0, 0, true);
}

Circle* EntityFactory::createCircleDynamic(World &world, float x, float y, float r, float density, float friction) {
    return createCircle(world, x, y, r, density, friction, false);
}


/** Convex **/
Convex* EntityFactory::createConvex(World &world, float x, float y, float a, std::vector<std::pair<float, float>>& relativeVertices, float density, float friction, bool isStatic) {
    //Body creation
    b2BodyDef bodyDef;
    if (!isStatic){
        bodyDef.type = b2_dynamicBody;
    }
    bodyDef.position.Set(x, -y);
    bodyDef.angle = a*3.14/180;

    b2Vec2 verticesConvex[relativeVertices.size()];
    int i = 0;
    for (auto it : relativeVertices){
        verticesConvex[i].Set(it.first, it.second);
        i++;
    }

    b2PolygonShape convexShape;
    convexShape.Set(verticesConvex, relativeVertices.size());

    b2Body* body = world.getWorld().CreateBody(&bodyDef);
    if (isStatic) {
        body->CreateFixture(&convexShape, 0.0f);
    } else {
        b2FixtureDef fixtureDefConvex;
        fixtureDefConvex.shape = &convexShape;
        fixtureDefConvex.density = density;
        fixtureDefConvex.friction = friction;
        body->CreateFixture(&fixtureDefConvex);
    }

    return new Convex(body, x, y, a, relativeVertices);;
}

Convex* EntityFactory::createConvexStatic(World &world, float x, float y, float a, std::vector<std::pair<float, float>>& relativeVertices) {
    return createConvex(world, x, y, a, relativeVertices, 0,0,true);
}

Convex* EntityFactory::createConvexStatic(World &world, float x, float y, std::vector<std::pair<float, float>>& relativeVertices) {
    return createConvex(world, x, y, 0, relativeVertices, 0, 0, true);
}

Convex* EntityFactory::createConvexDynamic(World &world, float x, float y, float a, std::vector<std::pair<float, float>>& relativeVertices, float density, float friction)
{
    return createConvex(world, x, y, a, relativeVertices, density, friction, false);
}
Convex* EntityFactory::createConvexDynamic(World &world, float x, float y, std::vector<std::pair<float, float>>& relativeVertices, float density, float friction)
{
    return createConvex(world, x, y, 0, relativeVertices, density, friction, false);
}

/** Car **/
Car* EntityFactory::createCar(World &world, float x, float y, float size) {
    // car body
    b2Vec2 verticesPoly1[5];
    int32 countPoly1 = 5;

    // bottom half
    verticesPoly1[4].Set(-44.0f*size,-14.8f*size);
    verticesPoly1[3].Set(-44.0f*size,0*size);
    verticesPoly1[2].Set(20.0f*size,0*size);
    verticesPoly1[1].Set(44.0f*size,-4.0f*size);
    verticesPoly1[0].Set(44.0f*size,-14.8f*size);
    b2PolygonShape poly1;
    poly1.Set(verticesPoly1, countPoly1);
    b2FixtureDef fixtureDefPoly1;
    fixtureDefPoly1.filter.groupIndex = -1;
    fixtureDefPoly1.shape = &poly1;
    fixtureDefPoly1.density	= 20.0f;
    fixtureDefPoly1.friction = 0.68f;

    // top half
    b2Vec2 verticesPoly2[4];
    int32 countPoly2 = 4;
    verticesPoly2[3].Set(-34.0f*size,0*size);
    verticesPoly2[2].Set(-26.0f*size,14.0f*size);
    verticesPoly2[1].Set(10.0f*size,14.8f*size);
    verticesPoly2[0].Set(20.0f*size,0*size);
    b2PolygonShape poly2;
    poly2.Set(verticesPoly2, countPoly2);
    b2FixtureDef fixtureDefPoly2;
    fixtureDefPoly2.filter.groupIndex = -1;
    fixtureDefPoly2.shape = &poly2;
    fixtureDefPoly2.density	= 20.0f;
    fixtureDefPoly2.friction = 0.68f;

    b2BodyDef vehicleBodyDef;
    vehicleBodyDef.type = b2_dynamicBody;
    vehicleBodyDef.linearDamping = 0.02;
    vehicleBodyDef.position.Set(x, -y);

    b2Body* vehicleBody;
    vehicleBody = world.getWorld().CreateBody(&vehicleBodyDef);
    vehicleBody->CreateFixture(&fixtureDefPoly1);
    vehicleBody->CreateFixture(&fixtureDefPoly2);

    // vehicle wheels
    b2CircleShape circ;
    b2FixtureDef fixtureDefCirc;
    circ.m_radius = 10*size;
    fixtureDefCirc.shape = &circ;
    fixtureDefCirc.density = 2.0f; //5
    fixtureDefCirc.restitution = 1;
    fixtureDefCirc.friction = 1.0f;
    fixtureDefCirc.filter.groupIndex = -1;

    b2BodyDef wheelBody;
    wheelBody.allowSleep = false;
    wheelBody.type = b2_dynamicBody;
    wheelBody.position.Set(x-25.0f*size, -y-22.0f*size);

    b2Body* rightWheel;
    rightWheel = world.getWorld().CreateBody(&wheelBody);
    rightWheel -> CreateFixture(&fixtureDefCirc);

    wheelBody.position.Set(x+30.0f*size, -y-22.0f*size);
    b2Body* leftWheel;
    leftWheel = world.getWorld().CreateBody(&wheelBody);
    leftWheel -> CreateFixture(&fixtureDefCirc);


    wheelBody.position.Set(x, -y);
    b2Body* compensatingWheel1;
    compensatingWheel1 = world.getWorld().CreateBody(&wheelBody);
    compensatingWheel1 -> CreateFixture(&fixtureDefCirc);

    wheelBody.position.Set(x, -y);
    b2Body* compensatingWheel2;
    compensatingWheel2 = world.getWorld().CreateBody(&wheelBody);
    compensatingWheel2 -> CreateFixture(&fixtureDefCirc);

    // join wheels to chassis
    b2WheelJointDef jd;
    jd.Initialize(vehicleBody, leftWheel, leftWheel->GetWorldCenter(), b2Vec2(0,1));
    jd.collideConnected = false;
    jd.enableMotor = true;
    jd.maxMotorTorque = 1000000.0f*size;
    jd.motorSpeed = 0.0f;
    b2WheelJoint* leftJoint = (b2WheelJoint*)world.getWorld().CreateJoint(&jd);

    jd.Initialize(vehicleBody, rightWheel, rightWheel->GetWorldCenter(), b2Vec2(0,1));
    jd.collideConnected = false;
    b2WheelJoint* rightJoint = (b2WheelJoint*)world.getWorld().CreateJoint(&jd);


    jd.Initialize(vehicleBody, compensatingWheel1, compensatingWheel1->GetWorldCenter(), b2Vec2(0,1));
    jd.collideConnected = false;
    b2WheelJoint* compensatingJoint1 = (b2WheelJoint*)world.getWorld().CreateJoint(&jd);

    jd.Initialize(vehicleBody, compensatingWheel2, compensatingWheel2->GetWorldCenter(), b2Vec2(0,1));
    jd.collideConnected = false;
    b2WheelJoint* compensatingJoint2 = (b2WheelJoint*)world.getWorld().CreateJoint(&jd);



    // Encapsulation
    Circle* leftWheelCircle = new Circle(leftWheel, x+24.0f*size, y-16.0f*size, circ.m_radius);
    Circle* rightWheelCircle = new Circle(rightWheel, x-24.0f*size, y-16.0f*size, circ.m_radius);
    Convex* vehicleConvex1 = new Convex(vehicleBody, x, y, 0, verticesPoly1, countPoly1);
    Convex* vehicleConvex2 = new Convex(vehicleBody, x, y, 0, verticesPoly2, countPoly2);
    return new Car(vehicleBody, vehicleConvex1, vehicleConvex2, leftWheelCircle, rightWheelCircle, leftJoint, rightJoint, compensatingJoint1, compensatingJoint2);
}

Car* EntityFactory::createCar(World &world, float x, float y) {
    return createCar(world, x, y, 1);
}
