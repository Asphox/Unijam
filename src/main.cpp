#include <SFML/Graphics.hpp>
#include "Graphics/AnimatedSprite.h"
#include "System/Timer.h"
#include "System/Thread.h"

#include "Tiers/Box2D/Box2D.h"

#include "Game/Game.h"


int main()
{
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    std::cout.sync_with_stdio(false);
    sf::RenderWindow window(sf::VideoMode(1600, 720), "SFML works!");

    Game game(window);

    game.run();

    //window.setFramerateLimit(60);
/*
    float z = 1.0f;

    GameScene gameScene(window);
    GameController gameController_0(nullptr,0);
    GameController gameController_1(nullptr,1);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if( event.type == sf::Event::KeyPressed)
            {
                if( event.key.code == sf::Keyboard::PageUp )
                {
                    z += 0.1;
                    gameScene.setZoomBotScreen(z);
                }
                if( event.key.code == sf::Keyboard::PageDown )
                {
                    z -= 0.1;
                    gameScene.setZoomBotScreen(z);
                }
                if( event.key.code == sf::Keyboard::Left )
                {
                    gameScene.translateLeftBotScreen(10);
                }
                if( event.key.code == sf::Keyboard::Right )
                {
                    gameScene.translateRightBotScreen(10);
                }
                if( event.key.code == sf::Keyboard::Up )
                {
                    gameScene.translateUpBotScreen(10);
                }
                if( event.key.code == sf::Keyboard::Down )
                {
                    gameScene.translateDownBotScreen(10);
                }
            }

            gameController_0.processInput(event);
            gameController_1.processInput(event);
        }
        window.clear();
        window.draw(gameScene);
        window.display();

        //gameScene.translateLeftBotScreen(0.1);
        //gameScene.translateRightTopScreen(0.1);
    }
    */

    return 0;
}