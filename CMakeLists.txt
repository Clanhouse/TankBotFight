cmake_minimum_required(VERSION 3.12)
project(TankBotFight)


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(tank_bot_fight 
    src/main.cpp 
    src/TankClass.cpp 
    src/ObstacleClass.cpp)

target_compile_options(tank_bot_fight PUBLIC -std=c++20 -Wall -Wpedantic -Werror)

target_include_directories(tank_bot_fight PRIVATE src)

target_link_libraries(tank_bot_fight sfml-graphics sfml-audio)
