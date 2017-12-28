#include "functions.h"
#include <iostream>

Functions::Functions()
{
    if (!font.loadFromFile("data/Graphics/Text/Montserrat-Regular.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
}

void Functions::DrawRectangle(sf::RenderWindow& window, double width, double height, double x, double y, int outlineThickness)
{
    sf::RectangleShape border(sf::Vector2f(width*window.getSize().x/200, height*window.getSize().y/200));
    border.setFillColor(sf::Color::Black);
    border.setOutlineThickness(outlineThickness*window.getSize().y/200);
    border.setOutlineColor(sf::Color::White);
    border.setPosition(x*window.getSize().x/200, y*window.getSize().y/200);
    window.draw(border);
}

void Functions::DisplayString(sf::RenderWindow& window, sf::String tekst, int x, int y, int size, int outlineThickness)
{
    sf::Text text;
    text.setFont(font);
    text.setString(tekst);
    text.setCharacterSize(window.getSize().y/size);
    text.setPosition(x*window.getSize().x/200,y*window.getSize().x/200);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(outlineThickness);
    window.draw(text);
}

void Functions::DisplayText(sf::RenderWindow& window, sf::Text& text, double position)
{
    text.setFont(font);
    text.setCharacterSize(window.getSize().y/15);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().y/5, (window.getSize().x/10)*position);

    sf::Text text1;
    text1.setFont(font);
    text1.setCharacterSize(text.getCharacterSize());
    text1.setFillColor(text.getFillColor());
    text1.setString(text.getString());
    text1.setPosition(text.getPosition());

    window.draw(text1);
}

int Functions::checkButtonPressed(sf::RenderWindow& window, std::vector<sf::Text> buttons, sf::Vector2f pointClicked)
{
    int counter = 0;
    bool truffetKnapp = false;
    for (std::vector<sf::Text>::const_iterator i = buttons.begin(); i != buttons.end(); ++i)
    {
        counter++;
        if (i->getGlobalBounds().contains(pointClicked))
        {
            truffetKnapp = true;
            break;
        }
    }
    if(truffetKnapp) return counter;
    else return 0;
}

