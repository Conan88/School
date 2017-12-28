#ifndef MINIGOLF_CONTROLS_H
#define MINIGOLF_CONTROLS_H

#include "functions.h"
#include "machine.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "stateMainMenu.h"
#include "state.h"

class controls: public State
{
public:
    controls(float screenWidth, float screenHeight);
    void Running(Machine &machine, Audio& audio);



protected:
    sf::Text exit;
    sf::Texture background;
    bool wasMousePressed;
    bool isMousePressed;
    std::vector<sf::Text> buttons;
};


#endif //MINIGOLF_CONTROLS_H