
#ifndef MINIGOLF_MUSICSTREAM_H
#define MINIGOLF_MUSICSTREAM_H

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Audio {
public:
    Audio();
    ~Audio();
    void play(int index);
    void playeffect(int index);
    void nextSong();

    enum class EFFECTS {BUMP = 0, GETITEM};
    enum class SONGS {CHILDISH, SWIFTY, POKE1, POKE2};

    sf::Sound player;
    sf::Sound effects;
private:
    std::vector<sf::SoundBuffer*> songlist;
    std::vector<sf::SoundBuffer*> soundeffectslist;
};
#endif //MINIGOLF_MUSICSTREAM_H
