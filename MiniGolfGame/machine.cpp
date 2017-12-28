#include <cstddef>
#include "machine.h"
#include "state.h"

void Machine::AddState(State* s)
{
    states.push_back(s);
}

void Machine::Running()
{
    while(window.isOpen())
        currentState->Running(*this, audio);
    running = false;
}

void Machine::SetState(StateId state)
{
    currentState = states[(std::size_t)state];
}

Machine::Machine(int width, int height)
{
    window.create(sf::VideoMode(width, height), "Pokemon GOlf");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

sf::RenderWindow &Machine::getWindow()
{
    return window;
}
