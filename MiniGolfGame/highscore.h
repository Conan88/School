#ifndef MINIGOLF_HIGHSCORE_H
#define MINIGOLF_HIGHSCORE_H

#include "state.h"
#include "machine.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class highScore: public State
{
public:
    highScore(float screenWidth, float screenHeight);

    void Running(Machine &machine, Audio& audio);

private:
    sf::Text exit;

    bool wasMousePressed;
    bool isMousePressed;
    std::vector<sf::Text> buttons;
    int textYPos;
};

#endif //MINIGOLF_HIGHSCORE_H
