//
// Created by nayht on 24/11/2019.
//

#include "Audio.h"

Audio::Audio() {
    addSound(SOUND::CAR1BOOST, "Assets/car1boost.ogg");
    addSound(SOUND::CAR2BOOST, "Assets/car2boost.ogg");
}

Audio::~Audio() {

}

void Audio::addSound(SOUND sound, char* filename){
    sf::SoundBuffer soundBuffer;
    if (!soundBuffer.loadFromFile(filename)){
        printf("Audio file '%s' not found!\n", filename);
    }
    m_soundBufferMap.emplace((int)sound, soundBuffer);

    sf::Sound soundPlayer;
    soundPlayer.setBuffer(m_soundBufferMap.at((int)sound));
    soundPlayer.play();
    m_soundMap.emplace((int)sound, soundPlayer);
}

void Audio::playSound(SOUND sound) {
    Audio::playSound(sound, 100.0f);
}

void Audio::playSound(SOUND sound, float volume){
    m_soundMap.at((int)sound).setVolume(std::max(volume,100.0f));
    m_soundMap.at((int)sound).play();
}

int Audio::playBackgroundMusic() {
    if (!m_isBackgroundMusicLaunched) {
        if (!m_backgroundMusic.openFromFile("Assets/backgroundMusic.ogg")) {
            printf("Audio file not found!\n");
            return -1; // error
        }
        m_backgroundMusic.setLoop(true);
        m_backgroundMusic.setVolume(30.0f);
        m_backgroundMusic.play();
        m_isBackgroundMusicLaunched = true;
        return 0;
    }
    else{
        return -1;
    }
}

void Audio::pause(bool isPause){
    if (isPause){
        m_backgroundMusic.setVolume(30.0f);
    }
    else{
        m_backgroundMusic.setVolume(100.0f);
    }
}


