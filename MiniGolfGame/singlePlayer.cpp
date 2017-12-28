#include "singlePlayer.h"
#include "functions.h"

singlePlay::singlePlay(float screenWidth, float screenHeight)
{
    training.setString("Training");
    vsComputer.setString("Computer");
    exit.setString("EXIT");
}

void singlePlay::Running(Machine &machine, Audio& audio)
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
        buttons = {training, vsComputer, exit};
        int buttonPressed = functions.checkButtonPressed(machine.getWindow(), buttons, pointClicked);

        if (buttonPressed == 1)
        {
            std::cout << "Training button pressed" << std::endl;
            machine.SetState(Machine::StateId::RUNNING);
            audio.playeffect(2);
        }
            //Knapp 2
        else if (buttonPressed == 2)
        {
            std::cout << "Computer button pressed" << std::endl;
            audio.playeffect(2);
        }
            //Knapp 3
        else if (buttonPressed == 3)
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

    // Tegn bakgrunnen
    machine.getWindow().clear(sf::Color::Black);
    if(!background.loadFromFile("data/Graphics/Textures/menybakgrunn.jpg")){
        std::cout << "Failed to load\n";
    }
    sf::Sprite sprite(background);
    machine.getWindow().draw(sprite);

    // Tegn ting
    // Se stateMainMenu.cpp for kommentar til functions.DisplayText
    functions.DisplayText(machine.getWindow(), training, 5);
    functions.DisplayText(machine.getWindow(), vsComputer, 5.7);
    functions.DisplayText(machine.getWindow(), exit, 6.4);

    // Vis innhold
    machine.getWindow().display();
}