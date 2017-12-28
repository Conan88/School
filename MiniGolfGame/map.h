/**
 * This class should handle all the the map.
 *
 * It will handle the  regular layers, and the object layers, it will also load the map from Tiled Json file.
 */
#ifndef MINIGOLF_MAP_H
#define MINIGOLF_MAP_H

#include <string>
#include <list>

#include "object.h"
#include "obstacle.h"

namespace Json
{
    class Value;
}

class Map
{
public:
    //load the Tiled Json file

    static bool load(std::string fileName, std::list<Object*>& object, std::list<Obstacle*>& testlistthing,
                     int (&frictionmap)[100][100], int& tilesizeinfo, std::list<Object*>& under, std::list<Object*>& over,
                     std::list<Obstacle*>& hullet, std::list<Obstacle*>& vann, std::list<Obstacle*>& ned);
protected:
    //layers
    static void loadLayer(Json::Value& layer, std::list<Object*>& object, TileSize tileSize, std::map<std::string, int>& frictiondict, int (&frictionmap)[100][100]);
    //objects
    static void loadObject(Json::Value& root, Json::Value& layer, std::list<Object*>& object, TileSize tileSize);
    //hindringer
    static void loadHindringer2(Json::Value& root, Json::Value& layer, std::list<Obstacle*>& testlistthing, TileSize tileSize, sf::Texture* texture);
};

#endif
