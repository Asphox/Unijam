#include <SFML/Graphics.hpp>
#include "Graphics/AnimatedSprite.h"
#include "System/Timer.h"
#include "System/Thread.h"


int main()
{
    std::cout.sync_with_stdio(false);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(600);

    AnimatedSprite sprite;
    AnimatedSprite sprite2;
    AnimatedSprite sprite3;
    sprite.setUpdatePeriodMultiplier(10);

    sf::Texture texture;
    texture.loadFromFile("a.png");
    sprite.setNbrSubTextures(5);
    sprite.setTexture(texture);

    sprite2 = sprite;
    sprite2.move(100,0);
    sprite3 = sprite;
    sprite3.move(200,0);


    Timer<AnimatedSprite> timer(10);
    timer.addCallBack(&sprite,&AnimatedSprite::onTickAnimation);
    timer.addCallBack(&sprite2,&AnimatedSprite::onTickAnimation);
    timer.addCallBack(&sprite3,&AnimatedSprite::onTickAnimation);
    timer.start();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyReleased)
            {
                static bool caca = true;
                if(caca)
                    timer.stop();
                else
                    timer.start();
                caca = !caca;
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);
        window.display();
    }

    return 0;
}