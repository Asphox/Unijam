//
// Created by nayht on 23/11/2019.
//

#include "Car.h"


Car::Car(b2Body* vehicleBody, Convex* bodyTop, Convex* bodyBot, Circle* leftWheel, Circle* rightWheel, b2WheelJoint* leftJoint, b2WheelJoint* rightJoint) {
    m_vehiclePhysicalBody = vehicleBody;
    m_carTop = bodyTop;
    m_carBot = bodyBot;
    m_leftWheel = leftWheel;
    m_rightWheel = rightWheel;
    m_leftJoint = leftJoint;
    m_rightJoint = rightJoint;
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

void Car::accelerate(){
    if (m_leftJoint->GetMotorSpeed() > -m_maxVelocity){
        m_leftJoint->SetMotorSpeed(m_leftJoint->GetMotorSpeed() - m_linearVelocityIncrement);
        if (!m_leftJoint->GetMotorSpeed() > -m_maxVelocity) {
            m_leftJoint->SetMotorSpeed(-m_maxVelocity);
        }
    }
    if (m_rightJoint->GetMotorSpeed() > -m_maxVelocity){
        m_rightJoint->SetMotorSpeed(m_rightJoint->GetMotorSpeed() - m_linearVelocityIncrement);
        if (!m_rightJoint->GetMotorSpeed() > -m_maxVelocity) {
            m_rightJoint->SetMotorSpeed(-m_maxVelocity);
        }
    }
    printf("right: %f\n", m_rightJoint->GetMotorSpeed());
}

void Car::decelerate(){
    if (m_leftJoint->GetMotorSpeed() < m_maxVelocity){
        m_leftJoint->SetMotorSpeed(m_leftJoint->GetMotorSpeed() + m_linearVelocityIncrement);
        if (!m_leftJoint->GetMotorSpeed() < m_maxVelocity) {
            m_leftJoint->SetMotorSpeed(m_maxVelocity);
        }
    }
    if (m_rightJoint->GetMotorSpeed() < m_maxVelocity){
        m_rightJoint->SetMotorSpeed(m_rightJoint->GetMotorSpeed() + m_linearVelocityIncrement);
        if (!m_rightJoint->GetMotorSpeed() < m_maxVelocity) {
            m_rightJoint->SetMotorSpeed(m_maxVelocity);
        }
    }
}

void Car::rotate(float userValue){
    m_vehiclePhysicalBody->ApplyAngularImpulse(userValue * m_angularVelocityCoefficient, false);
}


void Car::jump(){
    m_vehiclePhysicalBody->ApplyLinearImpulseToCenter(b2Vec2(0,m_jumpVerticalCoefficient), true);
}

