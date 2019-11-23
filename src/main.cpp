#include <SFML/Graphics.hpp>
#include "Graphics/AnimatedSprite.h"
#include "System/Timer.h"
#include "Physics/World.h"
#include "Physics/EntityFactory.h"


int main()
{
    World world = World(-10.0f);
    EntityFactory factory = EntityFactory();
    factory.createBoxStatic(world,100,100,50,20);
    factory.createBoxStatic(world,100,-100,50,20);
    factory.createBoxStatic(world,-100,100,50,20);
    factory.createBoxStatic(world,-100,-100,50,20);
    float32 timeStep = 1.0f / 60.0f;

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
        world.getWorld().Step(timeStep, 1, 1);
        for (Entity* entityIt : world.getEntities()){
            entityIt->update();
            window.draw(*entityIt);
        }
        window.clear();
        window.display();
    }

    return 0;
}