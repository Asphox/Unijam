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

    void translateLeftTopScreen(float move);
    void translateRightTopScreen(float move);
    void translateUpTopScreen(float move);
    void translateDownTopScreen(float move);
    void translateLeftBotScreen(float move);
    void translateRightBotScreen(float move);
    void translateUpBotScreen(float move);
    void translateDownBotScreen(float move);

    void setZoomTopScreen(float zoom);
    void setZoomBotScreen(float zoom);

    void resetZoomTopScreen();
    void resetZoomBotScreen();

private:
    sf::View m_viewTop,m_viewBot;
    sf::Vector2f m_viewTopNonZoomedCenter, m_viewBotNonZoomedCenter;
    float m_currentZoomTop = 1.0f, m_currentZoomBot = 1.0f;

    sf::RectangleShape m_test,m_test2;

    sf::RectangleShape m_splitScreenSeparation;
    sf::Vector2f m_defaultViewSize;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //UNIJAM_GAMESCENE_H
