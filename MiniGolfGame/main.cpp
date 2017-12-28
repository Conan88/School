#include "machine.h"
#include "stateRunning.h"
#include "settings.h"
#include "highscore.h"
#include "controls.h"


int main()
{
    //screen size
    float width = 960;
    float height = 960;

    // Instantiate states
    StateRunning* sr = new StateRunning(width, height);

    MenuState* ms = new MenuState(width, height);
    settingMenu* sm = new settingMenu(width, height);
    singlePlay* sp = new singlePlay(width, height);
    highScore* hs = new highScore(width, height);
    controls* co = new controls(width, height);

    // Create the machine and add states to it
    // screen size
    Machine* golfMachine = new Machine(width, height);

    golfMachine->AddState(sr);
    golfMachine->AddState(ms);
    golfMachine->AddState(sp);
    golfMachine->AddState(sm);
    golfMachine->AddState(hs);
    golfMachine->AddState(co);

    // Start in the Running state
    golfMachine->SetState(Machine::StateId::MAINMENU);

    //Set running flag to true
    golfMachine->SetRunning(true);

    // Run until the running flag is set to false
    while (golfMachine->GetRunning())
        golfMachine->Running();

    return 0;
}