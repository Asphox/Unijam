//
// Created by asphox on 23/11/2019.
//

#ifndef UNIJAM_GAMEMENU_H
#define UNIJAM_GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <Options.h>

class Game;

class GameMenu : public sf::Drawable
{
public:
      GameMenu(Game*);
    void updateControllerStatus();
    void setDefault();
    void setEchec();
    void setSuccess();

private:
    Game* m_game;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::RectangleShape m_logoSFML;
    sf::RectangleShape m_logoBOX2D;
    sf::Texture m_textureSFML;
    sf::Texture m_textureBOX2D;
    sf::CircleShape m_xboxc0state,m_xboxc1state;
    sf::Text m_GameTitle;
    sf::Text m_pressKey;
    sf::Text m_pressExit;
    sf::Text m_textxboxc0state;
    sf::Text m_textxboxc1state;
    sf::View m_view;
};


#endif //UNIJAM_GAMEMENU_H
