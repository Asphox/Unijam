//
// Created by nayht on 24/11/2019.
//

#ifndef UNIJAM_AUDIO_H
#define UNIJAM_AUDIO_H


#include <SFML/Audio.hpp>
#include <map>

class Audio {
    enum class SOUND{
        BOOST
    };
private:
    std::map<SOUND, sf::SoundBuffer> m_soundMap;
    sf::Music m_backgroundMusic;
    bool m_isBackgroundMusicLaunched = false;
public:
    Audio();
    ~Audio();
    void playSound(SOUND sound);
    int playBackgroundMusic();
    void pause(bool isPause);
};


#endif //UNIJAM_AUDIO_H
