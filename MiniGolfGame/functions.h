#ifndef MINIGOLF_FUNCTIONS_H
#define MINIGOLF_FUNCTIONS_H

#include "SFML/Graphics.hpp"

//Klassen brukes for funksjoner vi har bruk for flere steder.

class Functions
{
public:
    Functions();
    void DrawRectangle(sf::RenderWindow& window, double width, double height, double x, double y, int outlineThickness = 0);
    void DisplayText(sf::RenderWindow& window, sf::Text& text, double position);
    void DisplayString(sf::RenderWindow& window, sf::String tekst, int x, int y, int size = 35, int outlineThickness = 2);
    int checkButtonPressed(sf::RenderWindow& window, std::vector<sf::Text> buttons, sf::Vector2f pointClicked);

protected:
    sf::Font font;
    sf::RenderWindow renderWindow;
};

#endif
