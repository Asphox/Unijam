//
// Created by asphox on 23/11/2019.
//

#include "Game.h"

Game::Game(sf::RenderWindow& window) : m_menu(this), m_world(-10.0f), m_scene(window), m_window(window)
{
    m_state = STATE::MENU;
    if( !m_font.loadFromFile("Assets/Arial.ttf") )
    {
        std::cerr << "CAN'T LOAD FONT" << std::endl;
    }
}

void Game::run()
{
    EntityFactory factory = EntityFactory();
    level1 = new Level();

    //Ground level 1
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+5000/2, WORLD_SCENE_TOP_START_Y+500, 5000, 200));

    //Premier obstacle
    level1->addEntityTop(factory.createBoxStatic(m_world, WORLD_SCENE_TOP_START_X+1000, WORLD_SCENE_TOP_START_Y+300, 200, 25));

    //Second obstacle
    std::vector<std::pair<float, float>> convex1Vertices;
    convex1Vertices.push_back(std::pair<float,float>(-300,-25));
    convex1Vertices.push_back(std::pair<float,float>(-50,25));
    convex1Vertices.push_back(std::pair<float,float>(50,25));
    convex1Vertices.push_back(std::pair<float,float>(300,-25));
    level1->addEntityTop(factory.createConvexStatic(m_world, WORLD_SCENE_TOP_START_X+2500, WORLD_SCENE_TOP_START_Y+250, convex1Vertices));
/*
    factory.createBoxDynamic(m_world,400,400,380,20, 1, 1, 5);
    m_box1 = factory.createBoxStatic(m_world,WORLD_SCENE_TOP_START_X+500/2,WORLD_SCENE_TOP_START_Y+350,500,20);
    m_box2 = factory.createBoxStatic(m_world,WORLD_SCENE_BOT_START_X+500/2,WORLD_SCENE_BOT_START_Y+350,500,20);
    triangle1Vertices.push_back(std::pair<float,float>(-75,-100));
    triangle1Vertices.push_back(std::pair<float,float>(-75,-50));
    triangle1Vertices.push_back(std::pair<float,float>(-25,-50));
    m_convex1 = factory.createConvexStatic(m_world, WORLD_SCENE_TOP_START_X+100,WORLD_SCENE_TOP_START_Y+200, 0,triangle1Vertices);
    factory.createCircleDynamic(m_world, 500, 50, 10, 10, 1);
    factory.createCircleDynamic(m_world, 300, 30, 10, 10, 1);
    factory.createCircleDynamic(m_world, 680, 10, 10, 10, 1);
*/
    m_car1 = factory.createCar(m_world, WORLD_SCENE_TOP_START_X+100, WORLD_SCENE_TOP_START_Y);
    m_car2 = factory.createCar(m_world, WORLD_SCENE_BOT_START_X+100, WORLD_SCENE_BOT_START_Y);

    m_controller0 = new GameController(this,m_car1,0);
    m_controller1 = new GameController(this,m_car2,1);



    while (m_window.isOpen())
    {
        pollEvent();
        update();
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

void Game::update()
{
    m_window.clear();
    if(m_state == STATE::MENU || m_state == STATE::PAUSED)
    {
        m_menu.updateControllerStatus();
        m_window.draw(m_menu);
    }
    else if(m_state == STATE::RUNNING)
    {
        m_world.step(PHY_TIME_STEP);
        m_car1->update();
        m_car2->update();

        m_scene.selectTopScreenView();
        m_window.draw(*m_car1);
        level1->drawTop(m_window);
        //m_window.draw(*m_box1);
        //m_window.draw(*m_convex1);

        m_scene.selectBotScreenView();
        level1->drawBot(m_window);
        m_window.draw(*m_car2);


        m_window.draw(m_scene);
        //m_window.draw(*m_box2);


    }
    m_window.display();
}

void Game::pause()
{
    if(m_state == STATE::MENU || m_state == STATE::PAUSED) m_state = STATE::RUNNING;
    else if(m_state == STATE::RUNNING) m_state = STATE::PAUSED;
}

void Game::stop()
{
    if(m_state == STATE::MENU || m_state == STATE::PAUSED)
        m_window.close();
}