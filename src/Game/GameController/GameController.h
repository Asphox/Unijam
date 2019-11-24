//
// Created by asphox on 23/11/2019.
//

#ifndef UNIJAM_GAMECONTROLLER_H
#define UNIJAM_GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include <Options.h>
#include <Entities/Car.h>
class Game;

class GameController
{
public:
    GameController(Game*,Car*,uint8_t playerID);
    void onAccelerate(float pos);
    void onDecelerate(float pos);
    void onInclination(float pos); //-100 <-> 100
    void onJump();
    void onPause();
    void onQuit();

    void processInput(sf::Event& event);
    void perpetualCheck();

private:
    int m_playerID;

    bool m_lastEventWasButtonPressed = false;
    bool m_xboxMode;

    Game* m_game;
    Car* m_car;
};


#endif //UNIJAM_GAMECONTROLLER_H
