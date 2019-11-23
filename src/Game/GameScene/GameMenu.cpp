//
// Created by asphox on 23/11/2019.
//

#include "GameMenu.h"
#include "Game/Game.h"

GameMenu::GameMenu(Game* game) : m_game(game)
{
    m_view.setCenter(sf::Vector2f(WORLD_MENU_START_X+game->getWindow().getSize().x/2,WORLD_MENU_START_Y+game->getWindow().getSize().y/2));
    m_view.setSize(sf::Vector2f(game->getWindow().getSize().x,game->getWindow().getSize().y));
    m_view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));

    m_GameTitle.setString("MomentVRUM !");
    m_GameTitle.setFont(game->getFont());
    m_GameTitle.setScale(sf::Vector2f(2,2));
    m_GameTitle.setPosition(WORLD_MENU_START_X+600,WORLD_MENU_START_Y+100);

    m_pressKey.setString("Press start to play ...");
    m_pressKey.setFont(game->getFont());
    m_pressKey.setScale(sf::Vector2f(0.8,0.8));
    m_pressKey.setPosition(WORLD_MENU_START_X+700,WORLD_MENU_START_Y+400);

    m_pressExit.setString("Press select to exit ...");
    m_pressExit.setFont(game->getFont());
    m_pressExit.setScale(sf::Vector2f(0.8,0.8));
    m_pressExit.setPosition(WORLD_MENU_START_X+700,WORLD_MENU_START_Y+600);

    m_textxboxc0state.setString("Controller 1 : ");
    m_textxboxc0state.setFont(game->getFont());
    m_textxboxc0state.setScale(sf::Vector2f(0.8,0.8));
    m_textxboxc0state.setPosition(WORLD_MENU_START_X+50,WORLD_MENU_START_Y+50);

    m_xboxc0state.setPosition(WORLD_MENU_START_X+200,WORLD_MENU_START_Y+60);
    m_xboxc0state.setRadius(7);

    m_textxboxc1state.setString("Controller 2 : ");
    m_textxboxc1state.setFont(game->getFont());
    m_textxboxc1state.setScale(sf::Vector2f(0.8,0.8));
    m_textxboxc1state.setPosition(WORLD_MENU_START_X+50,WORLD_MENU_START_Y+100);

    m_xboxc1state.setPosition(WORLD_MENU_START_X+200,WORLD_MENU_START_Y+110);
    m_xboxc1state.setRadius(7);

}

void GameMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.setView(m_view);
    target.draw(m_GameTitle);
    target.draw(m_pressKey);
    target.draw(m_pressExit);
    target.draw(m_textxboxc0state);
    target.draw(m_textxboxc1state);
    target.draw(m_xboxc0state);
    target.draw(m_xboxc1state);

}

void GameMenu::updateControllerStatus()
{
    if( sf::Joystick::isConnected(0) )
        m_xboxc0state.setFillColor(sf::Color::Green);
    else
        m_xboxc0state.setFillColor(sf::Color::Red);

    if( sf::Joystick::isConnected(1) )
        m_xboxc1state.setFillColor(sf::Color::Green);
    else
        m_xboxc1state.setFillColor(sf::Color::Red);
}
