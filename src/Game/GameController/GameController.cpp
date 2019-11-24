//
// Created by asphox on 23/11/2019.
//

#include "GameController.h"
#include "Game/Game.h"

GameController::GameController(Game* game, Car* car1, uint8_t playerID) : m_game(game), m_car(car1),  m_playerID(playerID)
{
    sf::Joystick::update();
    m_xboxMode = sf::Joystick::isConnected(playerID);
}

#include <iostream>


void GameController::processInput(sf::Event &event)
{
    static long int i = 0;
    if( m_xboxMode && sf::Joystick::isConnected(m_playerID) )
    {
        switch(event.type)
        {
            case sf::Event::JoystickMoved :
                m_lastEventWasButtonPressed = false;
                if( event.joystickMove.joystickId == m_playerID )
                {
                    if( event.joystickMove.axis == sf::Joystick::X )
                        onInclination(event.joystickMove.position);
                    if( event.joystickMove.axis == sf::Joystick::Z )
                    {
                        onDecelerate((event.joystickMove.position+100.0)/2.0);
                    }
                    if(event.joystickMove.axis == sf::Joystick::R)
                    {
                        onAccelerate((event.joystickMove.position+100.0)/2.0);
                    }

                }
                break;

            case sf::Event::JoystickButtonPressed :
                if( event.joystickButton.joystickId == m_playerID )
                {
                    switch(event.joystickButton.button)
                    {
                        case XBOXC_BUTTON_A_ID : onJump(); break;
                        case XBOXC_BUTTON_START_ID : onPause(); break;
                        case XBOXC_BUTTON_SELECT_ID : onQuit(); break;
                        default: std::cout << event.joystickButton.button << std::endl;
                    }

                }
                break;

        }
    }
    i++;
}

void GameController::perpetualCheck()
{
    if( m_game->getState() == Game::STATE::RUNNING && m_xboxMode )
    {
        onInclination(sf::Joystick::getAxisPosition(m_playerID, sf::Joystick::X));
        float acc = (sf::Joystick::getAxisPosition(m_playerID, sf::Joystick::R)+100.0)/2.0;
        if( acc > 10 )
        {
            onAccelerate(acc);
        }
        float dec = (sf::Joystick::getAxisPosition(m_playerID, sf::Joystick::Z)+100.0)/2.0;
        if( dec > 10 )
        {
            onDecelerate(dec);
        }
    }
}

void GameController::onInclination(float pos)
{
    if( m_game->getState() == Game::STATE::RUNNING )
    {
        if(m_car)
        {
            m_car->rotate(-pos);
        }
    }

}

void GameController::onJump()
{
    if( ((m_playerID == 0 && m_game->m_jumpEnabled1) || ((m_playerID == 1 && m_game->m_jumpEnabled2))) && (m_game->getState() == Game::STATE::RUNNING) )
    {
        if(m_playerID == 0) {
            m_game->startJump1();
            m_game->m_audio.playSound(Audio::SOUND::CAR1JUMP, 30.0f);
        }
        if(m_playerID == 1) {
            m_game->startJump2();
            m_game->m_audio.playSound(Audio::SOUND::CAR2JUMP, 30.0f);
        }
        if(m_car)
            m_car->jump();
    }
}

void GameController::onPause()
{
    m_game->pause();
}

void GameController::onQuit()
{
    m_game->stop();
}

void GameController::onDecelerate(float pos)
{
    if( m_game->getState() == Game::STATE::RUNNING )
    {
        if(m_car)
        {
            m_car->decelerate(pos);
        }
    }

}

void GameController::onAccelerate(float pos)
{
    if( m_game->getState() == Game::STATE::RUNNING )
    {
        if(m_car)
            m_car->accelerate(pos);
        if (m_playerID == 0) {
            m_game->m_audio.modifySound(Audio::SOUND::CAR1SPEED, pos/4+20, pos/150);
        }
        else {
            m_game->m_audio.modifySound(Audio::SOUND::CAR2SPEED, pos/4+20, pos/150);
        }
    }
}