#include <SFML/Graphics.hpp>
#include "Graphics/AnimatedSprite.h"
#include "System/Timer.h"
#include "Physics/World.h"
#include "Physics/EntityFactory.h"

#include "Game/Game.h"


int main()
{

    sf::RenderWindow window(sf::VideoMode(1600, 720), "SFML works!");
    Game game(window);
    game.run();
    return 0;
}