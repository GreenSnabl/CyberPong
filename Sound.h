/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sound.h
 * Author: snbl
 *
 * Created on April 29, 2018, 2:20 PM
 */

#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <SFML/Audio.hpp>

class Sound {
public:
    Sound() : sbuff{new sf::SoundBuffer} {}
    ~Sound() {
        delete sbuff;
    }
    
    void loadBuffer(std::string name);
    
    void playSound();
    sf::SoundBuffer* sbuff;
    
};



#endif /* SOUND_H */

