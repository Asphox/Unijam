//
// Created by asphox on 23/11/2019.
//

#ifndef UNIJAM_OPTIONS_H
#define UNIJAM_OPTIONS_H

constexpr bool DISABLE_DEATH = false;

constexpr int WORLD_SCENE_TOP_START_X = 10000;
constexpr int WORLD_SCENE_TOP_START_Y  = 10000;

constexpr int WORLD_SCENE_BOT_START_X = 30000;
constexpr int WORLD_SCENE_BOT_START_Y  = 30000;

constexpr int WORLD_MENU_START_X = 40000;
constexpr int WORLD_MENU_START_Y = 40000;

constexpr float TOPVIEW_MAX_ZOOM = 10.0f;
constexpr float TOPVIEW_MIN_ZOOM = 0.3f;

constexpr float BOTVIEW_MAX_ZOOM = 10.0f;
constexpr float BOTVIEW_MIN_ZOOM = 0.3f;

constexpr float GAMESCENE_SEPARATION_SPLITSCREEN_RATIO = 0.02;

constexpr uint8_t XBOXC_BUTTON_A_ID = 0;
constexpr uint8_t XBOXC_BUTTON_SELECT_ID = 6;
constexpr uint8_t XBOXC_BUTTON_START_ID = 7;

constexpr float   PHY_TIME_STEP = 1.0f / 60.0f;


constexpr float RELATIVE_CAR_SPAWN_X = 300;
constexpr float RELATIVE_CAR_SPAWN_Y = 300;
constexpr float RELATIVE_PUSH_VIEW_X = 700;

constexpr float MIN_VIEW_SPEED = 0.25;

constexpr float DEATH_LEFT_OFFSET = 50;

constexpr unsigned int MAX_PASSED_SPEEDS_STORED = 10;



#endif //UNIJAM_OPTIONS_H
