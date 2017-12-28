#include "ball.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "util.h"
#define PI 3.14159265

Ball::Ball(float windowWidth, float windowHeight)
{
    if (!texture.loadFromFile("data/Graphics/Textures/ball.png"))
    {
        // error...
    }
    sprite.setTexture(texture);
    InitPosition(windowWidth, windowHeight);
}

void Ball::create(float windowWidth, float windowHeight){
    //do i need to delete existing texture if one exists? memory leak?
    if (!texture.loadFromFile("data/Graphics/Textures/ball.png"))
    {
        // error...
    }
    sprite.setTexture(texture);
    InitPosition(windowWidth, windowHeight);
    radius=20;
}

void Ball::InitPosition(float windowWidth, float windowHeight)
{
    xPos = windowWidth/2-radius;
    yPos = (windowHeight/10)*9;
    sprite.setPosition(xPos, yPos);
    speed = 0;
    xDir = 1;
    yDir = 1;

    radius = sprite.getLocalBounds().width/2;
}



void Ball::Move(int windowWidth, int windowHeight, sf::Vector2i mousePosition, int (&frictionmap)[100][100], int tilesize) {
    //Holder ballen innenfor banen
    if(sprite.getPosition().x > windowWidth-radius*2){           //høyre kant truffet
        //ball.setPosition(windowWidth-radius*2, ball.getPosition().y);
        xPos = windowWidth-radius*2;
        xDir = -xDir;                            //gå mot venstre
        speed-=fartsreduksjon;
    }
    else if(sprite.getPosition().x < 0)
    {                           //venstre kant truffet
        //ball.setPosition(0, ball.getPosition().y);
        xPos = 0;
        xDir = -xDir;                             //og gå mot høyre
        speed-=fartsreduksjon;

    }
    else if(sprite.getPosition().y < 0)
    {                           //kanten oppe truffet
        //ball.setPosition(ball.getPosition().x, 0);
        yPos = 0;
        yDir = -yDir;
        speed-=fartsreduksjon;
    }
    else if(sprite.getPosition().y >windowHeight-radius*2)
    {       //kanten nede truffet
        //ball.setPosition(ball.getPosition().x, windowHeight-radius*2);
        yPos = windowHeight-radius*2;
        yDir = -yDir;
        speed-=fartsreduksjon;
    }

    //Selve flyttingen av ballen
    xPos += cos(toRadians(grader))*speed*xDir;
    yPos -= sin(toRadians(grader))*speed*yDir;
    sprite.setPosition(xPos, yPos);

    if(speed > 0)
    {
        speed -= fartsreduksjon;
        int friksjonstall = frictionmap[(int)(getXPos() / tilesize)][(int)(getXPos() / tilesize)];
        if(friksjonstall > 0)
            std::cout << friksjonstall << std::endl;
        speed -= friksjonstall;

    }
    else
    {
        speed = 0;
        xDir = 1;
        yDir = 1;
    }

}

void Ball::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

float Ball::getXPos() const
{
    return xPos;
}

void Ball::setXPos(float xPos)
{
    Ball::xPos = xPos;
    sprite.setPosition(xPos, yPos);
}

float Ball::getYPos() const
{
    return yPos;
}

void Ball::setYPos(float yPos)
{
    Ball::yPos = yPos;
    sprite.setPosition(xPos, yPos);
}

float Ball::getSpeed() const
{
    return speed;
}

void Ball::setSpeed(float speed)
{
    Ball::speed = speed;
}

float Ball::getGrader() const
{
    return grader;
}

void Ball::setGrader(float grader)
{
    Ball::grader = grader;
}

float Ball::getRadius() const
{
    return radius;
}

void Ball::setRadius(float radius)
{
    Ball::radius = radius;
}

sf::Sprite &Ball::getSprite()
{
    return sprite;
}

float Ball::getFartsreduksjon() const
{
    return fartsreduksjon;
}

int Ball::getXDir() const
{
    return xDir;
}

void Ball::setXDir(int xDir)
{
    Ball::xDir = xDir;
}

int Ball::getYDir() const
{
    return yDir;
}

void Ball::setYDir(int yDir)
{
    Ball::yDir = yDir;
}
