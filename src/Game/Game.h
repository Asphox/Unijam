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
#include "Entities/Car.h"
#include "Physics/World.h"
#include "Physics/EntityFactory.h"

class Game
{
public:
    Game(sf::RenderWindow& window);
    void run();
    void stop();
    void pause();
    inline sf::RenderWindow& getWindow(){ return m_window; }
    inline sf::Font& getFont(){ return m_font; }

    enum class STATE
    {
        MENU,
        PAUSED,
        RUNNING
    }m_state = STATE::MENU;

private:
    void update();

    void pollEvent();

    sf::RenderWindow& m_window;
    sf::Font m_font;
    GameMenu m_menu;
    GameScene m_scene;
    GameController* m_controller0,*m_controller1;
    World m_world;
    Car* m_car1,*m_car2;
    Box* m_box1,*m_box2;

public:
    inline STATE getState() { return m_state; }
};


#endif //UNIJAM_GAME_H
