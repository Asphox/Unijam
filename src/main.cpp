#include <SFML/Graphics.hpp>
#include "Graphics/AnimatedSprite.h"
#include "System/Timer.h"
#include "System/Thread.h"
#include "Physics/World.h"


int main()
{
    World world = World(-10.0f);
    std::vector<Entity*>& bodies = world.getEntities();

    std::cout.sync_with_stdio(false);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(600);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }

    return 0;
}