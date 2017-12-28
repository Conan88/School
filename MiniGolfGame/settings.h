#ifndef MINIGOLF_SETTINGS_H
#define MINIGOLF_SETTINGS_H

#include "machine.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "stateMainMenu.h"
#include "state.h"


class settingMenu: public State
{
public:
    settingMenu(float screenWidth, float screenHeight);
    void Running(Machine &machine, Audio& audio);

protected:
    sf::Text video;
    sf::Text sound;
    sf::Text gamePlay;
    sf::Text exit;

    bool wasMousePressed;
    bool isMousePressed;

    std::vector<sf::Text> buttons;
};

#endif //MINIGOLF_SETTINGS_H
