#include <SFML/Graphics.hpp>
#include "Graphics/AnimatedSprite.h"
#include "System/Timer.h"
#include "System/Thread.h"

#include "Tiers/Box2D/Box2D.h"

#include "Game/GameScene/GameScene.h"


int main()
{
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    std::cout.sync_with_stdio(false);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    float z = 1.0f;

    GameScene gameScene(window);
    //gameScene.res

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if( event.type == sf::Event::KeyPressed)
            {
                if( event.key.code == sf::Keyboard::Up )
                {
                    z += 0.1;
                    gameScene.setZoomTopScreen(z);
                }
                if( event.key.code == sf::Keyboard::Down )
                {
                    z -= 0.1;
                    gameScene.setZoomTopScreen(z);
                }
            }
        }
        window.clear();
        window.draw(gameScene);
        window.display();

        //gameScene.translateLeftBotScreen(0.1);
        //gameScene.translateRightTopScreen(0.1);
    }

    return 0;
}