#ifndef MINIGOLF_BALL_H
#define MINIGOLF_BALL_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics.hpp"

class Ball
{
public:
    Ball() { }
    Ball(float windowWidth, float windowHeight);
    void create(float windowWidth, float windowHeight);

    void InitPosition(float windowWidth, float windowHeight);
    void Draw(sf::RenderWindow& window);

    float getFartsreduksjon() const;

    sf::Sprite &getSprite();

    sf::Vector2f getBallPos()
    {
        return sprite.getPosition();
    }

    void Move(int windowWidth, int windowHeight, sf::Vector2i mousePosition, int (&frictionmap)[100][100], int tilesize);

    float getXPos() const;
    void setXPos(float xPos);

    float getYPos() const;
    void setYPos(float yPos);

    float getSpeed() const;
    void setSpeed(float speed);

    float getGrader() const;
    void setGrader(float grader);

    float getRadius() const;
    void setRadius(float radius);

    int getXDir() const;
    void setXDir(int xDir);

    int getYDir() const;
    void setYDir(int yDir);

protected:
    int xDir = 1;
    int yDir = 1;

    float xPos;
    float yPos;
    float speed; //hypotnuse
    float grader = 0;
    float radius = 20;
    float fartsreduksjon = 0.05;

    sf::Texture texture;
    sf::Sprite sprite;
};

#endif