//
// Created by nayht on 24/11/2019.
//

#include "Audio.h"

Audio::Audio() {
    sf::SoundBuffer boostCar1Buffer;
    if (!boostCar1Buffer.loadFromFile("Assets/backgroundMusic.ogg")){
        printf("Audio file not found!\n");
    }
    m_soundMap.emplace(SOUND::BOOST, boostCar1Buffer);
}

Audio::~Audio() {

}

void Audio::playSound(SOUND sound){
    sf::Sound soundPlayer;
    soundPlayer.setBuffer(m_soundMap.at(sound));
    soundPlayer.play();
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


