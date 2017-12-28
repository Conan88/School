#include "stateMainMenu.h"
#include "functions.h"


MenuState::MenuState(float screenWidth, float screenHeight)
{
    singlePlayer.setString("Singleplayer");
    vsComputer.setString("Local");
    highScore.setString("Highscore");
    settings.setString("Settings");
    controls.setString("Controls");
    quitText.setString("Quit");
}

void MenuState::Running(Machine &machine, Audio& audio)
{
    if(firstenter){
        audio.play(4);
        firstenter = false;
    }
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
        buttons = {singlePlayer, singlePlayer, highScore, settings, controls, quitText};
        int buttonPressed = functions.checkButtonPressed(machine.getWindow(), buttons, pointClicked);
        if (buttonPressed == 1)
        {
            machine.SetState(Machine::StateId::singlePlay);
            audio.playeffect(2);
            firstenter = true;
        }
            //Knapp 2
        else if (buttonPressed == 2)
        {
            std::cout << "Local button pressed" << std::endl ;
            audio.playeffect(2);
        }
            //Knapp 3
        else if (buttonPressed == 3)
        {
            machine.SetState(Machine::StateId::highScore);
            audio.playeffect(2);
            firstenter = true;
        }
            //Knapp 4
        else if (buttonPressed == 4)
        {
            machine.SetState(Machine::StateId::settingMenu);
            audio.playeffect(2);
            firstenter = true;
        }
        else if (buttonPressed == 5)
        {
            std::cout << "Quitting" << std::endl;
            audio.playeffect(2);
            machine.SetState(Machine::StateId::controls);
            firstenter = true;
        }
            //Knapp 5
        else if (buttonPressed == 6)
        {
            std::cout << "Du trykket quit" << std::endl;
            audio.playeffect(2);
            machine.getWindow().close();
            //machine.SetState((Machine::StateId::EXIT));
        }
        else{
            std::cout << "Du trykket utenfor knappene" << std::endl;
        }
        wasMousePressed = isMousePressed;
    }
    if(!isMousePressed)
    {
        wasMousePressed=false;
    }

    // Tegn bakgrunn
    machine.getWindow().clear(sf::Color::Black);
    if(!background.loadFromFile("data/Graphics/Textures/menybakgrunn.jpg")){
        std::cout << "Failed to load\n";
    }
    sf::Sprite sprite(background);
    machine.getWindow().draw(sprite);

    // Tegn ting
    // Vi bruker en funksjon i klassen functions for å vise tekst på skjermen.
    // Vi sender inn vinduet, sf::Text, og posisjon som angir hvilken plass knappen har i høyderetning.
    // Se functions.cpp for detaljer.

    functions.DisplayText(machine.getWindow(), singlePlayer, 5);
    functions.DisplayText(machine.getWindow(), vsComputer, 5.7);
    functions.DisplayText(machine.getWindow(), highScore, 6.4);
    functions.DisplayText(machine.getWindow(), settings, 7.1);
    functions.DisplayText(machine.getWindow(), controls, 7.8);
    functions.DisplayText(machine.getWindow(), quitText, 8.5);

    //Vis innhold
    machine.getWindow().display();
}
