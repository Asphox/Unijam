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
    Convex* m_carTop;
    Convex* m_carBot;
    Circle* m_leftWheel;
    Circle* m_rightWheel;
    b2WheelJoint* m_leftJoint;
    b2WheelJoint* m_rightJoint;

    float m_maxSpeed = 10;
    float m_incrementingStep = 0.05;


public:
    Car(Convex* bodyTop, Convex* bodyBot, Circle* leftWheel, Circle* rightWhee, b2WheelJoint* leftJoint, b2WheelJoint* rightJoint);
    void update() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void accelerate();
    void decelerate();
};

#endif
