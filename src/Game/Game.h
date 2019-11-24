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
#include "System/Timer.h"
#include "Entities/Level.h"

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
        RUNNING,
        SUCCES,
        ECHEC
    }m_state = STATE::MENU;

    enum class LEVEL
    {
        ONE,
        TWO
    }m_currentLevel = LEVEL::TWO;

private:
    void updateGraphics();
    void updatePhysics();

    void pollEvent();

    void reset();

    void checkDeath();

    sf::RenderWindow& m_window;
    sf::Font m_font;
    GameMenu m_menu;
    GameScene m_scene;
    GameController* m_controller0, *m_controller1;
    Level* level;
    World m_world;
    Car* m_car1,*m_car2;
    std::vector<Box*> m_boxsTop;
    std::vector<Box*> m_boxsBot;
    //Box* m_box1,*m_box2;

    Timer<Game> physicsTimer;

    float m_car1previousSpeedX = 0, m_car2previousX = 0;
    float m_car1speedX = 0,m_car2speedX = 0;

    float getDeltaCarTopStartWithCurrent();
    float getDeltaCarBotStartWithCurrent();
    Box* m_box1,*m_box2;
    Convex* m_convex1;

public:
    inline STATE getState() { return m_state; }
};


#endif //UNIJAM_GAME_H
