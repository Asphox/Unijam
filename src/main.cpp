#include <SFML/Graphics.hpp>
#include "Graphics/AnimatedSprite.h"
#include "System/Timer.h"
#include "Physics/World.h"
#include "Physics/EntityFactory.h"


int main()
{
    World world = World(-10.0f);
    EntityFactory factory = EntityFactory();
    factory.createBoxDynamic(world,400,100,380,20, 1, 1, 5);
    factory.createBoxStatic(world,175,600,50,20);
    factory.createBoxStatic(world,800-175,600,50,20);
    factory.createCircleDynamic(world, 500, 50, 10, 10, 1);
    factory.createCircleDynamic(world, 300, 30, 10, 10, 1);
    factory.createCircleDynamic(world, 680, 10, 10, 10, 1);
    factory.createCar(world, 200, 100);
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
        world.step(timeStep);
        window.clear();
        for (Entity* entityIt : world.getEntities()){
            entityIt->update();
            window.draw(*entityIt);
        }
        window.display();
    }

    return 0;
}