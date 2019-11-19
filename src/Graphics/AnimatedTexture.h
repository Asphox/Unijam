//
// Created by asphox on 19/11/2019.
//

#ifndef UNIJAM_ANIMATEDTEXTURE_H
#define UNIJAM_ANIMATEDTEXTURE_H

#include <SFML/Graphics/Texture.hpp>

class AnimatedTexture : public sf::Texture
{
public:
    AnimatedTexture() = default;
    AnimatedTexture(uint16_t updatePeriodMS = 0);

    bool loadFromFile(const std::string& filename);

};


#endif //UNIJAM_ANIMATEDTEXTURE_H
