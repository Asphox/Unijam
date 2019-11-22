cmake_minimum_required(VERSION 3.15)

project(Unijam)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML could not be found")
endif()

add_executable(Unijam src/main.cpp src/Graphics/AnimatedSprite.cpp src/Graphics/AnimatedSprite.h src/System/Timer.cpp src/System/Timer.h src/System/Thread.cpp src/System/Thread.h)

target_link_libraries(Unijam
        sfml-window
        sfml-graphics
        sfml-system)

