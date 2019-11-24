//
// Created by asphox on 24/11/2019.
//

#ifndef UNIJAM_LETRAIT_H
#define UNIJAM_LETRAIT_H

#include <SFML/Graphics.hpp>
#include "Game/GameScene/GameScene.h"
#include "Car.h"

class LeTrait : public sf::Drawable
{
public:

    enum class MODE
    {
        M1TO2,
        M2TO1
    };

    LeTrait(sf::RenderWindow&,GameScene&,Car* start,Car* end);
    void show(bool);
    void setMode(MODE mode)
    {
        m_mode = mode;
        if(m_mode == MODE::M1TO2)
            m_shape.setTexture(&m_texture1to2);
        else
            m_shape.setTexture(&m_texture2to1);
    }
    void update();

private:

    sf::Texture m_texture1to2;
    sf::Texture m_texture2to1;

    Car* m_carStart,*m_carEnd;
    sf::RenderWindow& m_window;
    GameScene& m_gameScene;
    sf::RectangleShape m_shape;
    float m_length;
    MODE m_mode = MODE::M1TO2;
    bool m_show = false;

    void calcLength();
    void calcAngle();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //UNIJAM_LETRAIT_H
