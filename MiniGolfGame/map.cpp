#include <fstream>
#include <cstring>

#ifdef __linux__
#include <jsoncpp/json/json.h>
#elif _WIN32
#include <jsoncpp/json/json.h>
#elif __APPLE__
#include <json/json.h>
#else
#error No operating system defined
#endif

#include <SFML/Graphics.hpp>

#include "map.h"
#include "layer.h"
#include "sprite.h"
#include "iostream"

bool Map::load(std::string fileName, std::list<Object*>& object, std::list<Obstacle*>& testlistthing,
               int (&frictionmap)[100][100], int& tilesizeinfo, std::list<Object*>& under, std::list<Object*>& over,
               std::list<Obstacle*>& hullet, std::list<Obstacle*>& vann, std::list<Obstacle*>& ned)
{

    memset(frictionmap, 0, sizeof(frictionmap));

    //data we read inn
    Json::Value data;
    //parsing the file
    Json::Reader reader;
    //steam used for reading data file
    std::ifstream file(fileName);
    //read data from file into value
    bool parsingSuccsess = reader.parse(file, data);
    //check if all is ok
    if(!parsingSuccsess)
        return false;

    //get information about size of the tiles
    TileSize tileSize;
    tileSize.x = data["tilesets"][0u]["tilewidth"].asInt();
    tileSize.y = data["tilesets"][0u]["tileheight"].asInt();
    tileSize.s = data["tilesets"][0u]["spacing"].asInt();

    tilesizeinfo = tileSize.x;

    // Read in tileset (Should be handled by a resource handler)
    sf::Texture* tileset = new sf::Texture();
    tileset->loadFromFile("data/Graphics/Textures/" + data["tilesets"][0u]["image"].asString());

    std::map<std::string, int> frictiondict;
    if(!data["tilesets"][0u]["tileproperties"].isNull()){

        std::vector<std::string> frictionmembers = data["tilesets"][0u]["tileproperties"].getMemberNames();

        for(std::string s:frictionmembers){
            //std::cout << s << std::endl;
            frictiondict[s] = data["tilesets"][0u]["tileproperties"][s]["friction"].asInt();
        }

    }


    //read inn each layers (load inn all the layers and objects)
    for(Json::Value& layer: data["layers"])
    {
        //all the layers
        if(layer["name"].asString() == "Grass")
            loadLayer(layer, object, tileSize, frictiondict, frictionmap);

        else if(layer["name"].asString() == "over") {
            loadLayer(layer, over, tileSize, frictiondict, frictionmap);
        }
        else if(layer["name"].asString() == "under")
            loadLayer(layer, under, tileSize, frictiondict, frictionmap);

        //all the objects
        else if(layer["name"].asString() == "objectRock")
            loadObject(data, layer, object, tileSize);

        else if(layer["name"].asString() == "objectHole")
            loadObject(data, layer, object, tileSize);

        else if(layer["name"].asString() == "objectStart")
            loadObject(data, layer, object, tileSize);

        else if(layer["name"].asString() == "hittest")
        {
            loadHindringer2(data, layer, testlistthing, tileSize, tileset);
        }
        else if(layer["name"].asString() == "hullet")
        {
            loadHindringer2(data, layer, hullet, tileSize, tileset);
        }
        else if(layer["name"].asString() == "vann")
        {
            loadHindringer2(data, layer, vann, tileSize, tileset);
        }
        else if(layer["name"].asString() == "ned")
        {
            loadHindringer2(data, layer, ned, tileSize, tileset);
        }

        // Make layer
        else
        {
            loadLayer(layer, object, tileSize, frictiondict, frictionmap);
        }
    }
    // Assign tileset to every object
    for (Object* objects: object)
        objects->texture = tileset;
    for (Object* objects: over)
        objects->texture = tileset;
    for (Object* objects: under)
        objects->texture = tileset;

    return true;
}

void Map::loadLayer(Json::Value &layer, std::list<Object*>& object, TileSize tileSize, std::map<std::string, int>& frictiondict, int (&frictionmap)[100][100])
{
    Layer* tmp = new Layer(tileSize);

    // Store info on layer
    tmp->width = layer["width"].asInt();
    tmp->height = layer["height"].asInt();
    tmp->isSolid = layer["isSolid"].asBool();

    // Clear tilemap
    memset(tmp->tilemap, 0, sizeof(tmp->tilemap));

    // Read in tilemap
    std::cout << "layer data size: " << layer["data"].size() << std::endl;
    for (size_t i = 0; i < layer["data"].size(); i++){

        tmp->tilemap[i % tmp->width][i / tmp->width] = layer["data"][(int)i].asInt();

        int riktigtileid = layer["data"][(int)i].asInt();
        riktigtileid--;

        //Read in friction from json file
        if(frictiondict.find(std::to_string(riktigtileid)) != frictiondict.end()){
            frictionmap[i % tmp->width][i / tmp->width] = frictiondict[std::to_string(riktigtileid)];
        }
    }
        object.push_back(tmp);
}

void Map::loadObject(Json::Value &root, Json::Value &layer, std::list<Object*>& objects, TileSize tileSize)
{
// Get all objects from layer
    for (Json::Value& object: layer["objects"])
    {
        Sprite* sprite = new Sprite(tileSize);

        // Load basic object info
        sprite->x = object["x"].asInt();
        sprite->y = object["y"].asInt() - sprite->tileSize.y;
        sprite->id = object["gid"].asInt();

        // Load animation data
        Json::Value& tileInfo = root["tilesets"][0u]["tiles"][std::to_string(sprite->id - 1)];
        sprite->frame = 0;
        sprite->frameCount = tileInfo["animation"].size();
        sprite->frameDuration = tileInfo["animation"][0u]["duration"].asInt();

        objects.push_back(sprite);
    }
}

void Map::loadHindringer2(Json::Value& root, Json::Value& layer, std::list<Obstacle*>& testlistthing, TileSize tileSize, sf::Texture* texture)
{
    // Get all objects from layer
    for (Json::Value& object: layer["objects"])
    {
        int x = object["x"].asInt();
        int y = object["y"].asInt();
        int width = object["width"].asInt();
        int height = object["height"].asInt();

        Obstacle* sprite = new Obstacle(x, y, texture,
                                        sf::IntRect(0, 0, width, height));
        sprite->setRotation(object["rotation"].asFloat());
        testlistthing.push_back(sprite);
    }
}