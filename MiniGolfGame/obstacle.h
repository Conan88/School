#ifndef MINIGOLF_OBSTACLE_H
#define MINIGOLF_OBSTACLE_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics.hpp"

class Obstacle
{
public:
    Obstacle() { }
    ~Obstacle()
    {
        delete texture;
        texture = nullptr;
    }
    Obstacle(int xPos, int yPos, sf::Texture* textureptr, sf::IntRect subsection);

    int getXPos() const;
    int getYPos() const;

    float getRotation() const;

    const sf::Sprite &getSprite() const;

    void setXPos(int xPos);
    void setYPos(int yPos);
    void setRotation(float degrees);

    void setSides();

    const sf::Sprite &getTop() const;
    const sf::Sprite &getBottom() const;
    const sf::Sprite &getLeft() const;
    const sf::Sprite &getRight() const;

protected:
    int xPos = 0;
    int yPos = 0;

    sf::Texture* texture;
    sf::Sprite sprite;
    sf::IntRect subsec;
    sf::Sprite top;
    sf::Sprite bottom;
    sf::Sprite left;
    sf::Sprite right;

    int sideWidth = 1;
};


#endif //MINIGOLF_OBSTACLE_H
