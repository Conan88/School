//
// Created by Ruben on 10.11.2016.
//

#ifndef MINIGOLF_LOCAL_H
#define MINIGOLF_LOCAL_H

#include "machine.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "stateMainMenu.h"
#include "state.h"

class singlePlay: public State
{
public:
    singlePlay(float screenWidth, float screenHeight);
    void Running(Machine &machine, Audio& audio);
    int computers;
    sf::Texture background;

protected:
    sf::Text vsComputer;
    sf::Text training;
    sf::Text exit;
    bool wasMousePressed;
    bool isMousePressed;
    std::vector<sf::Text> buttons;
};

#endif //MINIGOLF_LOCAL_H
