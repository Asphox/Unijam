//
// Created by nayht on 24/11/2019.
//

#include "Audio.h"

Audio::Audio() {
    addSound(SOUND::CAR1BOOST, "Assets/car1boost.ogg");
    addSound(SOUND::CAR2BOOST, "Assets/car2boost.ogg");
    addSound(SOUND::CAR1SPEED, "Assets/car1Speed.ogg");
    addSound(SOUND::CAR2SPEED, "Assets/car2Speed.ogg");
    addSound(SOUND::CAR1JUMP, "Assets/car1Jump.ogg");
    addSound(SOUND::CAR2JUMP, "Assets/car2Jump.ogg");
    addSound(SOUND::CAR1CRASH, "Assets/car1Crash.ogg");
    addSound(SOUND::CAR2CRASH, "Assets/car2Crash.ogg");
    addSound(SOUND::ECHEC, "Assets/echec.ogg");
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
    if (volume > 100){
        volume = 100.0f;
    }
    m_soundMap.at((int)sound).setVolume(volume);
    m_soundMap.at((int)sound).play();
}

void Audio::playSound(SOUND sound, bool loop){
    m_soundMap.at((int)sound).setLoop(loop);
    m_soundMap.at((int)sound).play();
}

void Audio::modifySound(SOUND sound, float volume, float pitch){
    m_soundMap.at((int)sound).setVolume(volume);
    m_soundMap.at((int)sound).setPitch(pitch);
}

void Audio::modifySound(SOUND sound, float volume){
    m_soundMap.at((int)sound).setVolume(volume);
}

int Audio::playBackgroundMusic() {
    if (!m_isBackgroundMusicLaunched) {
        if (!m_backgroundMusic.openFromFile("Assets/backgroundMusic.ogg")) {
            printf("Audio file not found!\n");
            return -1; // error
        }
        m_backgroundMusic.setLoop(true);
        m_backgroundMusic.setVolume(20.0f);
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
        m_backgroundMusic.setVolume(20.0f);
    }
    else{
        m_backgroundMusic.setVolume(50.0f);
    }
}


