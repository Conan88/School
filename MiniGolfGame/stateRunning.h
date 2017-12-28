#ifndef MINIGOLF_STATETESTBALL_H
#define MINIGOLF_STATETESTBALL_H

#include "state.h"
#include "object.h"
#include <list>
#include <iostream>
#include "ball.h"
#include "obstacle.h"

class Object;

class StateRunning : public State
{
public:
    StateRunning(int width, int height);
    void Running(Machine &machine, Audio& audio);
    void reboundBall(Ball& ball, Obstacle& obstacle, Machine& machine, sf::Vector2i mousePosition, int (&frictionmap)[100][100], int tilesize);
    void reactUpDown(Ball& ball, Obstacle& obstacle, Machine& machine, sf::Vector2i mousePosition, int (&frictionmap)[100][100], int tilesize);
    void reactRightLeft(Ball& ball, Obstacle& obstacle, Machine& machine, sf::Vector2i mousePosition, int (&frictionmap)[100][100], int tilesize);
    void moveBall(float power);
    void initLevel();

    float deltatime;
    float scalingPower = 0.0f;
    float scalingPower2 = scalingPower;
    int powerbarDirection=1;
    bool isPressed = false, pastFirstClick = false, isMousePressed, wasMousePressed, tegn = false;

    sf::Texture background;
    bool firsttime = true;
    bool award = true;

    sf::Texture powerbarBack, powerbarFront;
    sf::Sprite spriteBack, spriteFront;
    sf::Clock timer;

protected:
    std::list<Object*> object;
    std::list<Object*> over;
    std::list<Object*> under;
    int strokes;
    std::list<Obstacle*> hullet;
    std::list<Obstacle*> vann;
    std::list<Obstacle*> ned;
    std::list<Obstacle*> obstaclelist;
    int frictionmap[100][100];
    Ball ball;
    int par;
    int tilesize;
    bool collisionWithHole = false, collisionWithWater = false;
    int level = 1;
    sf::Vector2i mousePosition = {0, 0};
    sf::String endingText = "";
};


#endif

