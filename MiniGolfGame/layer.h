/**
 *
 */

#ifndef MINIGOLF_LAYER_H
#define MINIGOLF_LAYER_H

#include "object.h"

// Class representing a tile layer
class Layer : public Object
{
    // Map needs to access protected/private data
    friend class Map;

public:
    Layer(TileSize tileSize) : Object(tileSize) { }

    void draw(sf::RenderWindow& window);

protected:
    // Size in tiles
    int width, height;
    int tilemap[100][100];

    bool isSolid;
};

#endif
