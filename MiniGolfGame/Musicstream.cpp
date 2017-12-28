
#include "Musicstream.h"

Audio::Audio(){
    sf::SoundBuffer* buffer = new sf::SoundBuffer;

    if (buffer->loadFromFile("data/Audio/Effects/039-obtained-a-key-item-.ogg"))
        soundeffectslist.push_back(buffer);

    buffer = new sf::SoundBuffer;
    if (buffer->loadFromFile("data/Audio/Effects/bump.ogg"))
        soundeffectslist.push_back(buffer);

    buffer = new sf::SoundBuffer;
    if (buffer->loadFromFile("data/Audio/Effects/Kingdom_Hearts_Sound_Effects_-_Select.ogg"))
        soundeffectslist.push_back(buffer);
//
    buffer = new sf::SoundBuffer;
    if (buffer->loadFromFile("data/Audio/Music/a.ogg"))
        songlist.push_back(buffer);

    buffer = new sf::SoundBuffer;
    if (buffer->loadFromFile("data/Audio/Music/Wonderland.ogg"))
        songlist.push_back(buffer);

    buffer = new sf::SoundBuffer;
    if (buffer->loadFromFile("data/Audio/Music/011-oldale-town.ogg"))
        songlist.push_back(buffer);

    buffer = new sf::SoundBuffer;
    if (buffer->loadFromFile("data/Audio/Music/009_Route_29.ogg"))
        songlist.push_back(buffer);

    buffer = new sf::SoundBuffer;
    if (buffer->loadFromFile("data/Audio/Music/002_Title_Screen.ogg"))
        songlist.push_back(buffer);

    buffer = new sf::SoundBuffer;
    if (buffer->loadFromFile("data/Audio/Music/073_Route_42.ogg"))
        songlist.push_back(buffer);

    player.setVolume(player.getVolume()/3);
}

Audio::~Audio(){
    for(sf::SoundBuffer* buffer : songlist){
        delete buffer;
        buffer = nullptr;
    }
}

void Audio::play(int index){
    player.setBuffer(*songlist[index]);
    player.play();
}
void Audio::playeffect(int index){
    effects.setBuffer(*soundeffectslist[index]);
    effects.play();
}

void Audio::nextSong(){
        player.setBuffer(*songlist[0]);
        player.play();

}
