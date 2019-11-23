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
    window.setFramerateLimit(600);

    GameScene gameScene(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(gameScene);
        window.display();
    }

    return 0;
}