//
// Created by asphox on 22/11/2019.
//

#ifndef UNIJAM_GAMESCENE_H
#define UNIJAM_GAMESCENE_H

#include <SFML/Graphics.hpp>
#include <Options.h>

class GameScene : public sf::Drawable
{
public:
    GameScene(sf::RenderWindow& window);

    void translateLeftTopScreen(unsigned int move);
    void translateRightTopScreen(unsigned int move);
    void translateLeftBotScreen(unsigned int move);
    void translateRightBotScreen(unsigned int move);

private:
    sf::View m_viewTop,m_viewBot;

    sf::RectangleShape m_test,m_test2;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //UNIJAM_GAMESCENE_H
