#ifndef MINIGOLF_STATEMAINMENU_H
#define MINIGOLF_STATEMAINMENU_H

#include "state.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "machine.h"
#include "singlePlayer.h"
#include "settings.h"
#include "controls.h"


class MenuState: public State
{
public:
    MenuState(float screenWidth, float screenHeight);
    void Running(Machine &machine, Audio& audio);

    sf::Texture background;
    bool firstenter = true;
protected:
    sf::Text vsComputer;
    sf::Text highScore;
    sf::Text singlePlayer;
    sf::Text settings;
    sf::Text quitText;
    sf::Text controls;


    bool wasMousePressed;
    bool isMousePressed;

    std::vector<sf::Text> buttons;
};

#endif //MINIGOLF_STATEMAINMENU_H
