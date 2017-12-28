cmake_minimum_required(VERSION 3.6)
project(miniGOlf)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

set(SOURCE_FILES main.cpp
        state.h
        machine.cpp
        machine.h
        stateRunning.cpp
        stateRunning.h
        ball.cpp
        ball.h
        obstacle.cpp
        obstacle.h
        map.cpp
        map.h
        object.cpp
        object.h
        sprite.cpp
        sprite.h
        layer.cpp
        layer.h
        map.cpp
        Collision.cpp
        Collision.h
        util.h
        stateMainMenu.h
        stateMainMenu.cpp
        highscore.cpp
        highscore.h
        settings.h
        settings.cpp
        singlePlayer.cpp
        singlePlayer.h
        functions.cpp
        functions.h
        Musicstream.cpp
        Musicstream.h
        controls.h controls.cpp)


include_directories(json/json.h )
add_executable(miniGOlf ${SOURCE_FILES})

target_link_libraries(miniGOlf jsoncpp sfml-audio sfml-graphics sfml-window sfml-system)