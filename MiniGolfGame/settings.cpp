#include "settings.h"
#include "functions.h"

settingMenu::settingMenu(float screenWidth, float screenHeight)
{
    video.setString("Video");
    sound.setString("Sound");
    gamePlay.setString("Gameplay");
    exit.setString("EXIT");
}

void settingMenu::Running(Machine &machine, Audio& audio)
{
    sf::Event event;
    while (machine.getWindow().pollEvent(event))
    {

    }

    Functions functions;    //Vi bruker en funksjon i klassen functions for å vise knappene.
    sf::Vector2f pointClicked;

    isMousePressed = false;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        pointClicked = {(float) sf::Mouse::getPosition(machine.getWindow()).x,
                        (float) sf::Mouse::getPosition(machine.getWindow()).y};
        isMousePressed = true;
    }

    if(isMousePressed && !wasMousePressed)
    {
        //Kjør funksjonen som finner ut hvilken knapp som er trykket på
        buttons = {video, sound, gamePlay, exit};
        int buttonPressed = functions.checkButtonPressed(machine.getWindow(), buttons, pointClicked);

        if(buttonPressed == 1)
        {
            std::cout << "Video button pressed" << std::endl;
            audio.playeffect(2);
        }
            //Knapp 2
        else if(buttonPressed == 2)
        {
            std::cout << "Sound button pressed" << std::endl;
            audio.playeffect(2);
        }
            //Knapp 3
        else if(buttonPressed == 3)
        {
            std::cout << "Gameplay button pressed" << std::endl;
            audio.playeffect(2);
        }
            //Knapp 4
        else if(buttonPressed == 4)
        {
            machine.SetState(Machine::StateId::MAINMENU);
            audio.playeffect(2);
        }
        wasMousePressed = isMousePressed;
    }
    if(!isMousePressed)
    {
        wasMousePressed=false;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        machine.SetState(Machine::StateId::MAINMENU);
    }

    //Tegn bakgrunnen
    machine.getWindow().clear(sf::Color::Black);

    //Tegn ting
    //Se stateMainMenu.cpp for kommentar til functions.DisplayText
    functions.DisplayText(machine.getWindow(), video, 1);
    functions.DisplayText(machine.getWindow(), sound, 2);
    functions.DisplayText(machine.getWindow(), gamePlay, 3);
    functions.DisplayText(machine.getWindow(), exit, 4);

    //Vis innhold
    machine.getWindow().display();
}

