//
// Created by asphox on 22/11/2019.
//

#ifndef UNIJAM_GAMESCENE_H
#define UNIJAM_GAMESCENE_H

#include <SFML/Graphics.hpp>
#include <Options.h>
#include "Entities/Car.h"
#include "Physics/Entity.h"

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

    void newDefaultTopCenterX(float x);
    void newDefaultBotCenterX(float x);

    void setZoomTopScreen(float zoom);
    void setZoomBotScreen(float zoom);

    void selectTopScreenView();
    void selectBotScreenView();
    void selectWindowView();

    void resetZoomTopScreen();
    void resetZoomBotScreen();

    inline void setTopScreenEntitiesToDraw(std::vector<Entity*>* entities ){ m_topScreenEntities = entities; }
    inline void setBotScreenEntitiesToDraw(std::vector<Entity*>* entities ){ m_botScreenEntities = entities; }

    inline float getCenterTopX(){ return m_viewTop.getCenter().x; }
    inline float getCenterBotX(){ return m_viewBot.getCenter().x; }


private:
    sf::View m_viewTop,m_viewBot;
    sf::Vector2f m_viewTopNonZoomedCenter, m_viewBotNonZoomedCenter;
    float m_currentZoomTop = 1.0f, m_currentZoomBot = 1.0f;

    sf::RenderWindow& m_window;

    sf::RectangleShape m_splitScreenSeparation;
    sf::Vector2f m_defaultViewSize;

    std::vector<Entity*>* m_topScreenEntities = nullptr;
    std::vector<Entity*>* m_botScreenEntities = nullptr;

    Car* m_car1,*m_car2;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //UNIJAM_GAMESCENE_H
