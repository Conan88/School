#include "stateRunning.h"
#include "machine.h"
#include "ball.h"
#include "map.h"
#include "object.h"
#include <iostream>
#include "Collision.h"
#include "functions.h"
#include <math.h>
#include <cmath>
#include "util.h"
#define PI 3.14159265

StateRunning::StateRunning(int width, int height)
{
    std::cout << "Klikk der du vil ballen skal rulle. Tast R for å resette ballen." << std::endl;
    ball.create(width, height);
    initLevel();
    strokes = 0;

    if (!powerbarBack.loadFromFile("data/Graphics/Textures/powerBack.png"))
    {
        std::cout << "Failed to load powerbar back." << std::endl;
    }
    if (!powerbarFront.loadFromFile("data/Graphics/Textures/powerFront.png"))
    {
        std::cout << "Failed to load powerbar front." << std::endl;
    }
}

void StateRunning::initLevel()
{
    object.clear();
    over.clear();
    under.clear();
    hullet.clear();
    obstaclelist.clear();
    vann.clear();
    ned.clear();

    collisionWithHole = false;
    collisionWithWater = false;
    ball.getSprite().setScale(1,1);

    scalingPower = 0;

    if (level == 1)
    {
        //Position for lvl 1 map
        ball.setXPos(838);
        ball.setYPos(806);
        par = 2;
        // Load map information from JSON into object list
        if (!Map::load("data/Graphics/Textures/pokemonGOlfLvl1.json", object, obstaclelist, frictionmap, tilesize,
                       under, over, hullet, vann, ned)) {
            std::cout << "Failed to load map data." << std::endl;
        }
    }
    else if (level == 2)
    {
        //Position for lvl 2 map
        ball.setXPos(453);
        ball.setYPos(839);
        par = 3;
        if (!Map::load("data/Graphics/Textures/pokemonGOlfLvl2.json", object, obstaclelist, frictionmap, tilesize, under, over, hullet, vann, ned))
        {
            std::cout << "Failed to load map data." << std::endl;
        }
    }
    else if (level == 3)
    {
        //Position for mapByAnders
        ball.setXPos(100);
        ball.setYPos(870);
        par = 14;
        if (!Map::load("data/Graphics/Textures/mapByAnders.json", object, obstaclelist, frictionmap, tilesize, under, over, hullet, vann, ned))
        {
            std::cout << "Failed to load map data." << std::endl;
        }
    }
    else if (level == 4)
    {
        //Position for mapByRuben
        ball.setXPos(132);
        ball.setYPos(837);
        par = 18;
        if (!Map::load("data/Graphics/Textures/rubenMap.json", object, obstaclelist, frictionmap, tilesize, under, over, hullet, vann, ned))
        {
            std::cout << "Failed to load map data." << std::endl;
        }
    }
}

void StateRunning::reactUpDown(Ball& ball, Obstacle& obstacle, Machine& machine, sf::Vector2i mousePosition, int (&frictionmap)[100][100], int tilesize)
{
    float ballVinkel = ball.getGrader();
    float vinkelTilBoksen = 0-obstacle.getRotation();
    float nyVinkelTilBallen = vinkelTilBoksen + (vinkelTilBoksen-ballVinkel); ball.setGrader(nyVinkelTilBallen);

    // Denne while løkken er i tilfelle ballen sitter fast i hindringen.
    while(Collision::BoundingBoxTest(ball.getSprite(), obstacle.getSprite())){
        ball.Move(machine.getWindow().getSize().x, machine.getWindow().getSize().y, mousePosition, frictionmap, tilesize);
        ball.setSpeed(ball.getSpeed() + ball.getFartsreduksjon());
    }
}


void StateRunning::reactRightLeft(Ball& ball, Obstacle& obstacle, Machine& machine, sf::Vector2i mousePosition, int (&frictionmap)[100][100], int tilesize)
{
    float ballVinkel = ball.getGrader();
    float vinkelTilBoksen = 90-obstacle.getRotation();
    float nyVinkelTilBallen = vinkelTilBoksen + (vinkelTilBoksen-ballVinkel);ball.setGrader(nyVinkelTilBallen);
    //in case ball gets stuck like in my pong game
    while(Collision::BoundingBoxTest(ball.getSprite(), obstacle.getSprite())){
        ball.Move(machine.getWindow().getSize().x, machine.getWindow().getSize().y, mousePosition, frictionmap, tilesize);
        ball.setSpeed(ball.getSpeed() + ball.getFartsreduksjon());
    }
}

