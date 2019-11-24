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
    m_world.clear();
    EntityFactory factory = EntityFactory();

    /** Level 1 **/
    level1 = new Level(10000);
    //Ground level 1
    level1->addEntityTop(factory.createCircleDynamic(m_world, WORLD_SCENE_TOP_START_X + 100, WORLD_SCENE_TOP_START_Y+100, 25, 1, 0.5f));
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+1000, WORLD_SCENE_TOP_START_Y+500, 1000, 200));
    level1->addEntityBot(factory.createBoxStatic(m_world, WORLD_SCENE_BOT_START_X+1000, WORLD_SCENE_BOT_START_Y+500, 1000, 200));
    //Premier obstacle
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+1000, WORLD_SCENE_TOP_START_Y+300, 200, 50));
    level1->addEntityBot(factory.createBoxStatic(m_world, WORLD_SCENE_BOT_START_X+1000, WORLD_SCENE_BOT_START_Y+300, 200, 50));
    //Second obstacle
    std::vector<std::pair<float, float>> convex1Vertices;
    convex1Vertices.push_back(std::pair<float,float>(-400,-75));
    convex1Vertices.push_back(std::pair<float,float>(-50,75));
    convex1Vertices.push_back(std::pair<float,float>(50,75));
    convex1Vertices.push_back(std::pair<float,float>(400,-75));
    level1->addEntityTop(factory.createConvexStatic(m_world, WORLD_SCENE_TOP_START_X+2600, WORLD_SCENE_TOP_START_Y+300, convex1Vertices));
    level1->addEntityBot(factory.createConvexStatic(m_world, WORLD_SCENE_BOT_START_X+2600, WORLD_SCENE_BOT_START_Y+300, convex1Vertices));
    //Trou TOP
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+3200, WORLD_SCENE_TOP_START_Y+500, 800, 200));
    //Deux étages
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+4700, WORLD_SCENE_TOP_START_Y+200, 500, 10));
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+4700, WORLD_SCENE_TOP_START_Y+300, 500, 10));
    //Bac à balles
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+5800, WORLD_SCENE_TOP_START_Y+300, 10, 25));
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+6000, WORLD_SCENE_TOP_START_Y+325, 210, 10));
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+6200, WORLD_SCENE_TOP_START_Y+300, 10, 25));
    for (int i = 0; i < 50; i++) {
        level1->addEntityTop(
                factory.createCircleDynamic(m_world,
                        WORLD_SCENE_TOP_START_X + 6000 + round((((double) rand() / (RAND_MAX)) + 1) * 150 - 75),
                        WORLD_SCENE_TOP_START_Y + 100 + round((((double) rand() / (RAND_MAX)) + 1) * 150 - 75),
                        10, 1, 0.5f));
    }
    //Plat jusqu'à la fin
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+8300, WORLD_SCENE_TOP_START_Y+500, 2000, 200));

    m_car1 = factory.createCar(m_world, WORLD_SCENE_TOP_START_X+RELATIVE_CAR_SPAWN_X, WORLD_SCENE_TOP_START_Y);
    m_car2 = factory.createCar(m_world, WORLD_SCENE_BOT_START_X+RELATIVE_CAR_SPAWN_X, WORLD_SCENE_BOT_START_Y);


    m_controller0 = new GameController(this,m_car1,0);
    m_controller1 = new GameController(this,m_car2,1);
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

void Game::checkDeath()
{
    if(!DISABLE_DEATH)
    {
        if( -m_car1->getPosition().y > WORLD_SCENE_TOP_START_Y+m_window.getSize().y/2)
            m_state = STATE::ECHEC;

        if( -m_car2->getPosition().y > WORLD_SCENE_BOT_START_Y+m_window.getSize().y/2)
            m_state = STATE::ECHEC;

        if( m_car1->getPosition().x < (m_scene.getLeftBorderTopX()-DEATH_LEFT_OFFSET) )
            m_state = STATE::ECHEC;

        if( m_car2->getPosition().x < (m_scene.getLeftBorderBotX()-DEATH_LEFT_OFFSET) )
            m_state = STATE::ECHEC;
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
    if(m_state == STATE::ECHEC)
    {
        physicsTimer.stop();
        m_menu.updateControllerStatus();
        m_menu.setEchec();
        m_window.draw(m_menu);

    }
    else if(m_state == STATE::RUNNING)
    {
        m_scene.selectTopScreenView();
        m_car1->update();
        m_window.draw(*m_car1);
        level1->drawTop(m_window);

        m_scene.selectBotScreenView();
        m_car2->update();
        m_window.draw(*m_car2);
        level1->drawBot(m_window);


        m_window.draw(m_scene);
    }
    m_window.display();
}

void Game::updatePhysics()
{
    float m_car1X = m_car1->getPosition().x;
    float m_car2X = m_car2->getPosition().x;
    m_world.step(PHY_TIME_STEP);
    m_car1speedX = m_car1->getPosition().x - m_car1X;
    m_car2speedX = m_car2->getPosition().x - m_car2X;

    m_scene.translateRightTopScreen(std::max(m_car1speedX,MIN_VIEW_SPEED) );
    m_scene.translateRightBotScreen(std::max(m_car2speedX,MIN_VIEW_SPEED) );

    checkDeath();
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
    else if(m_state == STATE::ECHEC)
    {
        physicsTimer.stop();
        m_state = STATE::RUNNING;
        reset();
    }
}

void Game::stop()
{
    if(m_state == STATE::MENU || m_state == STATE::PAUSED || m_state == STATE::ECHEC)
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