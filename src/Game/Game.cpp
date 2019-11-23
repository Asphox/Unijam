//
// Created by asphox on 23/11/2019.
//

#include "Game.h"

Game::Game(sf::RenderWindow& window) : m_menu(this), m_world(-10.0f), m_scene(window), m_window(window), physicsTimer(2)
{
    m_state = STATE::MENU;
    if( !m_font.loadFromFile("Assets/Arial.ttf") )
    {
        std::cerr << "CAN'T LOAD FONT" << std::endl;
    }
    physicsTimer.addCallBack(this,&Game::updatePhysics);
}

void Game::reset()
{
    EntityFactory factory = EntityFactory();
    factory.createBoxDynamic(m_world,400,400,380,20, 1, 1, 5);
    m_boxsTop.push_back(factory.createBoxStatic(m_world,WORLD_SCENE_TOP_START_X,WORLD_SCENE_TOP_START_Y+500/2,1300,20));
    m_boxsTop.push_back(factory.createBoxStatic(m_world,WORLD_SCENE_TOP_START_X+2000,WORLD_SCENE_TOP_START_Y+500/2,500,20));
    m_boxsBot.push_back(factory.createBoxStatic(m_world,WORLD_SCENE_BOT_START_X,WORLD_SCENE_BOT_START_Y+500/2,3000,20));
    m_boxsBot.push_back(factory.createBoxStatic(m_world,WORLD_SCENE_BOT_START_X+3400,WORLD_SCENE_BOT_START_Y+500/2,2500,20));
    factory.createCircleDynamic(m_world, 500, 50, 10, 10, 1);
    factory.createCircleDynamic(m_world, 300, 30, 10, 10, 1);
    factory.createCircleDynamic(m_world, 680, 10, 10, 10, 1);
    m_car1 = factory.createCar(m_world, WORLD_SCENE_TOP_START_X+RELATIVE_CAR_SPAWN_X, WORLD_SCENE_TOP_START_Y+RELATIVE_CAR_SPAWN_Y);
    m_car2 = factory.createCar(m_world, WORLD_SCENE_BOT_START_X+RELATIVE_CAR_SPAWN_X, WORLD_SCENE_BOT_START_Y+RELATIVE_CAR_SPAWN_Y);

    m_controller0 = new GameController(this,m_car1,m_car2,0);
    m_controller1 = new GameController(this,m_car2,m_car1,1);
}

void Game::run()
{
    reset();
    while (m_window.isOpen())
    {
        pollEvent();
        updateGraphics();
        m_controller0->perpetualCheck();
        m_controller1->perpetualCheck();
    }
}

void Game::pollEvent()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
        m_controller0->processInput(event);
        m_controller1->processInput(event);
    }
}

void Game::updateGraphics()
{
    m_window.clear();
    if(m_state == STATE::MENU || m_state == STATE::PAUSED)
    {
        physicsTimer.stop();
        m_menu.updateControllerStatus();
        m_window.draw(m_menu);
    }
    else if(m_state == STATE::RUNNING)
    {
        m_scene.selectTopScreenView();
        m_car1->update();
        float newSceneCenterX = WORLD_SCENE_TOP_START_X+m_window.getSize().x/2+(m_car1->getPosition().x-(WORLD_SCENE_TOP_START_X+RELATIVE_CAR_SPAWN_X));
        if( newSceneCenterX- m_scene.getCenterTopX() >= 0 )
            m_scene.newDefaultTopCenterX(newSceneCenterX);
        m_window.draw(*m_car1);
        for(auto it : m_boxsTop)
        {
            m_window.draw(*it);
        }
        m_car2->update();
        m_scene.selectBotScreenView();
        newSceneCenterX = WORLD_SCENE_BOT_START_X+m_window.getSize().x/2+(m_car2->getPosition().x-(WORLD_SCENE_BOT_START_X+RELATIVE_CAR_SPAWN_X));
        if( newSceneCenterX- m_scene.getCenterBotX() >= 0 )
            m_scene.newDefaultBotCenterX(newSceneCenterX);
        m_window.draw(*m_car2);
        for(auto it : m_boxsBot)
        {
            m_window.draw(*it);
        }
        m_window.draw(m_scene);

        std::cout << m_car1->getPosition().y  << std::endl;

        if( -m_car1->getPosition().y > WORLD_SCENE_TOP_START_Y+m_window.getSize().y/2)
            m_state = STATE::MENU;

        if( -m_car2->getPosition().y > WORLD_SCENE_BOT_START_Y+m_window.getSize().y/2)
            m_state = STATE::MENU;

    }
    m_window.display();
}

void Game::updatePhysics()
{
    static int i = 0;
    if( i == 10 )
    {
        m_car1->accelerate(0.01);
        m_car2->accelerate(0.01);
        i=0;
    }
    m_world.step(PHY_TIME_STEP);
    i++;
}

void Game::pause()
{
    if(m_state == STATE::MENU || m_state == STATE::PAUSED)
    {
        m_state = STATE::RUNNING;
        physicsTimer.start();
    }
    else if(m_state == STATE::RUNNING)
    {
        m_state = STATE::PAUSED;
        physicsTimer.stop();
    }
}

void Game::stop()
{
    if(m_state == STATE::MENU || m_state == STATE::PAUSED)
        m_window.close();
}

float Game::getDeltaCarTopStartWithCurrent()
{
    return (m_car1->getPosition().x - (WORLD_SCENE_TOP_START_X+RELATIVE_CAR_SPAWN_X));
}

float Game::getDeltaCarBotStartWithCurrent()
{
    return (m_car2->getPosition().x - (WORLD_SCENE_BOT_START_X+RELATIVE_CAR_SPAWN_X));
}