void StateRunning::reboundBall(Ball& ball, Obstacle& obstacle, Machine& machine, sf::Vector2i mousePosition, int (&frictionmap)[100][100], int tilesize)
{

    float ballCenterX = ball.getXPos() + ball.getRadius();
    float ballCenterY = ball.getYPos() + ball.getRadius();

    bool lefthit = false;
    bool righthit = false;
    bool tophit = false;
    bool bottomhit = false;

    int totalhits = 0;

    if(Collision::BoundingBoxTest(ball.getSprite(), obstacle.getBottom()))
    {
        bottomhit = true;
        totalhits++;
    }
    if(Collision::BoundingBoxTest(ball.getSprite(), obstacle.getTop()))
    {
        tophit = true;
        totalhits++;
    }
    if(Collision::BoundingBoxTest(ball.getSprite(), obstacle.getLeft()))
    {
        lefthit = true;
        totalhits++;
    }
    if(Collision::BoundingBoxTest(ball.getSprite(), obstacle.getRight()))
    {
        righthit = true;
        totalhits++;
    }


    if(totalhits == 1){

        if(lefthit || righthit)
        {
            reactRightLeft(ball, obstacle, machine, mousePosition, frictionmap, tilesize);
        }
        else if(tophit || bottomhit)
        {
            reactUpDown(ball, obstacle, machine, mousePosition, frictionmap, tilesize);
        }
    }
    else if(totalhits == 2)
    {
        float obstacleWidth = obstacle.getSprite().getLocalBounds().width;
        float obstacleHeight = obstacle.getSprite().getLocalBounds().height;

        float obstacleCenterX = obstacle.getXPos() + obstacleWidth/2;
        float obstacleCenterY = obstacle.getYPos() + obstacleHeight/2;

        float xdiff = obstacleCenterX - ballCenterX;
        float ydiff = obstacleCenterY - ballCenterY;

        // make diff relative to respective side
        xdiff /= obstacleWidth;
        ydiff /= obstacleHeight;

        xdiff = std::abs(xdiff);
        ydiff = std::abs(ydiff);


        if(xdiff < ydiff)
        {
            reactUpDown(ball, obstacle, machine, mousePosition, frictionmap, tilesize);
        }
        else if(ydiff < xdiff)
        {
            reactRightLeft(ball, obstacle, machine, mousePosition, frictionmap, tilesize);
        }
        else
        {
            //if hit corner exactly
            ball.setXDir(-ball.getXDir());
            ball.setYDir(-ball.getYDir());
        }


    } else if(totalhits == 3) {

        if(!lefthit || !righthit){
            reactRightLeft(ball, obstacle, machine, mousePosition, frictionmap, tilesize);
        }else if(!tophit|| !bottomhit){
            reactUpDown(ball, obstacle, machine, mousePosition, frictionmap, tilesize);
        }
    }
}

void StateRunning::moveBall(float power) {
    // Regner ut distansen mellom ballen og mus på x-aksen og y-aksen
    float yLengde = mousePosition.y - ball.getRadius() - ball.getBallPos().y;
    float xLengde = mousePosition.x - ball.getRadius() - ball.getBallPos().x;

    // Regner ut vinkelen ball skal gå mot mus posisjonen
    // -yLengde fordi y aksen er omvendt
    //may need fixing because multiple tan values are the same
    float ballVinkelIRadianer = atan2(-yLengde, xLengde);
    //gjør om radianer til grader siden sfml bruker grader
    float vinkelIGrader = toDegrees(ballVinkelIRadianer);

    //Setter hvilket retning/grader ballen skal bevege seg i
    ball.setGrader(vinkelIGrader);

    //Regner ut hastigheten ballen skal ha ved bruk av powerbar
    double speed = power*15;

    //Setter initial hastigheten til ballen.
    ball.setSpeed(speed);

    strokes++;
}

