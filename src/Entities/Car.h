#ifndef CAR_H
#define CAR_H

#include <Box2D/Box2D.h>
#include "../Physics/Entity.h"
#include "../Physics/Convex.h"
#include "../Physics/Circle.h"

// Adapted from SpiritWalkers by darkzerox
class Car : public Entity
{
private:
    b2Body* m_vehiclePhysicalBody;
    Convex* m_carTop;
    Convex* m_carBot;
    Circle* m_leftWheel;
    Circle* m_rightWheel;
    b2WheelJoint* m_leftJoint;
    b2WheelJoint* m_rightJoint;
    b2WheelJoint* m_compensatingJoint1;
    b2WheelJoint* m_compensatingJoint2;

    float m_maxVelocity = 100;
    float m_linearVelocityIncrement = 5;
    float m_angularVelocityCoefficient = 2000;
    float m_jumpVerticalCoefficient = 2000000;


public:
    Car(b2Body* vehicleBody, Convex* bodyTop, Convex* bodyBot, Circle* leftWheel, Circle* rightWhee, b2WheelJoint* leftJoint, b2WheelJoint* rightJoint, b2WheelJoint* compensatingJoint1, b2WheelJoint* compensatingJoint2);
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void accelerate(float);
    void decelerate(float);
    void rotate(float userValue);
    void jump();

    sf::Vector2f getPosition() const;
};

#endif
