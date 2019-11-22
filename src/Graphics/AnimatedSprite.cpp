//
// Created by asphox on 19/11/2019.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(const sf::Texture& texture, uint16_t nbrSubTextures)
: sf::Sprite(texture)
, m_nbrSubTextures(nbrSubTextures)
{

}

AnimatedSprite::AnimatedSprite(const sf::Texture& texture, uint16_t nbrSubTextures, uint16_t updatePeriodMS)
: sf::Sprite(texture)
, m_nbrSubTextures(nbrSubTextures)
, m_updatePeriodMultiplier(updatePeriodMS)
{

}

void AnimatedSprite::setTexture(const sf::Texture &texture)
{
    sf::Sprite::setTexture(texture,false);
    m_currentSubTexture.left = 0;
    m_currentSubTexture.top = 0;
    m_currentSubTexture.width = texture.getSize().x/m_nbrSubTextures;
    m_currentSubTexture.height = texture.getSize().y;
    setTextureRect(m_currentSubTexture);
}

#include <SFML/System.hpp>
#include <iostream>
void AnimatedSprite::onTickAnimation()
{
    static unsigned int ticks = 0;
    static sf::Clock clock;
    if(ticks >= m_updatePeriodMultiplier)
    {
        std::cout << clock.getElapsedTime().asMilliseconds() << std::endl;
        next();
        ticks = 0;
        clock.restart();
    }
    ++ticks;
}

void AnimatedSprite::next()
{
    ++m_currentSubTextureIndex;
    if(m_currentSubTextureIndex == m_nbrSubTextures)
        m_currentSubTextureIndex = 0;

    m_currentSubTexture.left = m_currentSubTextureIndex*m_currentSubTexture.width;
    setTextureRect(m_currentSubTexture);
}

void AnimatedSprite::previous()
{
    if(m_currentSubTextureIndex == 0)
        m_currentSubTextureIndex = m_nbrSubTextures;
    --m_currentSubTextureIndex;

    m_currentSubTexture.left = m_currentSubTextureIndex*m_currentSubTexture.width;
    setTextureRect(m_currentSubTexture);
}
