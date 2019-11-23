cmake_minimum_required(VERSION 3.15)

project(Unijam)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML could not be found")
endif()

include_directories(src/Tiers/)
include_directories(src/)
file(GLOB_RECURSE BOX2D_src "src/Tiers/Box2D/*.cpp")

add_executable(Unijam src/main.cpp src/Graphics/AnimatedSprite.cpp src/Graphics/AnimatedSprite.h src/System/Timer.cpp src/System/Timer.h src/System/Thread.cpp src/System/Thread.h ${BOX2D_src} src/Game/GameScene/GameScene.cpp src/Game/GameScene/GameScene.h src/Options.h)

target_link_libraries(Unijam
        sfml-window
        sfml-graphics
        sfml-system)

