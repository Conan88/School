#ifndef MINIGOLF_STATE_H
#define MINIGOLF_STATE_H

class Machine;

#include "Musicstream.h"

class State
{
public:
    State(){}
    virtual void Running(Machine &context, Audio& audio) = 0;
};


#endif
