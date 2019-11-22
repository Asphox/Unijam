//
// Created by asphox on 19/11/2019.
//

#ifndef UNIJAM_ANIMATEDSPRITE_H
#define UNIJAM_ANIMATEDSPRITE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class AnimatedSprite : public sf::Sprite
{
public:
    AnimatedSprite() = default;
    AnimatedSprite(const sf::Texture&, uint16_t nbrSubTextures);
    AnimatedSprite(const sf::Texture&, uint16_t nbrSubTextures, uint16_t updatePeriodMS);

    void next();
    void previous();

    void onTickAnimation();

    void setTexture(const sf::Texture& texture);

    inline void setNbrSubTextures(uint16_t nbr) { m_nbrSubTextures = nbr; }
    inline void setUpdatePeriodMultiplier(uint16_t multiplier) { m_updatePeriodMultiplier = multiplier; }

private:

    void init();

    uint16_t m_nbrSubTextures = 1;
    uint16_t m_updatePeriodMultiplier = 1;
    uint16_t m_currentSubTextureIndex = 0;
    sf::IntRect m_currentSubTexture;
};


#endif //UNIJAM_ANIMATEDSPRITE_H
