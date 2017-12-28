#include "obstacle.h"
#include "math.h"
#define PI 3.14159265
#include "util.h"

void Obstacle::setSides()
{
    top.setRotation(sprite.getRotation());
    bottom.setRotation(sprite.getRotation());
    left.setRotation(sprite.getRotation());
    right.setRotation(sprite.getRotation());

    top.setPosition(sprite.getPosition());
    bottom.setPosition(sprite.getPosition().x + sin(0 - toRadians(sprite.getRotation()))*(sprite.getLocalBounds().height-sideWidth),
                       sprite.getPosition().y + cos(0 - toRadians(sprite.getRotation()))*(sprite.getLocalBounds().height-sideWidth));
    left.setPosition(sprite.getPosition());
    right.setPosition(sprite.getPosition().x + cos(0 - toRadians(sprite.getRotation()))*(sprite.getLocalBounds().width-sideWidth),
                      sprite.getPosition().y - sin(0 - toRadians(sprite.getRotation()))*(sprite.getLocalBounds().width-sideWidth));
    }

Obstacle::Obstacle(int xPos, int yPos, sf::Texture* textureptr, sf::IntRect subsection)
{
    texture = textureptr;

    this->subsec = subsection;
    sprite.setTexture(*texture);
    sprite.setTextureRect(subsec);

    setXPos(xPos);
    setYPos(yPos);

    sprite.setPosition(xPos, yPos);

    top.setTexture(*texture);
    top.setTextureRect(sf::IntRect(0, 0, sprite.getLocalBounds().width, sideWidth));
    bottom.setTexture(*texture);
    bottom.setTextureRect(sf::IntRect(0, sprite.getLocalBounds().height-sideWidth, sprite.getLocalBounds().width, sideWidth));
    left.setTexture(*texture);
    left.setTextureRect(sf::IntRect(0, 0, sideWidth, sprite.getLocalBounds().height));
    right.setTexture(*texture);
    right.setTextureRect(sf::IntRect(sprite.getLocalBounds().width-sideWidth, 0, sideWidth, sprite.getLocalBounds().height));

    setSides();
}

int Obstacle::getXPos() const
{
    return xPos;
}
int Obstacle::getYPos() const
{
    return yPos;
}
float Obstacle::getRotation() const
{
    return sprite.getRotation();
}

void Obstacle::setXPos(int xPos)
{
    Obstacle::xPos = xPos;
    sprite.setPosition(xPos, yPos);
    setSides();
}
void Obstacle::setYPos(int yPos)
{
    Obstacle::yPos = yPos;
    sprite.setPosition(xPos, yPos);
    setSides();
}

void Obstacle::setRotation(float degrees)
{
    sprite.setRotation(degrees);
    setSides();
}

const sf::Sprite &Obstacle::getSprite() const
{
    return sprite;
}

const sf::Sprite &Obstacle::getTop() const
{
    return top;
}

const sf::Sprite &Obstacle::getBottom() const
{
    return bottom;
}

const sf::Sprite &Obstacle::getLeft() const
{
    return left;
}

const sf::Sprite &Obstacle::getRight() const
{
    return right;
}