void StateRunning::Running(Machine &machine, Audio& audio)
{
    if(firsttime){
        audio.play(2);
        firsttime = false;
    }
    if(audio.player.getStatus() ==  sf::SoundSource::Stopped){
        audio.play(4);
    }
    Functions functions;

    //Get events from OS
    sf::Event event;
    while (machine.getWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            machine.getWindow().close();
            machine.SetRunning(false);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            pastFirstClick=false;
            machine.SetState(Machine::StateId::MAINMENU);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            ball.setSpeed(0);
            strokes = 0;
            initLevel();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            audio.play(1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            audio.nextSong();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            machine.getWindow().close();
            machine.SetRunning(false);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isPressed)
        {
            pastFirstClick = true;
            mousePosition = sf::Mouse::getPosition(machine.getWindow());
            std::cout << "mouse: " << mousePosition.x << ", " << mousePosition.y << std::endl;
            scalingPower = 0;
        }
    }

    //Denne koden står utenfor pollevent fordi den skal registreres selv om brukeren bare
    //holder pekeren inne uten å samtidig flytte på den.
    //Hvis peker holdes inne og ballens fart er 0:
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ball.getSpeed() == 0 && pastFirstClick)
    {
        //Oppdaterer posisjon slik at ballen går til musens siste posisjon
        mousePosition = sf::Mouse::getPosition(machine.getWindow());
        isPressed = true;
        //powerbar økes eller minkes
        scalingPower+=0.01*powerbarDirection;
        scalingPower2 = scalingPower;
        if(scalingPower>1)
        {
            scalingPower=1;
            powerbarDirection=-1;
        }
        if(scalingPower<0)
        {
            scalingPower=0;
            powerbarDirection=1;
        }
    }
    else
    {
        isPressed=false;
    }
    //Hvis powerbar har blitt fylt, og brukeren ikke fremdeles fyller den
    if(scalingPower2>0 && !isPressed){
        scalingPower2=0;
        if(pastFirstClick) moveBall(scalingPower);
    }

    // Tester om ballen treffer hindringen
    for(Obstacle* obstacle : obstaclelist)
    {
        if(Collision::BoundingBoxTest(ball.getSprite(), obstacle->getSprite()))
        {
            audio.playeffect(1);
            //std::cout << "ball hit" << std::endl;
            reboundBall(ball, *obstacle, machine, mousePosition, frictionmap, tilesize);
            ball.setSpeed(ball.getSpeed()-1.2);

        }
    }

    // Tester om ballen treffer hullet og farten er mindre enn ...
    for(Obstacle* obstacle : hullet) {
        if (Collision::BoundingBoxTest(ball.getSprite(), obstacle->getSprite()) && ball.getSpeed() < 7) {
            //std::cout << "ball hit" << std::endl;
            ball.setSpeed(0);
            collisionWithHole = true;
        }
    }

    for(Obstacle* obstacle : vann) {
        if (Collision::BoundingBoxTest(ball.getSprite(), obstacle->getSprite())) {
            std::cout << "ball hit water" << std::endl;
            ball.setSpeed(ball.getSpeed()-0.5);
            collisionWithWater = true;
        }
    }
    for(Obstacle* obstacle : ned) {
        if (Collision::BoundingBoxTest(ball.getSprite(), obstacle->getSprite()) && ball.getGrader()>0) {
            std::cout << "ball hit wall" << std::endl;

            reboundBall(ball, *obstacle, machine, mousePosition, frictionmap, tilesize);
            ball.setSpeed(ball.getSpeed()-1.2);
        }
        else if (Collision::BoundingBoxTest(ball.getSprite(), obstacle->getSprite()) && ball.getGrader()<0) {
            std::cout << "fail" << std::endl;
            ball.setSpeed(ball.getSpeed()+0.1);
        }
    }

    // If the ball has collided with the hole
    if(collisionWithHole) {
        // Make ball smaller
        if (ball.getSprite().getScale().x > 0.01) {
            ball.getSprite().setScale(ball.getSprite().getScale().x - 0.01,
                                      ball.getSprite().getScale().y - 0.01);
            ball.setXPos(ball.getXPos() + ball.getSprite().getLocalBounds().width / 100);
            ball.setYPos(ball.getYPos() + ball.getSprite().getLocalBounds().height / 100);
        } else {
            tegn = true;

            //Venter på at brukeren skal trykke for at vi skal fortsette til neste hull
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                pastFirstClick = false;
                tegn = false;
                award = true;
                std::cout << "level fullført. Loader neste level" << std::endl;
                level++;
                if (level > 4) {
                    level = 1;
                    pastFirstClick = false;
                    machine.SetState(Machine::StateId::MAINMENU);
                    firsttime = true;

                }
                if(level == 1){
                    //audio.play(2);
                }else if(level == 2){
                    audio.play(3);
                }else if(level == 3){
                    audio.play(5);
                }else if(level == 4){
                    audio.play(2);
                }
                initLevel();
                strokes = 0;
            }
        }
    }
    //If the ball has collided with water
    if(collisionWithWater) {
        // Make ball smaller
        if (ball.getSprite().getScale().x > 0.01) {
            ball.getSprite().setScale(ball.getSprite().getScale().x - 0.02,
                                      ball.getSprite().getScale().y - 0.02);
            ball.setXPos(ball.getXPos() + ball.getSprite().getLocalBounds().width / 100);
            ball.setYPos(ball.getYPos() + ball.getSprite().getLocalBounds().height / 100);
        } else {
            functions.DisplayString(machine.getWindow(), "A wild water appeared! It's very effective!", 200, 200, 10);
            //Venter på at brukeren skal trykke for at vi skal fortsette til neste hull
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                pastFirstClick = false;
                std::cout << "resetting ball" << std::endl;
                initLevel();
            }
        }
    }



    //Tegn ting
    //Bakgrunn
    machine.getWindow().clear(sf::Color::Blue);

    //render each object
    for (Object* objects : object)
    {
        objects->process(deltatime);
        objects->draw(machine.getWindow());
    }

    // Tegner bildene som skal være under ballen
    for (Object* objects : under)
    {
        objects->process(deltatime);
        objects->draw(machine.getWindow());
    }

    //Ball
    ball.Move(machine.getWindow().getSize().x, machine.getWindow().getSize().y, mousePosition, frictionmap, tilesize);
    ball.Draw(machine.getWindow());

    // Tegner bildene som skal være over ballen
    for (Object* objects : over)
    {
        objects->process(deltatime);
        objects->draw(machine.getWindow());
    }

    sf::String holeText = "Hole: " + std::to_string(level);
    functions.DisplayString(machine.getWindow(), holeText, 48, 2);
    sf::String parText = "Par: " + std::to_string(par);
    functions.DisplayString(machine.getWindow(), parText, 72, 2);

    //Display strokes (fagbegrep for antall slag)
    sf::String strokesText = "Strokes: " + std::to_string(strokes);
    functions.DisplayString(machine.getWindow(), strokesText, 8, 2);

    //Drawing the powerbar
    spriteBack.setTexture(powerbarBack);
    spriteBack.setPosition(sf::Vector2f(600,13));

    spriteFront.setTexture(powerbarFront);
    spriteFront.setPosition(sf::Vector2f(604,17));

    spriteFront.setScale(sf::Vector2f(scalingPower, 1.f));

    machine.getWindow().draw(spriteBack);
    machine.getWindow().draw(spriteFront);

    if(tegn) {

        if(award){
            audio.playeffect(0);
            award = false;
        }

        //Sjekker så og si alle scenarioer for score, og gir en pokeball + score string
        if (strokes == par) {
            endingText = "Par. Nice";
            if (!background.loadFromFile("data/Graphics/Textures/Quickball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else if (strokes == 1) {
            endingText = "HOLE IN ONE!!!!!!";
            if (!background.loadFromFile("data/Graphics/Textures/Masterball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else if (strokes == par - 1) {
            endingText = "BIRDIE!";
            if (!background.loadFromFile("data/Graphics/Textures/Quickball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else if (strokes == par - 2) {
            endingText = "Eagle!!! WELL DONE!";
            if (!background.loadFromFile("data/Graphics/Textures/Quickball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else if (strokes == par - 3) {
            endingText = "ALBATROSS!!! EXCELLENT!!";
            if (!background.loadFromFile("data/Graphics/Textures/Masterball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else if (strokes == par + 1) {
            endingText = "Bogey";
            if (!background.loadFromFile("data/Graphics/Textures/Safariball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else if (strokes == par + 2) {
            endingText = "Double bogey";
            if (!background.loadFromFile("data/Graphics/Textures/Safariball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else if (strokes == par + 3) {
            endingText = "Triple bogey";
            if (!background.loadFromFile("data/Graphics/Textures/Safariball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else if (strokes == par + 4) {
            endingText = "Quadrouple bogey";
            if (!background.loadFromFile("data/Graphics/Textures/Timerball copy.png")) {
                std::cout << "Failed to load\n";
            }
        } else {
            endingText = "";
            if (!background.loadFromFile("data/Graphics/Textures/At least you tried copy.png")) {
                std::cout << "Failed to load\n";
            }
        }
        sf::Sprite sprite(background);
        machine.getWindow().draw(sprite);
        functions.DisplayString(machine.getWindow(), endingText, 8, 12);
    }

    if(collisionWithWater) functions.DisplayString(machine.getWindow(), "A wild water appeared! \n It's very effective!", 50, 50, 20);

    //Vis vinduet etter at alt er tegnet
    machine.getWindow().display();
}