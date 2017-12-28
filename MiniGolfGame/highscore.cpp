
#include "functions.h"
#include "highscore.h"

highScore::highScore(float screenWidth, float screenHeight)
{
    exit.setString("EXIT");
    textYPos = 0;
}

void highScore::Running(Machine &machine, Audio& audio)
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

        if(buttonPressed == 1)
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        textYPos+=2;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        textYPos-=2;
    }
    if(textYPos>0){
        textYPos=0;
    }


    //Tegn bakgrunnen
    machine.getWindow().clear(sf::Color::Black);

    //Tegn ting

    //Tegn firkant
    functions.DrawRectangle(machine.getWindow(),180,160,10,10,1);

    //Legg til tekst i firkanten
    functions.DisplayString(machine.getWindow(), "Skriver masse tekst her bare for", 15, 15+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "testing.", 15, 25+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), ":)", 15, 35+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "Masse, masse tekst.", 15, 45+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "Trenger nok tekst til at det havner", 15, 55+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "utenfor highscore vinduet", 15, 65+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "for demonstrasjon av scrolling.", 15, 75+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "Derfor skriver vi enda litt til.", 15, 85+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "Faktisk er vi ikke ferdige helt", 15, 95+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "enda heller.", 15, 105+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "Masse, masse tekst.", 15, 115+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "Bla bla bla bla bla bla", 15, 125+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "bla bla bla bla", 15, 135+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "har ikke god nok fantasi", 15, 145+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "til mer tulletekst.", 15, 155+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "bla bblaaaa bla bla bla", 15, 165+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "bla bla", 15, 175+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "stekeovn", 15, 185+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "Her er det enda mer, bare", 15, 195+textYPos, 20, 0);
    functions.DisplayString(machine.getWindow(), "for sikkerhets skyld.", 15, 205+textYPos, 20, 0);


    //Legg til firkanter som dekker over teksten utenfor highscore vinduet
    functions.DrawRectangle(machine.getWindow(),180,9.1,10,0);
    functions.DrawRectangle(machine.getWindow(),180,30,10,170.9);

    functions.DisplayString(machine.getWindow(), "Use arrows to scroll", 15, 2, 45);


    //Tegn exit knappen
    functions.DisplayText(machine.getWindow(), exit, 8.7);

    //Vis innhold
    machine.getWindow().display();
}
