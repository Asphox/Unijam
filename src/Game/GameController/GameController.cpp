//
// Created by asphox on 23/11/2019.
//

#include "GameController.h"
#include "Game/Game.h"

GameController::GameController(Game* game, uint8_t playerID) : m_game(game), m_playerID(playerID)
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

void GameController::onInclination(float pos)
{
    std::cout << m_playerID << "|" << pos << std::endl;
}

void GameController::onJump()
{
    std::cout << m_playerID << "jump" << std::endl;
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
    std::cout << m_playerID << " decelerate" << "|" << pos << std::endl;
}

void GameController::onAccelerate(float pos)
{
    std::cout << m_playerID << " accelerate" << "|" << pos << std::endl;
}