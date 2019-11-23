//
// Created by asphox on 22/11/2019.
//

#include "GameScene.h"

GameScene::GameScene(sf::RenderWindow& window)
{
    m_defaultViewSize.x = window.getSize().x;
    m_defaultViewSize.y = window.getSize().y/2;
    m_viewTopNonZoomedCenter.x = WORLD_SCENE_TOP_START_X+window.getSize().x/2;
    m_viewTopNonZoomedCenter.y = WORLD_SCENE_TOP_START_Y+window.getSize().y/4;
    m_viewBotNonZoomedCenter.x = WORLD_SCENE_BOT_START_X+window.getSize().x/2;
    m_viewBotNonZoomedCenter.y = WORLD_SCENE_BOT_START_Y+window.getSize().y/4;

    m_viewTop.setCenter(m_viewTopNonZoomedCenter);
    m_viewTop.setSize(m_defaultViewSize);
    m_viewTop.setViewport(sf::FloatRect(0,0,1.0f,0.5f));

    m_viewBot.setCenter(m_viewBotNonZoomedCenter);
    m_viewBot.setSize(m_defaultViewSize);
    m_viewBot.setViewport(sf::FloatRect(0,0.5f,1.0f,0.5f));

    m_test.setSize(sf::Vector2f(100,50));
    m_test.setPosition(WORLD_SCENE_TOP_START_X,WORLD_SCENE_TOP_START_Y+m_viewTop.getSize().y-50);
    m_test2.setSize(sf::Vector2f(100,50));
    m_test2.setPosition(WORLD_SCENE_BOT_START_X,WORLD_SCENE_BOT_START_Y+m_viewTop.getSize().y-50);

    m_splitScreenSeparation.setSize(sf::Vector2f(window.getSize().x,GAMESCENE_SEPARATION_SPLITSCREEN_RATIO*window.getSize().y) );
    m_splitScreenSeparation.setOrigin(m_splitScreenSeparation.getSize().x/2,m_splitScreenSeparation.getSize().y/2);
    m_splitScreenSeparation.setPosition(window.getSize().x/2,window.getSize().y/2);
    m_splitScreenSeparation.setFillColor(sf::Color::Cyan);
}

void GameScene::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.setView(m_viewTop);
    target.draw(m_test);

    target.setView(m_viewBot);
    target.draw(m_test2);

    target.setView(target.getDefaultView());
    target.draw(m_splitScreenSeparation);
}

void GameScene::translateLeftTopScreen(float move)
{
    m_viewTop.move(-move,0);
}

void GameScene::translateRightTopScreen(float move)
{
    m_viewTop.move(move,0);
}

void GameScene::translateLeftBotScreen(float move)
{
    m_viewBot.move(-move,0);
}

void GameScene::translateRightBotScreen(float move)
{
    m_viewBot.move(move,0);
}

void GameScene::translateUpTopScreen(float move)
{
    m_viewTop.move(0,-move);
}

void GameScene::translateDownTopScreen(float move)
{
    m_viewTop.move(0,move);
}

void GameScene::translateUpBotScreen(float move)
{
    m_viewBot.move(0,-move);
}

void GameScene::translateDownBotScreen(float move)
{
    m_viewBot.move(0,move);
}


void GameScene::setZoomTopScreen(float zoom)
{
    if( zoom > TOPVIEW_MAX_ZOOM ) zoom = TOPVIEW_MAX_ZOOM;
    else if( zoom < TOPVIEW_MIN_ZOOM ) zoom = TOPVIEW_MIN_ZOOM;
    zoom = 1/zoom;
    resetZoomTopScreen();
    m_currentZoomTop = zoom;
    m_viewTop.setSize(zoom*m_defaultViewSize.x,zoom*m_defaultViewSize.y);
    m_viewTop.setCenter(m_viewTop.getCenter().x+(zoom-1)*m_defaultViewSize.x/2.0f,m_viewTop.getCenter().y-(zoom-1)*m_defaultViewSize.y/2.0f);
}

void GameScene::setZoomBotScreen(float zoom)
{
    if( zoom > BOTVIEW_MAX_ZOOM ) zoom = BOTVIEW_MAX_ZOOM;
    else if( zoom < BOTVIEW_MIN_ZOOM ) zoom = BOTVIEW_MIN_ZOOM;
    zoom = 1/zoom;
    resetZoomBotScreen();
    m_currentZoomBot = zoom;
    m_viewBot.setSize(zoom*m_defaultViewSize.x,zoom*m_defaultViewSize.y);
    m_viewBot.setCenter(m_viewBot.getCenter().x+(zoom-1)*m_defaultViewSize.x/2.0f,m_viewBot.getCenter().y-(zoom-1)*m_defaultViewSize.y/2.0f);
}

void GameScene::resetZoomTopScreen()
{
    m_viewTop.setSize(m_defaultViewSize);
    m_viewTop.setCenter(m_viewTop.getCenter().x-(m_currentZoomTop-1)*m_defaultViewSize.x/2.0f,m_viewTop.getCenter().y+(m_currentZoomTop-1)*m_defaultViewSize.y/2.0);
    m_currentZoomTop = 1.0f;
}

void GameScene::resetZoomBotScreen()
{
    m_viewBot.setSize(m_defaultViewSize);
    m_viewBot.setCenter(m_viewBot.getCenter().x-(m_currentZoomBot-1)*m_defaultViewSize.x/2.0f,m_viewBot.getCenter().y+(m_currentZoomBot-1)*m_defaultViewSize.y/2.0);
    m_currentZoomBot = 1.0f;
}