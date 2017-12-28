#include "controls.h"

controls::controls(float screenWidth, float screenHeight)
{
    exit.setString("EXIT");
}

void controls::Running(Machine &machine, Audio& audio)
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
        buttons = {exit};
        int buttonPressed = functions.checkButtonPressed(machine.getWindow(), buttons, pointClicked);

        if (buttonPressed == 1)
        {
            machine.SetState(Machine::StateId::MAINMENU);
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
    if(!background.loadFromFile("data/Graphics/Textures/controls.png")){
        std::cout << "Failed to load\n";
    }
    sf::Sprite sprite(background);
    machine.getWindow().draw(sprite);


    // Tegn ting
    // Se stateMainMenu.cpp for kommentar til functions.DisplayText
    functions.DisplayText(machine.getWindow(), exit, 4);

    // Vis innhold
    machine.getWindow().display();
}