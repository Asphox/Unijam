//
// Created by asphox on 23/11/2019.
//

#ifndef UNIJAM_GAME_H
#define UNIJAM_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameScene/GameMenu.h"
#include "GameScene/GameScene.h"
#include "GameController/GameController.h"

class Game
{
public:
    Game(sf::RenderWindow& window);
    void run();
    void stop();
    void pause();
    inline sf::RenderWindow& getWindow(){ return m_window; }
    inline sf::Font& getFont(){ return m_font; }

private:
    enum class STATE
    {
        MENU,
        PAUSED,
        RUNNING
    }m_state = STATE::MENU;

    void update();

    void pollEvent();

    sf::RenderWindow& m_window;
    sf::Font m_font;
    GameMenu m_menu;
    GameScene m_scene;
    GameController m_controller0,m_controller1;
};


#endif //UNIJAM_GAME_H
