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
    level1 = new Level();

    //Ground level 1
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+1000, WORLD_SCENE_TOP_START_Y+500, 1000, 200));
    level1->addEntityBot(factory.createBoxStatic(m_world, WORLD_SCENE_BOT_START_X+1000, WORLD_SCENE_BOT_START_Y+500, 1000, 200));

    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+2200+2000, WORLD_SCENE_TOP_START_Y+500, 2000, 200));

    //Premier obstacle
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+1000, WORLD_SCENE_TOP_START_Y+300, 200, 50));
    level1->addEntityBot(factory.createBoxStatic(m_world, WORLD_SCENE_BOT_START_X+1000, WORLD_SCENE_BOT_START_Y+300, 200, 50));

    //Second obstacle
    std::vector<std::pair<float, float>> convex1Vertices;
    convex1Vertices.push_back(std::pair<float,float>(-300,-75));
    convex1Vertices.push_back(std::pair<float,float>(-50,75));
    convex1Vertices.push_back(std::pair<float,float>(50,75));
    convex1Vertices.push_back(std::pair<float,float>(300,-75));
    level1->addEntityTop(factory.createConvexStatic(m_world, WORLD_SCENE_TOP_START_X+2500, WORLD_SCENE_TOP_START_Y+300, convex1Vertices));
    level1->addEntityBot(factory.createConvexStatic(m_world, WORLD_SCENE_BOT_START_X+2500, WORLD_SCENE_BOT_START_Y+300, convex1Vertices));




    m_car1 = factory.createCar(m_world, WORLD_SCENE_TOP_START_X+100, WORLD_SCENE_TOP_START_Y);
    m_car2 = factory.createCar(m_world, WORLD_SCENE_BOT_START_X+100, WORLD_SCENE_BOT_START_Y);

    m_controller0 = new GameController(this,m_car1,m_car2,0);
    m_controller1 = new GameController(this,m_car2,m_car1,1);


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

        level1->drawTop(m_window);

        m_scene.selectBotScreenView();
        m_car2->update();
        newSceneCenterX = WORLD_SCENE_BOT_START_X+m_window.getSize().x/2+(m_car2->getPosition().x-(WORLD_SCENE_BOT_START_X+RELATIVE_CAR_SPAWN_X));
        if( newSceneCenterX- m_scene.getCenterBotX() >= 0 )
            m_scene.newDefaultBotCenterX(newSceneCenterX);
        m_window.draw(*m_car2);
        level1->drawBot(m_window);


        m_window.draw(m_scene);
        //m_window.draw(*m_box2);


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