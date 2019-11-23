//
// Created by asphox on 23/11/2019.
//

#include "Game.h"

Game::Game(sf::RenderWindow& window) : m_menu(this), m_controller0(this,0), m_controller1(this,1), m_scene(window), m_window(window)
{
    m_state = STATE::MENU;
    if( !m_font.loadFromFile("Assets/Arial.ttf") )
    {
        std::cerr << "CAN'T LOAD FONT" << std::endl;
    }
}

void Game::run()
{
    while (m_window.isOpen())
    {
        pollEvent();
        update();
    }
}

void Game::pollEvent()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();

        m_controller0.processInput(event);
        m_controller1.processInput(event);
    }
}

void Game::update()
{
    m_window.clear();
    if(m_state == STATE::MENU || m_state == STATE::PAUSED)
    {
        m_menu.updateControllerStatus();
        m_window.draw(m_menu);
    }
    else if(m_state == STATE::RUNNING)
    {
        m_window.draw(m_scene);
    }
    m_window.display();
}

void Game::pause()
{
    if(m_state == STATE::MENU || m_state == STATE::PAUSED) m_state = STATE::RUNNING;
    else if(m_state == STATE::RUNNING) m_state = STATE::PAUSED;
}

void Game::stop()
{
    if(m_state == STATE::MENU || m_state == STATE::PAUSED)
        m_window.close();
}