//
// Created by nayht on 24/11/2019.
//

#ifndef UNIJAM_AUDIO_H
#define UNIJAM_AUDIO_H


#include <SFML/Audio.hpp>
#include <map>

class Audio {
private:
    std::map<int, sf::SoundBuffer> m_soundBufferMap;
    std::map<int, sf::Sound> m_soundMap;
    sf::Music m_backgroundMusic;
    bool m_isBackgroundMusicLaunched = false;
public:
    enum class SOUND{
        CAR1BOOST,
        CAR2BOOST,
        CAR1SPEED,
        CAR2SPEED,
        CAR1JUMP,
        CAR2JUMP,
        CAR1CRASH,
        CAR2CRASH,
        ECHEC
    };
    Audio();
    ~Audio();
    void playSound(SOUND sound);
    int playBackgroundMusic();
    void pause(bool isPause);
    void addSound(SOUND sound, char *filename);

    void playSound(SOUND sound, bool loop);
    void playSound(SOUND sound, float volume);
    void modifySound(SOUND sound, float volume, float pitch);

    void modifySound(SOUND sound, float volume);
};


#endif //UNIJAM_AUDIO_H
