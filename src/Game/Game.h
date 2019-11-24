//
// Created by asphox on 23/11/2019.
//

#ifndef UNIJAM_GAME_H
#define UNIJAM_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <Audio/Audio.h>
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

    bool m_jumpEnabled1 = true;
    bool m_jumpEnabled2 = true;

    void resetJump1();
    void startJump1();
    void resetJump2();
    void startJump2();

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

    void initStacksSpeedsTop();
    void initStacksSpeedsBot();
    void addSpeedsTop(float);
    void addSpeedsBot(float);
    float getSpeedsTopAt(unsigned int index);
    float getSpeedsBotAt(unsigned int index);

    void shockDetectedOnCar1(float intensity);
    void shockDetectedOnCar2(float intensity);

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
    Audio m_audio;
    //Box* m_box1,*m_box2;

    Timer<Game> physicsTimer;
    Timer<Game> jumpTimer;

    std::deque<float> m_passedSpeedsTop,m_passedSpeedsBot;
    int m_stackSpeedsSize = 0;

    float m_car1previousSpeedX = 0, m_car2previousX = 0;
    float m_car1speedX = 0,m_car2speedX = 0;

    float getDeltaCarTopStartWithCurrent();
    float getDeltaCarBotStartWithCurrent();
    Box* m_box1,*m_box2;
    Convex* m_convex1;

    bool m_shockCar1Processed = false;
    bool m_shockCar2Processed = false;
    unsigned int jump1 = 0;
    unsigned int jump2 = 0;

public:
    inline STATE getState() { return m_state; }
};


#endif //UNIJAM_GAME_H
