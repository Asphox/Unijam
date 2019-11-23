//
// Created by asphox on 22/11/2019.
//

#include "GameScene.h"

GameScene::GameScene(sf::RenderWindow& window)
{
    m_viewTop.setCenter(WORLD_SCENE_TOP_START_X+window.getSize().x/2,WORLD_SCENE_TOP_START_Y+window.getSize().y/4);
    m_viewTop.setSize(window.getSize().x,window.getSize().y/2);
    m_viewTop.setViewport(sf::FloatRect(0,0,1.0f,0.5f));
    m_viewBot.setCenter(WORLD_SCENE_BOT_START_X+window.getSize().x/2,WORLD_SCENE_BOT_START_Y+window.getSize().y/4);
    m_viewBot.setSize(window.getSize().x,window.getSize().y/2);
    m_viewBot.setViewport(sf::FloatRect(0,0.5f,1.0f,0.5f));

    m_test.setSize(sf::Vector2f(100,50));
    m_test.setPosition(WORLD_SCENE_TOP_START_X,WORLD_SCENE_TOP_START_Y);
    m_test2.setSize(sf::Vector2f(100,50));
    m_test2.setPosition(WORLD_SCENE_BOT_START_X,WORLD_SCENE_BOT_START_Y);
}

void GameScene::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.setView(m_viewTop);
    target.draw(m_test);

    target.setView(m_viewBot);
    target.draw(m_test2);
}

void GameScene::translateLeftTopScreen(unsigned int move)
{
    m_viewTop.move(-move,0);
}

void GameScene::translateRightTopScreen(unsigned int move)
{
    m_viewTop.move(move,0);
}

void GameScene::translateLeftBotScreen(unsigned int move)
{
    m_viewBot.move(-move,0);
}

void GameScene::translateRightBotScreen(unsigned int move)
{
    m_viewBot.move(move,0);
}