#include <SFML/Graphics.hpp>
#include "Graphics/AnimatedSprite.h"
#include "System/Timer.h"
#include "Physics/World.h"
#include "Physics/EntityFactory.h"

#include "Game/Game.h"


int main()
{
    World world = World(-10.0f);
    EntityFactory factory = EntityFactory();
    factory.createBoxDynamic(world,400,400,380,20, 1, 1, 5);
    factory.createBoxStatic(world,175,600,50,20);
    factory.createBoxStatic(world,800-175,600,50,20);
    factory.createCircleDynamic(world, 500, 50, 10, 10, 1);
    factory.createCircleDynamic(world, 300, 30, 10, 10, 1);
    factory.createCircleDynamic(world, 680, 10, 10, 10, 1);
    Car* car1 = factory.createCar(world, 100, 300);
    //Car* car2 = factory.createCar(world, 700, 300);
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
        //car1->accelerate();
        //car1->jump();
        //car2->decelerate();
        window.clear();

        for (Entity* entityIt : world.getEntities()){
            entityIt->update();
            window.draw(*entityIt);
        }
        window.display();

    }

    /*
    sf::RenderWindow window(sf::VideoMode(1600, 720), "SFML works!");
    Game game(window);
    game.run();
*/
    return 0;
}