#ifndef MINIGOLF_MACHINE_H
#define MINIGOLF_MACHINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Musicstream.h"

class State;

class Machine
{
public:
    Machine(int width, int height);

    enum class StateId {RUNNING, MAINMENU, singlePlay, settingMenu, highScore, controls};

    void AddState(State* s);
    void Running();
    void SetState(StateId state);
    void SetRunning(bool running) { this->running = running; }
    bool GetRunning() const { return running; }

    sf::RenderWindow &getWindow();


protected:
    bool running;
    State* currentState;
    std::vector<State*> states;
    sf::RenderWindow window;
    Audio audio;
};

#endif
