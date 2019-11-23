//
// Created by nayht on 23/11/2019.
//

#include "Car.h"


Car::Car(b2Body* vehicleBody, Convex* bodyTop, Convex* bodyBot, Circle* leftWheel, Circle* rightWheel, b2WheelJoint* leftJoint, b2WheelJoint* rightJoint, b2WheelJoint* compensatingJoint1, b2WheelJoint* compensatingJoint2) {
    m_vehiclePhysicalBody = vehicleBody;
    m_carTop = bodyTop;
    m_carBot = bodyBot;
    m_leftWheel = leftWheel;
    m_rightWheel = rightWheel;
    m_leftJoint = leftJoint;
    m_rightJoint = rightJoint;
    m_compensatingJoint1 = compensatingJoint1;
    m_compensatingJoint2 = compensatingJoint2;
}

void Car::update() {
    m_carBot->update();
    m_carTop->update();
    m_leftWheel->update();
    m_rightWheel->update();
}

void Car::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    m_carBot->draw(target, states);
    m_carTop->draw(target, states);
    m_leftWheel->draw(target, states);
    m_rightWheel->draw(target, states);
}

void Car::accelerate(float f){
    if (m_leftJoint->GetMotorSpeed() > -m_maxVelocity){
        m_leftJoint->SetMotorSpeed(m_leftJoint->GetMotorSpeed() - m_linearVelocityIncrement*(f/100.0));
        if (!(m_leftJoint->GetMotorSpeed() > -m_maxVelocity)) {
            m_leftJoint->SetMotorSpeed(-m_maxVelocity);
        }
    }
    m_compensatingJoint1->SetMotorSpeed(-m_leftJoint->GetMotorSpeed());
    if (m_rightJoint->GetMotorSpeed() > -m_maxVelocity){
        m_rightJoint->SetMotorSpeed(m_rightJoint->GetMotorSpeed() - m_linearVelocityIncrement);
        if (!(m_rightJoint->GetMotorSpeed() > -m_maxVelocity)) {
            m_rightJoint->SetMotorSpeed(-m_maxVelocity);
        }
    }
    m_compensatingJoint2->SetMotorSpeed(-m_rightJoint->GetMotorSpeed());
    //printf("right: %f\n", m_rightJoint->GetMotorSpeed());
}

void Car::decelerate(float f){
    if (m_leftJoint->GetMotorSpeed() < m_maxVelocity){
        m_leftJoint->SetMotorSpeed(m_leftJoint->GetMotorSpeed() + m_linearVelocityIncrement*(f/100.0));
        if (!(m_leftJoint->GetMotorSpeed() < m_maxVelocity)) {
            m_leftJoint->SetMotorSpeed(m_maxVelocity);
        }
    }
    m_compensatingJoint1->SetMotorSpeed(-m_leftJoint->GetMotorSpeed());
    if (m_rightJoint->GetMotorSpeed() < m_maxVelocity){
        m_rightJoint->SetMotorSpeed(m_rightJoint->GetMotorSpeed() + m_linearVelocityIncrement);
        if (!(m_rightJoint->GetMotorSpeed() < m_maxVelocity)) {
            m_rightJoint->SetMotorSpeed(m_maxVelocity);
        }
    }
    m_compensatingJoint2->SetMotorSpeed(-m_rightJoint->GetMotorSpeed());
}

void Car::rotate(float userValue){
    m_vehiclePhysicalBody->ApplyAngularImpulse(userValue * m_angularVelocityCoefficient, false);
}


void Car::jump(){
    m_vehiclePhysicalBody->ApplyLinearImpulseToCenter(b2Vec2(0,m_jumpVerticalCoefficient), true);
}

sf::Vector2f Car::getPosition() const
{
    sf::Vector2f r;
    r.x = m_vehiclePhysicalBody->GetWorldCenter().x;
    r.y = m_vehiclePhysicalBody->GetWorldCenter().y;
    return r;
}

