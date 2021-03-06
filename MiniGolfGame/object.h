/**
 * This class shall represent any game object
 */

#ifndef MINIGOLF_OBJECT_H
#define MINIGOLF_OBJECT_H

namespace sf
{
    class RenderWindow;
    class Texture;
}

// Small helper struct that contains tile size information
struct TileSize
{
    int x; // Width
    int y; // Height
    int s; // Spacing
};

// Class representing any game object
class Object
{
    // Map needs to access protected/private data
    friend class Map;

public:
    //constructor
    Object(TileSize tileSize) : tileSize(tileSize) { }
    //deconstructor
    virtual ~Object();

    virtual void process(float deltaTime) {}
    virtual void draw(sf::RenderWindow& window) {}

    // Calculate x and y position of given tile in the texture
    void getTileCoords(int tile, int& x, int& y);

    const TileSize tileSize;

protected:
    sf::Texture* texture;
};

#endif
